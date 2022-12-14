#include <red3lib/CNamePool.hpp>

#include <red3lib/detail/Addresses.hpp>
#include <red3lib/detail/Relocation.hpp>

std::uint32_t red3lib::name_pool::add(const wchar_t* text)
{
    detail::RelocFunc<std::uint32_t, name_pool*, const wchar_t*> func(detail::addresses::CNamePool::add_wide);

    auto ptr = instance();
    return func(ptr, text);
}

std::wstring_view red3lib::name_pool::to_wide_string(const CNameHash& hash)
{
    detail::RelocFunc<wchar_t*, const CNameHash&> func(detail::addresses::CNamePool::find_wide);
    return func(hash);
}

red3lib::name_pool* red3lib::name_pool::instance()
{
    detail::RelocFunc<red3lib::name_pool*> func(detail::addresses::CNamePool::get);
    return func();
}
