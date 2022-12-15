#include <red3lib/CName.hpp>

#include <red3lib/CNamePool.hpp>

red3lib::CName::CName(const wchar_t* text)
{
    if (wcscmp(text, L"None") == 0)
    {
        m_index = 0;
        return;
    }
    m_index = CNamePool::AddDynamicPoolName(text);
}

std::wstring_view red3lib::CName::AsChar() const
{
    return CNamePool::FindText(*this);
}

std::string_view red3lib::CName::AsAnsiChar() const
{
    return CNamePool::FindTextAnsi(*this);
}

bool red3lib::CName::IsNone() const
{
    return m_index == 0;
}
