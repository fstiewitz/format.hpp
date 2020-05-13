/*
 * Copyright 2020 Fabian Stiewitz <fabian@stiewitz.pw>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <iostream>
#include <cassert>
#include <cstring>
#include <sstream>

#include <format.hpp>

using namespace format;

#define TEST(x) fprintf(stderr, "Test %2i: %s\n", tc++, x)

static auto double_value(const unsigned char &i) {
    return 2 * i;
}

static auto half_value(const unsigned char &i) {
    return i / 2;
}

struct TestS {
    uint8_t a;
    uint8_t b;
    uint8_t c;

    TestS() = default;

    TestS(uint8_t i, uint8_t j, uint8_t k) : a(i), b(j), c(k) {}

    bool operator==(const TestS &rhs) const {
        return a == rhs.a &&
               b == rhs.b &&
               c == rhs.c;
    }

    bool operator!=(const TestS &rhs) const {
        return !(rhs == *this);
    }
};

struct TestSerialize {
    template<typename S> using Base = CustomStructure<S, TestS, Sc<uint8_t>, Sc<uint8_t>, Sc<uint8_t>>;
    template<template<typename, typename...> typename P, typename OP, typename ...A> using Process = default_process<P, OP, A..., Sc<uint8_t>, Sc<uint8_t>, Sc<uint8_t>>;

    template<typename Stack>
    struct Interface : public Base<Stack> {
        explicit Interface(stream_type_t<Stack> &processor, Stack &stack) : Base<Stack>(processor, stack) {}

        template<typename S1=Stack, std::enable_if_t<!S1::IsReadStack, int> = 0>
        void write(const TestS &out) {
            Base<Stack>::make_writer().write(out.a).write(out.b).write(out.c);
        }

        template<typename S1=Stack, std::enable_if_t<S1::IsReadStack, int> = 0>
        void read(TestS &in) {
            Base<Stack>::Helper::read_into(in, Base<Stack>::processor, Base<Stack>::stack);
        }
    };
};

template<typename T>
struct Cnt {
    using Type = T;
};

template<template<typename, typename> typename Test, typename T, typename A = void, typename ...Args>
struct assert_all_with {
    static constexpr bool value = Test<T, A>::value && assert_all_with<Test, T, Args...>::value;
};

template<template<typename, typename> typename Test, typename T>
struct assert_all_with<Test, T, void> {
    static constexpr bool value = true;
};

template<template<typename, typename> typename Test, typename T = void, typename ...Args>
struct assert_all {
    static constexpr bool value = assert_all_with<Test, T, Args...>::value && assert_all<Test, Args...>::value;
};

template<template<typename, typename> typename Test>
struct assert_all<Test, void> {
    static constexpr bool value = true;
};

int main() {
    int tc = 1;
    TEST("is_promoted_cast");
    {
        static_assert(
                assert_all<is_promoted_cast, bool, char, int8_t, short, int16_t, int, int32_t, long, long long, float, double>::value);
        static_assert(
                assert_all<is_promoted_cast, unsigned char, uint8_t, unsigned short, uint16_t, unsigned int, uint32_t, unsigned long, unsigned long long, float, double>::value);
    }
    TEST("unpack_globals");
    {
        static_assert(
                std::is_same_v<unpack_globals<InternalStack<true, void, void>, Set<0, St<TestS, Copy<1, Sc<uint8_t>>>>, Copy<2, Sc<uint8_t>>>::Stack,
                        InternalStack<true, InternalVariable<2, unsigned char, Scalar<unsigned char>, false>, InternalStack<true, InternalVariable<0, TestS, Structure<TestS, Variable<1, Scalar<unsigned char>, false> >, false>, InternalStack<true, InternalVariable<1, unsigned char, Scalar<unsigned char>, false>, InternalStack<true, void, void>>>>>);

    }
    TEST("get_type");
    {
        static_assert(
                std::is_same_v<get_type<std::integral_constant<int, 0>, Set<0, St<TestS, Copy<1, Sc<uint8_t>>>>, Copy<2, Sc<uint8_t>>>::VariableType, St<TestS, Copy<1, Sc<uint8_t>>>>);
        static_assert(
                std::is_same_v<get_type<std::integral_constant<int, 1>, Set<0, St<TestS, Copy<1, Sc<uint8_t>>>>, Copy<2, Sc<uint8_t>>>::VariableType, Sc<uint8_t>>);
        static_assert(
                std::is_same_v<get_type<std::integral_constant<int, 2>, Set<0, St<TestS, Copy<1, Sc<uint8_t>>>>, Copy<2, Sc<uint8_t>>>::VariableType, Sc<uint8_t>>);
    }
    TEST("has_next_external");
    {
        static_assert(
                has_next_external<InternalStack<true, void, void>, Set<0, St<TestS, Copy<1, Sc<uint8_t>>>>, Copy<2, Sc<uint8_t>>>::Value::value);
        static_assert(has_next_external<InternalStack<true, void, void>, Copy<2, Sc<uint8_t>>>::Value::value);
        static_assert(!has_next_external<InternalStack<true, void, void>, void>::Value::value);
        static_assert(!has_next_external<InternalStack<true, void, void>, Set<2, Sc<uint8_t>>>::Value::value);
    }
    TEST("unpack_types");
    {
        static_assert(
                std::is_same_v<unpack_types<InternalStack<true, void, void>, Copy<0, St<TestS, Copy<1, Sc<uint8_t>>>>, Copy<2, Sc<uint8_t>>>::type, std::tuple<TestS, uint8_t>>);
    }
    TEST("optional_variant_variables");
    {
        using T1 = St<TestS, Copy<1, Sc<uint8_t>>>;
        using T2 = St<TestS, Copy<0, Sc<uint8_t>>>;
        using T3 = St<TestS, Copy<1, Sc<uint16_t>>>;
        using T4 = St<TestS, Copy<1, Sc<uint32_t>>>;
        using Stack1 = typename unpack_globals<InternalStack<true, void, void>, T1>::Stack;
        using Stack2 = typename unpack_globals<InternalStack<true, void, void>, T2>::Stack;
        using Stack3 = typename unpack_globals<InternalStack<true, void, void>, T3>::Stack;
        using Stack4 = typename unpack_globals<InternalStack<true, void, void>, T4>::Stack;

        using O12 = typename optional_variant_variables<Stack1, Stack2>::Stack;
        using O21 = typename optional_variant_variables<Stack2, Stack1>::Stack;

        using O121 = typename optional_variant_variables<O12, Stack1>::Stack;
        using O112 = typename optional_variant_variables<Stack1, O12>::Stack;

        using O11 = typename optional_variant_variables<Stack1, Stack1>::Stack;
        using O13 = typename optional_variant_variables<Stack1, Stack3>::Stack;
        using O31 = typename optional_variant_variables<Stack3, Stack1>::Stack;
        using O1212 = typename optional_variant_variables<O12, O12>::Stack;
        using O1211 = typename optional_variant_variables<O12, O11>::Stack;
        using O1231 = typename optional_variant_variables<O12, O31>::Stack;
        using O3112 = typename optional_variant_variables<O31, O12>::Stack;
        using O12311231 = typename optional_variant_variables<O1231, O1231>::Stack;
        using V2 = InternalStack<true, InternalVariable<1, std::variant<short, unsigned char>, variant<Sc<short>, Sc<unsigned char>>, false, true>, InternalStack<true, void, void>>;
        using V4 = InternalStack<true, InternalVariable<1, std::optional<int>, Sc<int>, true, false>, InternalStack<true, void, void>>;
        using OV2V4 = typename optional_variant_variables<V2, V4>::Stack;
        using OV4V2 = typename optional_variant_variables<V4, V2>::Stack;
        using O1231V2 = typename optional_variant_variables<O1231, V2>::Stack;
        using O123112314 = typename optional_variant_variables<O12311231, Stack4>::Stack;
        using O412311231 = typename optional_variant_variables<Stack4, O12311231>::Stack;


        // S S -> O
        static_assert(
                std::is_same_v<O12, InternalStack<true, InternalVariable<1, std::optional<unsigned char>, Scalar<unsigned char>, true>, InternalStack<true, void, void>>>);
        // S S -> O
        static_assert(
                std::is_same_v<O21, InternalStack<true, InternalVariable<0, std::optional<unsigned char>, Scalar<unsigned char>, true>, InternalStack<true, void, void>>>);

        // S O -> O
        static_assert(
                std::is_same_v<O121, InternalStack<true, InternalVariable<1, std::optional<unsigned char>, Scalar<unsigned char>, true>, InternalStack<true, void, void>>>);
        // S O -> O
        static_assert(
                std::is_same_v<O112, InternalStack<true, InternalVariable<1, std::optional<unsigned char>, Scalar<unsigned char>, true>, InternalStack<true, void, void>>>);

        // S S -> V
        static_assert(
                std::is_same_v<O31, InternalStack<true, InternalVariable<1, std::variant<unsigned short, unsigned char>, variant<Sc<unsigned short>, Sc<unsigned char>>, false, true>, InternalStack<true, void, void>>>);
        // S S -> V
        static_assert(
                std::is_same_v<O13, InternalStack<true, InternalVariable<1, std::variant<unsigned char, unsigned short>, variant<Sc<unsigned char>, Sc<unsigned short>>, false, true>, InternalStack<true, void, void>>>);

        // S S -> S
        static_assert(
                std::is_same_v<O11, InternalStack<true, InternalVariable<1, unsigned char, Scalar<unsigned char>, false>, InternalStack<true, void, void>>>);

        // O O -> O
        static_assert(
                std::is_same_v<O1212, InternalStack<true, InternalVariable<1, std::optional<unsigned char>, Scalar<unsigned char>, true>, InternalStack<true, void, void>>>);
        // O O -> O
        static_assert(
                std::is_same_v<O1211, InternalStack<true, InternalVariable<1, std::optional<unsigned char>, Scalar<unsigned char>, true>, InternalStack<true, void, void>>>);

        // O V -> V (same)
        static_assert(
                std::is_same_v<O1231, InternalStack<true, InternalVariable<1, std::variant<unsigned short, unsigned char>, variant<Sc<unsigned short>, Sc<unsigned char>>, false, true>, InternalStack<true, void, void>>>);
        // O V -> V (same)
        static_assert(
                std::is_same_v<O3112, InternalStack<true, InternalVariable<1, std::variant<unsigned short, unsigned char>, variant<Sc<unsigned short>, Sc<unsigned char>>, false, true>, InternalStack<true, void, void>>>);
        // O V -> V (different)
        static_assert(
                std::is_same_v<OV4V2, InternalStack<true, InternalVariable<1, std::variant<short, unsigned char, int>, variant<Sc<short>, Sc<unsigned char>, Sc<int>>, false, true>, InternalStack<true, void, void>>>);
        // O V -> V (different)
        static_assert(
                std::is_same_v<OV2V4, InternalStack<true, InternalVariable<1, std::variant<short, unsigned char, int>, variant<Sc<short>, Sc<unsigned char>, Sc<int>>, false, true>, InternalStack<true, void, void>>>);

        // V S -> V
        static_assert(
                std::is_same_v<O123112314, InternalStack<true, InternalVariable<1, std::variant<unsigned short, unsigned char, unsigned int>, variant<Sc<unsigned short>, Sc<unsigned char>, Sc<unsigned int>>, false, true>, InternalStack<true, void, void>>>);
        // S V -> V
        static_assert(
                std::is_same_v<O412311231, InternalStack<true, InternalVariable<1, std::variant<unsigned short, unsigned char, unsigned int>, variant<Sc<unsigned short>, Sc<unsigned char>, Sc<unsigned int>>, false, true>, InternalStack<true, void, void>>>);
        // V V -> V (same)
        static_assert(
                std::is_same_v<O12311231, InternalStack<true, InternalVariable<1, std::variant<unsigned short, unsigned char>, variant<Sc<unsigned short>, Sc<unsigned char>>, false, true>, InternalStack<true, void, void>>>);
        // V V -> V (partial)
        static_assert(
                std::is_same_v<O1231V2, InternalStack<true, InternalVariable<1, std::variant<unsigned short, unsigned char, short>, variant<Sc<unsigned short>, Sc<unsigned char>, Sc<short>>, false, true>, InternalStack<true, void, void>>>);
    }
    TEST("merge_stacks");
    {
        using T1 = unpack_globals<InternalStack<true, void, void>, St<TestS, Copy<1, Sc<uint8_t>>>>::Stack;
        using T2 = unpack_globals<InternalStack<true, void, void>, St<TestS, Copy<0, Sc<uint8_t>>>>::Stack;
        static_assert(
                std::is_same_v<merge_stacks<T1, T2>::Stack, InternalStack<true, InternalVariable<1, unsigned char, Scalar<unsigned char>, false>, InternalStack<true, InternalVariable<0, unsigned char, Scalar<unsigned char>, false>, InternalStack<true, void, void> > >>);
    }
    TEST("permutate_first_with_all");
    {
        static_assert(std::is_same_v<permutate_first_with_all<tuple, tuple<>, 0,
                std::integral_constant<int, 0>,
                std::integral_constant<int, 1>,
                std::integral_constant<int, 2>,
                std::integral_constant<int, 3>>::Type,
                tuple<
                        tuple<
                                std::integral_constant<int, 0>,
                                std::integral_constant<int, 0>,
                                std::integral_constant<int, 1>,
                                std::integral_constant<int, 2>,
                                std::integral_constant<int, 3>>,
                        tuple<
                                std::integral_constant<int, 1>,
                                std::integral_constant<int, 0>,
                                std::integral_constant<int, 1>,
                                std::integral_constant<int, 2>,
                                std::integral_constant<int, 3>>,
                        tuple<
                                std::integral_constant<int, 2>,
                                std::integral_constant<int, 0>,
                                std::integral_constant<int, 1>,
                                std::integral_constant<int, 2>,
                                std::integral_constant<int, 3>>,
                        tuple<
                                std::integral_constant<int, 3>,
                                std::integral_constant<int, 0>,
                                std::integral_constant<int, 1>,
                                std::integral_constant<int, 2>,
                                std::integral_constant<int, 3>>>>);
    }
    TEST("Packed");
    {
#include "packed-test.cpp"
    }
    TEST("Series of Singles");
    {
        std::stringstream sd{};
        sd.str("abc");
        sd.exceptions(std::ios_base::badbit);
        using Format = format::Format<Sc<uint8_t>, Sc<uint8_t>, Sc<uint8_t>, Sc<uint32_t>>;
        Format::Type<0> a = 0;
        Format::Type<1> b = 0;
        Format::Type<2> c = 0;
        static_assert(std::is_same_v<Format::Type<0>, uint8_t>);
        static_assert(std::is_same_v<Format::Type<1>, uint8_t>);
        static_assert(std::is_same_v<Format::Type<2>, uint8_t>);
        static_assert(std::is_same_v<Format::Type<3>, uint32_t>);
        auto t = Format::reader(sd)
                .read(a).read(b).read(c);
        assert(a == 'a');
        assert(b == 'b');
        assert(c == 'c');
        try {
            uint32_t d = 0;
            t.read(d);
            fprintf(stderr, "expected failure to be thrown\n");
            exit(1);
        } catch (binary_eof &) {
            sd.clear();
        }

        sd.str("");
        format::Format<Sc<uint8_t>, Sc<uint8_t>, Sc<uint8_t>>::writer(sd).write(a).write(b).write(c);
        assert(sd.str() == "abc");
    }
    TEST("Series of Singles (own stream)");
    {
        std::stringstream sd{};
        sd.str("abc");
        sd.exceptions(std::ios_base::badbit);
        uint8_t a = 0;
        uint8_t b = 0;
        uint8_t c = 0;
        auto t = format::Format<Sc<uint8_t>, Sc<uint8_t>, Sc<uint8_t>, Sc<uint32_t>>::reader(std::move(sd))
                .read(a).read(b).read(c);
        assert(a == 'a');
        assert(b == 'b');
        assert(c == 'c');
        try {
            uint32_t d = 0;
            t.read(d);
            fprintf(stderr, "expected failure to be thrown\n");
            exit(1);
        } catch (binary_eof &) {
            sd.clear();
        }

        format::Format<Sc<uint8_t>, Sc<uint8_t>, Sc<uint8_t>>::writer(sd).write(a).write(b).write(c);
        assert(sd.str() == "abc");
    }
    TEST("Single Structure");
    {
        std::stringstream sd{};
        sd.str("abc");
        sd.exceptions(std::ios_base::badbit);
        struct Test {
            uint8_t a;
            uint8_t b;
            uint8_t c;

            Test(uint8_t i, uint8_t j, uint8_t k) : a(i), b(j), c(k) {}
        } t{0, 0, 0};
        using Format = format::Format<St<Test, Sc<uint8_t>, Sc<uint8_t>, Sc<uint8_t>>>;
        Format::reader(sd).read(t);
        static_assert(std::is_same_v<Format::Type<0>, Test>);
        assert(t.a == 'a');
        assert(t.b == 'b');
        assert(t.c == 'c');
    }
    TEST("Bitfields");
    {
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
    }
    TEST("Writing Single Structure: Callback");
    {
        std::stringstream sd{};
        struct Test {
            uint8_t a;
            uint8_t b;
            uint8_t c;
        } t{'a', 'b', 'c'};
        format::Format<St<Test, Sc<uint8_t>, Sc<uint8_t>, Sc<uint8_t>>>::writer(sd).write([&t](auto r) {
            r.write(t.a).write(t.b).write(t.c);
        });
        assert(sd.str() == "abc");
    }
    TEST("Writing Single Structure: Offsets");
    {
        std::stringstream sd{};
        struct Test {
            uint8_t a;
            uint8_t b;
            uint8_t c;
        } t{'a', 'b', 'c'};
        format::Format<St<Test, O<offsetof(Test, a), Sc<uint8_t>>, O<offsetof(Test, b), Sc<uint8_t>>, O<offsetof(Test,
                                                                                                                 c), Sc<uint8_t>>>>::writer(
                sd).write(t);
        assert(sd.str() == "abc");
    }
    TEST("Writing Single Structure: Accessor");
    {
        std::stringstream sd{};
        struct Test {
            uint8_t a;
            uint8_t b;
            uint8_t c;

            auto &getA() const { return a; }

            auto &getB() const { return b; }

            auto &getC() const { return c; }
        } t{'a', 'b', 'c'};
        format::Format<St<Test,
                Acc<&Test::getA, Sc<uint8_t>>,
                Acc<&Test::getB, Sc<uint8_t>>,
                Acc<&Test::getC, Sc<uint8_t>>>>::writer(
                sd).write(t);
        assert(sd.str() == "abc");
    }
    TEST("Single Structure with ReadOnly component");
    {
        std::stringstream sd{};
        struct Test {
            uint8_t a;
            uint8_t b;
            uint8_t c;

            Test() = default;
            Test(uint8_t i, uint8_t j, uint8_t k) : a(i), b(j), c(k) {}
            auto &getA() const { return a; }
            auto &getB() const { return b; }
        } t{'a', 'b', 'c'};
        using F = format::Format<St<Test,
                Acc<&Test::getA, Sc<uint8_t>>,
                Acc<&Test::getB, Sc<uint8_t>>,
                Internal<Sc<uint8_t>, false, true>>>;
        sd.str("abc");
        F::reader(sd).read(t);
        assert(t.a == 'a');
        assert(t.b == 'b');
        assert(t.c == 'c');
        sd.clear();
        sd.str("");
        F::writer(sd).write(t);
        assert(sd.str() == "ab");
    }
    TEST("Writing Single Structure: Custom Class");
    {
        std::stringstream sd{};
        TestS t{'a', 'b', 'c'};
        format::Format<TestSerialize>::writer(sd).write(t);
        assert(sd.str() == "abc");
    }
    TEST("Nested Structure");
    {
        std::stringstream sd{};
        sd.str("abc");
        sd.exceptions(std::ios_base::badbit);
        struct Test0 {
            uint8_t d;
            uint8_t e;

            [[maybe_unused]] Test0() = default;

            Test0(uint8_t a, uint8_t b) : d(a), e(b) {}
        };
        struct Test {
            uint8_t a;
            Test0 t;

            [[maybe_unused]] Test() = default;

            Test(uint8_t i, Test0 j) : a(i), t(j) {}
        } t{0, Test0{0, 0}};
        format::Format<Structure<Test,
                Sc<uint8_t>,
                Structure<Test0,
                        Sc<uint8_t>,
                        Sc<uint8_t>
                >
        >
        >::reader(sd).read(t);
        assert(t.a == 'a');
        assert(t.t.d == 'b');
        assert(t.t.e == 'c');
    }
    TEST("Nested Structure with Offsets");
    {
        std::stringstream sd{};
        struct Test0 {
            uint8_t d;
            uint8_t e;

            [[maybe_unused]] Test0() = default;

            Test0(uint8_t a, uint8_t b) : d(a), e(b) {}
        };
        struct Test {
            uint8_t a;
            Test0 t;

            [[maybe_unused]] Test() = default;

            Test(uint8_t i, Test0 j) : a(i), t(j) {}
        } t{'a', Test0{'b', 'c'}};
        format::Format<Structure<Test,
                O<offsetof(Test, a), Sc<uint8_t>>,
                O<offsetof(Test, t), Structure<
                        Test0,
                        O<offsetof(Test0, d), Sc<uint8_t>>,
                        O<offsetof(Test0, e), Sc<uint8_t>>>
                >
        >>::writer(sd).write(t);
        assert(sd.str() == "abc");
    }
    TEST("Lines");
    {
        std::stringstream sd{};
        sd.str("Hello, World\nFoo Bar\nAbc");
        sd.exceptions(std::ios_base::badbit);
        std::string a;
        std::string b;
        std::string c;
        format::Format<TerminatedString, TerminatedString, TerminatedString>::reader(sd)
                .read(a, '\n').read(b, '\n').read(c, '\n');
        assert(a == "Hello, World");
        assert(b == "Foo Bar");
        assert(c == "Abc");
    }
    TEST("Custom Terminator");
    {
        std::stringstream sd{};
        sd.str("Hello,abc=def\n");
        sd.exceptions(std::ios_base::badbit);
        std::string a;
        std::string b;
        std::string c;
        format::Format<TerminatedString, TerminatedString, TerminatedString>::reader(sd)
                .read(a, ",=", BreakSet).read(b, ",=", BreakSet).read(c, ",=", BreakSet);
        assert(a == "Hello");
        assert(b == "abc");
        assert(c == "def\n");
    }
    TEST("Terminated Array");
    {
        std::stringstream sd;
        sd.str("abc0");
        sd.exceptions(std::ios_base::badbit);
        std::vector<uint8_t> a;
        format::Format<TerminatedArray<Sc<uint8_t>, '0'>>::reader(sd).read(a);
        assert(a == std::vector<uint8_t>({'a', 'b', 'c'}));

        sd.str("");
        a = std::vector<uint8_t>{'a', 'b', 'c'};
        format::Format<TerminatedArray<Sc<uint8_t>, '0'>>::writer(sd).write(a);
        assert(sd.str() == "abc0");
    }
    TEST("Terminated Array with custom abort");
    {
        std::stringstream sd;
        sd.str("abc0");
        sd.exceptions(std::ios_base::badbit);
        std::vector<uint8_t> a;
        format::Format<TerminatedArray<Sc<uint8_t>>>::reader(sd).read(a, static_cast<unsigned char>('0'));
        assert(a == std::vector<uint8_t>({'a', 'b', 'c'}));
    }
    TEST("Terminated Array with abort function");
    {
        std::stringstream sd;
        sd.str("abc0");
        sd.exceptions(std::ios_base::badbit);
        std::vector<uint8_t> a;
        format::Format<TerminatedArray<Sc<uint8_t>>>::reader(sd).read(a, [](const auto &c) { return !isdigit(c); });
        assert(a == std::vector<uint8_t>({'a', 'b', 'c'}));
    }
    TEST("Terminated Array with complex abort function");
    {
        std::stringstream sd;
        sd.str("abc0");
        sd.exceptions(std::ios_base::badbit);
        std::vector<uint8_t> a;
        format::Format<TerminatedArray<Sc<uint8_t>>>::reader(sd).read(a, [](const auto &c) -> ArrayTerminationMode {
            if (isdigit(c)) return BREAKAFTER;
            return VALID;
        });
        assert(a == std::vector<uint8_t>({'a', 'b', 'c', '0'}));
    }
    TEST("Terminated Array with prefix");
    {
        std::stringstream sd;
        sd.str("10101c0d");
        sd.exceptions(std::ios_base::badbit);
        std::vector<uint8_t> a;
        format::Format<Pt<Sc<uint8_t>, Sc<uint8_t>, '0', '1'>>::reader(sd).read(a);
        assert(a == std::vector<uint8_t>({'0', '0', 'c'}));
        sd.str("");
        format::Format<Pt<Sc<uint8_t>, Sc<uint8_t>, '0', '1'>>::writer(sd).write(a);
        assert(sd.str() == "10101c0");
    }
    TEST("Terminated Array with abort function and prefix");
    {
        std::stringstream sd;
        sd.str("10101c0");
        sd.exceptions(std::ios_base::badbit);
        std::vector<uint8_t> a;
        format::Format<PrefixedTerminatedArray<Sc<uint8_t>, Sc<uint8_t>, '0'>>::reader(sd).read(a, [](const auto &c) {
            return c == '1';
        });
        assert(a == std::vector<uint8_t>({'0', '0', 'c'}));
    }
    TEST("Terminated Array with complex abort function and prefix");
    {
        std::stringstream sd;
        sd.str("10102c");
        sd.exceptions(std::ios_base::badbit);
        std::vector<uint8_t> a;
        format::Format<PrefixedTerminatedArray<Sc<uint8_t>, Sc<uint8_t>, '0'>>::reader(sd).read(a,
                                                                                                [](const auto &c) -> ArrayTerminationMode {
                                                                                                    if (c == '2')
                                                                                                        return BREAKAFTER;
                                                                                                    return VALID;
                                                                                                });
        assert(a == std::vector<uint8_t>({'0', '0', 'c'}));
    }
    TEST("Strings with null-characters");
    {
        std::stringstream sd;
        sd.str(std::string("Hello\0World\nFoo", 15));
        sd.exceptions(std::ios_base::badbit);
        std::string a;
        std::string b;
        format::Format<TerminatedString, TerminatedString>::reader(sd)
                .read(a, '\n').read(b, '\0');
        assert(a == std::string("Hello\0World", 11));
        assert(b == "Foo");
    }
    TEST("Fixed Array");
    {
        std::stringstream sd{};
        sd.str("123456789012345678901234567890");
        sd.exceptions(std::ios_base::badbit);
        std::vector<char> d0;
        std::vector<char> d1;
        std::vector<char> d2;
        format::Format<FixedArray<Sc<char>, void>, FixedArray<Sc<char>, void>, FixedArray<Sc<char>, void>>::reader(
                sd).read(d0, 10u).read(
                d1, 10u).read(d2, 10u);
        assert(memcmp(d0.data(), "1234567890", 10) == 0);
        assert(memcmp(d1.data(), "1234567890", 10) == 0);
        assert(memcmp(d2.data(), "1234567890", 10) == 0);

        sd.str("");
        format::Format<Fa<Sc<char>, void>>::writer(sd).write(d1);
        assert(sd.str() == "1234567890");
    }
    TEST("Static Array");
    {
        std::stringstream sd{};
        sd.str("123456789012345678901234567890");
        sd.exceptions(std::ios_base::badbit);
        std::array<char, 10> d0{};
        char d1[10];
        format::Format<StaticArray<Sc<char>, 10>, StaticArray<Sc<char>, 10>>::reader(sd).read(d0).read(d1);
        assert(memcmp(d0.data(), "1234567890", 10) == 0);
        assert(memcmp(d1, "1234567890", 10) == 0);

        sd.str("");
        format::Format<Sa<Sc<char>, 10>>::writer(sd).write(d0);
        assert(sd.str() == "1234567890");
    }
    TEST("Static Array with Structure");
    {
        std::stringstream sd{};
        sd.str("123456789012345678901234567890");
        sd.exceptions(std::ios_base::badbit);
        struct test {
            char a;
            char b;

            [[maybe_unused]] test() = default;

            test(char i, char j) : a(i), b(j) {}
        };
        std::array<test, 5> d0{};
        format::Format<StaticArray<Structure<test, Sc<char>, Sc<char>>, 5>>::reader(sd).read(d0);
        for (int i = 0; i < 5; ++i) {
            assert(d0[static_cast<unsigned>(i)].a == '1' + 2 * i);
            if (i != 4) assert(d0[static_cast<unsigned>(i)].b == '2' + 2 * i);
            else
                assert(d0[static_cast<unsigned>(i)].b == '0');
        }
    }
    TEST("Prefixed Array with Structure");
    {
        std::stringstream sd{};
        sd.str("1abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc");
        sd.exceptions(std::ios_base::badbit);
        struct test {
            char a;
            char b;
            char c;

            [[maybe_unused]] test() = default;

            test(char i, char j, char k) : a(i), b(j), c(k) {}
        };
        std::vector<test> d0{};
        format::Format<PrefixedArray<Sc<uint8_t>, Structure<test, Sc<char>, Sc<char>, Sc<char>>>>::reader(sd).read(d0);
        assert(d0.size() == 49);
        for (auto i = 0u; i < 49u; ++i) {
            assert(d0[i].a == 'a');
            assert(d0[i].b == 'b');
            assert(d0[i].c == 'c');
        }

        sd.str("");
        format::Format<PrefixedArray<Sc<uint8_t>, Structure<test,
                O<offsetof(test, a), Sc<char>>,
                O<offsetof(test, b), Sc<char>>,
                O<offsetof(test, c), Sc<char>>>>>::writer(sd).write(d0);
        assert(sd.str() ==
               "1abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc");
    }
    TEST("Prefixed Array with Structure and custom prefix");
    {
        std::stringstream sd{};
        sd.str("1abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc");
        sd.exceptions(std::ios_base::badbit);
        struct test {
            char a;
            char b;
            char c;

            [[maybe_unused]] test() = default;

            test(char i, char j, char k) : a(i), b(j), c(k) {}
        };
        struct prefix {
            uint8_t p;

            prefix() = default;

            explicit prefix(size_t t) : p(static_cast<uint8_t>(t)) {
                if (t > std::numeric_limits<uint8_t>::max())
                    throw std::range_error("range error");
            }

            explicit prefix(uint8_t pr) : p(pr) {}

            [[maybe_unused]] bool operator<(size_t u) const {
                return p < u;
            }

            explicit operator size_t() {
                if (p == 0) {
                    return 0;
                }
                return p - 1;
            }
        };
        std::vector<test> d0{};
        format::Format<PrefixedArray<St<prefix, Sc<uint8_t>>, Structure<test, Sc<char>, Sc<char>, Sc<char>>>>::reader(
                sd).read(d0);
        assert(d0.size() == 48);
        for (auto i = 0u; i < 48u; ++i) {
            assert(d0[i].a == 'a');
            assert(d0[i].b == 'b');
            assert(d0[i].c == 'c');
        }

        sd.str("");
        format::Format<PrefixedArray<St<prefix, O<offsetof(prefix, p), Sc<uint8_t>>>, Structure<test,
                O<offsetof(test, a), Sc<char>>,
                O<offsetof(test, b), Sc<char>>,
                O<offsetof(test, c), Sc<char>>>>>::writer(sd).write(d0);
        assert(sd.str() ==
               "0abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc");
    }
    TEST("StaticArray specialization for std::string");
    {
        std::stringstream sd;
        sd.str(std::string("Hello"));
        sd.exceptions(std::ios_base::badbit);
        std::string a;
        format::Format<StaticString<5>>::reader(sd)
                .read(a);
        assert(a == "Hello");

        sd.str("");
        format::Format<StaticString<5>>::writer(sd).write(a);
        assert(sd.str() == "Hello");
    }
    TEST("FixedArray specialization for std::string");
    {
        std::stringstream sd;
        sd.str(std::string("Hello"));
        sd.exceptions(std::ios_base::badbit);
        std::string a;
        format::Format<FixedString<>>::reader(sd)
                .read(a, 5);
        assert(a == "Hello");

        sd.str("");
        format::Format<FixedString<>>::writer(sd).write(a);
        assert(sd.str() == "Hello");
    }
    TEST("PrefixedArray specialization for std::string");
    {
        std::stringstream sd;
        sd.str(std::string("1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
        sd.exceptions(std::ios_base::badbit);
        std::string a;
        format::Format<PrefixedString<Sc<uint8_t>>>::reader(sd).read(a);
        assert(a == "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

        sd.str("");
        format::Format<PrefixedString<Sc<uint8_t>>>::writer(sd).write(a);
        assert(sd.str() == "1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    }
    TEST("Variables");
    {
        std::stringstream sd;
        sd.str(std::string("1231aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa123"));
        sd.exceptions(std::ios_base::badbit);
        struct Test {
            uint8_t a;

            Test() : a(0) {}

            explicit Test(uint8_t i) : a(i) {}
        };
        int8_t v0;
        int8_t v1;
        int8_t v2;
        int8_t v3;
        int8_t v4;
        int8_t v5;
        std::string a;
        Test t;
        using Format =
        format::Format<Copy<0, Sc<int8_t>>,
                Ref<4, Sc<int8_t>>,
                Ref<5, Sc<int8_t>>,
                Structure<Test, O<offsetof(Test, a), Copy<7, Sc<uint8_t>>>>,
                Copy<10, StaticArray<char, 49>>,
                Ref<1, Sc<int8_t>>,
                Copy<2, Sc<int8_t>>,
                Copy<3, Sc<int8_t>>>;
        static_assert(std::is_same_v<Format::Type<0>, int8_t>);
        static_assert(std::is_same_v<Format::Type<1>, int8_t>);
        static_assert(std::is_same_v<Format::Type<2>, int8_t>);
        static_assert(std::is_same_v<Format::Type<3>, Test>);
        static_assert(std::is_same_v<Format::Type<4>, std::string>);
        static_assert(std::is_same_v<Format::Type<5>, int8_t>);
        static_assert(std::is_same_v<Format::Type<6>, int8_t>);
        static_assert(std::is_same_v<Format::Type<7>, int8_t>);
        static_assert(std::is_same_v<decltype(std::declval<Format::ReadStack>().get<0>().val), int8_t>);
        static_assert(
                std::is_same_v<decltype(std::declval<Format::ReadStack>().get<4>().val), std::optional<std::reference_wrapper<const int8_t>>>);
        static_assert(
                std::is_same_v<decltype(std::declval<Format::ReadStack>().get<5>().val), std::optional<std::reference_wrapper<const int8_t>>>);
        static_assert(std::is_same_v<decltype(std::declval<Format::ReadStack>().get<7>().val), uint8_t>);
        static_assert(std::is_same_v<decltype(std::declval<Format::ReadStack>().get<10>().val), std::string>);
        static_assert(
                std::is_same_v<decltype(std::declval<Format::ReadStack>().get<1>().val), std::optional<std::reference_wrapper<const int8_t>>>);
        static_assert(std::is_same_v<decltype(std::declval<Format::ReadStack>().get<2>().val), int8_t>);
        static_assert(std::is_same_v<decltype(std::declval<Format::ReadStack>().get<3>().val), int8_t>);
        auto stack = Format::reader(sd).read(v0).read(v4).read(v5).read(t).read(a).read(v1).read(v2).read(
                v3).stack();
        assert(t.a == '1');
        assert(a == "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
        assert(stack.get<10>().value() == a);
        assert(v0 == '1');
        assert(v1 == '1');
        assert(v2 == '2');
        assert(v3 == '3');
        assert(v4 == '2');
        assert(v5 == '3');
        assert(&stack.get<4>().currentValue() == &v4);
        assert(&stack.get<5>().currentValue() == &v5);
        assert(&stack.get<1>().currentValue() == &v1);

        sd.str("");
        Format::writer(sd).write('1').write('2').write('3').write(t).write(a).write('1').write('2').write('3');
        assert(sd.str() == "1231aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa123");
    }
    TEST("Get mismatch");
    {
        std::stringstream sd;
        sd.str("11");
        sd.exceptions(std::ios_base::badbit);
        std::vector<uint8_t> a;
        int8_t v0;
        using F = Format<Copy<0, Sc<int8_t>>, Get<0>>;
        static_assert(std::is_same_v<F::Type < 0>, int8_t > );
        F::reader(sd).read(v0);
        assert(v0 == '1');

        sd.clear();
        sd.str("10");
        try {
            F::reader(sd).read(v0);
            fprintf(stderr, "expected failure to be thrown\n");
            exit(1);
        } catch (get_mismatch &) {
            sd.clear();
        }
    }
    TEST("FixedArray with Variable");
    {
        std::stringstream sd;
        sd.str(std::string("1231aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1123"));
        sd.exceptions(std::ios_base::badbit);
        std::vector<uint8_t> a;
        int8_t v0;
        int8_t v1;
        int8_t v2;
        int8_t v3;
        int8_t v4;
        int8_t v5;
        using Format =
        format::Format<Copy<0, Sc<int8_t>>,
                Copy<4, Sc<int8_t>>,
                Copy<5, Sc<int8_t>>,
                Set<6, Sc<int8_t>>,
                Copy<10, FixedArray<Sc<uint8_t>, Get<6>>>,
                Get<6>,
                Copy<1, Sc<int8_t>>,
                Copy<2, Sc<int8_t>>,
                Copy<3, Sc<int8_t>>>;
        static_assert(std::is_same_v<Format::Type<0>, int8_t>);
        static_assert(std::is_same_v<Format::Type<1>, int8_t>);
        static_assert(std::is_same_v<Format::Type<2>, int8_t>);
        static_assert(std::is_same_v<Format::Type<3>, std::vector<uint8_t>>);
        static_assert(std::is_same_v<Format::Type<4>, int8_t>);
        static_assert(std::is_same_v<Format::Type<5>, int8_t>);
        static_assert(std::is_same_v<Format::Type<6>, int8_t>);
        auto stack = Format::reader(sd).read(v0).read(v4).read(v5).read(a).read(v1).read(v2).read(v3).stack();
        assert(memcmp(a.data(), "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", a.size()) == 0);
        assert(stack.get<10>().value().size() == a.size());
        assert(memcmp(stack.get<10>().value().data(), "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", a.size()) ==
               0);
        assert(v0 == '1');
        assert(v1 == '1');
        assert(v2 == '2');
        assert(v3 == '3');
        assert(v4 == '2');
        assert(v5 == '3');

        sd.str("");
        Format::writer(sd).stack<6>(static_cast<int8_t>(a.size()))
                .write('1')
                .write('2')
                .write('3')
                .write(a)
                .write('1')
                .write('2')
                .write('3');
        assert(sd.str() == "1231aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1123");
    }
    TEST("Structure as Variable");
    {
        std::stringstream sd;
        sd.str(std::string("1231baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1b123"));
        sd.exceptions(std::ios_base::badbit);
        std::vector<uint8_t> a;
        struct Test {
            uint8_t a;
            uint8_t b;

            [[maybe_unused]] Test() = default;

            Test(uint8_t i, uint8_t j) : a(i), b(j) {}

            [[maybe_unused]] explicit Test(uint8_t i) : a(i), b('b') {}

            operator size_t() {
                return a;
            }
        };
        using Format =
        format::Format<Set<0, Sc<uint8_t>>,
                Set<4, Sc<uint8_t>>,
                Set<5, Sc<uint8_t>>,
                Set<6, St<Test, O<offsetof(Test, a), Sc<uint8_t>>, O<offsetof(Test, b), Sc<uint8_t>>>>,
                FixedArray<Sc<uint8_t>, Get<6>>,
                Get<6>,
                Set<1, Sc<uint8_t>>,
                Set<2, Sc<uint8_t>>,
                Set<3, Sc<uint8_t>>>;
        static_assert(std::is_same_v<Format::Type<0>, std::vector<uint8_t>>);
        auto stack = Format::reader(sd).read().read(a).stack();
        assert(a.size() == 49);
        assert(memcmp(a.data(), "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", a.size()) == 0);
        assert(stack.get<0>() == '1');
        assert(stack.get<4>() == '2');
        assert(stack.get<5>() == '3');
        assert(static_cast<Test>(stack.get<6>().value()) == Test('1', 'b'));
        assert(stack.get<1>() == '1');
        assert(stack.get<2>() == '2');
        assert(stack.get<3>() == '3');

        sd.str("");
        Format::writer(sd).stack(stack).write().write(a);
        assert(sd.str() == "1231baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1b123");
    }
    TEST("Terminated Array as Variable");
    {
        std::stringstream sd;
        sd.str("abc0");
        sd.exceptions(std::ios_base::badbit);
        std::vector<uint8_t> a;
        using Form = format::Format<Copy<0, TerminatedArray<Sc<uint8_t>, '0'>>>;
        Form::reader(sd).read(a);
        assert(a == std::vector<uint8_t>({'a', 'b', 'c'}));

        sd.str("");
        a = std::vector<uint8_t>{'a', 'b', 'c'};
        format::Format<TerminatedArray<Sc<uint8_t>, '0'>>::writer(sd).write(a);
        assert(sd.str() == "abc0");
        sd.str("");
        Form::writer(sd).write(a);
        assert(sd.str() == "abc0");
        sd.str("");
        format::Format<Set<0, TerminatedArray<Sc<uint8_t>, '0'>>>::writer(sd).stack<0>(a).write();
        assert(sd.str() == "abc0");
    }
    TEST("Structure with Set-Variable");
    {
        std::stringstream sd;
        sd.str(std::string("12341aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4123"));
        sd.exceptions(std::ios_base::badbit);
        struct Test {
            uint8_t a;

            Test() : a(0) {}

            explicit Test(uint8_t i) : a(i) {}
        };
        std::string a;
        Test t;
        using Format =
        format::Format<Set<0, Sc<uint8_t>>,
                Set<4, Sc<uint8_t>>,
                Set<5, Sc<uint8_t>>,
                Structure<Test, Set<8, Sc<uint8_t>>, O<offsetof(Test, a), Copy<7, Sc<uint8_t>>>>,
                StaticArray<char, 49>,
                Get<8>,
                Set<1, Sc<uint8_t>>,
                Set<2, Sc<uint8_t>>,
                Set<3, Sc<uint8_t>>>;
        auto stack = Format::reader(sd).read().read(t).read(a).stack();
        assert(t.a == '1');
        assert(a == "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

        sd.str("");
        Format::writer(sd)
                .stack(stack)
                .write()
                .write(t)
                .write(a);
        assert(sd.str() == "12341aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4123");
    }
    TEST("Stack Reading/Writing to Set Variables");
    {
        std::stringstream sd;
        sd.exceptions(std::ios_base::badbit);
        using Format = format::Format<
                Set<0, Sc<uint8_t>>,
                Set<1, Sc<uint8_t>>,
                Set<2, Sc<uint8_t>>,
                Set<3, Sc<uint8_t>>>;
        sd.str("abcd");
        auto stack = Format::reader(sd).read().stack();
        assert(stack.get<0>() == 'a');
        assert(stack.get<1>() == 'b');
        assert(stack.get<2>() == 'c');
        assert(stack.get<3>() == 'd');
        sd.str("");
        Format::writer(sd).stack(stack).write();
        assert(sd.str() == "abcd");
    }
    TEST("Stack Reading/Writing to Copy Variables");
    {
        std::stringstream sd;
        sd.exceptions(std::ios_base::badbit);
        using Format = format::Format<
                Copy<0, Sc<uint8_t>>,
                Copy<1, Sc<uint8_t>>,
                Copy<2, Sc<uint8_t>>,
                Copy<3, Sc<uint8_t>>>;
        sd.str("abcd");
        uint8_t a;
        uint8_t b;
        uint8_t c;
        uint8_t d;
        auto stack = Format::reader(sd).read(a).read(b).read(c).read(d).stack();
        assert(stack.get<0>() == 'a');
        assert(stack.get<1>() == 'b');
        assert(stack.get<2>() == 'c');
        assert(stack.get<3>() == 'd');
        assert(a == 'a');
        assert(b == 'b');
        assert(c == 'c');
        assert(d == 'd');
        sd.str("");
        Format::writer(sd).write(a).write(b).write(c).write(d);
        assert(sd.str() == "abcd");
    }
    TEST("Stack Reading/Writing to Variables");
    {
        std::stringstream sd;
        sd.exceptions(std::ios_base::badbit);
        using Format = format::Format<
                Set<4, Sc<uint8_t>>,
                Set<5, Sc<uint8_t>>,
                Copy<0, Sc<uint8_t>>,
                Copy<1, Sc<uint8_t>>,
                Set<6, Sc<uint8_t>>,
                Copy<2, Sc<uint8_t>>,
                Copy<3, Sc<uint8_t>>,
                Set<7, Sc<uint8_t>>>;
        sd.str("efabgcdh");
        uint8_t a;
        uint8_t b;
        uint8_t c;
        uint8_t d;
        auto stack = Format::reader(sd).read().read(a).read(b).read(c).read(d).stack();
        assert(stack.get<4>() == 'e');
        assert(stack.get<5>() == 'f');
        assert(stack.get<0>() == 'a');
        assert(stack.get<1>() == 'b');
        assert(stack.get<6>() == 'g');
        assert(stack.get<2>() == 'c');
        assert(stack.get<3>() == 'd');
        assert(stack.get<7>() == 'h');
        assert(a == 'a');
        assert(b == 'b');
        assert(c == 'c');
        assert(d == 'd');
        sd.str("");
        Format::writer(sd).stack(stack).write().write(a).write(b).write(c).write(d);
        assert(sd.str() == "efabgcdh");
    }
    TEST("Stack Reading/Writing to nested Variables");
    {
        std::stringstream sd;
        sd.exceptions(std::ios_base::badbit);
        using Format = format::Format<
                Set<4, Set<8, Sc<uint8_t>>>,
                Copy<5, Set<9, Sc<uint8_t>>>,
                Copy<0, Copy<10, Sc<uint8_t>>>,
                Copy<1, Sc<uint8_t>>,
                Set<6, Sc<uint8_t>>,
                Copy<2, Sc<uint8_t>>,
                Copy<3, Sc<uint8_t>>,
                Set<7, Sc<uint8_t>>>;
        sd.str("efabgcdh");
        uint8_t a;
        uint8_t b;
        uint8_t c;
        uint8_t d;
        uint8_t f;
        auto stack = Format::reader(sd).read().read(f).read(a).read(b).read(c).read(d).stack();
        assert(stack.get<4>() == 'e');
        assert(stack.get<8>() == 'e');
        assert(stack.get<5>() == 'f');
        assert(stack.get<9>() == 'f');
        assert(stack.get<0>() == 'a');
        assert(stack.get<10>() == 'a');
        assert(stack.get<1>() == 'b');
        assert(stack.get<6>() == 'g');
        assert(stack.get<2>() == 'c');
        assert(stack.get<3>() == 'd');
        assert(stack.get<7>() == 'h');
        assert(a == 'a');
        assert(b == 'b');
        assert(c == 'c');
        assert(d == 'd');
        assert(f == 'f');
        sd.str("");
        Format::writer(sd).stack(stack).write().write(f).write(a).write(b).write(c).write(d);
        assert(sd.str() == "efabgcdh");
    }
    TEST("Stack Reading/Writing with Get");
    {
        std::stringstream sd;
        sd.exceptions(std::ios_base::badbit);
        using Format = format::Format<
                Set<0, Sc<uint8_t>>,
                Get<0>,
                Set<2, Sc<uint8_t>>,
                Set<3, Sc<uint8_t>>>;
        sd.str("aacd");
        auto stack = Format::reader(sd).read().stack();
        assert(stack.get<0>() == 'a');
        assert(stack.get<2>() == 'c');
        assert(stack.get<3>() == 'd');
        sd.str("");
        Format::writer(sd).stack(stack).write();
        assert(sd.str() == "aacd");
    }
    TEST("Terminated Array with prefix as Set-Variable");
    {
        std::stringstream sd;
        sd.str("10101c0d");
        sd.exceptions(std::ios_base::badbit);
        std::vector<uint8_t> a;
        auto stack = format::Format<Set<0, Pt<Sc<uint8_t>, Sc<uint8_t>, '0', '1'>>>::reader(sd).read().stack();
        assert(stack.get<0>().value() == std::vector<uint8_t>({'0', '0', 'c'}));
        sd.str("");
        format::Format<Set<0, Pt<Sc<uint8_t>, Sc<uint8_t>, '0', '1'>>>::writer(sd).stack(stack).write();
        assert(sd.str() == "10101c0");
    }
    TEST("Terminated Array with prefix as Copy-Variable");
    {
        std::stringstream sd;
        sd.str("10101c0d");
        sd.exceptions(std::ios_base::badbit);
        std::vector<uint8_t> a;
        auto stack = format::Format<Copy<0, Pt<Sc<uint8_t>, Sc<uint8_t>, '0', '1'>>>::reader(sd).read(a).stack();
        assert(stack.get<0>().value() == std::vector<uint8_t>({'0', '0', 'c'}));
        assert(a == std::vector<uint8_t>({'0', '0', 'c'}));
        sd.str("");
        format::Format<Copy<0, Pt<Sc<uint8_t>, Sc<uint8_t>, '0', '1'>>>::writer(sd).write(a);
        assert(sd.str() == "10101c0");
    }
    TEST("Prefixed Array with Structure and custom prefix as Copy-Variable");
    {
        std::stringstream sd{};
        sd.str("1abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc");
        sd.exceptions(std::ios_base::badbit);
        struct test {
            char a;
            char b;
            char c;

            [[maybe_unused]] test() = default;

            test(char i, char j, char k) : a(i), b(j), c(k) {}
        };
        struct prefix {
            uint8_t p;

            prefix() = default;

            explicit prefix(size_t t) : p(static_cast<uint8_t>(t)) {
                if (t > std::numeric_limits<uint8_t>::max())
                    throw std::range_error("range error");
            }

            explicit prefix(uint8_t pr) : p(pr) {}

            [[maybe_unused]] bool operator<(size_t u) const {
                return p < u;
            }

            explicit operator size_t() {
                if (p == 0) {
                    return 0;
                }
                return p - 1;
            }
        };
        std::vector<test> d0{};
        auto stack = format::Format<Copy<0, PrefixedArray<St<prefix, Sc<uint8_t>>, Structure<test, Sc<char>, Sc<char>, Sc<char>>>>>::reader(
                sd).read(d0).stack();
        assert(d0.size() == 48);
        assert(stack.get<0>().value().size() == 48);
        for (auto i = 0u; i < 48u; ++i) {
            assert(d0[i].a == 'a');
            assert(d0[i].b == 'b');
            assert(d0[i].c == 'c');
            assert(stack.get<0>().value()[i].a == 'a');
            assert(stack.get<0>().value()[i].b == 'b');
            assert(stack.get<0>().value()[i].c == 'c');
        }

        sd.str("");
        format::Format<Copy<0, PrefixedArray<St<prefix, O<offsetof(prefix, p), Sc<uint8_t>>>, Structure<test,
                O<offsetof(test, a), Sc<char>>,
                O<offsetof(test, b), Sc<char>>,
                O<offsetof(test, c), Sc<char>>>>>>::writer(sd).write(d0);
        assert(sd.str() ==
               "0abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc");
    }
    TEST("StaticArray specialization for std::string as Set-Variable");
    {
        std::stringstream sd;
        sd.str(std::string("Hello"));
        sd.exceptions(std::ios_base::badbit);
        auto stack = format::Format<Set<0, StaticString<5>>>::reader(sd)
                .read().stack();
        assert(stack.get<0>().value() == "Hello");

        sd.str("");
        format::Format<Set<0, StaticString<5>>>::writer(sd).stack(stack).write();
        assert(sd.str() == "Hello");
    }
    TEST("PrefixedArray specialization for std::string as Set-Variable");
    {
        std::stringstream sd;
        sd.str(std::string("1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
        sd.exceptions(std::ios_base::badbit);
        auto stack = format::Format<Set<0, PrefixedString<Sc<uint8_t>>>>::reader(sd).read().stack();
        assert(stack.get<0>().value() == "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

        sd.str("");
        format::Format<Set<0, PrefixedString<Sc<uint8_t>>>>::writer(sd).stack(stack).write();
        assert(sd.str() == "1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    }
    TEST("Writing Single Structure: Custom Class as Set-Variable");
    {
        std::stringstream sd{};
        sd.str("abc");
        auto stack = format::Format<Set<0, TestSerialize>>::reader(sd).read().stack();
        assert(stack.get<0>().value() == TestS('a', 'b', 'c'));
        TestS t{'a', 'b', 'c'};
        format::Format<Set<0, TestSerialize>>::writer(sd).stack(stack).write();
        assert(sd.str() == "abc");
    }
    TEST("Conditional: Simple");
    {
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
        using Format = format::Format<Copy<0, St<Num, O<offsetof(Num,
                                                                 a), Sc<uint8_t>>>>, Conditional<Get<0>, Sc<uint8_t>, StaticString<2>>>;
        Format::reader(sd).read(n).read(v);
        assert(n == true);
        assert(std::holds_alternative<uint8_t>(v));
        assert(std::get<uint8_t>(v) == 'b');
        sd.str("");
        Format::writer(sd).write(n).write(v);
        assert(sd.str() == "ab");

        sd.str("bbd");
        Format::reader(sd).read(n).read(v);
        assert(!n);
        assert(std::holds_alternative<std::string>(v));
        assert(std::get<std::string>(v) == "bd");
        sd.str("");
        Format::writer(sd).write(n).write(v);
        assert(sd.str() == "bbd");
    }
    TEST("Conditional: Without False-Branch");
    {
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
        std::optional<std::string> v;
        using Format = format::Format<Copy<0, St<Num, O<offsetof(Num,
                                                                 a), Sc<uint8_t>>>>, Conditional<Get<0>, StaticString<2>>>;
        Format::reader(sd).read(n).read(v);
        assert(n == true);
        assert(v);
        assert(v.value() == "bd");
        sd.str("");
        Format::writer(sd).write(n).write(v);
        assert(sd.str() == "abd");

        sd.str("bbd");
        Format::reader(sd).read(n).read(v);
        assert(!n);
        assert(!v);
        sd.str("");
        Format::writer(sd).write(n).write(v);
        sd.str("b");
    }
    TEST("Conditional: Variables");
    {
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
        using Format = format::Format<Copy<0, St<Num, O<offsetof(Num, a), Sc<uint8_t>>>>,
                Conditional<Get<0>, Copy<1, Sc<uint8_t>>, Copy<2, StaticString<2>>>>;
        auto stack = Format::reader(sd).read(n).read(v).stack();
        assert(n == true);
        assert(std::holds_alternative<uint8_t>(v));
        assert(std::get<uint8_t>(v) == 'b');
        assert(stack.get<1>().value() != std::nullopt);
        assert(stack.get<2>().value() == std::nullopt);
        assert(stack.get<1>().value() == 'b');
        sd.str("");
        Format::writer(sd).write(n).write(v);
        assert(sd.str() == "ab");

        sd.str("bbd");
        auto stack2 = Format::reader(sd).read(n).read(v).stack();
        assert(!n);
        assert(std::holds_alternative<std::string>(v));
        assert(std::get<std::string>(v) == "bd");
        assert(stack2.get<1>().value() == std::nullopt);
        assert(stack2.get<2>().value() != std::nullopt);
        assert(stack2.get<2>().value() == "bd");
        sd.str("");
        Format::writer(sd).write(n).write(v);
        assert(sd.str() == "bbd");
    }
    TEST("Conditional: non-optional Variables");
    {
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
        uint8_t v;
        using Format = format::Format<Copy<0, St<Num, O<offsetof(Num, a), Sc<uint8_t>>>>,
                Conditional<Get<0>, Copy<1, Sc<uint8_t>>, Copy<1, Sc<uint8_t>>>>;
        auto stack = Format::reader(sd).read(n).read(v).stack();
        assert(n == true);
        assert(v == 'b');
        static_assert(
                std::is_same_v<std::remove_reference_t<decltype(std::declval<Format::ReadStack>().get<1>())>::Type, uint8_t>);
        assert(stack.get<1>().value() == 'b');
        sd.str("");
        Format::writer(sd).write(n).write(v);
        assert(sd.str() == "ab");

        sd.str("bb");
        auto stack2 = Format::reader(sd).read(n).read(v).stack();
        assert(!n);
        assert(v == 'b');
        assert(stack2.get<1>().value() == 'b');
        sd.str("");
        Format::writer(sd).write(n).write(v);
        assert(sd.str() == "bb");
    }
    TEST("Conditional: Without False-Branch and Variables");
    {
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
        std::optional<std::string> v;
        using Format = format::Format<Copy<0, St<Num, O<offsetof(Num,
                                                                 a), Sc<uint8_t>>>>, Conditional<Get<0>, Copy<1, StaticString<2>>>>;
        auto stack = Format::reader(sd).read(n).read(v).stack();
        assert(n == true);
        assert(v);
        assert(v.value() == "bd");
        assert(stack.get<1>().value() != std::nullopt);
        assert(stack.get<1>().value() == "bd");
        sd.str("");
        Format::writer(sd).write(n).write(v);
        assert(sd.str() == "abd");

        sd.str("bbd");
        auto stack2 = Format::reader(sd).read(n).read(v).stack();
        assert(!n);
        assert(!v);
        assert(stack2.get<1>().value() == std::nullopt);
        sd.str("");
        Format::writer(sd).write(n).write(v);
        assert(sd.str() == "b");
    }
    TEST("Conditional: Optional Variables with structure");
    {
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
        std::variant<Num, std::string> v;
        using Format = format::Format<Copy<0, St<Num, O<offsetof(Num, a), Sc<uint8_t>>>>,
                Conditional<Get<0>, St<Num, O<offsetof(Num, a), Copy<1, Sc<uint8_t>>>>, Copy<2, StaticString<2>>>>;
        auto stack = Format::reader(sd).read(n).read(v).stack();
        assert(n == true);
        assert(std::holds_alternative<Num>(v));
        assert(std::get<Num>(v).a == 'b');
        assert(stack.get<1>().value() != std::nullopt);
        assert(stack.get<2>().value() == std::nullopt);
        assert(stack.get<1>().value() == 'b');
        sd.str("");
        Format::writer(sd).write(n).write(v);
        assert(sd.str() == "ab");

        sd.str("bbd");
        auto stack2 = Format::reader(sd).read(n).read(v).stack();
        assert(!n);
        assert(std::holds_alternative<std::string>(v));
        assert(std::get<std::string>(v) == "bd");
        assert(stack2.get<1>().value() == std::nullopt);
        assert(stack2.get<2>().value() != std::nullopt);
        assert(stack2.get<2>().value() == "bd");
        sd.str("");
        Format::writer(sd).write(n).write(v);
        assert(sd.str() == "bbd");
    }
    TEST("Conditional: variant Variables");
    {
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
        using Format = format::Format<Copy<0, St<Num, O<offsetof(Num, a), Sc<uint8_t>>>>,
                Conditional<Get<0>, Copy<1, Sc<uint8_t>>, Copy<1, StaticString<2>>>>;
        auto stack = Format::reader(sd).read(n).read(v).stack();
        assert(n == true);
        assert(std::holds_alternative<uint8_t>(v));
        assert(std::get<uint8_t>(v) == 'b');
        assert(std::holds_alternative<uint8_t>(stack.get<1>().value()));
        assert(std::get<uint8_t>(stack.get<1>().value()) == 'b');
        sd.str("");
        Format::writer(sd).write(n).write(v);
        assert(sd.str() == "ab");

        sd.str("bbd");
        auto stack2 = Format::reader(sd).read(n).read(v).stack();
        assert(!n);
        assert(std::holds_alternative<std::string>(v));
        assert(std::get<std::string>(v) == "bd");
        assert(std::holds_alternative<std::string>(stack2.get<1>().value()));
        assert(std::get<std::string>(stack2.get<1>().value()) == "bd");
        sd.str("");
        Format::writer(sd).write(n).write(v);
        assert(sd.str() == "bbd");
    }
    TEST("Switch: Simple");
    {
        std::stringstream sd{};
        sd.str("abd");
        std::variant<uint8_t, std::string, uint16_t> v;
        using Format = format::Format<Set<0, Sc<int8_t>>, Switch<Get<0>,
                Case<Constant<std::integral_constant<uint8_t, 'a'>>, Sc<uint8_t>>,
                Case<Constant<std::integral_constant<uint8_t, 'b'>>, StaticString<2>>,
                Case<Constant<std::integral_constant<uint8_t, 'c'>>, Sc<uint16_t>>>>;
        auto stack = Format::reader(sd).read().read(v).stack();
        assert(stack.get<0>().value() == 'a');
        assert(std::holds_alternative<uint8_t>(v));
        assert(std::get<uint8_t>(v) == 'b');
        sd.str("");
        Format::writer(sd).stack<0>('a').write().write(v);
        assert(sd.str() == "ab");

        sd.str("bbd");
        stack = Format::reader(sd).read().read(v).stack();
        assert(stack.get<0>().value() == 'b');
        assert(std::holds_alternative<std::string>(v));
        assert(std::get<std::string>(v) == "bd");
        sd.str("");
        Format::writer(sd).stack<0>('b').write().write(v);
        assert(sd.str() == "bbd");

        sd.str("cbd");
        stack = Format::reader(sd).read().read(v).stack();
        assert(stack.get<0>().value() == 'c');
        assert(std::holds_alternative<uint16_t>(v));
        assert(std::get<uint16_t>(v) == (static_cast<unsigned short>('b') | static_cast<unsigned short>('d') << 8));
        sd.str("");
        Format::writer(sd).stack<0>('c').write().write(v);
        assert(sd.str() == "cbd");
    }
    TEST("Switch: Variables");
    {
        using EmptyStack = InternalStack<true, void, void>;
        using ReduceCmd = reduce<merge_and_unwind<true>::template Operation, EmptyStack>;
        using Stack = typename permutate_first_with_all<ReduceCmd::template Operation, tuple<>, 0,
                Case<Constant<std::integral_constant<uint8_t, 'a'>>, Set<1, Sc<uint8_t>>>,
                Case<Constant<std::integral_constant<uint8_t, 'b'>>, Set<1, Sc<uint8_t>>>,
                Case<Constant<std::integral_constant<uint8_t, 'c'>>, Set<1, Sc<uint8_t>>>
        >::Type::Type;
        static_assert(std::is_same_v<std::remove_reference_t<decltype(std::declval<Stack>().get<1>())>::Type, uint8_t>);
    }
    TEST("Switch: Optional Variables");
    {
        using EmptyStack = InternalStack<true, void, void>;
        using ReduceCmd = reduce<merge_and_unwind<true>::template Operation, EmptyStack>;
        using Stack = typename permutate_first_with_all<ReduceCmd::template Operation, tuple<>, 0,
                Case<Constant<std::integral_constant<uint8_t, 'a'>>, Set<1, Sc<uint8_t>>>,
                Case<Constant<std::integral_constant<uint8_t, 'b'>>, Set<2, StaticString<2>>>,
                Case<Constant<std::integral_constant<uint8_t, 'c'>>, Set<3, Sc<uint16_t>>>
        >::Type::Type;
        static_assert(
                std::is_same_v<std::remove_reference_t<decltype(std::declval<Stack>().get<1>())>::Type, std::optional<uint8_t>>);
        static_assert(
                std::is_same_v<std::remove_reference_t<decltype(std::declval<Stack>().get<2>())>::Type, std::optional<std::string>>);
        static_assert(
                std::is_same_v<std::remove_reference_t<decltype(std::declval<Stack>().get<3>())>::Type, std::optional<uint16_t>>);
    }
    TEST("Switch: variant and Optional Variables");
    {
        using EmptyStack = InternalStack<true, void, void>;
        using ReduceCmd = reduce<merge_and_unwind<true>::template Operation, EmptyStack>;
        using Stack = typename permutate_first_with_all<ReduceCmd::template Operation, tuple<>, 0,
                Case<Constant<std::integral_constant<uint8_t, 'a'>>, Set<1, Sc<uint8_t>>>,
                Case<Constant<std::integral_constant<uint8_t, 'b'>>, Set<2, StaticString<2>>>,
                Case<Constant<std::integral_constant<uint8_t, 'c'>>, Set<1, Sc<uint16_t>>>
        >::Type::Type;
        static_assert(
                std::is_same_v<std::remove_reference_t<decltype(std::declval<Stack>().get<1>())>::Type, std::optional<std::variant<uint16_t, uint8_t>>>);
        static_assert(
                std::is_same_v<std::remove_reference_t<decltype(std::declval<Stack>().get<2>())>::Type, std::optional<std::string>>);
    }
    TEST("Switch: Full Test");
    {
        std::stringstream sd{};
        sd.str("abd");
        std::variant<uint8_t, std::string, uint16_t> v;
        using Format = format::Format<Set<0, Sc<int8_t>>, Switch<Get<0>,
                Case<Constant<std::integral_constant<uint8_t, 'a'>>, Set<1, Sc<uint8_t>>>,
                Case<Constant<std::integral_constant<uint8_t, 'b'>>, Set<2, StaticString<2>>>,
                Case<Constant<std::integral_constant<uint8_t, 'c'>>, Set<1, Sc<uint16_t>>>>>;
        static_assert(
                std::is_same_v<std::remove_reference_t<decltype(std::declval<Format::ReadStack>().get<1>())>::Type, std::optional<std::variant<uint16_t, uint8_t>>>);
        static_assert(
                std::is_same_v<std::remove_reference_t<decltype(std::declval<Format::ReadStack>().get<2>())>::Type, std::optional<std::string>>);
        auto stack = Format::reader(sd).read().read(v).stack();
        assert(stack.get<0>().value() == 'a');
        assert(stack.get<1>().value() != std::nullopt);
        assert(stack.get<2>().value() == std::nullopt);
        assert(std::holds_alternative<uint8_t>(stack.get<1>().value().value()));
        assert(std::get<uint8_t>(stack.get<1>().value().value()) == 'b');
        assert(std::holds_alternative<uint8_t>(v));
        assert(std::get<uint8_t>(v) == 'b');
        sd.str("");
        Format::writer(sd).stack<0>('a').write().write(v);
        assert(sd.str() == "ab");

        sd.str("bbd");
        stack = Format::reader(sd).read().read(v).stack();
        assert(stack.get<0>().value() == 'b');
        assert(stack.get<1>().value() == std::nullopt);
        assert(stack.get<2>().value() != std::nullopt);
        assert(stack.get<2>().value().value() == "bd");
        assert(std::get<std::string>(v) == "bd");
        sd.str("");
        Format::writer(sd).stack<0>('b').write().write(v);
        assert(sd.str() == "bbd");

        sd.str("cbd");
        stack = Format::reader(sd).read().read(v).stack();
        assert(stack.get<0>().value() == 'c');
        assert(stack.get<1>().value() != std::nullopt);
        assert(stack.get<2>().value() == std::nullopt);
        assert(std::holds_alternative<uint16_t>(stack.get<1>().value().value()));
        assert(std::get<uint16_t>(stack.get<1>().value().value()) ==
               (static_cast<unsigned short>('b') | static_cast<unsigned short>('d') << 8));
        assert(std::holds_alternative<uint16_t>(v));
        assert(std::get<uint16_t>(v) == (static_cast<unsigned short>('b') | static_cast<unsigned short>('d') << 8));
        sd.str("");
        Format::writer(sd).stack<0>('c').write().write(v);
        assert(sd.str() == "cbd");
    }
    TEST("Switch Default");
    {
        std::stringstream sd{};
        sd.str("abd");
        std::variant<uint8_t, std::string, uint16_t> v;
        using Format = format::Format<Set<0, Sc<int8_t>>, Switch<Get<0>,
                Case<Constant<std::integral_constant<uint8_t, 'a'>>, Sc<uint8_t>>,
                Default<StaticString<2>>,
                Case<Constant<std::integral_constant<uint8_t, 'c'>>, Sc<uint16_t>>>>;
        auto stack = Format::reader(sd).read().read(v).stack();
        assert(stack.get<0>().value() == 'a');
        assert(std::holds_alternative<uint8_t>(v));
        assert(std::get<uint8_t>(v) == 'b');
        sd.str("");
        Format::writer(sd).stack<0>('a').write().write(v);
        assert(sd.str() == "ab");

        sd.str("bbd");
        stack = Format::reader(sd).read().read(v).stack();
        assert(stack.get<0>().value() == 'b');
        assert(std::holds_alternative<std::string>(v));
        assert(std::get<std::string>(v) == "bd");
        sd.str("");
        Format::writer(sd).stack<0>('b').write().write(v);
        assert(sd.str() == "bbd");

        sd.str("cbd");
        stack = Format::reader(sd).read().read(v).stack();
        assert(stack.get<0>().value() == 'c');
        assert(std::holds_alternative<std::string>(v));
        assert(std::get<std::string>(v) == "bd");
        sd.str("");
        Format::writer(sd).stack<0>('c').write().write(v);
        assert(sd.str() == "cbd");

        using Format2 = format::Format<Set<0, Sc<int8_t>>, Switch<Get<0>,
                Case<Constant<std::integral_constant<uint8_t, 'a'>>, Sc<uint8_t>>,
                Case<Constant<std::integral_constant<uint8_t, 'c'>>, Sc<uint16_t>>>>;
        sd.str("bbd");
        try {
            Format2::Type<0> v2;
            Format2::reader(sd).read().read(v2);
            fprintf(stderr, "expected failure to be thrown\n");
            exit(1);
        } catch (no_matching_case &) {

        }
    }
    TEST("Constants");
    {
        std::stringstream sd;
        sd.str("ab");
        constexpr uint16_t constant =
                static_cast<unsigned>('a') | static_cast<unsigned>(static_cast<unsigned>('b') << 8u);
        using Format = format::Format<Constant<std::integral_constant<uint16_t, constant>, Sc<uint16_t>>>;
        Format::reader(sd).read();
        sd.str("");
        Format::writer(sd).write();
        assert(sd.str() == "ab");

        sd.str("aa");
        try {
            Format::reader(sd).read();
            fprintf(stderr, "expected failure to be thrown\n");
            exit(1);
        } catch (constant_mismatch &) {}
    }
    TEST("Calls");
    {
        std::stringstream sd;
        sd.str("ab");
        int x;
        using Format = format::Format<Call<&double_value, Sc<uint8_t>>>;
        Format::reader(sd).read(x);
        assert(x == 'a' * 2);
        sd.str("");
        Format::writer(sd).write();
        assert(sd.str().empty());
    }
    TEST("Map");
    {
        std::stringstream sd;
        sd.str("a");
        int x;
        using Format = format::Format<Map<&double_value, &half_value, Sc<uint8_t>>>;
        Format::reader(sd).read(x);
        assert(x == 'a' * 2);
        sd.str("");
        Format::writer(sd).write(x);
        assert(sd.str() == "a");
    }
    return 0;
}
