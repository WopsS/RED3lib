#include <red3lib/CScriptThreadParamWriter.hpp>

red3lib::CScriptThreadParamWriter::CScriptThreadParamWriter(std::uint8_t* ptr) noexcept
    : m_cursor(ptr)
{
}

void red3lib::CScriptThreadParamWriter::write_end()
{
    *m_cursor = 0x20;
    m_cursor++;
}
