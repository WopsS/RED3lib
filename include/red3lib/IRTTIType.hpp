#pragma once

#include <red3lib/CName.hpp>
#include <red3lib/IRTTIBaseObject.hpp>

namespace red3lib
{
struct IRTTIType : IRTTIBaseObject
{
    virtual CName name() const noexcept = 0; // 08
};
RED3LIB_ASSERT_SIZE(IRTTIType, 0x8);
} // namespace red3lib
