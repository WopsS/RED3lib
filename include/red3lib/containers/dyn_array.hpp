#pragma once

#include <cstdint>

#include <red3lib/detail/asserts.hpp>

namespace red3lib
{
// TODO: Need more reverse, is this really aligned to 4 bytes?
#pragma pack(push, 4)
template<typename T>
struct [[nodiscard]] dyn_array
{
    T* entries;    // 00
    uint32_t size; // 08
};
#pragma pack(pop)
RED3LIB_ASSERT_SIZE(dyn_array<void>, 0xC);
} // namespace red3lib
