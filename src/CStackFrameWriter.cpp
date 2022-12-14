#include <red3lib/CStackFrameWriter.hpp>

red3lib::CStackFrameWriter::CStackFrameWriter(const CStackFrame& stack_frame) noexcept
    : m_params(stack_frame.params)
    , m_code(stack_frame.code)
{
}

void red3lib::CStackFrameWriter::end_params()
{
    m_params.write_end();
}
