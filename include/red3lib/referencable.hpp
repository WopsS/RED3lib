#pragma once

#include <red3lib/detail/asserts.hpp>

namespace red3lib
{
// CRTTI: IReferencable
struct referencable
{
    virtual ~referencable() = 0;

    // TODO: Reverse this.
};
RED3LIB_ASSERT_SIZE(referencable, 0x8);
} // namespace red3lib
