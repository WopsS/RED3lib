#pragma once

#include <red3lib/IReferencable.hpp>

namespace red3lib
{
struct IScriptable : IReferencable
{
};
RED3LIB_ASSERT_SIZE(IScriptable, 0x8);
} // namespace red3lib
