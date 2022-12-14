#include <red3lib/CStackFrameCodeWriter.hpp>

red3lib::CStackFrameCodeWriter::CStackFrameCodeWriter(std::uint8_t* ptr) noexcept
    : m_cursor(ptr)
{
}

void red3lib::CStackFrameCodeWriter::write(CProperty* property)
{
    *m_cursor = 0x16;
    m_cursor++;

    *reinterpret_cast<CProperty**>(m_cursor) = property;
}
