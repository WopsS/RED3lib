#pragma once

#include <red3lib/rtti_class.hpp>

namespace red3lib
{
// CRTTI: TTypedClass
template<typename T>
struct rtti_typed_class : rtti_class
{
    std::int64_t unk110; // 110
};
RED3LIB_ASSERT_SIZE(rtti_typed_class<void*>, 0x118);
} // namespace red3lib
