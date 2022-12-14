#include <red3lib/rtti_class.hpp>
#include <red3lib/rtti_function.hpp>

red3lib::rtti_function* red3lib::rtti_class::find_function(red3lib::name_hash func_name) const
{
    // TODO: Improve this after some more RE is done.
    for (uint32_t i = 0; i < functions.size; i++)
    {
        auto function = functions.entries[i];
        auto name1 = function->name.to_wide();
        auto name2 = func_name.to_wide();
        if (name1 == name2)
        {
            return function;
        }
    }

    if (base)
    {
        return base->find_function(func_name);
    }

    return nullptr;
}
