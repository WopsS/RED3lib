#pragma once

#include <cstdint>

// Addresses for The Witcher 3: Wild Hunt (DX12), version 4.00.
namespace red3lib::detail::addresses
{
constexpr std::uintptr_t image_base = 0x140000000;

namespace rtti_function
{
constexpr std::uintptr_t execute_native = 0x1402FD190 - image_base;
constexpr std::uintptr_t execute_scripted = 0x1402FD880 - image_base;
} // namespace rtti_function

namespace name_pool
{
constexpr std::uintptr_t get = 0x140285AF0 - image_base;

constexpr std::uintptr_t add_wide = 0x1402D2C70 - image_base;
constexpr std::uintptr_t find_wide = 0x1402E1540 - image_base;
} // namespace name_pool
} // namespace red3lib::detail::addresses
