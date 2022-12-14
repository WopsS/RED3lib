#pragma once

#include <cstdint>
#include <string_view>

namespace red3lib
{
class [[nodiscard]] name_hash
{
public:
    constexpr name_hash() noexcept;
    name_hash(const wchar_t* text);

    // TODO: Implement other constructors.

    constexpr name_hash(const name_hash&) noexcept = default;
    constexpr name_hash& operator=(const name_hash&) noexcept = default;

    constexpr name_hash(name_hash&&) noexcept = default;
    constexpr name_hash& operator=(name_hash&&) noexcept = default;

    constexpr ~name_hash() noexcept = default;

    [[nodiscard]] std::wstring_view to_wide() const;

private:
    std::uint32_t m_index; // 00
};
} // namespace red3lib
