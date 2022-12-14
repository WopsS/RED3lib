#include <red3lib/stack_frame_writer.hpp>

red3lib::stack_frame_writer::stack_frame_writer(const stack_frame& stack_frame) noexcept
    : m_params(stack_frame.params)
    , m_code(stack_frame.code)
{
}

void red3lib::stack_frame_writer::end_params()
{
    m_params.write_end();
}
