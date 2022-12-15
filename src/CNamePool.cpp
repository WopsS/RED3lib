#include <red3lib/CNamePool.hpp>

#include <red3lib/detail/Addresses.hpp>
#include <red3lib/detail/Relocation.hpp>

std::uint32_t red3lib::CNamePool::AddDynamicPoolName(const wchar_t* text)
{
    detail::RelocFunc<std::uint32_t, CNamePool*, const wchar_t*> func(detail::addresses::CNamePool::AddDynamicPoolName);

    auto ptr = Instance();
    return func(ptr, text);
}

std::wstring_view red3lib::CNamePool::FindText(const CName& hash)
{
    detail::RelocFunc<wchar_t*, const CName&> func(detail::addresses::CNamePool::FindText);
    return func(hash);
}

red3lib::CNamePool* red3lib::CNamePool::Instance()
{
    detail::RelocFunc<red3lib::CNamePool*> func(detail::addresses::CNamePool::s_instance);
    return func();
}
