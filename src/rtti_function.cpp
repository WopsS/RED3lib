#include <red3lib/rtti_function.hpp>

#include <red3lib/detail/addresses.hpp>
#include <red3lib/detail/relocation.hpp>

void red3lib::rtti_function::execute_native(void* context, stack_frame& frame, void* out)
{
    detail::reloc_func<bool, rtti_function*, void*, stack_frame&, void*> func(
        detail::addresses::rtti_function::execute_native);
    func(this, context, frame, out);
}
