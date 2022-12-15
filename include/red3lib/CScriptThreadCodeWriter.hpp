#pragma once

#include <cstdint>

namespace red3lib
{
struct CProperty;

class [[nodiscard]] CScriptThreadCodeWriter
{
public:
    CScriptThreadCodeWriter(std::uint8_t* ptr) noexcept;
    ~CScriptThreadCodeWriter() noexcept = default;

    void write(CProperty* property);

private:
    std::uint8_t* m_cursor;
};
} // namespace red3lib
