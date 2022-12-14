#pragma once

#include <red3lib/detail/asserts.hpp>
#include <red3lib/rtti_class.hpp>

namespace red3lib
{
// CRTTI: IClassBuilder
struct rtti_class_builder
{
    virtual ~rtti_class_builder() = 0;

    virtual void sub_8() = 0;  // 08
    virtual void sub_10() = 0; // 10

    rtti_class* cls;
};
RED3LIB_ASSERT_SIZE(rtti_class_builder, 0x10);
RED3LIB_ASSERT_OFFSET(rtti_class_builder, cls, 0x8);
} // namespace red3lib
