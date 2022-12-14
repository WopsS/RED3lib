#pragma once

#include <cstdint>

#include <red3lib/containers/dyn_array.hpp>
#include <red3lib/containers/hash_map.hpp>
#include <red3lib/detail/asserts.hpp>
#include <red3lib/name.hpp>

namespace red3lib
{
struct rtti_class_builder;
struct rtti_function;
struct rtti_type;

struct rtti_system
{
    dyn_array<rtti_class_builder*> builders;  // 00
    hash_map<name, rtti_type*> types;         // 10
    hash_map<name, rtti_function*> functions; // 40
    hash_map<name, void> unk70;               // 70 - Probably hash_map, deduced this based on ASM pattern.
    hash_map<name, void> unkA0;               // A0 - Probably hash_map, deduced this based on ASM pattern.
    int64_t unkD0;                            // D0
    int32_t unkD8;                            // D8
    int32_t unkDC;                            // DC
    int32_t unkE0;                            // E0
    int32_t unkE4;                            // E4
    int64_t unkE8;                            // E8
    int32_t unkF8;                            // F8
};
RED3LIB_ASSERT_SIZE(rtti_system, 0xF8);
} // namespace red3lib
