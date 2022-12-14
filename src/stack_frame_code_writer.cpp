#include <red3lib/stack_frame_code_writer.hpp>

red3lib::stack_frame_code_writer::stack_frame_code_writer(std::uint8_t* ptr) noexcept
    : m_cursor(ptr)
{
}

void red3lib::stack_frame_code_writer::write(rtti_property* property)
{
    *m_cursor = 0x16;
    m_cursor++;

    *reinterpret_cast<rtti_property**>(m_cursor) = property;
}
