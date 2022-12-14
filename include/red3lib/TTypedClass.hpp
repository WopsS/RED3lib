#pragma once

#include <red3lib/CClass.hpp>

namespace red3lib
{
template<typename T>
struct TTypedClass : CClass
{
    std::int64_t unk110; // 110
};
RED3LIB_ASSERT_SIZE(TTypedClass<void*>, 0x118);
} // namespace red3lib
