#pragma once

#include <red3lib/CScriptThread.hpp>
#include <red3lib/CScriptThreadCodeWriter.hpp>
#include <red3lib/CScriptThreadParamWriter.hpp>
#include <red3lib/detail/Common.hpp>

namespace red3lib
{
struct CProperty;

class [[nodiscard]] CScriptThreadWriter
{
public:
    CScriptThreadWriter(const CScriptThread& stack_frame) noexcept;
    ~CScriptThreadWriter() noexcept = default;

    RED3LIB_NON_COPYABLE_AND_NON_MOVABLE(CScriptThreadWriter);

    template<typename T>
    void write_value(CProperty* property, T value);
    void end_params();

private:
    CScriptThreadParamWriter m_params;
    CScriptThreadCodeWriter m_code;
};

template<typename T>
inline void CScriptThreadWriter::write_value(CProperty* property, T value)
{
    m_params.write(value);
    m_code.write(property);
}
} // namespace red3lib
