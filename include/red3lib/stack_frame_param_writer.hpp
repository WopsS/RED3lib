#pragma once

#include <red3lib/stack_frame.hpp>

namespace red3lib
{
class [[nodiscard]] stack_frame_param_writer
{
public:
    stack_frame_param_writer(std::uint8_t* ptr) noexcept;
    ~stack_frame_param_writer() noexcept = default;

    template<typename T>
    void write(T value);
    void write_end();

private:
    std::uint8_t* m_cursor;
};

template<typename T>
inline void stack_frame_param_writer::write(T value)
{
    *reinterpret_cast<T*>(m_cursor) = value;
    m_cursor += sizeof(T);
}
} // namespace red3lib
