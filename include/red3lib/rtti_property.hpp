#pragma once

#include <red3lib/detail/asserts.hpp>
#include <red3lib/rtti_object.hpp>

namespace red3lib
{
// CRTTI: CProperty
struct rtti_property : rtti_object
{
};
RED3LIB_ASSERT_SIZE(rtti_property, 0x8);
} // namespace red3lib
