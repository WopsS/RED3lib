#include <red3lib/CNameHash.hpp>

#include <red3lib/CNamePool.hpp>

constexpr red3lib::CNameHash::CNameHash() noexcept
    : m_index(0)
{
}

red3lib::CNameHash::CNameHash(const wchar_t* text)
{
    // TODO: Handle "None" -> set index = 0.
    m_index = name_pool::add(text);
}

std::wstring_view red3lib::CNameHash::to_wide() const
{
    return name_pool::to_wide_string(*this);
}
