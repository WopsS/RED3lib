#pragma once

#include <red3lib/stack_frame.hpp>

namespace red3lib
{
struct rtti_property;

class [[nodiscard]] stack_frame_code_writer
{
public:
    stack_frame_code_writer(std::uint8_t* ptr) noexcept;
    ~stack_frame_code_writer() noexcept = default;

    void write(rtti_property* property);

private:
    std::uint8_t* m_cursor;
};
} // namespace red3lib
