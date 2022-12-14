#include <red3lib/CStackFrameParamWriter.hpp>

red3lib::CStackFrameParamWriter::CStackFrameParamWriter(std::uint8_t* ptr) noexcept
    : m_cursor(ptr)
{
}

void red3lib::CStackFrameParamWriter::write_end()
{
    *m_cursor = 0x20;
    m_cursor++;
}
