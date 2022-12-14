#pragma once

#include <cstdint>
#include <string_view>

namespace red3lib
{
class [[nodiscard]] CNameHash
{
public:
    constexpr CNameHash() noexcept;
    CNameHash(const wchar_t* text);

    // TODO: Implement other constructors.

    constexpr CNameHash(const CNameHash&) noexcept = default;
    constexpr CNameHash& operator=(const CNameHash&) noexcept = default;

    constexpr CNameHash(CNameHash&&) noexcept = default;
    constexpr CNameHash& operator=(CNameHash&&) noexcept = default;

    constexpr ~CNameHash() noexcept = default;

    [[nodiscard]] std::wstring_view to_wide() const;

private:
    std::uint32_t m_index; // 00
};
} // namespace red3lib
