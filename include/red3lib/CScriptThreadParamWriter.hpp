#pragma once

#include <cstdint>

namespace red3lib
{
class [[nodiscard]] CScriptThreadParamWriter
{
public:
    CScriptThreadParamWriter(std::uint8_t* ptr) noexcept;
    ~CScriptThreadParamWriter() noexcept = default;

    template<typename T>
    void write(T value);
    void write_end();

private:
    std::uint8_t* m_cursor;
};

template<typename T>
inline void CScriptThreadParamWriter::write(T value)
{
    *reinterpret_cast<T*>(m_cursor) = value;
    m_cursor += sizeof(T);
}
} // namespace red3lib
