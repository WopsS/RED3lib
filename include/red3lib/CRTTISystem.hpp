#pragma once

#include <cstdint>

#include <red3lib/CNameHash.hpp>
#include <red3lib/containers/TDynArray.hpp>
#include <red3lib/containers/THashMap.hpp>
#include <red3lib/detail/Asserts.hpp>

namespace red3lib
{
struct IClassBuilder;
struct CFunction;
struct IRTTIType;

struct CRTTISystem
{
    TDynArray<IClassBuilder*> builders;        // 00
    THashMap<CNameHash, IRTTIType*> types;     // 10
    THashMap<CNameHash, CFunction*> functions; // 40
    THashMap<CNameHash, void> unk70;           // 70 - Probably THashMap, deduced this based on ASM pattern.
    THashMap<CNameHash, void> unkA0;           // A0 - Probably THashMap, deduced this based on ASM pattern.
    int64_t unkD0;                             // D0
    int32_t unkD8;                             // D8
    int32_t unkDC;                             // DC
    int32_t unkE0;                             // E0
    int32_t unkE4;                             // E4
    int64_t unkE8;                             // E8
    int32_t unkF8;                             // F8
};
RED3LIB_ASSERT_SIZE(CRTTISystem, 0xF8);
} // namespace red3lib
