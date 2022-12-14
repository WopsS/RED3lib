#include <red3lib/name_pool.hpp>

#include <red3lib/detail/addresses.hpp>
#include <red3lib/detail/relocation.hpp>

std::uint32_t red3lib::name_pool::add(const wchar_t* text)
{
    detail::reloc_func<std::uint32_t, name_pool*, const wchar_t*> func(detail::addresses::name_pool::add_wide);

    auto ptr = instance();
    return func(ptr, text);
}

std::wstring_view red3lib::name_pool::to_wide_string(const name& which)
{
    detail::reloc_func<wchar_t*, const name&> func(detail::addresses::name_pool::find_wide);
    return func(which);
}

red3lib::name_pool* red3lib::name_pool::instance()
{
    detail::reloc_func<red3lib::name_pool*> func(detail::addresses::name_pool::get);
    return func();
}
