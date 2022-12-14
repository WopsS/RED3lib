#include <red3lib/detail/Relocation.hpp>

#include <Windows.h>

std::uintptr_t red3lib::detail::BaseReloc::image_base() noexcept
{
    static const auto base = reinterpret_cast<std::uintptr_t>(GetModuleHandle(nullptr));
    return base;
}
