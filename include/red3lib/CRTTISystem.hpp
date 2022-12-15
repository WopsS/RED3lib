#pragma once

#include <cstdint>

#include <red3lib/CName.hpp>
#include <red3lib/containers/TDynArray.hpp>
#include <red3lib/containers/THashMap.hpp>
#include <red3lib/detail/Asserts.hpp>

namespace red3lib
{
struct IClassBuilder;
struct CFunction;
struct IFile;

struct IRTTIBaseObject
{
    virtual ~IRTTIBaseObject() = 0;
};

struct IRTTIType
{
    virtual ~IRTTIType() = 0;                                           // 00
    virtual CName GetName() const = 0;                                  // 08
    virtual uint32_t GetSize() const = 0;                               // 10
    virtual uint32_t GetAlignment() const = 0;                          // 18
    virtual uint32_t GetType() const = 0;                               // 20
    virtual uint32_t GetUnkFlag1() const = 0;                           // 28
    virtual uint32_t GetUnkFlag2() const = 0;                           // 30
    virtual void Construct(void* aPtr) const = 0;                       // 38
    virtual void Destruct(void* aPtr) const = 0;                        // 40
    virtual bool Compare(void* aPtr1, void* aPtr2) const = 0;           // 48
    virtual bool Copy(void* aOut, const void* aPtr) const = 0;          // 50
    virtual bool Clean(void* aOut) const = 0;                           // 58
    virtual bool Serialize(IFile* aOut, void* aPtr) const = 0;          // 60
    virtual bool ToString(void* aPtr, void* aString) const = 0;         // 68
    virtual bool FromString(void* aPtr, void* aString) const = 0;       // 70
    virtual bool DebugValidate(void* aPtr, void* aString) const = 0;    // 78
    virtual uint32_t GetUnkFlag3() const = 0;                           // 80
    virtual uint32_t GetUnkFlag4() const = 0;                           // 88
};

struct CRTTISystem
{
    TDynArray<IClassBuilder*> builders;        // 00
    THashMap<CName, IRTTIType*> types;     // 10
    THashMap<CName, CFunction*> functions; // 40
    THashMap<CName, void> unk70;           // 70 - Probably THashMap, deduced this based on ASM pattern.
    THashMap<CName, void> unkA0;           // A0 - Probably THashMap, deduced this based on ASM pattern.
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
