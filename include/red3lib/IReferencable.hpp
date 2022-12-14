#pragma once

#include <red3lib/detail/Asserts.hpp>

namespace red3lib
{
struct IReferencable
{
    virtual ~IReferencable() = 0;

    // TODO: Reverse this.
};
RED3LIB_ASSERT_SIZE(IReferencable, 0x8);
} // namespace red3lib
