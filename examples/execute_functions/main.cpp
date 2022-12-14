#include <cstdint>
#include <iostream>

#include <Windows.h>

#include <red3lib/detail/relocation.hpp>
#include <red3lib/RED3Lib.hpp>

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
    red3lib::detail::RelocPtr<red3lib::CClass> game_cls(0x145549010 - 0x140000000);
    if (game_cls != nullptr)
    {
        red3lib::detail::RelocPtr<red3lib::IScriptable> game_context(0x1452BB290 - 0x140000000);

        {
            auto func = game_cls->find_function(L"GetEngineTimeAsSeconds");
            auto seconds = func->execute<float>(game_context.get());
            std::cout << "GetEngineTimeAsSeconds: " << seconds << std::endl;
        }

        {
            auto func = game_cls->find_function(L"GetTimeScale");

            auto scale = func->execute<float>(game_context.get(), true);
            std::cout << "GetTimeScale: " << scale << std::endl;
        }

        {
            auto func = game_cls->find_function(L"IsUberMovementEnabled");
            auto isUberMovement = func->execute<bool>(game_context.get());

            std::cout << "IsUberMovementEnabled: " << isUberMovement << std::endl;
        }

        int a = 10;
    }
}

RED3LIB_C_EXPORT const char* RED3LIB_CALL Supports()
{
    return "4.0.0.65171";
}
