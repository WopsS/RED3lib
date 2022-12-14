#include <red3lib/name_hash.hpp>

#include <red3lib/name_pool.hpp>

constexpr red3lib::name_hash::name_hash() noexcept
    : m_index(0)
{
}

red3lib::name_hash::name_hash(const wchar_t* text)
{
    // TODO: Handle "None" -> set index = 0.
    m_index = name_pool::add(text);
}

std::wstring_view red3lib::name_hash::to_wide() const
{
    return name_pool::to_wide_string(*this);
}
