#include <red3lib/detail/relocation.hpp>

#include <Windows.h>

std::uintptr_t red3lib::detail::base_reloc::image_base() noexcept
{
    static const auto base = reinterpret_cast<std::uintptr_t>(GetModuleHandle(nullptr));
    return base;
}
