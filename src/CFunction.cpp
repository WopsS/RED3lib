#include <red3lib/CFunction.hpp>

std::size_t red3lib::CFunction::calculate_locals_stack_size() const
{
    static constexpr std::uint32_t min_stack_size = 0x10;

    auto result = stack_size + min_stack_size;
    if (result < min_stack_size)
    {
        result = min_stack_size;
    }

    return result & ~(min_stack_size - 1);
}
