#pragma once

#include <red3lib/CStackFrame.hpp>
#include <red3lib/CStackFrameCodeWriter.hpp>
#include <red3lib/CStackFrameParamWriter.hpp>
#include <red3lib/detail/Common.hpp>

namespace red3lib
{
struct CProperty;

class [[nodiscard]] CStackFrameWriter
{
public:
    CStackFrameWriter(const CStackFrame& stack_frame) noexcept;
    ~CStackFrameWriter() noexcept = default;

    RED3LIB_NON_COPYABLE_AND_NON_MOVABLE(CStackFrameWriter);

    template<typename T>
    void write_value(CProperty* property, T value);
    void end_params();

private:
    CStackFrameParamWriter m_params;
    CStackFrameCodeWriter m_code;
};

template<typename T>
inline void CStackFrameWriter::write_value(CProperty* property, T value)
{
    m_params.write(value);
    m_code.write(property);
}
} // namespace red3lib
