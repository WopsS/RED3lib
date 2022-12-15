#pragma once

#include <cstdint>
#include <string_view>

#include <red3lib/CName.hpp>
#include <red3lib/detail/Common.hpp>

namespace red3lib
{
class [[nodiscard]] CNamePool
{
public:
    RED3LIB_NO_DEFAULT_CONSTRUCTOR_AND_DESTRUCTOR(CNamePool);
    RED3LIB_NON_COPYABLE_AND_NON_MOVABLE(CNamePool);

    [[nodiscard]] static std::uint32_t AddDynamicPoolName(const wchar_t* name);
    [[nodiscard]] static std::wstring_view FindText(const CName& hash);

private:
    [[nodiscard]] static CNamePool* Instance();
};
} // namespace red3lib
