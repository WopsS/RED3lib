#include <cstdint>
#include <iostream>

#include <Windows.h>

#include <red3lib/detail/relocation.hpp>
#include <red3lib/rtti_class.hpp>
#include <red3lib/rtti_function.hpp>
#include <red3lib/stack_frame.hpp>

#define RED3LIB_C_EXPORT extern "C" __declspec(dllexport)
#define RED3LIB_CALL __fastcall

enum class EMainReason : std::uint8_t
{
    Load = 0,
    Unload
};

RED3LIB_C_EXPORT bool RED3LIB_CALL Main(HMODULE aHandle, EMainReason aReason)
{
    switch (aReason)
    {
    case EMainReason::Load:
    {
        break;
    }
    case EMainReason::Unload:
    {
        break;
    }
    }

    return true;
}

RED3LIB_C_EXPORT void RED3LIB_CALL Update()
{
    // red3lib::rtti_class* game_cls = *(red3lib::rtti_class**)(0x145549010 - 0x140000000 +
    // reinterpret_cast<std::uintptr_t>(GetModuleHandle(nullptr)));
    red3lib::detail::reloc_ptr<red3lib::rtti_class> game_cls(0x145549010 - 0x140000000);
    if (game_cls != nullptr)
    {
        red3lib::detail::reloc_ptr<void*> game_context(0x1452BB290 - 0x140000000);

        auto name = game_cls->name.to_wide();
        auto func = game_cls->find_function(L"GetEngineTimeAsSeconds");

        float engineTime;
        red3lib::stack_frame frame{};
        frame.function = func;
        frame.code = nullptr;

        func->execute_native(game_context.get(), frame, &engineTime);
        std::cout << "GetEngineTimeAsSeconds called, returned: " << engineTime << std::endl;
        int a = 10;
    }
}

RED3LIB_C_EXPORT const char* RED3LIB_CALL Supports()
{
    return "4.0.0.65171";
}
