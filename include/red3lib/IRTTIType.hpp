#pragma once

#include <red3lib/CName.hpp>
#include <red3lib/IRTTIBaseObject.hpp>

namespace red3lib
{
struct IFile;

struct IRTTIType : IRTTIBaseObject
{
    virtual ~IRTTIType() = 0;                                        // 00
    virtual CName GetName() const = 0;                               // 08
    virtual uint32_t GetSize() const = 0;                            // 10
    virtual uint32_t GetAlignment() const = 0;                       // 18
    virtual uint32_t GetType() const = 0;                            // 20
    virtual uint32_t GetUnkFlag1() const = 0;                        // 28
    virtual uint32_t GetUnkFlag2() const = 0;                        // 30
    virtual void Construct(void* aPtr) const = 0;                    // 38
    virtual void Destruct(void* aPtr) const = 0;                     // 40
    virtual bool Compare(void* aPtr1, void* aPtr2) const = 0;        // 48
    virtual bool Copy(void* aOut, const void* aPtr) const = 0;       // 50
    virtual bool Clean(void* aOut) const = 0;                        // 58
    virtual bool Serialize(IFile* aOut, void* aPtr) const = 0;       // 60
    virtual bool ToString(void* aPtr, void* aString) const = 0;      // 68
    virtual bool FromString(void* aPtr, void* aString) const = 0;    // 70
    virtual bool DebugValidate(void* aPtr, void* aString) const = 0; // 78
    virtual uint32_t GetUnkFlag3() const = 0;                        // 80
    virtual uint32_t GetUnkFlag4() const = 0;                        // 88
};
RED3LIB_ASSERT_SIZE(IRTTIType, 0x8);
} // namespace red3lib
