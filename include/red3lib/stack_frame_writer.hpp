#pragma once

#include <red3lib/detail/common.hpp>
#include <red3lib/stack_frame_code_writer.hpp>
#include <red3lib/stack_frame_param_writer.hpp>

namespace red3lib
{
class [[nodiscard]] stack_frame_writer
{
public:
    stack_frame_writer(const stack_frame& stack_frame) noexcept;
    ~stack_frame_writer() noexcept = default;

    RED3LIB_NON_COPYABLE_AND_NON_MOVABLE(stack_frame_writer);

    template<typename T>
    void write_value(rtti_property* property, T value);
    void end_params();

private:
    stack_frame_param_writer m_params;
    stack_frame_code_writer m_code;
};

template<typename T>
inline void stack_frame_writer::write_value(rtti_property* property, T value)
{
    m_params.write(value);
    m_code.write(property);
}
} // namespace red3lib
