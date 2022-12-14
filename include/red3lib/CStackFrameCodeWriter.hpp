#pragma once

#include <cstdint>

namespace red3lib
{
struct CProperty;

class [[nodiscard]] CStackFrameCodeWriter
{
public:
    CStackFrameCodeWriter(std::uint8_t* ptr) noexcept;
    ~CStackFrameCodeWriter() noexcept = default;

    void write(CProperty* property);

private:
    std::uint8_t* m_cursor;
};
} // namespace red3lib
