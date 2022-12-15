#pragma once

#include <cstdint>
#include <string_view>

#include <red3lib/CName.hpp>
#include <red3lib/detail/Common.hpp>

namespace red3lib
{
class [[nodiscard]] CNamesPool
{
public:

    struct SNameHolder
    {
        wchar_t* WString; // 00
        char* String;     // 08
        void* unk10;      // 10
        uint32_t Hash;    // 18
        uint32_t Id;      // 1C
    };

    RED3LIB_NO_DEFAULT_CONSTRUCTOR_AND_DESTRUCTOR(CNamesPool);
    RED3LIB_NON_COPYABLE_AND_NON_MOVABLE(CNamesPool);

    [[nodiscard]] static std::uint32_t AddDynamicPoolName(const wchar_t* name);
    [[nodiscard]] static std::wstring_view FindText(const CName& hash);
    [[nodiscard]] static std::string_view FindTextAnsi(const CName& hash);

private:
    [[nodiscard]] static CNamesPool* Instance();
};
} // namespace red3lib
