#include <red3lib/CScriptThreadWriter.hpp>

red3lib::CScriptThreadWriter::CScriptThreadWriter(const CScriptThread& stack_frame) noexcept
    : m_params(stack_frame.params)
    , m_code(stack_frame.code)
{
}

void red3lib::CScriptThreadWriter::end_params()
{
    m_params.write_end();
}
