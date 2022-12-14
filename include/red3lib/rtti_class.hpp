#pragma once

#include <cstdint>

#include <red3lib/containers/dyn_array.hpp>
#include <red3lib/detail/asserts.hpp>
#include <red3lib/name.hpp>
#include <red3lib/rtti_type.hpp>

namespace red3lib
{
struct rtti_function;
struct rtti_property;

// CRTTI: CClass
struct rtti_class : rtti_type
{
    rtti_function* find_function(red3lib::name func_name) const;

    std::int32_t unk8;                    // 08
    rtti_class* base;                     // 10
    std::int64_t unk18;                   // 18
    std::int64_t unk20;                   // 20
    std::int32_t unk28;                   // 28
    red3lib::name name;                   // 2C
    dyn_array<rtti_property*> properties; // 30
    std::int32_t unk3C;                   // 3C
    std::int32_t unk40;                   // 40
    std::int32_t unk44;                   // 44
    dyn_array<rtti_function*> functions;  // 48
    std::int32_t unk58;                   // 58
    std::int32_t unk5C;                   // 5C
    std::int32_t unk60;                   // 60
    std::int32_t scriptedSize;            // 64
    std::int32_t flags;                   // 68
    std::int32_t unk6C;                   // 6C
    std::int64_t unk70;                   // 70
    std::int64_t unk78;                   // 78
    std::int64_t unk80;                   // 80
    std::int64_t unk88;                   // 88
    std::int64_t unk90;                   // 90
    std::int64_t unk98;                   // 98
    std::int64_t unkA0;                   // A0
    std::int32_t unkA8;                   // A8
    std::int32_t unkAC;                   // AC
    std::int64_t unkB0;                   // B0
    std::int32_t unkB8;                   // B8
    std::int32_t unkBC;                   // BC
    std::int64_t unkC0;                   // C0
    std::int32_t unkC8;                   // C8
    std::int32_t unkCC;                   // CC
    std::int64_t unkD0;                   // D0
    std::int64_t unkD8;                   // D8
    std::int32_t unkE0;                   // E0
    std::int32_t unkE4;                   // E4
    std::int32_t unkE8;                   // E8
    std::int32_t unkEC;                   // EC
    std::int64_t unkF0;                   // F0
    std::int32_t unkF8;                   // F8
    std::int32_t unkFC;                   // FC
    std::int32_t unk100;                  // 100
    std::int32_t unk104;                  // 104
    std::int8_t unk108;                   // 108
};
RED3LIB_ASSERT_SIZE(rtti_class, 0x110);
RED3LIB_ASSERT_OFFSET(rtti_class, base, 0x10);
RED3LIB_ASSERT_OFFSET(rtti_class, name, 0x2C);
RED3LIB_ASSERT_OFFSET(rtti_class, properties, 0x30);
RED3LIB_ASSERT_OFFSET(rtti_class, functions, 0x48);
} // namespace red3lib
