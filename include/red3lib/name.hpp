#pragma once

#include <cstdint>
#include <string_view>

namespace red3lib
{
class [[nodiscard]] name
{
public:
    constexpr name() noexcept;
    name(const wchar_t* text);

    // TODO: Implement other constructors.

    constexpr name(const name&) noexcept = default;
    constexpr name& operator=(const name&) noexcept = default;

    constexpr name(name&&) noexcept = default;
    constexpr name& operator=(name&&) noexcept = default;

    constexpr ~name() noexcept = default;

    [[nodiscard]] std::wstring_view to_wide() const;

private:
    std::uint32_t m_index; // 00
};
} // namespace red3lib
