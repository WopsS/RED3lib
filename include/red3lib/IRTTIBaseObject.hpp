#pragma once

#include <red3lib/detail/Asserts.hpp>

namespace red3lib
{
struct IRTTIBaseObject
{
    virtual ~IRTTIBaseObject() = default; // 00
};
RED3LIB_ASSERT_SIZE(IRTTIBaseObject, 0x8);
} // namespace red3lib
