#include <red3lib/name.hpp>

#include <red3lib/name_pool.hpp>

constexpr red3lib::name::name() noexcept
    : m_index(0)
{
}

red3lib::name::name(const wchar_t* text)
{
    // TODO: Handle "None" -> set index = 0.
    m_index = name_pool::add(text);
}

std::wstring_view red3lib::name::to_wide() const
{
    return name_pool::to_wide_string(*this);
}
