## format.hpp

#### Binary serialization/deserialization in a single header

The purpose of this single-header library is to provide a framework with which you
can create readers and writers of structured binary data using template meta programming.

#### Example

```c++
std::stringstream sd{};
sd.exceptions(std::ios_base::badbit);
struct Test {
    uint8_t a;
    uint8_t b;
    uint8_t c;
    Test(uint8_t i, uint8_t j, uint8_t k) : a(i), b(j), c(k) {}
} t{0, 0, 0};
using F = Format<St<Test, // St = Structure
                    O<offsetof(Test, a), Sc<uint8_t>>, // Sc = Scalar
                    O<offsetof(Test, b), Sc<uint8_t>>,
                    O<offsetof(Test, c), Sc<uint8_t>>>>;
sd.str("abc");
F::reader(sd).read(t);
assert(t.a == 'a');
assert(t.b == 'b');
assert(t.c == 'c');
sd.clear();
F::writer(sd).write(a).write(b).write(c);
assert(sd.str() == "abc");
```

The format "specification" of the structured data is the template argument to `format::Format`.
The individual data is then read into variables by calling
`Format::reader(STL-stream).read(first-value).read(second-value)...` and written from variables using
`Format::writer(STL-stream).write(first-value).write(second-value)...`.

**Note: In the documentation below, template type arguments (`T`, `Prefix`, ...) refer to format-types
(like `Scalar<uint8_t>` instead of `uint8_t`), but when talking about data/variables of type `T` its result data type
is meant (like `uint8_t` for `Scalar<uint8_t>`).**

#### Usage

git users who only want the header can add a release branch as a submodule:

```
git submodule add -b v0.1-release https://github.com/fstiewitz/format.hpp format
```

The header is then located in `format/include/format.hpp`. The branch name follows semantic versioning. `v0.1-release`
is a branch which only includes the header and license. `v0.1-code` is on the master branch with tests and README.
Full version names (like `v0.1.0-...`) are tags.

#### Scalar Values (`Sc<T>`, `Scalar<T>`)

Read/Write data of type `T` by reading `sizeof(T)` bytes.

```c++
uint8_t a;
Format<Sc<uint8_t>>::reader(stream).read(a);
```

#### Structures (`St<T, Args...>`, `Structure<T, Args...>`)

##### Reading

Read data according to `Args`, create structure/class of type `T` by calling its constructor
with rvalue references to the data.

##### Writing

To write a structure, `Args` need to include information on how to access the data inside the structure.
To do this, you can use `Offset<int, T>` (`O<int, T>`) to specify byte-offsets (usually using `offsetof`)
or `Accessor<Ptr, T>` (`Acc<Ptr, T>`) to specify the function pointer to a member function getter.

```c++
struct Test {
    uint8_t a;
    uint8_t b;
    uint8_t c;
    Test(uint8_t i, uint8_t j, uint8_t k) : a(i), b(j), c(k) {}
};

Format<St<Test,
          O<offsetof(Test, a), Sc<uint8_t>>,
          O<offsetof(Test, b), Sc<uint8_t>>,
          O<offsetof(Test, c), Sc<uint8_t>>>>;
```

```c++
struct Test {
    uint8_t a;
    uint8_t b;
    uint8_t c;
    Test(uint8_t i, uint8_t j, uint8_t k) : a(i), b(j), c(k) {}
    auto &getA() const {return a;}
    auto &getB() const {return b;}
    auto &getC() const {return c;}
};

Format<St<Test,
          Acc<&Test::getA, Sc<uint8_t>>,
          Acc<&Test::getB, Sc<uint8_t>>,
          Acc<&Test::getC, Sc<uint8_t>>>>;
```

#### Bitfields (`Bitfield<R, T, Bits<O, S, E>, Bits<O1, S1, E1>>`)

Read data of type `T` (must be `uint8_t`, `uint16_t` or `uint32_t`).
A value inside `T` is described by `Bits<O, S, E>` where `S` is the start bit, `E` is the end bit (inclusive).
Returns a value of type `R` constructed using those values.

To write the bitfield, `O` is the byte-offset of the value inside of the structure. The type of each value is
an unsigned integer of the smallest size which fits the data (ex: `Bits<0, 5, 10>` reads `1+10-5=6` bytes = `uint8_t`).

```c++
std::stringstream sd{};
uint8_t r = '1';
sd.str(std::string(reinterpret_cast<const char*>(&r), 1));
sd.exceptions(std::ios_base::badbit);
struct Test {
    uint8_t a {};
    uint8_t b {};
    uint8_t c {};
    Test() = default;
    Test(uint8_t i, uint8_t j, uint8_t k) : a(i), b(j), c(k) {}
} t {};
using Format = format::Format<Bitfield<Test, uint8_t,
                                       Bits<offsetof(Test, a), 0, 2>,
                                       Bits<offsetof(Test, b), 3, 4>,
                                       Bits<offsetof(Test, c), 5, 7>>>;
Format::reader(sd).read(t);
static_assert(std::is_same_v<Format::Type<0>, Test>);
assert(t.a == 1);
assert(t.b == 2);
assert(t.c == 1);
sd.clear();
Format::writer(sd).write(t);
assert(sd.str() == "1");
```

##### Packed Values (`Packed<T>`)

This is a helper class used by `Bitfield`. It has one property, `T value` and two methods:

- `apply<Start, End>(v)` inserts `v` into `value` from bits `Start` to `End`.
- `get<Start, End>()` returns bits `Start` to `End` in `value`.

This class is a wrapper around `(Value >> Offset) & Mask` and `Value = (Value & !Mask) | ((Value << Offset) & Mask)`.

#### Terminated Array (`TerminatedArray<T, int Abort = 0>`, `Ta<T, int Abort = 0>`)

Read entries using format `T` until:

- if `T` reads/writes an integral value: entry equals `T(Abort)`.
- else: entry equals `T()` (default-constructed).

Result is an `std::vector<T>`.

Likewise, write data of type `T` and terminate array with `T(Abort)` or `T()`.

```c++
std::stringstream sd;
sd.str("abc0");
sd.exceptions(std::ios_base::badbit);
std::vector<uint8_t> a;
Format<TerminatedArray<Sc<uint8_t>, '0'>>::reader(sd).read(a);
assert(a == std::vector<uint8_t>({'a', 'b', 'c'}));
sd.str("");
a = std::vector<uint8_t>{'a', 'b', 'c'};
Format<TerminatedArray<Sc<uint8_t>, '0'>>::writer(sd).write(a);
assert(sd.str() == "abc0");
```

#### Fixed Array (`FixedArray<T>`, `Fa<T>`)

Read and write array (`std::vector<T>`), length provided manually as second argument to `read` call.
**This only works for top-level items. A fixed array in a nested element (like a `Structure`) is
not supported like that.**

```c++
std::stringstream sd{};
sd.str("1234567890");
sd.exceptions(std::ios_base::badbit);
std::vector<char> d;
Format<FixedArray<Sc<char>, void>>::reader(sd).read(d, 10u);
assert(memcmp(d.data(), "1234567890", 10) == 0);
```

#### Static Array (`StaticArray<T, int Count>`, `Sa<T, int Count>`)

An `std::array<T, int>` with a length known at compile-time. As top-level item, can also read/write a raw pointer.

```c++
std::stringstream sd{};
sd.str("123456789012345678901234567890");
sd.exceptions(std::ios_base::badbit);
std::array<char, 10> d0{};
char d1[10];
format::Format<StaticArray<Sc<char>, 10>, StaticArray<Sc<char>, 10>>::reader(sd).read(d0).read(d1);
assert(memcmp(d0.data(), "1234567890", 10) == 0);
assert(memcmp(d1, "1234567890", 10) == 0);
```

#### PrefixedArray (`PrefixedArray<P, T>`, `Pa<P, T>`)

Read array of `T` (`std::vector<T>`). Length of array is first read as type `P`.

```c++
std::stringstream sd{};
sd.str("1abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc");
sd.exceptions(std::ios_base::badbit);
struct test {
    char a;
    char b;
    char c;
    test() = default;
    test(char i, char j, char k) : a(i), b(j), c(k) {}
};
std::vector<test> d0{};
Format<PrefixedArray<Sc<uint8_t>, Structure<test, Sc<char>, Sc<char>, Sc<char>>>>::reader(sd).read(d0);
assert(d0.size() == 49);
for (auto i = 0u; i < 49u; ++i) {
    assert(d0[i].a == 'a');
    assert(d0[i].b == 'b');
    assert(d0[i].c == 'c');
}
```

#### Variables (`Copy<int ID, T>`, `Ref<int ID, T>`, `Get<int ID>`)

`Copy` acts like `T` but stores an internal copy referenced by `ID`.
`Ref` acts like `T` but stores a reference to the variable as `ID`.

`Get` uses `T` from the `Copy` or `Ref` with the same `ID` to read/write data.
If the value `Get` reads differs from the value stored in `ID` a `get_mismatch` is thrown.
Its main use, however, is as the second argument to `FixedArray`. With this,
the length of an array can be read from the input stream. Of course, if the array length is
stored right before the array, you can use `PrefixedArray` instead.

```c++
Format<...
       ...
       Copy<0, Sc<uint8_t>>,
       ...
       FixedArray<..., Get<0>>,
       ...>;
```

*There is also `Set<int ID, T>` which acts like `T` but **only** stores an internal copy. You can use this
to read an input stream, but writing a `Format` with `Set`-Variables is more difficult because you
have to provide the length of the array before actually supplying the array reference. I recommend not using
it.*

#### String Specializations

The following types return `std::string`:

- `PrefixedArray<Prefix, char>` = `PrefixedString<Prefix>` (`Ps<Prefix>`)
- `StaticArray<char, Len>` = `StaticString<Len>` (`Ss<Len>`)
- `FixedArray<char>` = `FixedString` (`Fs`)
- `FixedArray<char, L>` = `FixedString<L>` (`Fs<L>`)
- `TerminatedArray<char>` = `TerminatedString` (`Ts`)

#### Conditionals (`Conditional<Cmp, T, F>`, `Cd<Cmp, T, F>`)

First read `Cmp` (usually a `Get` or `Call`-Instruction). If `Cmp` evaluates to `true`, read/write `T`.
Otherwise read/write `F`.

If `T` and `F` return the same type, the conditional returns that type.
If they are not, the conditional returns an `std::variant` of the types.
If `F` is omitted, the conditional returns an `std::optional`.

```c++
std::stringstream sd{};
sd.str("abd");
struct Num {
    uint8_t a;
    Num() = default;
    explicit Num(uint8_t i) : a(i) {}
    operator bool() {
        return a == 'a';
    }
};
Num n;
std::variant<uint8_t, std::string> v;
using F = Format<Copy<0, St<Num, O<offsetof(Num, a), Sc<uint8_t>>>>,
                 Conditional<Get<0>, Sc<uint8_t>, StaticString<2>>>;
F::reader(sd).read(n).read(v);
assert(n == true);
assert(std::holds_alternative<uint8_t>(v));
assert(std::get<uint8_t>(v) == 'b');
sd.str("");
F::writer(sd).write(n).write(v);
assert(sd.str() == "ab");
```

##### Variables

- Variables will be `std::optional` if they are only declared in one of the branches.
- If they are declared in both branches with the same type, their type remains the same.
- If they are declared in both branches with different types, their type becomes `std::variant`.

#### Switch (`Switch<Cmp, Case<Constant<C>, T>, Case<Constant<C2>, T2>, ...>`)

First read `Cmp`.
Then find a matching case-statement by matching against a constant (like `Constant<std::integral_constant<int, 0>>`).
Evaluate `T` of the first matching case-argument.

Like `Conditional`-Instructions, variables inside branches and the return type can be 
the type itself, `std::optional`, `std::variant`, or `std::optional<std::variant<...>>` depending on
the cases.

#### Call (`Call<Fun, T>`)

Read-only operation.
Read `T`, return `Fun(T)`.

```c++
std::stringstream sd;
sd.str("ab");
int x;
using Format = format::Format<Call<&double_value, Sc<uint8_t>>>;
Format::reader(sd).read(x);
assert(x == 'a' * 2);
sd.str("");
Format::writer(sd).write();
assert(sd.str().empty());
```

#### Map (`Map<RFun, WFun, T>`)

Read `T`, return `RFun(T)`.
Write `WFun(return-type-of-RFun)`.

```c++
std::stringstream sd;
sd.str("a");
int x;
using Format = format::Format<Map<&double_value, &half_value, Sc<uint8_t>>>;
Format::reader(sd).read(x);
assert(x == 'a' * 2);
sd.str("");
Format::writer(sd).write(x);
assert(sd.str() == "a");
```

#### License

This library is released under the terms of the `LGPL v3` (GNU Lesser General Public License Version 3 or later).
