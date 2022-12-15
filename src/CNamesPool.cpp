#include <red3lib/CNamesPool.hpp>

#include <red3lib/detail/Addresses.hpp>
#include <red3lib/detail/Relocation.hpp>

std::uint32_t red3lib::CNamesPool::AddDynamicPoolName(const wchar_t* text)
{
    detail::RelocFunc<std::uint32_t, CNamesPool*, const wchar_t*> func(detail::addresses::CNamesPool::AddDynamicPoolName);

    auto ptr = Instance();
    return func(ptr, text);
}

std::wstring_view red3lib::CNamesPool::FindText(const CName& hash)
{
    detail::RelocFunc<wchar_t*, const CName&> func(detail::addresses::CNamesPool::FindText);
    return func(hash);
}

std::string_view red3lib::CNamesPool::FindTextAnsi(const CName& hash)
{
    detail::RelocFunc<char*, const CName&> func(detail::addresses::CNamesPool::FindTextAnsi);
    return func(hash);
}

red3lib::CNamesPool* red3lib::CNamesPool::Instance()
{
    detail::RelocFunc<red3lib::CNamesPool*> func(detail::addresses::CNamesPool::s_instance);
    return func();
}
