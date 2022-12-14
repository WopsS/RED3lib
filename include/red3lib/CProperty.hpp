#pragma once

#include <red3lib/detail/Asserts.hpp>
#include <red3lib/IRTTIBaseObject.hpp>

namespace red3lib
{
struct CProperty : IRTTIBaseObject
{
};
RED3LIB_ASSERT_SIZE(CProperty, 0x8);
} // namespace red3lib
