#pragma once

#include <cstdint>
#include <string_view>

#include <red3lib/detail/Common.hpp>
#include <red3lib/CNameHash.hpp>

namespace red3lib
{
class [[nodiscard]] name_pool
{
public:
    RED3LIB_NO_DEFAULT_CONSTRUCTOR_AND_DESTRUCTOR(name_pool);
    RED3LIB_NON_COPYABLE_AND_NON_MOVABLE(name_pool);

    [[nodiscard]] static std::uint32_t add(const wchar_t* name);
    [[nodiscard]] static std::wstring_view to_wide_string(const CNameHash& hash);

private:
    [[nodiscard]] static name_pool* instance();
};
} // namespace red3lib
