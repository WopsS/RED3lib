#include <red3lib/CScriptThreadCodeWriter.hpp>

red3lib::CScriptThreadCodeWriter::CScriptThreadCodeWriter(std::uint8_t* ptr) noexcept
    : m_cursor(ptr)
{
}

void red3lib::CScriptThreadCodeWriter::write(CProperty* property)
{
    *m_cursor = 0x16;
    m_cursor++;

    *reinterpret_cast<CProperty**>(m_cursor) = property;
}
