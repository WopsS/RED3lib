#include <red3lib/CName.hpp>

#include <red3lib/CNamePool.hpp>

constexpr red3lib::CName::CName() noexcept
    : m_index(0)
{
}

red3lib::CName::CName(const wchar_t* text)
{
    // TODO: Handle "None" -> set index = 0.
    m_index = CNamePool::AddDynamicPoolName(text);
}

std::wstring_view red3lib::CName::AsChar() const
{
    return CNamePool::FindText(*this);
}
