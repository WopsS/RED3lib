#pragma once

#include <red3lib/referencable.hpp>

namespace red3lib
{
// CRTTI: IReferencable
struct scriptable : referencable
{
};
RED3LIB_ASSERT_SIZE(scriptable, 0x8);
} // namespace red3lib
