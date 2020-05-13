assert((Packed<uint8_t>().apply<0,7>(255).value == 255u));
assert((Packed<uint8_t>().apply<0,7>(0).value == 0u));
assert((Packed<uint8_t>().apply<0,7>(99).value == 99u));
assert((Packed<uint8_t>().apply<0,7>(49).value == 49u));
assert((Packed<uint8_t>().apply<0,7>(122).value == 122u));

assert((Packed<uint8_t>().apply<0,0>(0).value == 0u));
assert((Packed<uint8_t>().apply<0,0>(1).value == 1u));

assert((Packed<uint8_t>().apply<0,1>(0).value == 0u));
assert((Packed<uint8_t>().apply<0,1>(3).value == 3u));

assert((Packed<uint8_t>().apply<0,2>(0).value == 0u));
assert((Packed<uint8_t>().apply<0,2>(1).value == 1u));
assert((Packed<uint8_t>().apply<0,2>(7).value == 7u));
assert((Packed<uint8_t>().apply<0,2>(2).value == 2u));

assert((Packed<uint8_t>().apply<0,3>(15).value == 15u));
assert((Packed<uint8_t>().apply<0,3>(0).value == 0u));
assert((Packed<uint8_t>().apply<0,3>(8).value == 8u));
assert((Packed<uint8_t>().apply<0,3>(14).value == 14u));
assert((Packed<uint8_t>().apply<0,3>(7).value == 7u));

assert((Packed<uint8_t>().apply<0,4>(31).value == 31u));
assert((Packed<uint8_t>().apply<0,4>(0).value == 0u));
assert((Packed<uint8_t>().apply<0,4>(6).value == 6u));
assert((Packed<uint8_t>().apply<0,4>(15).value == 15u));
assert((Packed<uint8_t>().apply<0,4>(2).value == 2u));

assert((Packed<uint8_t>().apply<0,5>(63).value == 63u));
assert((Packed<uint8_t>().apply<0,5>(0).value == 0u));
assert((Packed<uint8_t>().apply<0,5>(11).value == 11u));
assert((Packed<uint8_t>().apply<0,5>(56).value == 56u));
assert((Packed<uint8_t>().apply<0,5>(58).value == 58u));

assert((Packed<uint8_t>().apply<0,6>(127).value == 127u));
assert((Packed<uint8_t>().apply<0,6>(0).value == 0u));
assert((Packed<uint8_t>().apply<0,6>(78).value == 78u));
assert((Packed<uint8_t>().apply<0,6>(35).value == 35u));
assert((Packed<uint8_t>().apply<0,6>(11).value == 11u));

assert((Packed<uint8_t>().apply<0,7>(255).value == 255u));
assert((Packed<uint8_t>().apply<0,7>(0).value == 0u));
assert((Packed<uint8_t>().apply<0,7>(172).value == 172u));
assert((Packed<uint8_t>().apply<0,7>(201).value == 201u));
assert((Packed<uint8_t>().apply<0,7>(178).value == 178u));

assert((Packed<uint8_t>().apply<1,1>(1).value == 2u));
assert((Packed<uint8_t>().apply<1,1>(0).value == 0u));

assert((Packed<uint8_t>().apply<1,2>(3).value == 6u));
assert((Packed<uint8_t>().apply<1,2>(0).value == 0u));
assert((Packed<uint8_t>().apply<1,2>(2).value == 4u));
assert((Packed<uint8_t>().apply<1,2>(1).value == 2u));

assert((Packed<uint8_t>().apply<1,3>(7).value == 14u));
assert((Packed<uint8_t>().apply<1,3>(0).value == 0u));
assert((Packed<uint8_t>().apply<1,3>(5).value == 10u));
assert((Packed<uint8_t>().apply<1,3>(4).value == 8u));

assert((Packed<uint8_t>().apply<1,4>(15).value == 30u));
assert((Packed<uint8_t>().apply<1,4>(0).value == 0u));
assert((Packed<uint8_t>().apply<1,4>(2).value == 4u));
assert((Packed<uint8_t>().apply<1,4>(1).value == 2u));

assert((Packed<uint8_t>().apply<1,5>(31).value == 62u));
assert((Packed<uint8_t>().apply<1,5>(0).value == 0u));
assert((Packed<uint8_t>().apply<1,5>(19).value == 38u));
assert((Packed<uint8_t>().apply<1,5>(28).value == 56u));

assert((Packed<uint8_t>().apply<1,6>(63).value == 126u));
assert((Packed<uint8_t>().apply<1,6>(0).value == 0u));
assert((Packed<uint8_t>().apply<1,6>(21).value == 42u));
assert((Packed<uint8_t>().apply<1,6>(22).value == 44u));
assert((Packed<uint8_t>().apply<1,6>(19).value == 38u));

assert((Packed<uint8_t>().apply<1,7>(127).value == 254u));
assert((Packed<uint8_t>().apply<1,7>(0).value == 0u));
assert((Packed<uint8_t>().apply<1,7>(72).value == 144u));
assert((Packed<uint8_t>().apply<1,7>(117).value == 234u));

assert((Packed<uint8_t>().apply<2,2>(0).value == 0u));
assert((Packed<uint8_t>().apply<2,2>(1).value == 4u));

assert((Packed<uint8_t>().apply<2,3>(0).value == 0u));
assert((Packed<uint8_t>().apply<2,3>(3).value == 12u));
assert((Packed<uint8_t>().apply<2,3>(2).value == 8u));

assert((Packed<uint8_t>().apply<2,4>(7).value == 28u));
assert((Packed<uint8_t>().apply<2,4>(0).value == 0u));
assert((Packed<uint8_t>().apply<2,4>(3).value == 12u));
assert((Packed<uint8_t>().apply<2,4>(5).value == 20u));
assert((Packed<uint8_t>().apply<2,4>(4).value == 16u));

assert((Packed<uint8_t>().apply<2,5>(15).value == 60u));
assert((Packed<uint8_t>().apply<2,5>(0).value == 0u));
assert((Packed<uint8_t>().apply<2,5>(5).value == 20u));

assert((Packed<uint8_t>().apply<2,6>(31).value == 124u));
assert((Packed<uint8_t>().apply<2,6>(0).value == 0u));
assert((Packed<uint8_t>().apply<2,6>(4).value == 16u));
assert((Packed<uint8_t>().apply<2,6>(5).value == 20u));
assert((Packed<uint8_t>().apply<2,6>(24).value == 96u));

assert((Packed<uint8_t>().apply<2,7>(63).value == 252u));
assert((Packed<uint8_t>().apply<2,7>(0).value == 0u));
assert((Packed<uint8_t>().apply<2,7>(62).value == 248u));
assert((Packed<uint8_t>().apply<2,7>(2).value == 8u));
assert((Packed<uint8_t>().apply<2,7>(61).value == 244u));

assert((Packed<uint8_t>().apply<3,3>(1).value == 8u));
assert((Packed<uint8_t>().apply<3,3>(0).value == 0u));

assert((Packed<uint8_t>().apply<3,4>(0).value == 0u));
assert((Packed<uint8_t>().apply<3,4>(3).value == 24u));
assert((Packed<uint8_t>().apply<3,4>(2).value == 16u));
assert((Packed<uint8_t>().apply<3,4>(1).value == 8u));

assert((Packed<uint8_t>().apply<3,5>(7).value == 56u));
assert((Packed<uint8_t>().apply<3,5>(2).value == 16u));
assert((Packed<uint8_t>().apply<3,5>(0).value == 0u));

assert((Packed<uint8_t>().apply<3,6>(0).value == 0u));
assert((Packed<uint8_t>().apply<3,6>(11).value == 88u));
assert((Packed<uint8_t>().apply<3,6>(13).value == 104u));
assert((Packed<uint8_t>().apply<3,6>(15).value == 120u));

assert((Packed<uint8_t>().apply<3,7>(31).value == 248u));
assert((Packed<uint8_t>().apply<3,7>(0).value == 0u));
assert((Packed<uint8_t>().apply<3,7>(18).value == 144u));
assert((Packed<uint8_t>().apply<3,7>(6).value == 48u));
assert((Packed<uint8_t>().apply<3,7>(14).value == 112u));

assert((Packed<uint8_t>().apply<4,4>(1).value == 16u));
assert((Packed<uint8_t>().apply<4,4>(0).value == 0u));

assert((Packed<uint8_t>().apply<4,5>(3).value == 48u));
assert((Packed<uint8_t>().apply<4,5>(0).value == 0u));
assert((Packed<uint8_t>().apply<4,5>(2).value == 32u));

assert((Packed<uint8_t>().apply<4,6>(7).value == 112u));
assert((Packed<uint8_t>().apply<4,6>(0).value == 0u));
assert((Packed<uint8_t>().apply<4,6>(6).value == 96u));
assert((Packed<uint8_t>().apply<4,6>(3).value == 48u));
assert((Packed<uint8_t>().apply<4,6>(1).value == 16u));

assert((Packed<uint8_t>().apply<4,7>(15).value == 240u));
assert((Packed<uint8_t>().apply<4,7>(0).value == 0u));
assert((Packed<uint8_t>().apply<4,7>(14).value == 224u));
assert((Packed<uint8_t>().apply<4,7>(8).value == 128u));
assert((Packed<uint8_t>().apply<4,7>(13).value == 208u));

assert((Packed<uint8_t>().apply<5,5>(1).value == 32u));
assert((Packed<uint8_t>().apply<5,5>(0).value == 0u));

assert((Packed<uint8_t>().apply<5,6>(3).value == 96u));
assert((Packed<uint8_t>().apply<5,6>(0).value == 0u));
assert((Packed<uint8_t>().apply<5,6>(2).value == 64u));
assert((Packed<uint8_t>().apply<5,6>(1).value == 32u));

assert((Packed<uint8_t>().apply<5,7>(7).value == 224u));
assert((Packed<uint8_t>().apply<5,7>(0).value == 0u));
assert((Packed<uint8_t>().apply<5,7>(1).value == 32u));
assert((Packed<uint8_t>().apply<5,7>(2).value == 64u));
assert((Packed<uint8_t>().apply<5,7>(5).value == 160u));

assert((Packed<uint8_t>().apply<6,6>(1).value == 64u));
assert((Packed<uint8_t>().apply<6,6>(0).value == 0u));

assert((Packed<uint8_t>().apply<6,7>(3).value == 192u));
assert((Packed<uint8_t>().apply<6,7>(0).value == 0u));
assert((Packed<uint8_t>().apply<6,7>(1).value == 64u));
assert((Packed<uint8_t>().apply<6,7>(2).value == 128u));

assert((Packed<uint8_t>().apply<7,7>(1).value == 128u));
assert((Packed<uint8_t>().apply<7,7>(0).value == 0u));

assert((Packed<uint16_t>().apply<0,7>(255).value == 255u));
assert((Packed<uint16_t>().apply<0,7>(0).value == 0u));
assert((Packed<uint16_t>().apply<0,7>(186).value == 186u));
assert((Packed<uint16_t>().apply<0,7>(159).value == 159u));
assert((Packed<uint16_t>().apply<0,7>(156).value == 156u));

assert((Packed<uint16_t>().apply<8,15>(255).value == 65280u));
assert((Packed<uint16_t>().apply<8,15>(0).value == 0u));
assert((Packed<uint16_t>().apply<8,15>(39).value == 9984u));
assert((Packed<uint16_t>().apply<8,15>(100).value == 25600u));
assert((Packed<uint16_t>().apply<8,15>(86).value == 22016u));

assert((Packed<uint16_t>().apply<0,0>(1).value == 1u));
assert((Packed<uint16_t>().apply<0,0>(0).value == 0u));

assert((Packed<uint16_t>().apply<0,1>(3).value == 3u));
assert((Packed<uint16_t>().apply<0,1>(1).value == 1u));
assert((Packed<uint16_t>().apply<0,1>(0).value == 0u));

assert((Packed<uint16_t>().apply<0,2>(7).value == 7u));
assert((Packed<uint16_t>().apply<0,2>(0).value == 0u));
assert((Packed<uint16_t>().apply<0,2>(1).value == 1u));
assert((Packed<uint16_t>().apply<0,2>(2).value == 2u));
assert((Packed<uint16_t>().apply<0,2>(3).value == 3u));

assert((Packed<uint16_t>().apply<0,3>(15).value == 15u));
assert((Packed<uint16_t>().apply<0,3>(0).value == 0u));
assert((Packed<uint16_t>().apply<0,3>(7).value == 7u));
assert((Packed<uint16_t>().apply<0,3>(4).value == 4u));

assert((Packed<uint16_t>().apply<0,4>(31).value == 31u));
assert((Packed<uint16_t>().apply<0,4>(0).value == 0u));
assert((Packed<uint16_t>().apply<0,4>(27).value == 27u));
assert((Packed<uint16_t>().apply<0,4>(20).value == 20u));
assert((Packed<uint16_t>().apply<0,4>(3).value == 3u));

assert((Packed<uint16_t>().apply<0,5>(63).value == 63u));
assert((Packed<uint16_t>().apply<0,5>(0).value == 0u));
assert((Packed<uint16_t>().apply<0,5>(23).value == 23u));
assert((Packed<uint16_t>().apply<0,5>(44).value == 44u));
assert((Packed<uint16_t>().apply<0,5>(62).value == 62u));

assert((Packed<uint16_t>().apply<0,6>(127).value == 127u));
assert((Packed<uint16_t>().apply<0,6>(0).value == 0u));
assert((Packed<uint16_t>().apply<0,6>(126).value == 126u));
assert((Packed<uint16_t>().apply<0,6>(79).value == 79u));
assert((Packed<uint16_t>().apply<0,6>(6).value == 6u));

assert((Packed<uint16_t>().apply<0,7>(255).value == 255u));
assert((Packed<uint16_t>().apply<0,7>(0).value == 0u));
assert((Packed<uint16_t>().apply<0,7>(254).value == 254u));
assert((Packed<uint16_t>().apply<0,7>(33).value == 33u));
assert((Packed<uint16_t>().apply<0,7>(210).value == 210u));

assert((Packed<uint16_t>().apply<1,1>(1).value == 2u));
assert((Packed<uint16_t>().apply<1,1>(0).value == 0u));

assert((Packed<uint16_t>().apply<1,2>(3).value == 6u));
assert((Packed<uint16_t>().apply<1,2>(0).value == 0u));
assert((Packed<uint16_t>().apply<1,2>(1).value == 2u));
assert((Packed<uint16_t>().apply<1,2>(2).value == 4u));

assert((Packed<uint16_t>().apply<1,3>(7).value == 14u));
assert((Packed<uint16_t>().apply<1,3>(0).value == 0u));
assert((Packed<uint16_t>().apply<1,3>(4).value == 8u));
assert((Packed<uint16_t>().apply<1,3>(3).value == 6u));
assert((Packed<uint16_t>().apply<1,3>(5).value == 10u));

assert((Packed<uint16_t>().apply<1,4>(15).value == 30u));
assert((Packed<uint16_t>().apply<1,4>(0).value == 0u));
assert((Packed<uint16_t>().apply<1,4>(14).value == 28u));
assert((Packed<uint16_t>().apply<1,4>(7).value == 14u));
assert((Packed<uint16_t>().apply<1,4>(8).value == 16u));

assert((Packed<uint16_t>().apply<1,5>(31).value == 62u));
assert((Packed<uint16_t>().apply<1,5>(0).value == 0u));
assert((Packed<uint16_t>().apply<1,5>(6).value == 12u));
assert((Packed<uint16_t>().apply<1,5>(7).value == 14u));
assert((Packed<uint16_t>().apply<1,5>(17).value == 34u));

assert((Packed<uint16_t>().apply<1,6>(63).value == 126u));
assert((Packed<uint16_t>().apply<1,6>(0).value == 0u));
assert((Packed<uint16_t>().apply<1,6>(38).value == 76u));
assert((Packed<uint16_t>().apply<1,6>(39).value == 78u));
assert((Packed<uint16_t>().apply<1,6>(9).value == 18u));

assert((Packed<uint16_t>().apply<1,7>(127).value == 254u));
assert((Packed<uint16_t>().apply<1,7>(0).value == 0u));
assert((Packed<uint16_t>().apply<1,7>(73).value == 146u));
assert((Packed<uint16_t>().apply<1,7>(14).value == 28u));
assert((Packed<uint16_t>().apply<1,7>(55).value == 110u));

assert((Packed<uint16_t>().apply<2,2>(1).value == 4u));
assert((Packed<uint16_t>().apply<2,2>(0).value == 0u));

assert((Packed<uint16_t>().apply<2,3>(3).value == 12u));
assert((Packed<uint16_t>().apply<2,3>(2).value == 8u));
assert((Packed<uint16_t>().apply<2,3>(0).value == 0u));

assert((Packed<uint16_t>().apply<2,4>(7).value == 28u));
assert((Packed<uint16_t>().apply<2,4>(5).value == 20u));
assert((Packed<uint16_t>().apply<2,4>(0).value == 0u));

assert((Packed<uint16_t>().apply<2,5>(15).value == 60u));
assert((Packed<uint16_t>().apply<2,5>(0).value == 0u));
assert((Packed<uint16_t>().apply<2,5>(10).value == 40u));
assert((Packed<uint16_t>().apply<2,5>(2).value == 8u));

assert((Packed<uint16_t>().apply<2,6>(31).value == 124u));
assert((Packed<uint16_t>().apply<2,6>(0).value == 0u));
assert((Packed<uint16_t>().apply<2,6>(28).value == 112u));
assert((Packed<uint16_t>().apply<2,6>(15).value == 60u));
assert((Packed<uint16_t>().apply<2,6>(30).value == 120u));

assert((Packed<uint16_t>().apply<2,7>(63).value == 252u));
assert((Packed<uint16_t>().apply<2,7>(0).value == 0u));
assert((Packed<uint16_t>().apply<2,7>(5).value == 20u));
assert((Packed<uint16_t>().apply<2,7>(9).value == 36u));
assert((Packed<uint16_t>().apply<2,7>(60).value == 240u));

assert((Packed<uint16_t>().apply<3,3>(0).value == 0u));
assert((Packed<uint16_t>().apply<3,3>(1).value == 8u));

assert((Packed<uint16_t>().apply<3,4>(3).value == 24u));
assert((Packed<uint16_t>().apply<3,4>(0).value == 0u));
assert((Packed<uint16_t>().apply<3,4>(2).value == 16u));
assert((Packed<uint16_t>().apply<3,4>(1).value == 8u));

assert((Packed<uint16_t>().apply<3,5>(0).value == 0u));
assert((Packed<uint16_t>().apply<3,5>(7).value == 56u));
assert((Packed<uint16_t>().apply<3,5>(6).value == 48u));

assert((Packed<uint16_t>().apply<3,6>(15).value == 120u));
assert((Packed<uint16_t>().apply<3,6>(0).value == 0u));
assert((Packed<uint16_t>().apply<3,6>(4).value == 32u));
assert((Packed<uint16_t>().apply<3,6>(13).value == 104u));

assert((Packed<uint16_t>().apply<3,7>(31).value == 248u));
assert((Packed<uint16_t>().apply<3,7>(0).value == 0u));
assert((Packed<uint16_t>().apply<3,7>(11).value == 88u));
assert((Packed<uint16_t>().apply<3,7>(4).value == 32u));
assert((Packed<uint16_t>().apply<3,7>(12).value == 96u));

assert((Packed<uint16_t>().apply<4,4>(0).value == 0u));
assert((Packed<uint16_t>().apply<4,4>(1).value == 16u));

assert((Packed<uint16_t>().apply<4,5>(3).value == 48u));
assert((Packed<uint16_t>().apply<4,5>(0).value == 0u));
assert((Packed<uint16_t>().apply<4,5>(2).value == 32u));

assert((Packed<uint16_t>().apply<4,6>(7).value == 112u));
assert((Packed<uint16_t>().apply<4,6>(0).value == 0u));
assert((Packed<uint16_t>().apply<4,6>(6).value == 96u));

assert((Packed<uint16_t>().apply<4,7>(15).value == 240u));
assert((Packed<uint16_t>().apply<4,7>(0).value == 0u));
assert((Packed<uint16_t>().apply<4,7>(8).value == 128u));
assert((Packed<uint16_t>().apply<4,7>(6).value == 96u));

assert((Packed<uint16_t>().apply<5,5>(1).value == 32u));
assert((Packed<uint16_t>().apply<5,5>(0).value == 0u));

assert((Packed<uint16_t>().apply<5,6>(3).value == 96u));
assert((Packed<uint16_t>().apply<5,6>(1).value == 32u));
assert((Packed<uint16_t>().apply<5,6>(0).value == 0u));

assert((Packed<uint16_t>().apply<5,7>(7).value == 224u));
assert((Packed<uint16_t>().apply<5,7>(4).value == 128u));
assert((Packed<uint16_t>().apply<5,7>(0).value == 0u));

assert((Packed<uint16_t>().apply<6,6>(0).value == 0u));
assert((Packed<uint16_t>().apply<6,6>(1).value == 64u));

assert((Packed<uint16_t>().apply<6,7>(0).value == 0u));
assert((Packed<uint16_t>().apply<6,7>(2).value == 128u));
assert((Packed<uint16_t>().apply<6,7>(3).value == 192u));

assert((Packed<uint16_t>().apply<7,7>(0).value == 0u));
assert((Packed<uint16_t>().apply<7,7>(1).value == 128u));

assert((Packed<uint16_t>().apply<8,8>(1).value == 256u));
assert((Packed<uint16_t>().apply<8,8>(0).value == 0u));

assert((Packed<uint16_t>().apply<8,9>(0).value == 0u));
assert((Packed<uint16_t>().apply<8,9>(3).value == 768u));

assert((Packed<uint16_t>().apply<8,10>(7).value == 1792u));
assert((Packed<uint16_t>().apply<8,10>(0).value == 0u));
assert((Packed<uint16_t>().apply<8,10>(2).value == 512u));
assert((Packed<uint16_t>().apply<8,10>(6).value == 1536u));
assert((Packed<uint16_t>().apply<8,10>(1).value == 256u));

assert((Packed<uint16_t>().apply<8,11>(0).value == 0u));
assert((Packed<uint16_t>().apply<8,11>(15).value == 3840u));
assert((Packed<uint16_t>().apply<8,11>(10).value == 2560u));
assert((Packed<uint16_t>().apply<8,11>(3).value == 768u));

assert((Packed<uint16_t>().apply<8,12>(31).value == 7936u));
assert((Packed<uint16_t>().apply<8,12>(0).value == 0u));
assert((Packed<uint16_t>().apply<8,12>(24).value == 6144u));
assert((Packed<uint16_t>().apply<8,12>(2).value == 512u));
assert((Packed<uint16_t>().apply<8,12>(19).value == 4864u));

assert((Packed<uint16_t>().apply<8,13>(63).value == 16128u));
assert((Packed<uint16_t>().apply<8,13>(0).value == 0u));
assert((Packed<uint16_t>().apply<8,13>(26).value == 6656u));
assert((Packed<uint16_t>().apply<8,13>(52).value == 13312u));
assert((Packed<uint16_t>().apply<8,13>(55).value == 14080u));

assert((Packed<uint16_t>().apply<8,14>(127).value == 32512u));
assert((Packed<uint16_t>().apply<8,14>(0).value == 0u));
assert((Packed<uint16_t>().apply<8,14>(88).value == 22528u));
assert((Packed<uint16_t>().apply<8,14>(34).value == 8704u));
assert((Packed<uint16_t>().apply<8,14>(101).value == 25856u));

assert((Packed<uint16_t>().apply<8,15>(255).value == 65280u));
assert((Packed<uint16_t>().apply<8,15>(0).value == 0u));
assert((Packed<uint16_t>().apply<8,15>(73).value == 18688u));
assert((Packed<uint16_t>().apply<8,15>(13).value == 3328u));
assert((Packed<uint16_t>().apply<8,15>(250).value == 64000u));

assert((Packed<uint16_t>().apply<9,9>(0).value == 0u));
assert((Packed<uint16_t>().apply<9,9>(1).value == 512u));

assert((Packed<uint16_t>().apply<9,10>(0).value == 0u));
assert((Packed<uint16_t>().apply<9,10>(3).value == 1536u));

assert((Packed<uint16_t>().apply<9,11>(7).value == 3584u));
assert((Packed<uint16_t>().apply<9,11>(1).value == 512u));
assert((Packed<uint16_t>().apply<9,11>(0).value == 0u));

assert((Packed<uint16_t>().apply<9,12>(15).value == 7680u));
assert((Packed<uint16_t>().apply<9,12>(0).value == 0u));
assert((Packed<uint16_t>().apply<9,12>(2).value == 1024u));
assert((Packed<uint16_t>().apply<9,12>(6).value == 3072u));
assert((Packed<uint16_t>().apply<9,12>(1).value == 512u));

assert((Packed<uint16_t>().apply<9,13>(0).value == 0u));
assert((Packed<uint16_t>().apply<9,13>(17).value == 8704u));
assert((Packed<uint16_t>().apply<9,13>(31).value == 15872u));
assert((Packed<uint16_t>().apply<9,13>(10).value == 5120u));

assert((Packed<uint16_t>().apply<9,14>(63).value == 32256u));
assert((Packed<uint16_t>().apply<9,14>(0).value == 0u));
assert((Packed<uint16_t>().apply<9,14>(57).value == 29184u));
assert((Packed<uint16_t>().apply<9,14>(7).value == 3584u));

assert((Packed<uint16_t>().apply<9,15>(127).value == 65024u));
assert((Packed<uint16_t>().apply<9,15>(0).value == 0u));
assert((Packed<uint16_t>().apply<9,15>(110).value == 56320u));
assert((Packed<uint16_t>().apply<9,15>(39).value == 19968u));
assert((Packed<uint16_t>().apply<9,15>(52).value == 26624u));

assert((Packed<uint16_t>().apply<10,10>(0).value == 0u));
assert((Packed<uint16_t>().apply<10,10>(1).value == 1024u));

assert((Packed<uint16_t>().apply<10,11>(0).value == 0u));
assert((Packed<uint16_t>().apply<10,11>(3).value == 3072u));

assert((Packed<uint16_t>().apply<10,12>(7).value == 7168u));
assert((Packed<uint16_t>().apply<10,12>(0).value == 0u));
assert((Packed<uint16_t>().apply<10,12>(5).value == 5120u));
assert((Packed<uint16_t>().apply<10,12>(3).value == 3072u));

assert((Packed<uint16_t>().apply<10,13>(15).value == 15360u));
assert((Packed<uint16_t>().apply<10,13>(0).value == 0u));
assert((Packed<uint16_t>().apply<10,13>(1).value == 1024u));
assert((Packed<uint16_t>().apply<10,13>(9).value == 9216u));

assert((Packed<uint16_t>().apply<10,14>(31).value == 31744u));
assert((Packed<uint16_t>().apply<10,14>(0).value == 0u));
assert((Packed<uint16_t>().apply<10,14>(30).value == 30720u));
assert((Packed<uint16_t>().apply<10,14>(25).value == 25600u));
assert((Packed<uint16_t>().apply<10,14>(7).value == 7168u));

assert((Packed<uint16_t>().apply<10,15>(63).value == 64512u));
assert((Packed<uint16_t>().apply<10,15>(0).value == 0u));
assert((Packed<uint16_t>().apply<10,15>(49).value == 50176u));
assert((Packed<uint16_t>().apply<10,15>(4).value == 4096u));
assert((Packed<uint16_t>().apply<10,15>(35).value == 35840u));

assert((Packed<uint16_t>().apply<11,11>(0).value == 0u));
assert((Packed<uint16_t>().apply<11,11>(1).value == 2048u));

assert((Packed<uint16_t>().apply<11,12>(3).value == 6144u));
assert((Packed<uint16_t>().apply<11,12>(2).value == 4096u));
assert((Packed<uint16_t>().apply<11,12>(0).value == 0u));

assert((Packed<uint16_t>().apply<11,13>(0).value == 0u));
assert((Packed<uint16_t>().apply<11,13>(7).value == 14336u));
assert((Packed<uint16_t>().apply<11,13>(3).value == 6144u));
assert((Packed<uint16_t>().apply<11,13>(2).value == 4096u));

assert((Packed<uint16_t>().apply<11,14>(0).value == 0u));
assert((Packed<uint16_t>().apply<11,14>(15).value == 30720u));
assert((Packed<uint16_t>().apply<11,14>(14).value == 28672u));

assert((Packed<uint16_t>().apply<11,15>(31).value == 63488u));
assert((Packed<uint16_t>().apply<11,15>(0).value == 0u));
assert((Packed<uint16_t>().apply<11,15>(22).value == 45056u));
assert((Packed<uint16_t>().apply<11,15>(28).value == 57344u));

assert((Packed<uint16_t>().apply<12,12>(1).value == 4096u));
assert((Packed<uint16_t>().apply<12,12>(0).value == 0u));

assert((Packed<uint16_t>().apply<12,13>(0).value == 0u));
assert((Packed<uint16_t>().apply<12,13>(2).value == 8192u));
assert((Packed<uint16_t>().apply<12,13>(3).value == 12288u));

assert((Packed<uint16_t>().apply<12,14>(7).value == 28672u));
assert((Packed<uint16_t>().apply<12,14>(0).value == 0u));
assert((Packed<uint16_t>().apply<12,14>(3).value == 12288u));
assert((Packed<uint16_t>().apply<12,14>(2).value == 8192u));

assert((Packed<uint16_t>().apply<12,15>(15).value == 61440u));
assert((Packed<uint16_t>().apply<12,15>(0).value == 0u));
assert((Packed<uint16_t>().apply<12,15>(11).value == 45056u));
assert((Packed<uint16_t>().apply<12,15>(6).value == 24576u));
assert((Packed<uint16_t>().apply<12,15>(7).value == 28672u));

assert((Packed<uint16_t>().apply<13,13>(0).value == 0u));
assert((Packed<uint16_t>().apply<13,13>(1).value == 8192u));

assert((Packed<uint16_t>().apply<13,14>(3).value == 24576u));
assert((Packed<uint16_t>().apply<13,14>(0).value == 0u));

assert((Packed<uint16_t>().apply<13,15>(7).value == 57344u));
assert((Packed<uint16_t>().apply<13,15>(0).value == 0u));
assert((Packed<uint16_t>().apply<13,15>(4).value == 32768u));
assert((Packed<uint16_t>().apply<13,15>(3).value == 24576u));
assert((Packed<uint16_t>().apply<13,15>(6).value == 49152u));

assert((Packed<uint16_t>().apply<14,14>(1).value == 16384u));
assert((Packed<uint16_t>().apply<14,14>(0).value == 0u));

assert((Packed<uint16_t>().apply<14,15>(3).value == 49152u));
assert((Packed<uint16_t>().apply<14,15>(0).value == 0u));
assert((Packed<uint16_t>().apply<14,15>(1).value == 16384u));
assert((Packed<uint16_t>().apply<14,15>(2).value == 32768u));

assert((Packed<uint16_t>().apply<15,15>(1).value == 32768u));
assert((Packed<uint16_t>().apply<15,15>(0).value == 0u));

assert((Packed<uint16_t>().apply<1,8>(255).value == 510u));
assert((Packed<uint16_t>().apply<1,8>(0).value == 0u));
assert((Packed<uint16_t>().apply<1,8>(65).value == 130u));
assert((Packed<uint16_t>().apply<1,8>(7).value == 14u));
assert((Packed<uint16_t>().apply<1,8>(167).value == 334u));

assert((Packed<uint16_t>().apply<1,9>(511).value == 1022u));
assert((Packed<uint16_t>().apply<1,9>(0).value == 0u));
assert((Packed<uint16_t>().apply<1,9>(111).value == 222u));
assert((Packed<uint16_t>().apply<1,9>(33).value == 66u));
assert((Packed<uint16_t>().apply<1,9>(396).value == 792u));

assert((Packed<uint16_t>().apply<1,10>(1023).value == 2046u));
assert((Packed<uint16_t>().apply<1,10>(0).value == 0u));
assert((Packed<uint16_t>().apply<1,10>(833).value == 1666u));
assert((Packed<uint16_t>().apply<1,10>(697).value == 1394u));
assert((Packed<uint16_t>().apply<1,10>(87).value == 174u));

assert((Packed<uint16_t>().apply<1,11>(2047).value == 4094u));
assert((Packed<uint16_t>().apply<1,11>(0).value == 0u));
assert((Packed<uint16_t>().apply<1,11>(490).value == 980u));
assert((Packed<uint16_t>().apply<1,11>(1724).value == 3448u));
assert((Packed<uint16_t>().apply<1,11>(606).value == 1212u));

assert((Packed<uint16_t>().apply<1,12>(4095).value == 8190u));
assert((Packed<uint16_t>().apply<1,12>(0).value == 0u));
assert((Packed<uint16_t>().apply<1,12>(675).value == 1350u));
assert((Packed<uint16_t>().apply<1,12>(3322).value == 6644u));
assert((Packed<uint16_t>().apply<1,12>(3040).value == 6080u));

assert((Packed<uint16_t>().apply<1,13>(8191).value == 16382u));
assert((Packed<uint16_t>().apply<1,13>(0).value == 0u));
assert((Packed<uint16_t>().apply<1,13>(2355).value == 4710u));
assert((Packed<uint16_t>().apply<1,13>(8184).value == 16368u));
assert((Packed<uint16_t>().apply<1,13>(3927).value == 7854u));

assert((Packed<uint16_t>().apply<1,14>(16383).value == 32766u));
assert((Packed<uint16_t>().apply<1,14>(0).value == 0u));
assert((Packed<uint16_t>().apply<1,14>(3782).value == 7564u));
assert((Packed<uint16_t>().apply<1,14>(4619).value == 9238u));
assert((Packed<uint16_t>().apply<1,14>(10080).value == 20160u));

assert((Packed<uint16_t>().apply<1,15>(32767).value == 65534u));
assert((Packed<uint16_t>().apply<1,15>(0).value == 0u));
assert((Packed<uint16_t>().apply<1,15>(22964).value == 45928u));
assert((Packed<uint16_t>().apply<1,15>(574).value == 1148u));
assert((Packed<uint16_t>().apply<1,15>(10342).value == 20684u));

assert((Packed<uint16_t>().apply<2,8>(127).value == 508u));
assert((Packed<uint16_t>().apply<2,8>(0).value == 0u));
assert((Packed<uint16_t>().apply<2,8>(123).value == 492u));
assert((Packed<uint16_t>().apply<2,8>(74).value == 296u));
assert((Packed<uint16_t>().apply<2,8>(86).value == 344u));

assert((Packed<uint16_t>().apply<2,9>(255).value == 1020u));
assert((Packed<uint16_t>().apply<2,9>(0).value == 0u));
assert((Packed<uint16_t>().apply<2,9>(6).value == 24u));
assert((Packed<uint16_t>().apply<2,9>(116).value == 464u));
assert((Packed<uint16_t>().apply<2,9>(220).value == 880u));

assert((Packed<uint16_t>().apply<2,10>(511).value == 2044u));
assert((Packed<uint16_t>().apply<2,10>(0).value == 0u));
assert((Packed<uint16_t>().apply<2,10>(58).value == 232u));
assert((Packed<uint16_t>().apply<2,10>(418).value == 1672u));
assert((Packed<uint16_t>().apply<2,10>(17).value == 68u));

assert((Packed<uint16_t>().apply<2,11>(1023).value == 4092u));
assert((Packed<uint16_t>().apply<2,11>(0).value == 0u));
assert((Packed<uint16_t>().apply<2,11>(622).value == 2488u));
assert((Packed<uint16_t>().apply<2,11>(839).value == 3356u));
assert((Packed<uint16_t>().apply<2,11>(143).value == 572u));

assert((Packed<uint16_t>().apply<2,12>(2047).value == 8188u));
assert((Packed<uint16_t>().apply<2,12>(0).value == 0u));
assert((Packed<uint16_t>().apply<2,12>(1338).value == 5352u));
assert((Packed<uint16_t>().apply<2,12>(1675).value == 6700u));
assert((Packed<uint16_t>().apply<2,12>(1715).value == 6860u));

assert((Packed<uint16_t>().apply<2,13>(4095).value == 16380u));
assert((Packed<uint16_t>().apply<2,13>(0).value == 0u));
assert((Packed<uint16_t>().apply<2,13>(2698).value == 10792u));
assert((Packed<uint16_t>().apply<2,13>(3212).value == 12848u));
assert((Packed<uint16_t>().apply<2,13>(666).value == 2664u));

assert((Packed<uint16_t>().apply<2,14>(8191).value == 32764u));
assert((Packed<uint16_t>().apply<2,14>(0).value == 0u));
assert((Packed<uint16_t>().apply<2,14>(3754).value == 15016u));
assert((Packed<uint16_t>().apply<2,14>(7617).value == 30468u));
assert((Packed<uint16_t>().apply<2,14>(2166).value == 8664u));

assert((Packed<uint16_t>().apply<2,15>(16383).value == 65532u));
assert((Packed<uint16_t>().apply<2,15>(0).value == 0u));
assert((Packed<uint16_t>().apply<2,15>(7201).value == 28804u));
assert((Packed<uint16_t>().apply<2,15>(2212).value == 8848u));
assert((Packed<uint16_t>().apply<2,15>(877).value == 3508u));

assert((Packed<uint16_t>().apply<3,8>(63).value == 504u));
assert((Packed<uint16_t>().apply<3,8>(0).value == 0u));
assert((Packed<uint16_t>().apply<3,8>(52).value == 416u));
assert((Packed<uint16_t>().apply<3,8>(33).value == 264u));
assert((Packed<uint16_t>().apply<3,8>(59).value == 472u));

assert((Packed<uint16_t>().apply<3,9>(127).value == 1016u));
assert((Packed<uint16_t>().apply<3,9>(0).value == 0u));
assert((Packed<uint16_t>().apply<3,9>(50).value == 400u));
assert((Packed<uint16_t>().apply<3,9>(48).value == 384u));
assert((Packed<uint16_t>().apply<3,9>(60).value == 480u));

assert((Packed<uint16_t>().apply<3,10>(255).value == 2040u));
assert((Packed<uint16_t>().apply<3,10>(0).value == 0u));
assert((Packed<uint16_t>().apply<3,10>(93).value == 744u));
assert((Packed<uint16_t>().apply<3,10>(39).value == 312u));
assert((Packed<uint16_t>().apply<3,10>(18).value == 144u));

assert((Packed<uint16_t>().apply<3,11>(511).value == 4088u));
assert((Packed<uint16_t>().apply<3,11>(0).value == 0u));
assert((Packed<uint16_t>().apply<3,11>(139).value == 1112u));
assert((Packed<uint16_t>().apply<3,11>(502).value == 4016u));
assert((Packed<uint16_t>().apply<3,11>(201).value == 1608u));

assert((Packed<uint16_t>().apply<3,12>(1023).value == 8184u));
assert((Packed<uint16_t>().apply<3,12>(0).value == 0u));
assert((Packed<uint16_t>().apply<3,12>(256).value == 2048u));
assert((Packed<uint16_t>().apply<3,12>(223).value == 1784u));
assert((Packed<uint16_t>().apply<3,12>(35).value == 280u));

assert((Packed<uint16_t>().apply<3,13>(2047).value == 16376u));
assert((Packed<uint16_t>().apply<3,13>(0).value == 0u));
assert((Packed<uint16_t>().apply<3,13>(743).value == 5944u));
assert((Packed<uint16_t>().apply<3,13>(402).value == 3216u));
assert((Packed<uint16_t>().apply<3,13>(16).value == 128u));

assert((Packed<uint16_t>().apply<3,14>(4095).value == 32760u));
assert((Packed<uint16_t>().apply<3,14>(0).value == 0u));
assert((Packed<uint16_t>().apply<3,14>(3207).value == 25656u));
assert((Packed<uint16_t>().apply<3,14>(245).value == 1960u));
assert((Packed<uint16_t>().apply<3,14>(2148).value == 17184u));

assert((Packed<uint16_t>().apply<3,15>(8191).value == 65528u));
assert((Packed<uint16_t>().apply<3,15>(0).value == 0u));
assert((Packed<uint16_t>().apply<3,15>(2486).value == 19888u));
assert((Packed<uint16_t>().apply<3,15>(7110).value == 56880u));
assert((Packed<uint16_t>().apply<3,15>(5681).value == 45448u));

assert((Packed<uint16_t>().apply<4,8>(31).value == 496u));
assert((Packed<uint16_t>().apply<4,8>(0).value == 0u));
assert((Packed<uint16_t>().apply<4,8>(21).value == 336u));
assert((Packed<uint16_t>().apply<4,8>(10).value == 160u));
assert((Packed<uint16_t>().apply<4,8>(7).value == 112u));

assert((Packed<uint16_t>().apply<4,9>(63).value == 1008u));
assert((Packed<uint16_t>().apply<4,9>(0).value == 0u));
assert((Packed<uint16_t>().apply<4,9>(62).value == 992u));
assert((Packed<uint16_t>().apply<4,9>(7).value == 112u));
assert((Packed<uint16_t>().apply<4,9>(13).value == 208u));

assert((Packed<uint16_t>().apply<4,10>(127).value == 2032u));
assert((Packed<uint16_t>().apply<4,10>(0).value == 0u));
assert((Packed<uint16_t>().apply<4,10>(72).value == 1152u));
assert((Packed<uint16_t>().apply<4,10>(126).value == 2016u));

assert((Packed<uint16_t>().apply<4,11>(255).value == 4080u));
assert((Packed<uint16_t>().apply<4,11>(0).value == 0u));
assert((Packed<uint16_t>().apply<4,11>(226).value == 3616u));
assert((Packed<uint16_t>().apply<4,11>(7).value == 112u));
assert((Packed<uint16_t>().apply<4,11>(166).value == 2656u));

assert((Packed<uint16_t>().apply<4,12>(511).value == 8176u));
assert((Packed<uint16_t>().apply<4,12>(0).value == 0u));
assert((Packed<uint16_t>().apply<4,12>(429).value == 6864u));
assert((Packed<uint16_t>().apply<4,12>(191).value == 3056u));
assert((Packed<uint16_t>().apply<4,12>(235).value == 3760u));

assert((Packed<uint16_t>().apply<4,13>(1023).value == 16368u));
assert((Packed<uint16_t>().apply<4,13>(0).value == 0u));
assert((Packed<uint16_t>().apply<4,13>(562).value == 8992u));
assert((Packed<uint16_t>().apply<4,13>(303).value == 4848u));
assert((Packed<uint16_t>().apply<4,13>(201).value == 3216u));

assert((Packed<uint16_t>().apply<4,14>(2047).value == 32752u));
assert((Packed<uint16_t>().apply<4,14>(0).value == 0u));
assert((Packed<uint16_t>().apply<4,14>(1062).value == 16992u));
assert((Packed<uint16_t>().apply<4,14>(1874).value == 29984u));
assert((Packed<uint16_t>().apply<4,14>(521).value == 8336u));

assert((Packed<uint16_t>().apply<4,15>(4095).value == 65520u));
assert((Packed<uint16_t>().apply<4,15>(0).value == 0u));
assert((Packed<uint16_t>().apply<4,15>(39).value == 624u));
assert((Packed<uint16_t>().apply<4,15>(2367).value == 37872u));
assert((Packed<uint16_t>().apply<4,15>(614).value == 9824u));

assert((Packed<uint16_t>().apply<5,8>(15).value == 480u));
assert((Packed<uint16_t>().apply<5,8>(0).value == 0u));
assert((Packed<uint16_t>().apply<5,8>(11).value == 352u));
assert((Packed<uint16_t>().apply<5,8>(12).value == 384u));

assert((Packed<uint16_t>().apply<5,9>(31).value == 992u));
assert((Packed<uint16_t>().apply<5,9>(0).value == 0u));
assert((Packed<uint16_t>().apply<5,9>(17).value == 544u));
assert((Packed<uint16_t>().apply<5,9>(22).value == 704u));
assert((Packed<uint16_t>().apply<5,9>(19).value == 608u));

assert((Packed<uint16_t>().apply<5,10>(63).value == 2016u));
assert((Packed<uint16_t>().apply<5,10>(0).value == 0u));
assert((Packed<uint16_t>().apply<5,10>(54).value == 1728u));
assert((Packed<uint16_t>().apply<5,10>(55).value == 1760u));
assert((Packed<uint16_t>().apply<5,10>(21).value == 672u));

assert((Packed<uint16_t>().apply<5,11>(127).value == 4064u));
assert((Packed<uint16_t>().apply<5,11>(117).value == 3744u));
assert((Packed<uint16_t>().apply<5,11>(34).value == 1088u));
assert((Packed<uint16_t>().apply<5,11>(0).value == 0u));

assert((Packed<uint16_t>().apply<5,12>(255).value == 8160u));
assert((Packed<uint16_t>().apply<5,12>(0).value == 0u));
assert((Packed<uint16_t>().apply<5,12>(124).value == 3968u));
assert((Packed<uint16_t>().apply<5,12>(150).value == 4800u));
assert((Packed<uint16_t>().apply<5,12>(38).value == 1216u));

assert((Packed<uint16_t>().apply<5,13>(511).value == 16352u));
assert((Packed<uint16_t>().apply<5,13>(0).value == 0u));
assert((Packed<uint16_t>().apply<5,13>(90).value == 2880u));
assert((Packed<uint16_t>().apply<5,13>(423).value == 13536u));
assert((Packed<uint16_t>().apply<5,13>(390).value == 12480u));

assert((Packed<uint16_t>().apply<5,14>(1023).value == 32736u));
assert((Packed<uint16_t>().apply<5,14>(0).value == 0u));
assert((Packed<uint16_t>().apply<5,14>(675).value == 21600u));
assert((Packed<uint16_t>().apply<5,14>(418).value == 13376u));
assert((Packed<uint16_t>().apply<5,14>(632).value == 20224u));

assert((Packed<uint16_t>().apply<5,15>(2047).value == 65504u));
assert((Packed<uint16_t>().apply<5,15>(0).value == 0u));
assert((Packed<uint16_t>().apply<5,15>(1678).value == 53696u));
assert((Packed<uint16_t>().apply<5,15>(1087).value == 34784u));
assert((Packed<uint16_t>().apply<5,15>(1693).value == 54176u));

assert((Packed<uint16_t>().apply<6,8>(7).value == 448u));
assert((Packed<uint16_t>().apply<6,8>(3).value == 192u));
assert((Packed<uint16_t>().apply<6,8>(6).value == 384u));
assert((Packed<uint16_t>().apply<6,8>(0).value == 0u));

assert((Packed<uint16_t>().apply<6,9>(15).value == 960u));
assert((Packed<uint16_t>().apply<6,9>(0).value == 0u));
assert((Packed<uint16_t>().apply<6,9>(12).value == 768u));
assert((Packed<uint16_t>().apply<6,9>(14).value == 896u));
assert((Packed<uint16_t>().apply<6,9>(13).value == 832u));

assert((Packed<uint16_t>().apply<6,10>(31).value == 1984u));
assert((Packed<uint16_t>().apply<6,10>(0).value == 0u));
assert((Packed<uint16_t>().apply<6,10>(14).value == 896u));
assert((Packed<uint16_t>().apply<6,10>(17).value == 1088u));
assert((Packed<uint16_t>().apply<6,10>(24).value == 1536u));

assert((Packed<uint16_t>().apply<6,11>(63).value == 4032u));
assert((Packed<uint16_t>().apply<6,11>(0).value == 0u));
assert((Packed<uint16_t>().apply<6,11>(45).value == 2880u));
assert((Packed<uint16_t>().apply<6,11>(24).value == 1536u));
assert((Packed<uint16_t>().apply<6,11>(28).value == 1792u));

assert((Packed<uint16_t>().apply<6,12>(127).value == 8128u));
assert((Packed<uint16_t>().apply<6,12>(0).value == 0u));
assert((Packed<uint16_t>().apply<6,12>(77).value == 4928u));
assert((Packed<uint16_t>().apply<6,12>(118).value == 7552u));
assert((Packed<uint16_t>().apply<6,12>(103).value == 6592u));

assert((Packed<uint16_t>().apply<6,13>(255).value == 16320u));
assert((Packed<uint16_t>().apply<6,13>(0).value == 0u));
assert((Packed<uint16_t>().apply<6,13>(159).value == 10176u));
assert((Packed<uint16_t>().apply<6,13>(48).value == 3072u));
assert((Packed<uint16_t>().apply<6,13>(42).value == 2688u));

assert((Packed<uint16_t>().apply<6,14>(511).value == 32704u));
assert((Packed<uint16_t>().apply<6,14>(0).value == 0u));
assert((Packed<uint16_t>().apply<6,14>(6).value == 384u));
assert((Packed<uint16_t>().apply<6,14>(446).value == 28544u));
assert((Packed<uint16_t>().apply<6,14>(30).value == 1920u));

assert((Packed<uint16_t>().apply<6,15>(1023).value == 65472u));
assert((Packed<uint16_t>().apply<6,15>(0).value == 0u));
assert((Packed<uint16_t>().apply<6,15>(479).value == 30656u));
assert((Packed<uint16_t>().apply<6,15>(326).value == 20864u));
assert((Packed<uint16_t>().apply<6,15>(483).value == 30912u));

assert((Packed<uint16_t>().apply<7,8>(3).value == 384u));
assert((Packed<uint16_t>().apply<7,8>(1).value == 128u));
assert((Packed<uint16_t>().apply<7,8>(0).value == 0u));

assert((Packed<uint16_t>().apply<7,9>(7).value == 896u));
assert((Packed<uint16_t>().apply<7,9>(2).value == 256u));
assert((Packed<uint16_t>().apply<7,9>(0).value == 0u));

assert((Packed<uint16_t>().apply<7,10>(0).value == 0u));
assert((Packed<uint16_t>().apply<7,10>(2).value == 256u));
assert((Packed<uint16_t>().apply<7,10>(15).value == 1920u));
assert((Packed<uint16_t>().apply<7,10>(13).value == 1664u));

assert((Packed<uint16_t>().apply<7,11>(31).value == 3968u));
assert((Packed<uint16_t>().apply<7,11>(0).value == 0u));
assert((Packed<uint16_t>().apply<7,11>(8).value == 1024u));
assert((Packed<uint16_t>().apply<7,11>(14).value == 1792u));
assert((Packed<uint16_t>().apply<7,11>(15).value == 1920u));

assert((Packed<uint16_t>().apply<7,12>(63).value == 8064u));
assert((Packed<uint16_t>().apply<7,12>(0).value == 0u));
assert((Packed<uint16_t>().apply<7,12>(19).value == 2432u));
assert((Packed<uint16_t>().apply<7,12>(44).value == 5632u));
assert((Packed<uint16_t>().apply<7,12>(22).value == 2816u));

assert((Packed<uint16_t>().apply<7,13>(127).value == 16256u));
assert((Packed<uint16_t>().apply<7,13>(0).value == 0u));
assert((Packed<uint16_t>().apply<7,13>(55).value == 7040u));
assert((Packed<uint16_t>().apply<7,13>(76).value == 9728u));
assert((Packed<uint16_t>().apply<7,13>(1).value == 128u));

assert((Packed<uint16_t>().apply<7,14>(255).value == 32640u));
assert((Packed<uint16_t>().apply<7,14>(0).value == 0u));
assert((Packed<uint16_t>().apply<7,14>(224).value == 28672u));
assert((Packed<uint16_t>().apply<7,14>(195).value == 24960u));
assert((Packed<uint16_t>().apply<7,14>(59).value == 7552u));

assert((Packed<uint16_t>().apply<7,15>(511).value == 65408u));
assert((Packed<uint16_t>().apply<7,15>(0).value == 0u));
assert((Packed<uint16_t>().apply<7,15>(434).value == 55552u));
assert((Packed<uint16_t>().apply<7,15>(91).value == 11648u));
assert((Packed<uint16_t>().apply<7,15>(407).value == 52096u));

assert((Packed<uint32_t>().apply<0,7>(255).value == 255u));
assert((Packed<uint32_t>().apply<0,7>(0).value == 0u));
assert((Packed<uint32_t>().apply<0,7>(124).value == 124u));
assert((Packed<uint32_t>().apply<0,7>(35).value == 35u));
assert((Packed<uint32_t>().apply<0,7>(251).value == 251u));

assert((Packed<uint32_t>().apply<8,15>(255).value == 65280u));
assert((Packed<uint32_t>().apply<8,15>(0).value == 0u));
assert((Packed<uint32_t>().apply<8,15>(20).value == 5120u));
assert((Packed<uint32_t>().apply<8,15>(166).value == 42496u));
assert((Packed<uint32_t>().apply<8,15>(243).value == 62208u));

assert((Packed<uint32_t>().apply<16,23>(255).value == 16711680u));
assert((Packed<uint32_t>().apply<16,23>(0).value == 0u));
assert((Packed<uint32_t>().apply<16,23>(52).value == 3407872u));
assert((Packed<uint32_t>().apply<16,23>(1).value == 65536u));
assert((Packed<uint32_t>().apply<16,23>(142).value == 9306112u));

assert((Packed<uint32_t>().apply<24,31>(255).value == 4278190080u));
assert((Packed<uint32_t>().apply<24,31>(0).value == 0u));
assert((Packed<uint32_t>().apply<24,31>(182).value == 3053453312u));
assert((Packed<uint32_t>().apply<24,31>(12).value == 201326592u));
assert((Packed<uint32_t>().apply<24,31>(62).value == 1040187392u));

assert((Packed<uint32_t>().apply<0,0>(0).value == 0u));
assert((Packed<uint32_t>().apply<0,0>(1).value == 1u));

assert((Packed<uint32_t>().apply<0,1>(3).value == 3u));
assert((Packed<uint32_t>().apply<0,1>(2).value == 2u));
assert((Packed<uint32_t>().apply<0,1>(0).value == 0u));

assert((Packed<uint32_t>().apply<0,2>(7).value == 7u));
assert((Packed<uint32_t>().apply<0,2>(0).value == 0u));
assert((Packed<uint32_t>().apply<0,2>(6).value == 6u));
assert((Packed<uint32_t>().apply<0,2>(3).value == 3u));

assert((Packed<uint32_t>().apply<0,3>(15).value == 15u));
assert((Packed<uint32_t>().apply<0,3>(0).value == 0u));
assert((Packed<uint32_t>().apply<0,3>(2).value == 2u));
assert((Packed<uint32_t>().apply<0,3>(13).value == 13u));
assert((Packed<uint32_t>().apply<0,3>(6).value == 6u));

assert((Packed<uint32_t>().apply<0,4>(31).value == 31u));
assert((Packed<uint32_t>().apply<0,4>(0).value == 0u));
assert((Packed<uint32_t>().apply<0,4>(17).value == 17u));
assert((Packed<uint32_t>().apply<0,4>(23).value == 23u));
assert((Packed<uint32_t>().apply<0,4>(27).value == 27u));

assert((Packed<uint32_t>().apply<0,5>(63).value == 63u));
assert((Packed<uint32_t>().apply<0,5>(0).value == 0u));
assert((Packed<uint32_t>().apply<0,5>(32).value == 32u));
assert((Packed<uint32_t>().apply<0,5>(6).value == 6u));
assert((Packed<uint32_t>().apply<0,5>(44).value == 44u));

assert((Packed<uint32_t>().apply<0,6>(127).value == 127u));
assert((Packed<uint32_t>().apply<0,6>(0).value == 0u));
assert((Packed<uint32_t>().apply<0,6>(48).value == 48u));
assert((Packed<uint32_t>().apply<0,6>(89).value == 89u));
assert((Packed<uint32_t>().apply<0,6>(75).value == 75u));

assert((Packed<uint32_t>().apply<0,7>(255).value == 255u));
assert((Packed<uint32_t>().apply<0,7>(0).value == 0u));
assert((Packed<uint32_t>().apply<0,7>(248).value == 248u));
assert((Packed<uint32_t>().apply<0,7>(27).value == 27u));
assert((Packed<uint32_t>().apply<0,7>(84).value == 84u));

assert((Packed<uint32_t>().apply<1,1>(0).value == 0u));
assert((Packed<uint32_t>().apply<1,1>(1).value == 2u));

assert((Packed<uint32_t>().apply<1,2>(0).value == 0u));
assert((Packed<uint32_t>().apply<1,2>(3).value == 6u));

assert((Packed<uint32_t>().apply<1,3>(7).value == 14u));
assert((Packed<uint32_t>().apply<1,3>(0).value == 0u));
assert((Packed<uint32_t>().apply<1,3>(2).value == 4u));
assert((Packed<uint32_t>().apply<1,3>(3).value == 6u));
assert((Packed<uint32_t>().apply<1,3>(4).value == 8u));

assert((Packed<uint32_t>().apply<1,4>(15).value == 30u));
assert((Packed<uint32_t>().apply<1,4>(0).value == 0u));
assert((Packed<uint32_t>().apply<1,4>(13).value == 26u));
assert((Packed<uint32_t>().apply<1,4>(10).value == 20u));
assert((Packed<uint32_t>().apply<1,4>(12).value == 24u));

assert((Packed<uint32_t>().apply<1,5>(31).value == 62u));
assert((Packed<uint32_t>().apply<1,5>(0).value == 0u));
assert((Packed<uint32_t>().apply<1,5>(11).value == 22u));
assert((Packed<uint32_t>().apply<1,5>(9).value == 18u));

assert((Packed<uint32_t>().apply<1,6>(63).value == 126u));
assert((Packed<uint32_t>().apply<1,6>(0).value == 0u));
assert((Packed<uint32_t>().apply<1,6>(41).value == 82u));
assert((Packed<uint32_t>().apply<1,6>(37).value == 74u));
assert((Packed<uint32_t>().apply<1,6>(6).value == 12u));

assert((Packed<uint32_t>().apply<1,7>(127).value == 254u));
assert((Packed<uint32_t>().apply<1,7>(0).value == 0u));
assert((Packed<uint32_t>().apply<1,7>(55).value == 110u));
assert((Packed<uint32_t>().apply<1,7>(87).value == 174u));
assert((Packed<uint32_t>().apply<1,7>(24).value == 48u));

assert((Packed<uint32_t>().apply<2,2>(0).value == 0u));
assert((Packed<uint32_t>().apply<2,2>(1).value == 4u));

assert((Packed<uint32_t>().apply<2,3>(3).value == 12u));
assert((Packed<uint32_t>().apply<2,3>(2).value == 8u));
assert((Packed<uint32_t>().apply<2,3>(0).value == 0u));

assert((Packed<uint32_t>().apply<2,4>(7).value == 28u));
assert((Packed<uint32_t>().apply<2,4>(0).value == 0u));
assert((Packed<uint32_t>().apply<2,4>(6).value == 24u));
assert((Packed<uint32_t>().apply<2,4>(3).value == 12u));

assert((Packed<uint32_t>().apply<2,5>(15).value == 60u));
assert((Packed<uint32_t>().apply<2,5>(0).value == 0u));
assert((Packed<uint32_t>().apply<2,5>(10).value == 40u));
assert((Packed<uint32_t>().apply<2,5>(6).value == 24u));
assert((Packed<uint32_t>().apply<2,5>(13).value == 52u));

assert((Packed<uint32_t>().apply<2,6>(31).value == 124u));
assert((Packed<uint32_t>().apply<2,6>(0).value == 0u));
assert((Packed<uint32_t>().apply<2,6>(10).value == 40u));
assert((Packed<uint32_t>().apply<2,6>(15).value == 60u));
assert((Packed<uint32_t>().apply<2,6>(1).value == 4u));

assert((Packed<uint32_t>().apply<2,7>(63).value == 252u));
assert((Packed<uint32_t>().apply<2,7>(0).value == 0u));
assert((Packed<uint32_t>().apply<2,7>(32).value == 128u));
assert((Packed<uint32_t>().apply<2,7>(28).value == 112u));
assert((Packed<uint32_t>().apply<2,7>(12).value == 48u));

assert((Packed<uint32_t>().apply<3,3>(1).value == 8u));
assert((Packed<uint32_t>().apply<3,3>(0).value == 0u));

assert((Packed<uint32_t>().apply<3,4>(0).value == 0u));
assert((Packed<uint32_t>().apply<3,4>(3).value == 24u));

assert((Packed<uint32_t>().apply<3,5>(7).value == 56u));
assert((Packed<uint32_t>().apply<3,5>(0).value == 0u));
assert((Packed<uint32_t>().apply<3,5>(4).value == 32u));
assert((Packed<uint32_t>().apply<3,5>(3).value == 24u));

assert((Packed<uint32_t>().apply<3,6>(0).value == 0u));
assert((Packed<uint32_t>().apply<3,6>(3).value == 24u));
assert((Packed<uint32_t>().apply<3,6>(8).value == 64u));
assert((Packed<uint32_t>().apply<3,6>(15).value == 120u));

assert((Packed<uint32_t>().apply<3,7>(31).value == 248u));
assert((Packed<uint32_t>().apply<3,7>(0).value == 0u));
assert((Packed<uint32_t>().apply<3,7>(1).value == 8u));
assert((Packed<uint32_t>().apply<3,7>(17).value == 136u));
assert((Packed<uint32_t>().apply<3,7>(30).value == 240u));

assert((Packed<uint32_t>().apply<4,4>(0).value == 0u));
assert((Packed<uint32_t>().apply<4,4>(1).value == 16u));

assert((Packed<uint32_t>().apply<4,5>(3).value == 48u));
assert((Packed<uint32_t>().apply<4,5>(1).value == 16u));
assert((Packed<uint32_t>().apply<4,5>(2).value == 32u));
assert((Packed<uint32_t>().apply<4,5>(0).value == 0u));

assert((Packed<uint32_t>().apply<4,6>(7).value == 112u));
assert((Packed<uint32_t>().apply<4,6>(0).value == 0u));
assert((Packed<uint32_t>().apply<4,6>(3).value == 48u));
assert((Packed<uint32_t>().apply<4,6>(6).value == 96u));

assert((Packed<uint32_t>().apply<4,7>(15).value == 240u));
assert((Packed<uint32_t>().apply<4,7>(0).value == 0u));
assert((Packed<uint32_t>().apply<4,7>(1).value == 16u));
assert((Packed<uint32_t>().apply<4,7>(13).value == 208u));

assert((Packed<uint32_t>().apply<5,5>(0).value == 0u));
assert((Packed<uint32_t>().apply<5,5>(1).value == 32u));

assert((Packed<uint32_t>().apply<5,6>(3).value == 96u));
assert((Packed<uint32_t>().apply<5,6>(0).value == 0u));

assert((Packed<uint32_t>().apply<5,7>(2).value == 64u));
assert((Packed<uint32_t>().apply<5,7>(0).value == 0u));
assert((Packed<uint32_t>().apply<5,7>(7).value == 224u));

assert((Packed<uint32_t>().apply<6,6>(0).value == 0u));
assert((Packed<uint32_t>().apply<6,6>(1).value == 64u));

assert((Packed<uint32_t>().apply<6,7>(0).value == 0u));
assert((Packed<uint32_t>().apply<6,7>(2).value == 128u));
assert((Packed<uint32_t>().apply<6,7>(3).value == 192u));

assert((Packed<uint32_t>().apply<7,7>(1).value == 128u));
assert((Packed<uint32_t>().apply<7,7>(0).value == 0u));

assert((Packed<uint32_t>().apply<8,8>(0).value == 0u));
assert((Packed<uint32_t>().apply<8,8>(1).value == 256u));

assert((Packed<uint32_t>().apply<8,9>(3).value == 768u));
assert((Packed<uint32_t>().apply<8,9>(2).value == 512u));
assert((Packed<uint32_t>().apply<8,9>(0).value == 0u));
assert((Packed<uint32_t>().apply<8,9>(1).value == 256u));

assert((Packed<uint32_t>().apply<8,10>(7).value == 1792u));
assert((Packed<uint32_t>().apply<8,10>(0).value == 0u));
assert((Packed<uint32_t>().apply<8,10>(5).value == 1280u));
assert((Packed<uint32_t>().apply<8,10>(6).value == 1536u));

assert((Packed<uint32_t>().apply<8,11>(15).value == 3840u));
assert((Packed<uint32_t>().apply<8,11>(0).value == 0u));
assert((Packed<uint32_t>().apply<8,11>(1).value == 256u));
assert((Packed<uint32_t>().apply<8,11>(9).value == 2304u));

assert((Packed<uint32_t>().apply<8,12>(31).value == 7936u));
assert((Packed<uint32_t>().apply<8,12>(0).value == 0u));
assert((Packed<uint32_t>().apply<8,12>(3).value == 768u));
assert((Packed<uint32_t>().apply<8,12>(22).value == 5632u));
assert((Packed<uint32_t>().apply<8,12>(6).value == 1536u));

assert((Packed<uint32_t>().apply<8,13>(63).value == 16128u));
assert((Packed<uint32_t>().apply<8,13>(0).value == 0u));
assert((Packed<uint32_t>().apply<8,13>(46).value == 11776u));
assert((Packed<uint32_t>().apply<8,13>(8).value == 2048u));
assert((Packed<uint32_t>().apply<8,13>(13).value == 3328u));

assert((Packed<uint32_t>().apply<8,14>(127).value == 32512u));
assert((Packed<uint32_t>().apply<8,14>(0).value == 0u));
assert((Packed<uint32_t>().apply<8,14>(90).value == 23040u));
assert((Packed<uint32_t>().apply<8,14>(61).value == 15616u));
assert((Packed<uint32_t>().apply<8,14>(64).value == 16384u));

assert((Packed<uint32_t>().apply<8,15>(255).value == 65280u));
assert((Packed<uint32_t>().apply<8,15>(0).value == 0u));
assert((Packed<uint32_t>().apply<8,15>(144).value == 36864u));
assert((Packed<uint32_t>().apply<8,15>(240).value == 61440u));
assert((Packed<uint32_t>().apply<8,15>(66).value == 16896u));

assert((Packed<uint32_t>().apply<9,9>(0).value == 0u));
assert((Packed<uint32_t>().apply<9,9>(1).value == 512u));

assert((Packed<uint32_t>().apply<9,10>(2).value == 1024u));
assert((Packed<uint32_t>().apply<9,10>(3).value == 1536u));
assert((Packed<uint32_t>().apply<9,10>(0).value == 0u));

assert((Packed<uint32_t>().apply<9,11>(0).value == 0u));
assert((Packed<uint32_t>().apply<9,11>(5).value == 2560u));
assert((Packed<uint32_t>().apply<9,11>(7).value == 3584u));
assert((Packed<uint32_t>().apply<9,11>(2).value == 1024u));

assert((Packed<uint32_t>().apply<9,12>(15).value == 7680u));
assert((Packed<uint32_t>().apply<9,12>(0).value == 0u));
assert((Packed<uint32_t>().apply<9,12>(6).value == 3072u));
assert((Packed<uint32_t>().apply<9,12>(13).value == 6656u));

assert((Packed<uint32_t>().apply<9,13>(31).value == 15872u));
assert((Packed<uint32_t>().apply<9,13>(8).value == 4096u));
assert((Packed<uint32_t>().apply<9,13>(0).value == 0u));
assert((Packed<uint32_t>().apply<9,13>(25).value == 12800u));

assert((Packed<uint32_t>().apply<9,14>(63).value == 32256u));
assert((Packed<uint32_t>().apply<9,14>(0).value == 0u));
assert((Packed<uint32_t>().apply<9,14>(17).value == 8704u));
assert((Packed<uint32_t>().apply<9,14>(25).value == 12800u));
assert((Packed<uint32_t>().apply<9,14>(14).value == 7168u));

assert((Packed<uint32_t>().apply<9,15>(127).value == 65024u));
assert((Packed<uint32_t>().apply<9,15>(0).value == 0u));
assert((Packed<uint32_t>().apply<9,15>(31).value == 15872u));
assert((Packed<uint32_t>().apply<9,15>(81).value == 41472u));

assert((Packed<uint32_t>().apply<10,10>(0).value == 0u));
assert((Packed<uint32_t>().apply<10,10>(1).value == 1024u));

assert((Packed<uint32_t>().apply<10,11>(3).value == 3072u));
assert((Packed<uint32_t>().apply<10,11>(0).value == 0u));
assert((Packed<uint32_t>().apply<10,11>(2).value == 2048u));

assert((Packed<uint32_t>().apply<10,12>(7).value == 7168u));
assert((Packed<uint32_t>().apply<10,12>(0).value == 0u));

assert((Packed<uint32_t>().apply<10,13>(15).value == 15360u));
assert((Packed<uint32_t>().apply<10,13>(0).value == 0u));
assert((Packed<uint32_t>().apply<10,13>(8).value == 8192u));
assert((Packed<uint32_t>().apply<10,13>(2).value == 2048u));

assert((Packed<uint32_t>().apply<10,14>(31).value == 31744u));
assert((Packed<uint32_t>().apply<10,14>(0).value == 0u));
assert((Packed<uint32_t>().apply<10,14>(30).value == 30720u));
assert((Packed<uint32_t>().apply<10,14>(15).value == 15360u));
assert((Packed<uint32_t>().apply<10,14>(14).value == 14336u));

assert((Packed<uint32_t>().apply<10,15>(63).value == 64512u));
assert((Packed<uint32_t>().apply<10,15>(0).value == 0u));
assert((Packed<uint32_t>().apply<10,15>(13).value == 13312u));
assert((Packed<uint32_t>().apply<10,15>(33).value == 33792u));
assert((Packed<uint32_t>().apply<10,15>(46).value == 47104u));

assert((Packed<uint32_t>().apply<11,11>(0).value == 0u));
assert((Packed<uint32_t>().apply<11,11>(1).value == 2048u));

assert((Packed<uint32_t>().apply<11,12>(1).value == 2048u));
assert((Packed<uint32_t>().apply<11,12>(0).value == 0u));
assert((Packed<uint32_t>().apply<11,12>(3).value == 6144u));

assert((Packed<uint32_t>().apply<11,13>(7).value == 14336u));
assert((Packed<uint32_t>().apply<11,13>(2).value == 4096u));
assert((Packed<uint32_t>().apply<11,13>(4).value == 8192u));
assert((Packed<uint32_t>().apply<11,13>(0).value == 0u));

assert((Packed<uint32_t>().apply<11,14>(15).value == 30720u));
assert((Packed<uint32_t>().apply<11,14>(0).value == 0u));
assert((Packed<uint32_t>().apply<11,14>(7).value == 14336u));
assert((Packed<uint32_t>().apply<11,14>(3).value == 6144u));
assert((Packed<uint32_t>().apply<11,14>(6).value == 12288u));

assert((Packed<uint32_t>().apply<11,15>(31).value == 63488u));
assert((Packed<uint32_t>().apply<11,15>(0).value == 0u));
assert((Packed<uint32_t>().apply<11,15>(2).value == 4096u));
assert((Packed<uint32_t>().apply<11,15>(5).value == 10240u));
assert((Packed<uint32_t>().apply<11,15>(24).value == 49152u));

assert((Packed<uint32_t>().apply<12,12>(0).value == 0u));
assert((Packed<uint32_t>().apply<12,12>(1).value == 4096u));

assert((Packed<uint32_t>().apply<12,13>(3).value == 12288u));
assert((Packed<uint32_t>().apply<12,13>(0).value == 0u));
assert((Packed<uint32_t>().apply<12,13>(2).value == 8192u));

assert((Packed<uint32_t>().apply<12,14>(0).value == 0u));
assert((Packed<uint32_t>().apply<12,14>(7).value == 28672u));
assert((Packed<uint32_t>().apply<12,14>(4).value == 16384u));

assert((Packed<uint32_t>().apply<12,15>(15).value == 61440u));
assert((Packed<uint32_t>().apply<12,15>(0).value == 0u));
assert((Packed<uint32_t>().apply<12,15>(14).value == 57344u));
assert((Packed<uint32_t>().apply<12,15>(1).value == 4096u));
assert((Packed<uint32_t>().apply<12,15>(13).value == 53248u));

assert((Packed<uint32_t>().apply<13,13>(1).value == 8192u));
assert((Packed<uint32_t>().apply<13,13>(0).value == 0u));

assert((Packed<uint32_t>().apply<13,14>(3).value == 24576u));
assert((Packed<uint32_t>().apply<13,14>(2).value == 16384u));
assert((Packed<uint32_t>().apply<13,14>(0).value == 0u));

assert((Packed<uint32_t>().apply<13,15>(0).value == 0u));
assert((Packed<uint32_t>().apply<13,15>(7).value == 57344u));
assert((Packed<uint32_t>().apply<13,15>(6).value == 49152u));

assert((Packed<uint32_t>().apply<14,14>(1).value == 16384u));
assert((Packed<uint32_t>().apply<14,14>(0).value == 0u));

assert((Packed<uint32_t>().apply<14,15>(3).value == 49152u));
assert((Packed<uint32_t>().apply<14,15>(0).value == 0u));

assert((Packed<uint32_t>().apply<15,15>(1).value == 32768u));
assert((Packed<uint32_t>().apply<15,15>(0).value == 0u));

assert((Packed<uint32_t>().apply<16,16>(0).value == 0u));
assert((Packed<uint32_t>().apply<16,16>(1).value == 65536u));

assert((Packed<uint32_t>().apply<16,17>(0).value == 0u));
assert((Packed<uint32_t>().apply<16,17>(1).value == 65536u));
assert((Packed<uint32_t>().apply<16,17>(3).value == 196608u));

assert((Packed<uint32_t>().apply<16,18>(7).value == 458752u));
assert((Packed<uint32_t>().apply<16,18>(0).value == 0u));
assert((Packed<uint32_t>().apply<16,18>(5).value == 327680u));
assert((Packed<uint32_t>().apply<16,18>(4).value == 262144u));

assert((Packed<uint32_t>().apply<16,19>(15).value == 983040u));
assert((Packed<uint32_t>().apply<16,19>(0).value == 0u));
assert((Packed<uint32_t>().apply<16,19>(9).value == 589824u));
assert((Packed<uint32_t>().apply<16,19>(10).value == 655360u));
assert((Packed<uint32_t>().apply<16,19>(2).value == 131072u));

assert((Packed<uint32_t>().apply<16,20>(31).value == 2031616u));
assert((Packed<uint32_t>().apply<16,20>(0).value == 0u));
assert((Packed<uint32_t>().apply<16,20>(2).value == 131072u));
assert((Packed<uint32_t>().apply<16,20>(29).value == 1900544u));
assert((Packed<uint32_t>().apply<16,20>(10).value == 655360u));

assert((Packed<uint32_t>().apply<16,21>(63).value == 4128768u));
assert((Packed<uint32_t>().apply<16,21>(0).value == 0u));
assert((Packed<uint32_t>().apply<16,21>(12).value == 786432u));
assert((Packed<uint32_t>().apply<16,21>(22).value == 1441792u));
assert((Packed<uint32_t>().apply<16,21>(54).value == 3538944u));

assert((Packed<uint32_t>().apply<16,22>(127).value == 8323072u));
assert((Packed<uint32_t>().apply<16,22>(0).value == 0u));
assert((Packed<uint32_t>().apply<16,22>(12).value == 786432u));
assert((Packed<uint32_t>().apply<16,22>(109).value == 7143424u));
assert((Packed<uint32_t>().apply<16,22>(61).value == 3997696u));

assert((Packed<uint32_t>().apply<16,23>(255).value == 16711680u));
assert((Packed<uint32_t>().apply<16,23>(0).value == 0u));
assert((Packed<uint32_t>().apply<16,23>(38).value == 2490368u));
assert((Packed<uint32_t>().apply<16,23>(2).value == 131072u));
assert((Packed<uint32_t>().apply<16,23>(78).value == 5111808u));

assert((Packed<uint32_t>().apply<17,17>(0).value == 0u));
assert((Packed<uint32_t>().apply<17,17>(1).value == 131072u));

assert((Packed<uint32_t>().apply<17,18>(3).value == 393216u));
assert((Packed<uint32_t>().apply<17,18>(1).value == 131072u));
assert((Packed<uint32_t>().apply<17,18>(0).value == 0u));

assert((Packed<uint32_t>().apply<17,19>(0).value == 0u));
assert((Packed<uint32_t>().apply<17,19>(7).value == 917504u));
assert((Packed<uint32_t>().apply<17,19>(2).value == 262144u));

assert((Packed<uint32_t>().apply<17,20>(15).value == 1966080u));
assert((Packed<uint32_t>().apply<17,20>(0).value == 0u));
assert((Packed<uint32_t>().apply<17,20>(13).value == 1703936u));
assert((Packed<uint32_t>().apply<17,20>(6).value == 786432u));
assert((Packed<uint32_t>().apply<17,20>(3).value == 393216u));

assert((Packed<uint32_t>().apply<17,21>(31).value == 4063232u));
assert((Packed<uint32_t>().apply<17,21>(0).value == 0u));
assert((Packed<uint32_t>().apply<17,21>(15).value == 1966080u));
assert((Packed<uint32_t>().apply<17,21>(4).value == 524288u));
assert((Packed<uint32_t>().apply<17,21>(1).value == 131072u));

assert((Packed<uint32_t>().apply<17,22>(63).value == 8257536u));
assert((Packed<uint32_t>().apply<17,22>(0).value == 0u));
assert((Packed<uint32_t>().apply<17,22>(10).value == 1310720u));
assert((Packed<uint32_t>().apply<17,22>(36).value == 4718592u));
assert((Packed<uint32_t>().apply<17,22>(29).value == 3801088u));

assert((Packed<uint32_t>().apply<17,23>(127).value == 16646144u));
assert((Packed<uint32_t>().apply<17,23>(0).value == 0u));
assert((Packed<uint32_t>().apply<17,23>(84).value == 11010048u));
assert((Packed<uint32_t>().apply<17,23>(79).value == 10354688u));
assert((Packed<uint32_t>().apply<17,23>(66).value == 8650752u));

assert((Packed<uint32_t>().apply<18,18>(1).value == 262144u));
assert((Packed<uint32_t>().apply<18,18>(0).value == 0u));

assert((Packed<uint32_t>().apply<18,19>(3).value == 786432u));
assert((Packed<uint32_t>().apply<18,19>(1).value == 262144u));
assert((Packed<uint32_t>().apply<18,19>(2).value == 524288u));
assert((Packed<uint32_t>().apply<18,19>(0).value == 0u));

assert((Packed<uint32_t>().apply<18,20>(0).value == 0u));
assert((Packed<uint32_t>().apply<18,20>(7).value == 1835008u));
assert((Packed<uint32_t>().apply<18,20>(6).value == 1572864u));
assert((Packed<uint32_t>().apply<18,20>(1).value == 262144u));

assert((Packed<uint32_t>().apply<18,21>(15).value == 3932160u));
assert((Packed<uint32_t>().apply<18,21>(0).value == 0u));
assert((Packed<uint32_t>().apply<18,21>(10).value == 2621440u));

assert((Packed<uint32_t>().apply<18,22>(31).value == 8126464u));
assert((Packed<uint32_t>().apply<18,22>(0).value == 0u));
assert((Packed<uint32_t>().apply<18,22>(6).value == 1572864u));
assert((Packed<uint32_t>().apply<18,22>(26).value == 6815744u));
assert((Packed<uint32_t>().apply<18,22>(25).value == 6553600u));

assert((Packed<uint32_t>().apply<18,23>(63).value == 16515072u));
assert((Packed<uint32_t>().apply<18,23>(0).value == 0u));
assert((Packed<uint32_t>().apply<18,23>(1).value == 262144u));
assert((Packed<uint32_t>().apply<18,23>(47).value == 12320768u));
assert((Packed<uint32_t>().apply<18,23>(35).value == 9175040u));

assert((Packed<uint32_t>().apply<19,19>(1).value == 524288u));
assert((Packed<uint32_t>().apply<19,19>(0).value == 0u));

assert((Packed<uint32_t>().apply<19,20>(0).value == 0u));
assert((Packed<uint32_t>().apply<19,20>(2).value == 1048576u));
assert((Packed<uint32_t>().apply<19,20>(3).value == 1572864u));
assert((Packed<uint32_t>().apply<19,20>(1).value == 524288u));

assert((Packed<uint32_t>().apply<19,21>(0).value == 0u));
assert((Packed<uint32_t>().apply<19,21>(4).value == 2097152u));
assert((Packed<uint32_t>().apply<19,21>(6).value == 3145728u));
assert((Packed<uint32_t>().apply<19,21>(7).value == 3670016u));

assert((Packed<uint32_t>().apply<19,22>(0).value == 0u));
assert((Packed<uint32_t>().apply<19,22>(15).value == 7864320u));
assert((Packed<uint32_t>().apply<19,22>(7).value == 3670016u));

assert((Packed<uint32_t>().apply<19,23>(31).value == 16252928u));
assert((Packed<uint32_t>().apply<19,23>(0).value == 0u));
assert((Packed<uint32_t>().apply<19,23>(18).value == 9437184u));
assert((Packed<uint32_t>().apply<19,23>(12).value == 6291456u));
assert((Packed<uint32_t>().apply<19,23>(29).value == 15204352u));

assert((Packed<uint32_t>().apply<20,20>(1).value == 1048576u));
assert((Packed<uint32_t>().apply<20,20>(0).value == 0u));

assert((Packed<uint32_t>().apply<20,21>(3).value == 3145728u));
assert((Packed<uint32_t>().apply<20,21>(1).value == 1048576u));
assert((Packed<uint32_t>().apply<20,21>(0).value == 0u));

assert((Packed<uint32_t>().apply<20,22>(0).value == 0u));
assert((Packed<uint32_t>().apply<20,22>(1).value == 1048576u));
assert((Packed<uint32_t>().apply<20,22>(5).value == 5242880u));
assert((Packed<uint32_t>().apply<20,22>(7).value == 7340032u));

assert((Packed<uint32_t>().apply<20,23>(15).value == 15728640u));
assert((Packed<uint32_t>().apply<20,23>(0).value == 0u));
assert((Packed<uint32_t>().apply<20,23>(14).value == 14680064u));
assert((Packed<uint32_t>().apply<20,23>(1).value == 1048576u));
assert((Packed<uint32_t>().apply<20,23>(9).value == 9437184u));

assert((Packed<uint32_t>().apply<21,21>(1).value == 2097152u));
assert((Packed<uint32_t>().apply<21,21>(0).value == 0u));

assert((Packed<uint32_t>().apply<21,22>(0).value == 0u));
assert((Packed<uint32_t>().apply<21,22>(1).value == 2097152u));
assert((Packed<uint32_t>().apply<21,22>(3).value == 6291456u));

assert((Packed<uint32_t>().apply<21,23>(0).value == 0u));
assert((Packed<uint32_t>().apply<21,23>(6).value == 12582912u));
assert((Packed<uint32_t>().apply<21,23>(7).value == 14680064u));
assert((Packed<uint32_t>().apply<21,23>(1).value == 2097152u));

assert((Packed<uint32_t>().apply<22,22>(1).value == 4194304u));
assert((Packed<uint32_t>().apply<22,22>(0).value == 0u));

assert((Packed<uint32_t>().apply<22,23>(3).value == 12582912u));
assert((Packed<uint32_t>().apply<22,23>(2).value == 8388608u));
assert((Packed<uint32_t>().apply<22,23>(0).value == 0u));

assert((Packed<uint32_t>().apply<23,23>(1).value == 8388608u));
assert((Packed<uint32_t>().apply<23,23>(0).value == 0u));

assert((Packed<uint32_t>().apply<24,24>(0).value == 0u));
assert((Packed<uint32_t>().apply<24,24>(1).value == 16777216u));

assert((Packed<uint32_t>().apply<24,25>(3).value == 50331648u));
assert((Packed<uint32_t>().apply<24,25>(0).value == 0u));
assert((Packed<uint32_t>().apply<24,25>(2).value == 33554432u));
assert((Packed<uint32_t>().apply<24,25>(1).value == 16777216u));

assert((Packed<uint32_t>().apply<24,26>(7).value == 117440512u));
assert((Packed<uint32_t>().apply<24,26>(5).value == 83886080u));
assert((Packed<uint32_t>().apply<24,26>(1).value == 16777216u));
assert((Packed<uint32_t>().apply<24,26>(0).value == 0u));

assert((Packed<uint32_t>().apply<24,27>(15).value == 251658240u));
assert((Packed<uint32_t>().apply<24,27>(0).value == 0u));
assert((Packed<uint32_t>().apply<24,27>(2).value == 33554432u));
assert((Packed<uint32_t>().apply<24,27>(5).value == 83886080u));

assert((Packed<uint32_t>().apply<24,28>(31).value == 520093696u));
assert((Packed<uint32_t>().apply<24,28>(0).value == 0u));
assert((Packed<uint32_t>().apply<24,28>(19).value == 318767104u));
assert((Packed<uint32_t>().apply<24,28>(10).value == 167772160u));
assert((Packed<uint32_t>().apply<24,28>(2).value == 33554432u));

assert((Packed<uint32_t>().apply<24,29>(63).value == 1056964608u));
assert((Packed<uint32_t>().apply<24,29>(0).value == 0u));
assert((Packed<uint32_t>().apply<24,29>(49).value == 822083584u));
assert((Packed<uint32_t>().apply<24,29>(6).value == 100663296u));
assert((Packed<uint32_t>().apply<24,29>(16).value == 268435456u));

assert((Packed<uint32_t>().apply<24,30>(127).value == 2130706432u));
assert((Packed<uint32_t>().apply<24,30>(0).value == 0u));
assert((Packed<uint32_t>().apply<24,30>(85).value == 1426063360u));
assert((Packed<uint32_t>().apply<24,30>(82).value == 1375731712u));
assert((Packed<uint32_t>().apply<24,30>(106).value == 1778384896u));

assert((Packed<uint32_t>().apply<24,31>(255).value == 4278190080u));
assert((Packed<uint32_t>().apply<24,31>(0).value == 0u));
assert((Packed<uint32_t>().apply<24,31>(217).value == 3640655872u));
assert((Packed<uint32_t>().apply<24,31>(8).value == 134217728u));
assert((Packed<uint32_t>().apply<24,31>(253).value == 4244635648u));

assert((Packed<uint32_t>().apply<25,25>(1).value == 33554432u));
assert((Packed<uint32_t>().apply<25,25>(0).value == 0u));

assert((Packed<uint32_t>().apply<25,26>(1).value == 33554432u));
assert((Packed<uint32_t>().apply<25,26>(3).value == 100663296u));
assert((Packed<uint32_t>().apply<25,26>(0).value == 0u));

assert((Packed<uint32_t>().apply<25,27>(7).value == 234881024u));
assert((Packed<uint32_t>().apply<25,27>(0).value == 0u));
assert((Packed<uint32_t>().apply<25,27>(1).value == 33554432u));
assert((Packed<uint32_t>().apply<25,27>(4).value == 134217728u));

assert((Packed<uint32_t>().apply<25,28>(15).value == 503316480u));
assert((Packed<uint32_t>().apply<25,28>(0).value == 0u));
assert((Packed<uint32_t>().apply<25,28>(2).value == 67108864u));
assert((Packed<uint32_t>().apply<25,28>(13).value == 436207616u));
assert((Packed<uint32_t>().apply<25,28>(5).value == 167772160u));

assert((Packed<uint32_t>().apply<25,29>(31).value == 1040187392u));
assert((Packed<uint32_t>().apply<25,29>(0).value == 0u));
assert((Packed<uint32_t>().apply<25,29>(9).value == 301989888u));
assert((Packed<uint32_t>().apply<25,29>(1).value == 33554432u));

assert((Packed<uint32_t>().apply<25,30>(0).value == 0u));
assert((Packed<uint32_t>().apply<25,30>(46).value == 1543503872u));
assert((Packed<uint32_t>().apply<25,30>(60).value == 2013265920u));
assert((Packed<uint32_t>().apply<25,30>(63).value == 2113929216u));

assert((Packed<uint32_t>().apply<25,31>(127).value == 4261412864u));
assert((Packed<uint32_t>().apply<25,31>(0).value == 0u));
assert((Packed<uint32_t>().apply<25,31>(94).value == 3154116608u));
assert((Packed<uint32_t>().apply<25,31>(38).value == 1275068416u));
assert((Packed<uint32_t>().apply<25,31>(116).value == 3892314112u));

assert((Packed<uint32_t>().apply<26,26>(1).value == 67108864u));
assert((Packed<uint32_t>().apply<26,26>(0).value == 0u));

assert((Packed<uint32_t>().apply<26,27>(0).value == 0u));
assert((Packed<uint32_t>().apply<26,27>(3).value == 201326592u));
assert((Packed<uint32_t>().apply<26,27>(1).value == 67108864u));

assert((Packed<uint32_t>().apply<26,28>(7).value == 469762048u));
assert((Packed<uint32_t>().apply<26,28>(0).value == 0u));
assert((Packed<uint32_t>().apply<26,28>(3).value == 201326592u));
assert((Packed<uint32_t>().apply<26,28>(6).value == 402653184u));
assert((Packed<uint32_t>().apply<26,28>(1).value == 67108864u));

assert((Packed<uint32_t>().apply<26,29>(0).value == 0u));
assert((Packed<uint32_t>().apply<26,29>(15).value == 1006632960u));
assert((Packed<uint32_t>().apply<26,29>(8).value == 536870912u));
assert((Packed<uint32_t>().apply<26,29>(3).value == 201326592u));

assert((Packed<uint32_t>().apply<26,30>(31).value == 2080374784u));
assert((Packed<uint32_t>().apply<26,30>(0).value == 0u));
assert((Packed<uint32_t>().apply<26,30>(17).value == 1140850688u));
assert((Packed<uint32_t>().apply<26,30>(28).value == 1879048192u));
assert((Packed<uint32_t>().apply<26,30>(7).value == 469762048u));

assert((Packed<uint32_t>().apply<26,31>(63).value == 4227858432u));
assert((Packed<uint32_t>().apply<26,31>(0).value == 0u));
assert((Packed<uint32_t>().apply<26,31>(50).value == 3355443200u));
assert((Packed<uint32_t>().apply<26,31>(11).value == 738197504u));

assert((Packed<uint32_t>().apply<27,27>(0).value == 0u));
assert((Packed<uint32_t>().apply<27,27>(1).value == 134217728u));

assert((Packed<uint32_t>().apply<27,28>(0).value == 0u));
assert((Packed<uint32_t>().apply<27,28>(3).value == 402653184u));

assert((Packed<uint32_t>().apply<27,29>(7).value == 939524096u));
assert((Packed<uint32_t>().apply<27,29>(0).value == 0u));
assert((Packed<uint32_t>().apply<27,29>(6).value == 805306368u));
assert((Packed<uint32_t>().apply<27,29>(3).value == 402653184u));

assert((Packed<uint32_t>().apply<27,30>(0).value == 0u));
assert((Packed<uint32_t>().apply<27,30>(10).value == 1342177280u));
assert((Packed<uint32_t>().apply<27,30>(6).value == 805306368u));
assert((Packed<uint32_t>().apply<27,30>(15).value == 2013265920u));

assert((Packed<uint32_t>().apply<27,31>(31).value == 4160749568u));
assert((Packed<uint32_t>().apply<27,31>(0).value == 0u));
assert((Packed<uint32_t>().apply<27,31>(19).value == 2550136832u));
assert((Packed<uint32_t>().apply<27,31>(14).value == 1879048192u));
assert((Packed<uint32_t>().apply<27,31>(27).value == 3623878656u));

assert((Packed<uint32_t>().apply<28,28>(0).value == 0u));
assert((Packed<uint32_t>().apply<28,28>(1).value == 268435456u));

assert((Packed<uint32_t>().apply<28,29>(3).value == 805306368u));
assert((Packed<uint32_t>().apply<28,29>(0).value == 0u));
assert((Packed<uint32_t>().apply<28,29>(1).value == 268435456u));

assert((Packed<uint32_t>().apply<28,30>(7).value == 1879048192u));
assert((Packed<uint32_t>().apply<28,30>(5).value == 1342177280u));
assert((Packed<uint32_t>().apply<28,30>(0).value == 0u));
assert((Packed<uint32_t>().apply<28,30>(1).value == 268435456u));

assert((Packed<uint32_t>().apply<28,31>(15).value == 4026531840u));
assert((Packed<uint32_t>().apply<28,31>(0).value == 0u));
assert((Packed<uint32_t>().apply<28,31>(13).value == 3489660928u));
assert((Packed<uint32_t>().apply<28,31>(14).value == 3758096384u));
assert((Packed<uint32_t>().apply<28,31>(5).value == 1342177280u));

assert((Packed<uint32_t>().apply<29,29>(1).value == 536870912u));
assert((Packed<uint32_t>().apply<29,29>(0).value == 0u));

assert((Packed<uint32_t>().apply<29,30>(0).value == 0u));
assert((Packed<uint32_t>().apply<29,30>(2).value == 1073741824u));
assert((Packed<uint32_t>().apply<29,30>(1).value == 536870912u));
assert((Packed<uint32_t>().apply<29,30>(3).value == 1610612736u));

assert((Packed<uint32_t>().apply<29,31>(0).value == 0u));
assert((Packed<uint32_t>().apply<29,31>(7).value == 3758096384u));
assert((Packed<uint32_t>().apply<29,31>(4).value == 2147483648u));

assert((Packed<uint32_t>().apply<30,30>(1).value == 1073741824u));
assert((Packed<uint32_t>().apply<30,30>(0).value == 0u));

assert((Packed<uint32_t>().apply<30,31>(0).value == 0u));
assert((Packed<uint32_t>().apply<30,31>(3).value == 3221225472u));
assert((Packed<uint32_t>().apply<30,31>(2).value == 2147483648u));
assert((Packed<uint32_t>().apply<30,31>(1).value == 1073741824u));

assert((Packed<uint32_t>().apply<31,31>(1).value == 2147483648u));
assert((Packed<uint32_t>().apply<31,31>(0).value == 0u));

assert((Packed<uint32_t>().apply<1,8>(255).value == 510u));
assert((Packed<uint32_t>().apply<1,8>(0).value == 0u));
assert((Packed<uint32_t>().apply<1,8>(226).value == 452u));
assert((Packed<uint32_t>().apply<1,8>(162).value == 324u));

assert((Packed<uint32_t>().apply<1,9>(511).value == 1022u));
assert((Packed<uint32_t>().apply<1,9>(0).value == 0u));
assert((Packed<uint32_t>().apply<1,9>(78).value == 156u));
assert((Packed<uint32_t>().apply<1,9>(205).value == 410u));
assert((Packed<uint32_t>().apply<1,9>(460).value == 920u));

assert((Packed<uint32_t>().apply<1,10>(1023).value == 2046u));
assert((Packed<uint32_t>().apply<1,10>(0).value == 0u));
assert((Packed<uint32_t>().apply<1,10>(727).value == 1454u));
assert((Packed<uint32_t>().apply<1,10>(762).value == 1524u));
assert((Packed<uint32_t>().apply<1,10>(61).value == 122u));

assert((Packed<uint32_t>().apply<1,11>(2047).value == 4094u));
assert((Packed<uint32_t>().apply<1,11>(0).value == 0u));
assert((Packed<uint32_t>().apply<1,11>(1019).value == 2038u));
assert((Packed<uint32_t>().apply<1,11>(1951).value == 3902u));
assert((Packed<uint32_t>().apply<1,11>(476).value == 952u));

assert((Packed<uint32_t>().apply<1,12>(4095).value == 8190u));
assert((Packed<uint32_t>().apply<1,12>(0).value == 0u));
assert((Packed<uint32_t>().apply<1,12>(3834).value == 7668u));
assert((Packed<uint32_t>().apply<1,12>(564).value == 1128u));
assert((Packed<uint32_t>().apply<1,12>(1928).value == 3856u));

assert((Packed<uint32_t>().apply<1,13>(8191).value == 16382u));
assert((Packed<uint32_t>().apply<1,13>(0).value == 0u));
assert((Packed<uint32_t>().apply<1,13>(6392).value == 12784u));
assert((Packed<uint32_t>().apply<1,13>(3686).value == 7372u));
assert((Packed<uint32_t>().apply<1,13>(1819).value == 3638u));

assert((Packed<uint32_t>().apply<1,14>(16383).value == 32766u));
assert((Packed<uint32_t>().apply<1,14>(0).value == 0u));
assert((Packed<uint32_t>().apply<1,14>(12983).value == 25966u));
assert((Packed<uint32_t>().apply<1,14>(1842).value == 3684u));
assert((Packed<uint32_t>().apply<1,14>(16372).value == 32744u));

assert((Packed<uint32_t>().apply<1,15>(32767).value == 65534u));
assert((Packed<uint32_t>().apply<1,15>(0).value == 0u));
assert((Packed<uint32_t>().apply<1,15>(20331).value == 40662u));
assert((Packed<uint32_t>().apply<1,15>(26092).value == 52184u));
assert((Packed<uint32_t>().apply<1,15>(23451).value == 46902u));

assert((Packed<uint32_t>().apply<2,8>(127).value == 508u));
assert((Packed<uint32_t>().apply<2,8>(0).value == 0u));
assert((Packed<uint32_t>().apply<2,8>(63).value == 252u));
assert((Packed<uint32_t>().apply<2,8>(26).value == 104u));
assert((Packed<uint32_t>().apply<2,8>(37).value == 148u));

assert((Packed<uint32_t>().apply<2,9>(255).value == 1020u));
assert((Packed<uint32_t>().apply<2,9>(0).value == 0u));
assert((Packed<uint32_t>().apply<2,9>(200).value == 800u));
assert((Packed<uint32_t>().apply<2,9>(188).value == 752u));
assert((Packed<uint32_t>().apply<2,9>(162).value == 648u));

assert((Packed<uint32_t>().apply<2,10>(511).value == 2044u));
assert((Packed<uint32_t>().apply<2,10>(0).value == 0u));
assert((Packed<uint32_t>().apply<2,10>(505).value == 2020u));
assert((Packed<uint32_t>().apply<2,10>(146).value == 584u));
assert((Packed<uint32_t>().apply<2,10>(361).value == 1444u));

assert((Packed<uint32_t>().apply<2,11>(1023).value == 4092u));
assert((Packed<uint32_t>().apply<2,11>(0).value == 0u));
assert((Packed<uint32_t>().apply<2,11>(619).value == 2476u));
assert((Packed<uint32_t>().apply<2,11>(269).value == 1076u));
assert((Packed<uint32_t>().apply<2,11>(1014).value == 4056u));

assert((Packed<uint32_t>().apply<2,12>(2047).value == 8188u));
assert((Packed<uint32_t>().apply<2,12>(0).value == 0u));
assert((Packed<uint32_t>().apply<2,12>(162).value == 648u));
assert((Packed<uint32_t>().apply<2,12>(1240).value == 4960u));
assert((Packed<uint32_t>().apply<2,12>(1795).value == 7180u));

assert((Packed<uint32_t>().apply<2,13>(4095).value == 16380u));
assert((Packed<uint32_t>().apply<2,13>(0).value == 0u));
assert((Packed<uint32_t>().apply<2,13>(3795).value == 15180u));
assert((Packed<uint32_t>().apply<2,13>(1071).value == 4284u));
assert((Packed<uint32_t>().apply<2,13>(3957).value == 15828u));

assert((Packed<uint32_t>().apply<2,14>(8191).value == 32764u));
assert((Packed<uint32_t>().apply<2,14>(0).value == 0u));
assert((Packed<uint32_t>().apply<2,14>(2609).value == 10436u));
assert((Packed<uint32_t>().apply<2,14>(2908).value == 11632u));
assert((Packed<uint32_t>().apply<2,14>(7672).value == 30688u));

assert((Packed<uint32_t>().apply<2,15>(16383).value == 65532u));
assert((Packed<uint32_t>().apply<2,15>(0).value == 0u));
assert((Packed<uint32_t>().apply<2,15>(4245).value == 16980u));
assert((Packed<uint32_t>().apply<2,15>(1918).value == 7672u));
assert((Packed<uint32_t>().apply<2,15>(15446).value == 61784u));

assert((Packed<uint32_t>().apply<3,8>(63).value == 504u));
assert((Packed<uint32_t>().apply<3,8>(0).value == 0u));
assert((Packed<uint32_t>().apply<3,8>(49).value == 392u));
assert((Packed<uint32_t>().apply<3,8>(42).value == 336u));
assert((Packed<uint32_t>().apply<3,8>(6).value == 48u));

assert((Packed<uint32_t>().apply<3,9>(127).value == 1016u));
assert((Packed<uint32_t>().apply<3,9>(0).value == 0u));
assert((Packed<uint32_t>().apply<3,9>(75).value == 600u));
assert((Packed<uint32_t>().apply<3,9>(18).value == 144u));
assert((Packed<uint32_t>().apply<3,9>(77).value == 616u));

assert((Packed<uint32_t>().apply<3,10>(255).value == 2040u));
assert((Packed<uint32_t>().apply<3,10>(0).value == 0u));
assert((Packed<uint32_t>().apply<3,10>(122).value == 976u));
assert((Packed<uint32_t>().apply<3,10>(203).value == 1624u));
assert((Packed<uint32_t>().apply<3,10>(161).value == 1288u));

assert((Packed<uint32_t>().apply<3,11>(511).value == 4088u));
assert((Packed<uint32_t>().apply<3,11>(0).value == 0u));
assert((Packed<uint32_t>().apply<3,11>(31).value == 248u));
assert((Packed<uint32_t>().apply<3,11>(155).value == 1240u));
assert((Packed<uint32_t>().apply<3,11>(415).value == 3320u));

assert((Packed<uint32_t>().apply<3,12>(1023).value == 8184u));
assert((Packed<uint32_t>().apply<3,12>(0).value == 0u));
assert((Packed<uint32_t>().apply<3,12>(639).value == 5112u));
assert((Packed<uint32_t>().apply<3,12>(676).value == 5408u));
assert((Packed<uint32_t>().apply<3,12>(275).value == 2200u));

assert((Packed<uint32_t>().apply<3,13>(2047).value == 16376u));
assert((Packed<uint32_t>().apply<3,13>(0).value == 0u));
assert((Packed<uint32_t>().apply<3,13>(908).value == 7264u));
assert((Packed<uint32_t>().apply<3,13>(2044).value == 16352u));
assert((Packed<uint32_t>().apply<3,13>(1524).value == 12192u));

assert((Packed<uint32_t>().apply<3,14>(4095).value == 32760u));
assert((Packed<uint32_t>().apply<3,14>(0).value == 0u));
assert((Packed<uint32_t>().apply<3,14>(2452).value == 19616u));
assert((Packed<uint32_t>().apply<3,14>(80).value == 640u));
assert((Packed<uint32_t>().apply<3,14>(2605).value == 20840u));

assert((Packed<uint32_t>().apply<3,15>(8191).value == 65528u));
assert((Packed<uint32_t>().apply<3,15>(0).value == 0u));
assert((Packed<uint32_t>().apply<3,15>(6714).value == 53712u));
assert((Packed<uint32_t>().apply<3,15>(3405).value == 27240u));
assert((Packed<uint32_t>().apply<3,15>(1356).value == 10848u));

assert((Packed<uint32_t>().apply<4,8>(31).value == 496u));
assert((Packed<uint32_t>().apply<4,8>(0).value == 0u));
assert((Packed<uint32_t>().apply<4,8>(2).value == 32u));
assert((Packed<uint32_t>().apply<4,8>(24).value == 384u));

assert((Packed<uint32_t>().apply<4,9>(63).value == 1008u));
assert((Packed<uint32_t>().apply<4,9>(0).value == 0u));
assert((Packed<uint32_t>().apply<4,9>(54).value == 864u));
assert((Packed<uint32_t>().apply<4,9>(34).value == 544u));
assert((Packed<uint32_t>().apply<4,9>(25).value == 400u));

assert((Packed<uint32_t>().apply<4,10>(127).value == 2032u));
assert((Packed<uint32_t>().apply<4,10>(0).value == 0u));
assert((Packed<uint32_t>().apply<4,10>(16).value == 256u));
assert((Packed<uint32_t>().apply<4,10>(23).value == 368u));
assert((Packed<uint32_t>().apply<4,10>(38).value == 608u));

assert((Packed<uint32_t>().apply<4,11>(255).value == 4080u));
assert((Packed<uint32_t>().apply<4,11>(0).value == 0u));
assert((Packed<uint32_t>().apply<4,11>(135).value == 2160u));
assert((Packed<uint32_t>().apply<4,11>(191).value == 3056u));
assert((Packed<uint32_t>().apply<4,11>(36).value == 576u));

assert((Packed<uint32_t>().apply<4,12>(511).value == 8176u));
assert((Packed<uint32_t>().apply<4,12>(0).value == 0u));
assert((Packed<uint32_t>().apply<4,12>(4).value == 64u));
assert((Packed<uint32_t>().apply<4,12>(332).value == 5312u));
assert((Packed<uint32_t>().apply<4,12>(415).value == 6640u));

assert((Packed<uint32_t>().apply<4,13>(1023).value == 16368u));
assert((Packed<uint32_t>().apply<4,13>(0).value == 0u));
assert((Packed<uint32_t>().apply<4,13>(150).value == 2400u));
assert((Packed<uint32_t>().apply<4,13>(898).value == 14368u));
assert((Packed<uint32_t>().apply<4,13>(758).value == 12128u));

assert((Packed<uint32_t>().apply<4,14>(2047).value == 32752u));
assert((Packed<uint32_t>().apply<4,14>(0).value == 0u));
assert((Packed<uint32_t>().apply<4,14>(109).value == 1744u));
assert((Packed<uint32_t>().apply<4,14>(196).value == 3136u));
assert((Packed<uint32_t>().apply<4,14>(1952).value == 31232u));

assert((Packed<uint32_t>().apply<4,15>(4095).value == 65520u));
assert((Packed<uint32_t>().apply<4,15>(0).value == 0u));
assert((Packed<uint32_t>().apply<4,15>(546).value == 8736u));
assert((Packed<uint32_t>().apply<4,15>(2781).value == 44496u));
assert((Packed<uint32_t>().apply<4,15>(3134).value == 50144u));

assert((Packed<uint32_t>().apply<5,8>(15).value == 480u));
assert((Packed<uint32_t>().apply<5,8>(0).value == 0u));
assert((Packed<uint32_t>().apply<5,8>(1).value == 32u));

assert((Packed<uint32_t>().apply<5,9>(31).value == 992u));
assert((Packed<uint32_t>().apply<5,9>(0).value == 0u));
assert((Packed<uint32_t>().apply<5,9>(7).value == 224u));
assert((Packed<uint32_t>().apply<5,9>(2).value == 64u));
assert((Packed<uint32_t>().apply<5,9>(29).value == 928u));

assert((Packed<uint32_t>().apply<5,10>(0).value == 0u));
assert((Packed<uint32_t>().apply<5,10>(29).value == 928u));
assert((Packed<uint32_t>().apply<5,10>(23).value == 736u));
assert((Packed<uint32_t>().apply<5,10>(63).value == 2016u));

assert((Packed<uint32_t>().apply<5,11>(127).value == 4064u));
assert((Packed<uint32_t>().apply<5,11>(0).value == 0u));
assert((Packed<uint32_t>().apply<5,11>(58).value == 1856u));
assert((Packed<uint32_t>().apply<5,11>(7).value == 224u));

assert((Packed<uint32_t>().apply<5,12>(255).value == 8160u));
assert((Packed<uint32_t>().apply<5,12>(0).value == 0u));
assert((Packed<uint32_t>().apply<5,12>(141).value == 4512u));
assert((Packed<uint32_t>().apply<5,12>(116).value == 3712u));
assert((Packed<uint32_t>().apply<5,12>(200).value == 6400u));

assert((Packed<uint32_t>().apply<5,13>(511).value == 16352u));
assert((Packed<uint32_t>().apply<5,13>(0).value == 0u));
assert((Packed<uint32_t>().apply<5,13>(170).value == 5440u));
assert((Packed<uint32_t>().apply<5,13>(202).value == 6464u));
assert((Packed<uint32_t>().apply<5,13>(22).value == 704u));

assert((Packed<uint32_t>().apply<5,14>(1023).value == 32736u));
assert((Packed<uint32_t>().apply<5,14>(0).value == 0u));
assert((Packed<uint32_t>().apply<5,14>(712).value == 22784u));
assert((Packed<uint32_t>().apply<5,14>(319).value == 10208u));
assert((Packed<uint32_t>().apply<5,14>(1022).value == 32704u));

assert((Packed<uint32_t>().apply<5,15>(2047).value == 65504u));
assert((Packed<uint32_t>().apply<5,15>(0).value == 0u));
assert((Packed<uint32_t>().apply<5,15>(14).value == 448u));
assert((Packed<uint32_t>().apply<5,15>(2002).value == 64064u));
assert((Packed<uint32_t>().apply<5,15>(384).value == 12288u));

assert((Packed<uint32_t>().apply<6,8>(7).value == 448u));
assert((Packed<uint32_t>().apply<6,8>(5).value == 320u));
assert((Packed<uint32_t>().apply<6,8>(0).value == 0u));
assert((Packed<uint32_t>().apply<6,8>(4).value == 256u));

assert((Packed<uint32_t>().apply<6,9>(15).value == 960u));
assert((Packed<uint32_t>().apply<6,9>(0).value == 0u));
assert((Packed<uint32_t>().apply<6,9>(2).value == 128u));
assert((Packed<uint32_t>().apply<6,9>(1).value == 64u));

assert((Packed<uint32_t>().apply<6,10>(31).value == 1984u));
assert((Packed<uint32_t>().apply<6,10>(0).value == 0u));
assert((Packed<uint32_t>().apply<6,10>(3).value == 192u));
assert((Packed<uint32_t>().apply<6,10>(8).value == 512u));
assert((Packed<uint32_t>().apply<6,10>(10).value == 640u));

assert((Packed<uint32_t>().apply<6,11>(63).value == 4032u));
assert((Packed<uint32_t>().apply<6,11>(0).value == 0u));
assert((Packed<uint32_t>().apply<6,11>(51).value == 3264u));
assert((Packed<uint32_t>().apply<6,11>(56).value == 3584u));
assert((Packed<uint32_t>().apply<6,11>(8).value == 512u));

assert((Packed<uint32_t>().apply<6,12>(127).value == 8128u));
assert((Packed<uint32_t>().apply<6,12>(0).value == 0u));
assert((Packed<uint32_t>().apply<6,12>(107).value == 6848u));
assert((Packed<uint32_t>().apply<6,12>(55).value == 3520u));
assert((Packed<uint32_t>().apply<6,12>(49).value == 3136u));

assert((Packed<uint32_t>().apply<6,13>(255).value == 16320u));
assert((Packed<uint32_t>().apply<6,13>(0).value == 0u));
assert((Packed<uint32_t>().apply<6,13>(126).value == 8064u));
assert((Packed<uint32_t>().apply<6,13>(107).value == 6848u));
assert((Packed<uint32_t>().apply<6,13>(201).value == 12864u));

assert((Packed<uint32_t>().apply<6,14>(511).value == 32704u));
assert((Packed<uint32_t>().apply<6,14>(0).value == 0u));
assert((Packed<uint32_t>().apply<6,14>(335).value == 21440u));
assert((Packed<uint32_t>().apply<6,14>(489).value == 31296u));
assert((Packed<uint32_t>().apply<6,14>(8).value == 512u));

assert((Packed<uint32_t>().apply<6,15>(1023).value == 65472u));
assert((Packed<uint32_t>().apply<6,15>(0).value == 0u));
assert((Packed<uint32_t>().apply<6,15>(595).value == 38080u));
assert((Packed<uint32_t>().apply<6,15>(902).value == 57728u));
assert((Packed<uint32_t>().apply<6,15>(200).value == 12800u));

assert((Packed<uint32_t>().apply<7,8>(0).value == 0u));
assert((Packed<uint32_t>().apply<7,8>(3).value == 384u));
assert((Packed<uint32_t>().apply<7,8>(1).value == 128u));

assert((Packed<uint32_t>().apply<7,9>(0).value == 0u));
assert((Packed<uint32_t>().apply<7,9>(3).value == 384u));
assert((Packed<uint32_t>().apply<7,9>(1).value == 128u));
assert((Packed<uint32_t>().apply<7,9>(7).value == 896u));

assert((Packed<uint32_t>().apply<7,10>(15).value == 1920u));
assert((Packed<uint32_t>().apply<7,10>(0).value == 0u));
assert((Packed<uint32_t>().apply<7,10>(10).value == 1280u));
assert((Packed<uint32_t>().apply<7,10>(3).value == 384u));
assert((Packed<uint32_t>().apply<7,10>(7).value == 896u));

assert((Packed<uint32_t>().apply<7,11>(31).value == 3968u));
assert((Packed<uint32_t>().apply<7,11>(0).value == 0u));
assert((Packed<uint32_t>().apply<7,11>(9).value == 1152u));
assert((Packed<uint32_t>().apply<7,11>(23).value == 2944u));
assert((Packed<uint32_t>().apply<7,11>(13).value == 1664u));

assert((Packed<uint32_t>().apply<7,12>(63).value == 8064u));
assert((Packed<uint32_t>().apply<7,12>(0).value == 0u));
assert((Packed<uint32_t>().apply<7,12>(47).value == 6016u));
assert((Packed<uint32_t>().apply<7,12>(42).value == 5376u));
assert((Packed<uint32_t>().apply<7,12>(32).value == 4096u));

assert((Packed<uint32_t>().apply<7,13>(127).value == 16256u));
assert((Packed<uint32_t>().apply<7,13>(0).value == 0u));
assert((Packed<uint32_t>().apply<7,13>(32).value == 4096u));
assert((Packed<uint32_t>().apply<7,13>(110).value == 14080u));
assert((Packed<uint32_t>().apply<7,13>(59).value == 7552u));

assert((Packed<uint32_t>().apply<7,14>(255).value == 32640u));
assert((Packed<uint32_t>().apply<7,14>(0).value == 0u));
assert((Packed<uint32_t>().apply<7,14>(107).value == 13696u));
assert((Packed<uint32_t>().apply<7,14>(183).value == 23424u));
assert((Packed<uint32_t>().apply<7,14>(130).value == 16640u));

assert((Packed<uint32_t>().apply<7,15>(511).value == 65408u));
assert((Packed<uint32_t>().apply<7,15>(0).value == 0u));
assert((Packed<uint32_t>().apply<7,15>(476).value == 60928u));
assert((Packed<uint32_t>().apply<7,15>(234).value == 29952u));
assert((Packed<uint32_t>().apply<7,15>(434).value == 55552u));

assert((Packed<uint32_t>().apply<9,16>(0).value == 0u));
assert((Packed<uint32_t>().apply<9,16>(234).value == 119808u));
assert((Packed<uint32_t>().apply<9,16>(255).value == 130560u));
assert((Packed<uint32_t>().apply<9,16>(51).value == 26112u));

assert((Packed<uint32_t>().apply<9,17>(511).value == 261632u));
assert((Packed<uint32_t>().apply<9,17>(0).value == 0u));
assert((Packed<uint32_t>().apply<9,17>(293).value == 150016u));
assert((Packed<uint32_t>().apply<9,17>(435).value == 222720u));
assert((Packed<uint32_t>().apply<9,17>(369).value == 188928u));

assert((Packed<uint32_t>().apply<9,18>(1023).value == 523776u));
assert((Packed<uint32_t>().apply<9,18>(0).value == 0u));
assert((Packed<uint32_t>().apply<9,18>(278).value == 142336u));
assert((Packed<uint32_t>().apply<9,18>(637).value == 326144u));
assert((Packed<uint32_t>().apply<9,18>(845).value == 432640u));

assert((Packed<uint32_t>().apply<9,19>(2047).value == 1048064u));
assert((Packed<uint32_t>().apply<9,19>(0).value == 0u));
assert((Packed<uint32_t>().apply<9,19>(61).value == 31232u));
assert((Packed<uint32_t>().apply<9,19>(774).value == 396288u));
assert((Packed<uint32_t>().apply<9,19>(1089).value == 557568u));

assert((Packed<uint32_t>().apply<9,20>(4095).value == 2096640u));
assert((Packed<uint32_t>().apply<9,20>(0).value == 0u));
assert((Packed<uint32_t>().apply<9,20>(1570).value == 803840u));
assert((Packed<uint32_t>().apply<9,20>(436).value == 223232u));
assert((Packed<uint32_t>().apply<9,20>(570).value == 291840u));

assert((Packed<uint32_t>().apply<9,21>(8191).value == 4193792u));
assert((Packed<uint32_t>().apply<9,21>(0).value == 0u));
assert((Packed<uint32_t>().apply<9,21>(7303).value == 3739136u));
assert((Packed<uint32_t>().apply<9,21>(4394).value == 2249728u));
assert((Packed<uint32_t>().apply<9,21>(2620).value == 1341440u));

assert((Packed<uint32_t>().apply<9,22>(16383).value == 8388096u));
assert((Packed<uint32_t>().apply<9,22>(0).value == 0u));
assert((Packed<uint32_t>().apply<9,22>(14926).value == 7642112u));
assert((Packed<uint32_t>().apply<9,22>(1707).value == 873984u));
assert((Packed<uint32_t>().apply<9,22>(10674).value == 5465088u));

assert((Packed<uint32_t>().apply<9,23>(32767).value == 16776704u));
assert((Packed<uint32_t>().apply<9,23>(0).value == 0u));
assert((Packed<uint32_t>().apply<9,23>(15333).value == 7850496u));
assert((Packed<uint32_t>().apply<9,23>(28608).value == 14647296u));
assert((Packed<uint32_t>().apply<9,23>(10102).value == 5172224u));

assert((Packed<uint32_t>().apply<10,16>(127).value == 130048u));
assert((Packed<uint32_t>().apply<10,16>(0).value == 0u));
assert((Packed<uint32_t>().apply<10,16>(119).value == 121856u));
assert((Packed<uint32_t>().apply<10,16>(76).value == 77824u));
assert((Packed<uint32_t>().apply<10,16>(66).value == 67584u));

assert((Packed<uint32_t>().apply<10,17>(255).value == 261120u));
assert((Packed<uint32_t>().apply<10,17>(0).value == 0u));
assert((Packed<uint32_t>().apply<10,17>(95).value == 97280u));
assert((Packed<uint32_t>().apply<10,17>(136).value == 139264u));
assert((Packed<uint32_t>().apply<10,17>(78).value == 79872u));

assert((Packed<uint32_t>().apply<10,18>(511).value == 523264u));
assert((Packed<uint32_t>().apply<10,18>(0).value == 0u));
assert((Packed<uint32_t>().apply<10,18>(297).value == 304128u));
assert((Packed<uint32_t>().apply<10,18>(476).value == 487424u));
assert((Packed<uint32_t>().apply<10,18>(421).value == 431104u));

assert((Packed<uint32_t>().apply<10,19>(1023).value == 1047552u));
assert((Packed<uint32_t>().apply<10,19>(0).value == 0u));
assert((Packed<uint32_t>().apply<10,19>(979).value == 1002496u));
assert((Packed<uint32_t>().apply<10,19>(823).value == 842752u));
assert((Packed<uint32_t>().apply<10,19>(81).value == 82944u));

assert((Packed<uint32_t>().apply<10,20>(2047).value == 2096128u));
assert((Packed<uint32_t>().apply<10,20>(0).value == 0u));
assert((Packed<uint32_t>().apply<10,20>(2041).value == 2089984u));
assert((Packed<uint32_t>().apply<10,20>(67).value == 68608u));
assert((Packed<uint32_t>().apply<10,20>(1838).value == 1882112u));

assert((Packed<uint32_t>().apply<10,21>(4095).value == 4193280u));
assert((Packed<uint32_t>().apply<10,21>(0).value == 0u));
assert((Packed<uint32_t>().apply<10,21>(581).value == 594944u));
assert((Packed<uint32_t>().apply<10,21>(1281).value == 1311744u));
assert((Packed<uint32_t>().apply<10,21>(616).value == 630784u));

assert((Packed<uint32_t>().apply<10,22>(8191).value == 8387584u));
assert((Packed<uint32_t>().apply<10,22>(0).value == 0u));
assert((Packed<uint32_t>().apply<10,22>(5627).value == 5762048u));
assert((Packed<uint32_t>().apply<10,22>(6446).value == 6600704u));
assert((Packed<uint32_t>().apply<10,22>(7307).value == 7482368u));

assert((Packed<uint32_t>().apply<10,23>(16383).value == 16776192u));
assert((Packed<uint32_t>().apply<10,23>(0).value == 0u));
assert((Packed<uint32_t>().apply<10,23>(15777).value == 16155648u));
assert((Packed<uint32_t>().apply<10,23>(13556).value == 13881344u));
assert((Packed<uint32_t>().apply<10,23>(300).value == 307200u));

assert((Packed<uint32_t>().apply<11,16>(63).value == 129024u));
assert((Packed<uint32_t>().apply<11,16>(0).value == 0u));
assert((Packed<uint32_t>().apply<11,16>(24).value == 49152u));
assert((Packed<uint32_t>().apply<11,16>(39).value == 79872u));
assert((Packed<uint32_t>().apply<11,16>(14).value == 28672u));

assert((Packed<uint32_t>().apply<11,17>(127).value == 260096u));
assert((Packed<uint32_t>().apply<11,17>(0).value == 0u));
assert((Packed<uint32_t>().apply<11,17>(8).value == 16384u));
assert((Packed<uint32_t>().apply<11,17>(9).value == 18432u));
assert((Packed<uint32_t>().apply<11,17>(68).value == 139264u));

assert((Packed<uint32_t>().apply<11,18>(255).value == 522240u));
assert((Packed<uint32_t>().apply<11,18>(0).value == 0u));
assert((Packed<uint32_t>().apply<11,18>(117).value == 239616u));
assert((Packed<uint32_t>().apply<11,18>(130).value == 266240u));
assert((Packed<uint32_t>().apply<11,18>(135).value == 276480u));

assert((Packed<uint32_t>().apply<11,19>(511).value == 1046528u));
assert((Packed<uint32_t>().apply<11,19>(0).value == 0u));
assert((Packed<uint32_t>().apply<11,19>(173).value == 354304u));
assert((Packed<uint32_t>().apply<11,19>(65).value == 133120u));
assert((Packed<uint32_t>().apply<11,19>(442).value == 905216u));

assert((Packed<uint32_t>().apply<11,20>(1023).value == 2095104u));
assert((Packed<uint32_t>().apply<11,20>(0).value == 0u));
assert((Packed<uint32_t>().apply<11,20>(238).value == 487424u));
assert((Packed<uint32_t>().apply<11,20>(888).value == 1818624u));
assert((Packed<uint32_t>().apply<11,20>(295).value == 604160u));

assert((Packed<uint32_t>().apply<11,21>(2047).value == 4192256u));
assert((Packed<uint32_t>().apply<11,21>(0).value == 0u));
assert((Packed<uint32_t>().apply<11,21>(1501).value == 3074048u));
assert((Packed<uint32_t>().apply<11,21>(1145).value == 2344960u));
assert((Packed<uint32_t>().apply<11,21>(1636).value == 3350528u));

assert((Packed<uint32_t>().apply<11,22>(4095).value == 8386560u));
assert((Packed<uint32_t>().apply<11,22>(0).value == 0u));
assert((Packed<uint32_t>().apply<11,22>(834).value == 1708032u));
assert((Packed<uint32_t>().apply<11,22>(2849).value == 5834752u));
assert((Packed<uint32_t>().apply<11,22>(2621).value == 5367808u));

assert((Packed<uint32_t>().apply<11,23>(8191).value == 16775168u));
assert((Packed<uint32_t>().apply<11,23>(0).value == 0u));
assert((Packed<uint32_t>().apply<11,23>(6560).value == 13434880u));
assert((Packed<uint32_t>().apply<11,23>(2233).value == 4573184u));
assert((Packed<uint32_t>().apply<11,23>(2549).value == 5220352u));

assert((Packed<uint32_t>().apply<12,16>(31).value == 126976u));
assert((Packed<uint32_t>().apply<12,16>(0).value == 0u));
assert((Packed<uint32_t>().apply<12,16>(19).value == 77824u));
assert((Packed<uint32_t>().apply<12,16>(15).value == 61440u));
assert((Packed<uint32_t>().apply<12,16>(23).value == 94208u));

assert((Packed<uint32_t>().apply<12,17>(63).value == 258048u));
assert((Packed<uint32_t>().apply<12,17>(0).value == 0u));
assert((Packed<uint32_t>().apply<12,17>(16).value == 65536u));
assert((Packed<uint32_t>().apply<12,17>(26).value == 106496u));
assert((Packed<uint32_t>().apply<12,17>(12).value == 49152u));

assert((Packed<uint32_t>().apply<12,18>(127).value == 520192u));
assert((Packed<uint32_t>().apply<12,18>(0).value == 0u));
assert((Packed<uint32_t>().apply<12,18>(77).value == 315392u));
assert((Packed<uint32_t>().apply<12,18>(101).value == 413696u));
assert((Packed<uint32_t>().apply<12,18>(29).value == 118784u));

assert((Packed<uint32_t>().apply<12,19>(255).value == 1044480u));
assert((Packed<uint32_t>().apply<12,19>(0).value == 0u));
assert((Packed<uint32_t>().apply<12,19>(84).value == 344064u));
assert((Packed<uint32_t>().apply<12,19>(23).value == 94208u));
assert((Packed<uint32_t>().apply<12,19>(111).value == 454656u));

assert((Packed<uint32_t>().apply<12,20>(511).value == 2093056u));
assert((Packed<uint32_t>().apply<12,20>(0).value == 0u));
assert((Packed<uint32_t>().apply<12,20>(261).value == 1069056u));
assert((Packed<uint32_t>().apply<12,20>(446).value == 1826816u));
assert((Packed<uint32_t>().apply<12,20>(219).value == 897024u));

assert((Packed<uint32_t>().apply<12,21>(1023).value == 4190208u));
assert((Packed<uint32_t>().apply<12,21>(0).value == 0u));
assert((Packed<uint32_t>().apply<12,21>(1011).value == 4141056u));
assert((Packed<uint32_t>().apply<12,21>(111).value == 454656u));
assert((Packed<uint32_t>().apply<12,21>(956).value == 3915776u));

assert((Packed<uint32_t>().apply<12,22>(2047).value == 8384512u));
assert((Packed<uint32_t>().apply<12,22>(0).value == 0u));
assert((Packed<uint32_t>().apply<12,22>(1106).value == 4530176u));
assert((Packed<uint32_t>().apply<12,22>(1000).value == 4096000u));
assert((Packed<uint32_t>().apply<12,22>(180).value == 737280u));

assert((Packed<uint32_t>().apply<12,23>(4095).value == 16773120u));
assert((Packed<uint32_t>().apply<12,23>(0).value == 0u));
assert((Packed<uint32_t>().apply<12,23>(595).value == 2437120u));
assert((Packed<uint32_t>().apply<12,23>(1456).value == 5963776u));
assert((Packed<uint32_t>().apply<12,23>(3565).value == 14602240u));

assert((Packed<uint32_t>().apply<13,16>(15).value == 122880u));
assert((Packed<uint32_t>().apply<13,16>(0).value == 0u));
assert((Packed<uint32_t>().apply<13,16>(5).value == 40960u));
assert((Packed<uint32_t>().apply<13,16>(8).value == 65536u));
assert((Packed<uint32_t>().apply<13,16>(1).value == 8192u));

assert((Packed<uint32_t>().apply<13,17>(31).value == 253952u));
assert((Packed<uint32_t>().apply<13,17>(0).value == 0u));
assert((Packed<uint32_t>().apply<13,17>(6).value == 49152u));
assert((Packed<uint32_t>().apply<13,17>(9).value == 73728u));
assert((Packed<uint32_t>().apply<13,17>(29).value == 237568u));

assert((Packed<uint32_t>().apply<13,18>(63).value == 516096u));
assert((Packed<uint32_t>().apply<13,18>(49).value == 401408u));
assert((Packed<uint32_t>().apply<13,18>(34).value == 278528u));
assert((Packed<uint32_t>().apply<13,18>(0).value == 0u));

assert((Packed<uint32_t>().apply<13,19>(127).value == 1040384u));
assert((Packed<uint32_t>().apply<13,19>(0).value == 0u));
assert((Packed<uint32_t>().apply<13,19>(117).value == 958464u));
assert((Packed<uint32_t>().apply<13,19>(61).value == 499712u));
assert((Packed<uint32_t>().apply<13,19>(44).value == 360448u));

assert((Packed<uint32_t>().apply<13,20>(255).value == 2088960u));
assert((Packed<uint32_t>().apply<13,20>(0).value == 0u));
assert((Packed<uint32_t>().apply<13,20>(136).value == 1114112u));
assert((Packed<uint32_t>().apply<13,20>(23).value == 188416u));
assert((Packed<uint32_t>().apply<13,20>(63).value == 516096u));

assert((Packed<uint32_t>().apply<13,21>(511).value == 4186112u));
assert((Packed<uint32_t>().apply<13,21>(0).value == 0u));
assert((Packed<uint32_t>().apply<13,21>(140).value == 1146880u));
assert((Packed<uint32_t>().apply<13,21>(443).value == 3629056u));
assert((Packed<uint32_t>().apply<13,21>(323).value == 2646016u));

assert((Packed<uint32_t>().apply<13,22>(1023).value == 8380416u));
assert((Packed<uint32_t>().apply<13,22>(0).value == 0u));
assert((Packed<uint32_t>().apply<13,22>(631).value == 5169152u));
assert((Packed<uint32_t>().apply<13,22>(200).value == 1638400u));
assert((Packed<uint32_t>().apply<13,22>(984).value == 8060928u));

assert((Packed<uint32_t>().apply<13,23>(2047).value == 16769024u));
assert((Packed<uint32_t>().apply<13,23>(0).value == 0u));
assert((Packed<uint32_t>().apply<13,23>(1213).value == 9936896u));
assert((Packed<uint32_t>().apply<13,23>(39).value == 319488u));
assert((Packed<uint32_t>().apply<13,23>(558).value == 4571136u));

assert((Packed<uint32_t>().apply<14,16>(7).value == 114688u));
assert((Packed<uint32_t>().apply<14,16>(0).value == 0u));
assert((Packed<uint32_t>().apply<14,16>(2).value == 32768u));
assert((Packed<uint32_t>().apply<14,16>(4).value == 65536u));
assert((Packed<uint32_t>().apply<14,16>(6).value == 98304u));

assert((Packed<uint32_t>().apply<14,17>(0).value == 0u));
assert((Packed<uint32_t>().apply<14,17>(15).value == 245760u));
assert((Packed<uint32_t>().apply<14,17>(3).value == 49152u));

assert((Packed<uint32_t>().apply<14,18>(31).value == 507904u));
assert((Packed<uint32_t>().apply<14,18>(0).value == 0u));
assert((Packed<uint32_t>().apply<14,18>(13).value == 212992u));
assert((Packed<uint32_t>().apply<14,18>(25).value == 409600u));
assert((Packed<uint32_t>().apply<14,18>(24).value == 393216u));

assert((Packed<uint32_t>().apply<14,19>(63).value == 1032192u));
assert((Packed<uint32_t>().apply<14,19>(0).value == 0u));
assert((Packed<uint32_t>().apply<14,19>(40).value == 655360u));
assert((Packed<uint32_t>().apply<14,19>(49).value == 802816u));
assert((Packed<uint32_t>().apply<14,19>(24).value == 393216u));

assert((Packed<uint32_t>().apply<14,20>(127).value == 2080768u));
assert((Packed<uint32_t>().apply<14,20>(0).value == 0u));
assert((Packed<uint32_t>().apply<14,20>(78).value == 1277952u));
assert((Packed<uint32_t>().apply<14,20>(20).value == 327680u));
assert((Packed<uint32_t>().apply<14,20>(74).value == 1212416u));

assert((Packed<uint32_t>().apply<14,21>(255).value == 4177920u));
assert((Packed<uint32_t>().apply<14,21>(0).value == 0u));
assert((Packed<uint32_t>().apply<14,21>(77).value == 1261568u));
assert((Packed<uint32_t>().apply<14,21>(92).value == 1507328u));
assert((Packed<uint32_t>().apply<14,21>(252).value == 4128768u));

assert((Packed<uint32_t>().apply<14,22>(511).value == 8372224u));
assert((Packed<uint32_t>().apply<14,22>(0).value == 0u));
assert((Packed<uint32_t>().apply<14,22>(485).value == 7946240u));
assert((Packed<uint32_t>().apply<14,22>(148).value == 2424832u));
assert((Packed<uint32_t>().apply<14,22>(113).value == 1851392u));

assert((Packed<uint32_t>().apply<14,23>(1023).value == 16760832u));
assert((Packed<uint32_t>().apply<14,23>(0).value == 0u));
assert((Packed<uint32_t>().apply<14,23>(630).value == 10321920u));
assert((Packed<uint32_t>().apply<14,23>(794).value == 13008896u));
assert((Packed<uint32_t>().apply<14,23>(732).value == 11993088u));

assert((Packed<uint32_t>().apply<15,16>(3).value == 98304u));
assert((Packed<uint32_t>().apply<15,16>(0).value == 0u));
assert((Packed<uint32_t>().apply<15,16>(2).value == 65536u));

assert((Packed<uint32_t>().apply<15,17>(0).value == 0u));
assert((Packed<uint32_t>().apply<15,17>(7).value == 229376u));
assert((Packed<uint32_t>().apply<15,17>(4).value == 131072u));

assert((Packed<uint32_t>().apply<15,18>(15).value == 491520u));
assert((Packed<uint32_t>().apply<15,18>(0).value == 0u));
assert((Packed<uint32_t>().apply<15,18>(3).value == 98304u));
assert((Packed<uint32_t>().apply<15,18>(2).value == 65536u));

assert((Packed<uint32_t>().apply<15,19>(31).value == 1015808u));
assert((Packed<uint32_t>().apply<15,19>(0).value == 0u));
assert((Packed<uint32_t>().apply<15,19>(24).value == 786432u));
assert((Packed<uint32_t>().apply<15,19>(21).value == 688128u));

assert((Packed<uint32_t>().apply<15,20>(63).value == 2064384u));
assert((Packed<uint32_t>().apply<15,20>(0).value == 0u));
assert((Packed<uint32_t>().apply<15,20>(56).value == 1835008u));
assert((Packed<uint32_t>().apply<15,20>(19).value == 622592u));
assert((Packed<uint32_t>().apply<15,20>(37).value == 1212416u));

assert((Packed<uint32_t>().apply<15,21>(127).value == 4161536u));
assert((Packed<uint32_t>().apply<15,21>(0).value == 0u));
assert((Packed<uint32_t>().apply<15,21>(89).value == 2916352u));
assert((Packed<uint32_t>().apply<15,21>(14).value == 458752u));
assert((Packed<uint32_t>().apply<15,21>(28).value == 917504u));

assert((Packed<uint32_t>().apply<15,22>(255).value == 8355840u));
assert((Packed<uint32_t>().apply<15,22>(43).value == 1409024u));
assert((Packed<uint32_t>().apply<15,22>(0).value == 0u));
assert((Packed<uint32_t>().apply<15,22>(231).value == 7569408u));

assert((Packed<uint32_t>().apply<15,23>(511).value == 16744448u));
assert((Packed<uint32_t>().apply<15,23>(0).value == 0u));
assert((Packed<uint32_t>().apply<15,23>(149).value == 4882432u));
assert((Packed<uint32_t>().apply<15,23>(478).value == 15663104u));
assert((Packed<uint32_t>().apply<15,23>(35).value == 1146880u));

assert((Packed<uint32_t>().apply<17,24>(255).value == 33423360u));
assert((Packed<uint32_t>().apply<17,24>(0).value == 0u));
assert((Packed<uint32_t>().apply<17,24>(146).value == 19136512u));
assert((Packed<uint32_t>().apply<17,24>(193).value == 25296896u));
assert((Packed<uint32_t>().apply<17,24>(45).value == 5898240u));

assert((Packed<uint32_t>().apply<17,25>(511).value == 66977792u));
assert((Packed<uint32_t>().apply<17,25>(0).value == 0u));
assert((Packed<uint32_t>().apply<17,25>(266).value == 34865152u));
assert((Packed<uint32_t>().apply<17,25>(309).value == 40501248u));
assert((Packed<uint32_t>().apply<17,25>(338).value == 44302336u));

assert((Packed<uint32_t>().apply<17,26>(1023).value == 134086656u));
assert((Packed<uint32_t>().apply<17,26>(0).value == 0u));
assert((Packed<uint32_t>().apply<17,26>(275).value == 36044800u));
assert((Packed<uint32_t>().apply<17,26>(212).value == 27787264u));
assert((Packed<uint32_t>().apply<17,26>(294).value == 38535168u));

assert((Packed<uint32_t>().apply<17,27>(2047).value == 268304384u));
assert((Packed<uint32_t>().apply<17,27>(0).value == 0u));
assert((Packed<uint32_t>().apply<17,27>(1857).value == 243400704u));
assert((Packed<uint32_t>().apply<17,27>(1882).value == 246677504u));
assert((Packed<uint32_t>().apply<17,27>(1452).value == 190316544u));

assert((Packed<uint32_t>().apply<17,28>(4095).value == 536739840u));
assert((Packed<uint32_t>().apply<17,28>(0).value == 0u));
assert((Packed<uint32_t>().apply<17,28>(4041).value == 529661952u));
assert((Packed<uint32_t>().apply<17,28>(2968).value == 389021696u));
assert((Packed<uint32_t>().apply<17,28>(3719).value == 487456768u));

assert((Packed<uint32_t>().apply<17,29>(8191).value == 1073610752u));
assert((Packed<uint32_t>().apply<17,29>(0).value == 0u));
assert((Packed<uint32_t>().apply<17,29>(1566).value == 205258752u));
assert((Packed<uint32_t>().apply<17,29>(5002).value == 655622144u));
assert((Packed<uint32_t>().apply<17,29>(4377).value == 573702144u));

assert((Packed<uint32_t>().apply<17,30>(16383).value == 2147352576u));
assert((Packed<uint32_t>().apply<17,30>(0).value == 0u));
assert((Packed<uint32_t>().apply<17,30>(12357).value == 1619656704u));
assert((Packed<uint32_t>().apply<17,30>(13232).value == 1734344704u));
assert((Packed<uint32_t>().apply<17,30>(11168).value == 1463812096u));

assert((Packed<uint32_t>().apply<17,31>(32767).value == 4294836224u));
assert((Packed<uint32_t>().apply<17,31>(0).value == 0u));
assert((Packed<uint32_t>().apply<17,31>(2148).value == 281542656u));
assert((Packed<uint32_t>().apply<17,31>(6835).value == 895877120u));
assert((Packed<uint32_t>().apply<17,31>(2807).value == 367919104u));

assert((Packed<uint32_t>().apply<18,24>(0).value == 0u));
assert((Packed<uint32_t>().apply<18,24>(127).value == 33292288u));
assert((Packed<uint32_t>().apply<18,24>(104).value == 27262976u));
assert((Packed<uint32_t>().apply<18,24>(83).value == 21757952u));

assert((Packed<uint32_t>().apply<18,25>(255).value == 66846720u));
assert((Packed<uint32_t>().apply<18,25>(0).value == 0u));
assert((Packed<uint32_t>().apply<18,25>(75).value == 19660800u));
assert((Packed<uint32_t>().apply<18,25>(219).value == 57409536u));
assert((Packed<uint32_t>().apply<18,25>(8).value == 2097152u));

assert((Packed<uint32_t>().apply<18,26>(511).value == 133955584u));
assert((Packed<uint32_t>().apply<18,26>(0).value == 0u));
assert((Packed<uint32_t>().apply<18,26>(298).value == 78118912u));
assert((Packed<uint32_t>().apply<18,26>(148).value == 38797312u));
assert((Packed<uint32_t>().apply<18,26>(460).value == 120586240u));

assert((Packed<uint32_t>().apply<18,27>(1023).value == 268173312u));
assert((Packed<uint32_t>().apply<18,27>(0).value == 0u));
assert((Packed<uint32_t>().apply<18,27>(1021).value == 267649024u));
assert((Packed<uint32_t>().apply<18,27>(326).value == 85458944u));
assert((Packed<uint32_t>().apply<18,27>(148).value == 38797312u));

assert((Packed<uint32_t>().apply<18,28>(2047).value == 536608768u));
assert((Packed<uint32_t>().apply<18,28>(0).value == 0u));
assert((Packed<uint32_t>().apply<18,28>(1460).value == 382730240u));
assert((Packed<uint32_t>().apply<18,28>(812).value == 212860928u));
assert((Packed<uint32_t>().apply<18,28>(1144).value == 299892736u));

assert((Packed<uint32_t>().apply<18,29>(4095).value == 1073479680u));
assert((Packed<uint32_t>().apply<18,29>(0).value == 0u));
assert((Packed<uint32_t>().apply<18,29>(3590).value == 941096960u));
assert((Packed<uint32_t>().apply<18,29>(2171).value == 569114624u));
assert((Packed<uint32_t>().apply<18,29>(3491).value == 915144704u));

assert((Packed<uint32_t>().apply<18,30>(8191).value == 2147221504u));
assert((Packed<uint32_t>().apply<18,30>(0).value == 0u));
assert((Packed<uint32_t>().apply<18,30>(2560).value == 671088640u));
assert((Packed<uint32_t>().apply<18,30>(1751).value == 459014144u));
assert((Packed<uint32_t>().apply<18,30>(4696).value == 1231028224u));

assert((Packed<uint32_t>().apply<18,31>(16383).value == 4294705152u));
assert((Packed<uint32_t>().apply<18,31>(0).value == 0u));
assert((Packed<uint32_t>().apply<18,31>(8899).value == 2332819456u));
assert((Packed<uint32_t>().apply<18,31>(4583).value == 1201405952u));
assert((Packed<uint32_t>().apply<18,31>(10495).value == 2751201280u));

assert((Packed<uint32_t>().apply<19,24>(63).value == 33030144u));
assert((Packed<uint32_t>().apply<19,24>(0).value == 0u));
assert((Packed<uint32_t>().apply<19,24>(17).value == 8912896u));
assert((Packed<uint32_t>().apply<19,24>(15).value == 7864320u));
assert((Packed<uint32_t>().apply<19,24>(29).value == 15204352u));

assert((Packed<uint32_t>().apply<19,25>(127).value == 66584576u));
assert((Packed<uint32_t>().apply<19,25>(0).value == 0u));
assert((Packed<uint32_t>().apply<19,25>(100).value == 52428800u));
assert((Packed<uint32_t>().apply<19,25>(95).value == 49807360u));
assert((Packed<uint32_t>().apply<19,25>(83).value == 43515904u));

assert((Packed<uint32_t>().apply<19,26>(255).value == 133693440u));
assert((Packed<uint32_t>().apply<19,26>(0).value == 0u));
assert((Packed<uint32_t>().apply<19,26>(243).value == 127401984u));
assert((Packed<uint32_t>().apply<19,26>(132).value == 69206016u));
assert((Packed<uint32_t>().apply<19,26>(96).value == 50331648u));

assert((Packed<uint32_t>().apply<19,27>(511).value == 267911168u));
assert((Packed<uint32_t>().apply<19,27>(0).value == 0u));
assert((Packed<uint32_t>().apply<19,27>(21).value == 11010048u));
assert((Packed<uint32_t>().apply<19,27>(283).value == 148373504u));
assert((Packed<uint32_t>().apply<19,27>(7).value == 3670016u));

assert((Packed<uint32_t>().apply<19,28>(1023).value == 536346624u));
assert((Packed<uint32_t>().apply<19,28>(0).value == 0u));
assert((Packed<uint32_t>().apply<19,28>(926).value == 485490688u));
assert((Packed<uint32_t>().apply<19,28>(721).value == 378011648u));
assert((Packed<uint32_t>().apply<19,28>(342).value == 179306496u));

assert((Packed<uint32_t>().apply<19,29>(2047).value == 1073217536u));
assert((Packed<uint32_t>().apply<19,29>(0).value == 0u));
assert((Packed<uint32_t>().apply<19,29>(1327).value == 695730176u));
assert((Packed<uint32_t>().apply<19,29>(1488).value == 780140544u));
assert((Packed<uint32_t>().apply<19,29>(1010).value == 529530880u));

assert((Packed<uint32_t>().apply<19,30>(4095).value == 2146959360u));
assert((Packed<uint32_t>().apply<19,30>(0).value == 0u));
assert((Packed<uint32_t>().apply<19,30>(2578).value == 1351614464u));
assert((Packed<uint32_t>().apply<19,30>(3739).value == 1960312832u));
assert((Packed<uint32_t>().apply<19,30>(1729).value == 906493952u));

assert((Packed<uint32_t>().apply<19,31>(8191).value == 4294443008u));
assert((Packed<uint32_t>().apply<19,31>(0).value == 0u));
assert((Packed<uint32_t>().apply<19,31>(6000).value == 3145728000u));
assert((Packed<uint32_t>().apply<19,31>(7337).value == 3846701056u));
assert((Packed<uint32_t>().apply<19,31>(7791).value == 4084727808u));

assert((Packed<uint32_t>().apply<20,24>(31).value == 32505856u));
assert((Packed<uint32_t>().apply<20,24>(0).value == 0u));
assert((Packed<uint32_t>().apply<20,24>(17).value == 17825792u));
assert((Packed<uint32_t>().apply<20,24>(12).value == 12582912u));
assert((Packed<uint32_t>().apply<20,24>(30).value == 31457280u));

assert((Packed<uint32_t>().apply<20,25>(63).value == 66060288u));
assert((Packed<uint32_t>().apply<20,25>(0).value == 0u));
assert((Packed<uint32_t>().apply<20,25>(52).value == 54525952u));
assert((Packed<uint32_t>().apply<20,25>(33).value == 34603008u));
assert((Packed<uint32_t>().apply<20,25>(42).value == 44040192u));

assert((Packed<uint32_t>().apply<20,26>(127).value == 133169152u));
assert((Packed<uint32_t>().apply<20,26>(0).value == 0u));
assert((Packed<uint32_t>().apply<20,26>(114).value == 119537664u));
assert((Packed<uint32_t>().apply<20,26>(40).value == 41943040u));
assert((Packed<uint32_t>().apply<20,26>(122).value == 127926272u));

assert((Packed<uint32_t>().apply<20,27>(255).value == 267386880u));
assert((Packed<uint32_t>().apply<20,27>(0).value == 0u));
assert((Packed<uint32_t>().apply<20,27>(155).value == 162529280u));
assert((Packed<uint32_t>().apply<20,27>(90).value == 94371840u));
assert((Packed<uint32_t>().apply<20,27>(189).value == 198180864u));

assert((Packed<uint32_t>().apply<20,28>(511).value == 535822336u));
assert((Packed<uint32_t>().apply<20,28>(0).value == 0u));
assert((Packed<uint32_t>().apply<20,28>(226).value == 236978176u));
assert((Packed<uint32_t>().apply<20,28>(461).value == 483393536u));
assert((Packed<uint32_t>().apply<20,28>(404).value == 423624704u));

assert((Packed<uint32_t>().apply<20,29>(1023).value == 1072693248u));
assert((Packed<uint32_t>().apply<20,29>(0).value == 0u));
assert((Packed<uint32_t>().apply<20,29>(746).value == 782237696u));
assert((Packed<uint32_t>().apply<20,29>(384).value == 402653184u));
assert((Packed<uint32_t>().apply<20,29>(161).value == 168820736u));

assert((Packed<uint32_t>().apply<20,30>(2047).value == 2146435072u));
assert((Packed<uint32_t>().apply<20,30>(0).value == 0u));
assert((Packed<uint32_t>().apply<20,30>(327).value == 342884352u));
assert((Packed<uint32_t>().apply<20,30>(829).value == 869269504u));
assert((Packed<uint32_t>().apply<20,30>(226).value == 236978176u));

assert((Packed<uint32_t>().apply<20,31>(4095).value == 4293918720u));
assert((Packed<uint32_t>().apply<20,31>(0).value == 0u));
assert((Packed<uint32_t>().apply<20,31>(1064).value == 1115684864u));
assert((Packed<uint32_t>().apply<20,31>(2161).value == 2265972736u));
assert((Packed<uint32_t>().apply<20,31>(2755).value == 2888826880u));

assert((Packed<uint32_t>().apply<21,24>(15).value == 31457280u));
assert((Packed<uint32_t>().apply<21,24>(0).value == 0u));
assert((Packed<uint32_t>().apply<21,24>(8).value == 16777216u));
assert((Packed<uint32_t>().apply<21,24>(10).value == 20971520u));

assert((Packed<uint32_t>().apply<21,25>(31).value == 65011712u));
assert((Packed<uint32_t>().apply<21,25>(0).value == 0u));
assert((Packed<uint32_t>().apply<21,25>(1).value == 2097152u));
assert((Packed<uint32_t>().apply<21,25>(30).value == 62914560u));
assert((Packed<uint32_t>().apply<21,25>(4).value == 8388608u));

assert((Packed<uint32_t>().apply<21,26>(63).value == 132120576u));
assert((Packed<uint32_t>().apply<21,26>(0).value == 0u));
assert((Packed<uint32_t>().apply<21,26>(60).value == 125829120u));
assert((Packed<uint32_t>().apply<21,26>(21).value == 44040192u));
assert((Packed<uint32_t>().apply<21,26>(54).value == 113246208u));

assert((Packed<uint32_t>().apply<21,27>(127).value == 266338304u));
assert((Packed<uint32_t>().apply<21,27>(0).value == 0u));
assert((Packed<uint32_t>().apply<21,27>(16).value == 33554432u));
assert((Packed<uint32_t>().apply<21,27>(49).value == 102760448u));
assert((Packed<uint32_t>().apply<21,27>(39).value == 81788928u));

assert((Packed<uint32_t>().apply<21,28>(255).value == 534773760u));
assert((Packed<uint32_t>().apply<21,28>(0).value == 0u));
assert((Packed<uint32_t>().apply<21,28>(195).value == 408944640u));
assert((Packed<uint32_t>().apply<21,28>(149).value == 312475648u));
assert((Packed<uint32_t>().apply<21,28>(115).value == 241172480u));

assert((Packed<uint32_t>().apply<21,29>(511).value == 1071644672u));
assert((Packed<uint32_t>().apply<21,29>(0).value == 0u));
assert((Packed<uint32_t>().apply<21,29>(215).value == 450887680u));
assert((Packed<uint32_t>().apply<21,29>(320).value == 671088640u));
assert((Packed<uint32_t>().apply<21,29>(84).value == 176160768u));

assert((Packed<uint32_t>().apply<21,30>(1023).value == 2145386496u));
assert((Packed<uint32_t>().apply<21,30>(0).value == 0u));
assert((Packed<uint32_t>().apply<21,30>(912).value == 1912602624u));
assert((Packed<uint32_t>().apply<21,30>(420).value == 880803840u));
assert((Packed<uint32_t>().apply<21,30>(732).value == 1535115264u));

assert((Packed<uint32_t>().apply<21,31>(2047).value == 4292870144u));
assert((Packed<uint32_t>().apply<21,31>(0).value == 0u));
assert((Packed<uint32_t>().apply<21,31>(1696).value == 3556769792u));
assert((Packed<uint32_t>().apply<21,31>(1145).value == 2401239040u));
assert((Packed<uint32_t>().apply<21,31>(1312).value == 2751463424u));

assert((Packed<uint32_t>().apply<22,24>(7).value == 29360128u));
assert((Packed<uint32_t>().apply<22,24>(0).value == 0u));
assert((Packed<uint32_t>().apply<22,24>(6).value == 25165824u));
assert((Packed<uint32_t>().apply<22,24>(2).value == 8388608u));

assert((Packed<uint32_t>().apply<22,25>(0).value == 0u));
assert((Packed<uint32_t>().apply<22,25>(6).value == 25165824u));
assert((Packed<uint32_t>().apply<22,25>(15).value == 62914560u));
assert((Packed<uint32_t>().apply<22,25>(4).value == 16777216u));

assert((Packed<uint32_t>().apply<22,26>(31).value == 130023424u));
assert((Packed<uint32_t>().apply<22,26>(0).value == 0u));
assert((Packed<uint32_t>().apply<22,26>(27).value == 113246208u));
assert((Packed<uint32_t>().apply<22,26>(10).value == 41943040u));
assert((Packed<uint32_t>().apply<22,26>(24).value == 100663296u));

assert((Packed<uint32_t>().apply<22,27>(63).value == 264241152u));
assert((Packed<uint32_t>().apply<22,27>(0).value == 0u));
assert((Packed<uint32_t>().apply<22,27>(62).value == 260046848u));
assert((Packed<uint32_t>().apply<22,27>(34).value == 142606336u));
assert((Packed<uint32_t>().apply<22,27>(38).value == 159383552u));

assert((Packed<uint32_t>().apply<22,28>(127).value == 532676608u));
assert((Packed<uint32_t>().apply<22,28>(0).value == 0u));
assert((Packed<uint32_t>().apply<22,28>(88).value == 369098752u));
assert((Packed<uint32_t>().apply<22,28>(97).value == 406847488u));
assert((Packed<uint32_t>().apply<22,28>(125).value == 524288000u));

assert((Packed<uint32_t>().apply<22,29>(255).value == 1069547520u));
assert((Packed<uint32_t>().apply<22,29>(0).value == 0u));
assert((Packed<uint32_t>().apply<22,29>(162).value == 679477248u));
assert((Packed<uint32_t>().apply<22,29>(125).value == 524288000u));
assert((Packed<uint32_t>().apply<22,29>(221).value == 926941184u));

assert((Packed<uint32_t>().apply<22,30>(511).value == 2143289344u));
assert((Packed<uint32_t>().apply<22,30>(0).value == 0u));
assert((Packed<uint32_t>().apply<22,30>(154).value == 645922816u));
assert((Packed<uint32_t>().apply<22,30>(118).value == 494927872u));
assert((Packed<uint32_t>().apply<22,30>(63).value == 264241152u));

assert((Packed<uint32_t>().apply<22,31>(1023).value == 4290772992u));
assert((Packed<uint32_t>().apply<22,31>(0).value == 0u));
assert((Packed<uint32_t>().apply<22,31>(87).value == 364904448u));
assert((Packed<uint32_t>().apply<22,31>(946).value == 3967811584u));
assert((Packed<uint32_t>().apply<22,31>(584).value == 2449473536u));

assert((Packed<uint32_t>().apply<23,24>(3).value == 25165824u));
assert((Packed<uint32_t>().apply<23,24>(0).value == 0u));
assert((Packed<uint32_t>().apply<23,24>(1).value == 8388608u));

assert((Packed<uint32_t>().apply<23,25>(7).value == 58720256u));
assert((Packed<uint32_t>().apply<23,25>(0).value == 0u));
assert((Packed<uint32_t>().apply<23,25>(6).value == 50331648u));

assert((Packed<uint32_t>().apply<23,26>(0).value == 0u));
assert((Packed<uint32_t>().apply<23,26>(15).value == 125829120u));
assert((Packed<uint32_t>().apply<23,26>(6).value == 50331648u));
assert((Packed<uint32_t>().apply<23,26>(7).value == 58720256u));

assert((Packed<uint32_t>().apply<23,27>(31).value == 260046848u));
assert((Packed<uint32_t>().apply<23,27>(0).value == 0u));
assert((Packed<uint32_t>().apply<23,27>(7).value == 58720256u));
assert((Packed<uint32_t>().apply<23,27>(3).value == 25165824u));
assert((Packed<uint32_t>().apply<23,27>(15).value == 125829120u));

assert((Packed<uint32_t>().apply<23,28>(63).value == 528482304u));
assert((Packed<uint32_t>().apply<23,28>(0).value == 0u));
assert((Packed<uint32_t>().apply<23,28>(54).value == 452984832u));
assert((Packed<uint32_t>().apply<23,28>(18).value == 150994944u));
assert((Packed<uint32_t>().apply<23,28>(39).value == 327155712u));

assert((Packed<uint32_t>().apply<23,29>(127).value == 1065353216u));
assert((Packed<uint32_t>().apply<23,29>(0).value == 0u));
assert((Packed<uint32_t>().apply<23,29>(126).value == 1056964608u));
assert((Packed<uint32_t>().apply<23,29>(31).value == 260046848u));
assert((Packed<uint32_t>().apply<23,29>(102).value == 855638016u));

assert((Packed<uint32_t>().apply<23,30>(255).value == 2139095040u));
assert((Packed<uint32_t>().apply<23,30>(0).value == 0u));
assert((Packed<uint32_t>().apply<23,30>(62).value == 520093696u));
assert((Packed<uint32_t>().apply<23,30>(168).value == 1409286144u));
assert((Packed<uint32_t>().apply<23,30>(234).value == 1962934272u));

assert((Packed<uint32_t>().apply<23,31>(511).value == 4286578688u));
assert((Packed<uint32_t>().apply<23,31>(0).value == 0u));
assert((Packed<uint32_t>().apply<23,31>(45).value == 377487360u));
assert((Packed<uint32_t>().apply<23,31>(476).value == 3992977408u));
assert((Packed<uint32_t>().apply<23,31>(468).value == 3925868544u));

