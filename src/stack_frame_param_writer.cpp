#include <red3lib/stack_frame_param_writer.hpp>

red3lib::stack_frame_param_writer::stack_frame_param_writer(std::uint8_t* ptr) noexcept
    : m_cursor(ptr)
{
}

void red3lib::stack_frame_param_writer::write_end()
{
    *m_cursor = 0x20;
    m_cursor++;
}
