#pragma once

#include <red3lib/name.hpp>
#include <red3lib/rtti_object.hpp>

namespace red3lib
{
// CRTTI: IRTTIType
struct rtti_type : rtti_object
{
    virtual name name() const noexcept = 0; // 08
};
RED3LIB_ASSERT_SIZE(rtti_type, 0x8);
} // namespace red3lib
