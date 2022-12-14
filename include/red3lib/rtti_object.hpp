#pragma once

#include <red3lib/detail/asserts.hpp>

namespace red3lib
{
// CRTTI: IRTTIBaseObject
struct rtti_object
{
    virtual ~rtti_object() = default; // 00
};
RED3LIB_ASSERT_SIZE(rtti_object, 0x8);
} // namespace red3lib
