#pragma once

#include <red3lib/detail/Asserts.hpp>

namespace red3lib
{
struct CClass;
struct IClassBuilder
{
    virtual ~IClassBuilder() = 0;

    virtual void sub_8() = 0;  // 08
    virtual void sub_10() = 0; // 10

    CClass* cls;
};
RED3LIB_ASSERT_SIZE(IClassBuilder, 0x10);
RED3LIB_ASSERT_OFFSET(IClassBuilder, cls, 0x8);
} // namespace red3lib
