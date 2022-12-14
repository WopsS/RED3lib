#pragma once

#include <cstdint>

#include <red3lib/detail/asserts.hpp>

namespace red3lib
{
template<typename Key, typename T>
struct [[nodiscard]] hash_map
{
    std::int32_t capacity; // 00
    std::int32_t size;     // 04
    std::int64_t unk8;     // 08
    std::int64_t unk10;    // 10
    std::int64_t unk18;    // 18
    std::int64_t buckets;  // 20
    std::int8_t unk28;     // 28
};
RED3LIB_ASSERT_SIZE(RED3LIB_ASSERT_ESCAPE(hash_map<std::int32_t, void>), 0x30);
} // namespace red3lib
