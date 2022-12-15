#pragma once

#include <array>
#include <cstdint>
#include <memory>
#include <type_traits>

#include <red3lib/CName.hpp>
#include <red3lib/CStackFrame.hpp>
#include <red3lib/CStackFrameWriter.hpp>
#include <red3lib/IRTTIBaseObject.hpp>
#include <red3lib/containers/TDynArray.hpp>
#include <red3lib/detail/Addresses.hpp>
#include <red3lib/detail/Asserts.hpp>
#include <red3lib/detail/Relocation.hpp>

namespace red3lib
{
struct CClass;
struct CProperty;
struct IScriptable;

struct CFunction : IRTTIBaseObject
{
    struct unk
    {
        std::int64_t unk0;
        std::int32_t unk8;
        std::int32_t unkC;
        std::int32_t unk10;
        std::int32_t unk14;
        std::int64_t unk18;
        std::int64_t unk20;
        std::int64_t unk28;
        std::int32_t size;
        std::int64_t unk38;
        std::int32_t unk40;
        std::int32_t unk44;
        std::int32_t unk48;
        std::int32_t unk4C;
    };

    template<typename R = void, typename... Args>
    R execute(IScriptable* context, Args&&... args);

    CClass* owner;                    // 08
    red3lib::CName name;          // 10
    std::int32_t flags;               // 14
    std::int64_t return_type;         // 18
    TDynArray<CProperty*> params;     // 20
    TDynArray<CProperty*> locals;     // 2C
    std::int64_t unk38;               // 38
    std::int32_t unk40;               // 40
    std::int32_t unk44;               // 44
    std::int32_t unk48;               // 48
    std::int32_t unk4C;               // 4C
    std::int32_t stack_size;          // 50
    unk unk58;                        // 58
    std::int32_t registration_offset; // A8
    std::int64_t unkB0;               // B0
    std::int64_t unkB8;               // B8

private:
    template<typename R, typename... Args>
    R execute_native(IScriptable* context, Args&&... args);

    template<typename R, typename... Args>
    R execute_scripted(IScriptable* context, Args&&... args);

    std::size_t calculate_locals_stack_size() const;
};
RED3LIB_ASSERT_SIZE(CFunction, 0xC0);
RED3LIB_ASSERT_OFFSET(CFunction, owner, 0x8);
RED3LIB_ASSERT_OFFSET(CFunction, name, 0x10);
RED3LIB_ASSERT_OFFSET(CFunction, flags, 0x14);
RED3LIB_ASSERT_OFFSET(CFunction, return_type, 0x18);
RED3LIB_ASSERT_OFFSET(CFunction, params, 0x20);
RED3LIB_ASSERT_OFFSET(CFunction, locals, 0x2C);
RED3LIB_ASSERT_OFFSET(CFunction, registration_offset, 0xA8);

template<typename R, typename... Args>
inline R CFunction::execute(IScriptable* context, Args&&... args)
{
    // Maybe this one should be removed and add something similar to https://doc.rust-lang.org/std/result/.
    RED3LIB_ASSERT(params.size == sizeof...(args));

    constexpr auto is_native_flag = 1 << 0;
    if ((flags & is_native_flag) == is_native_flag)
    {
        return execute_native<R>(context, std::forward<Args>(args)...);
    }
    else
    {
        return execute_scripted<R>(context, std::forward<Args>(args)...);
    }
}

template<typename R, typename... Args>
inline R CFunction::execute_native(IScriptable* context, Args&&... args)
{
    constexpr auto args_count = sizeof...(Args);
    constexpr auto args_total_size = (0 + ... + sizeof(Args));

    auto locals_stack_size = calculate_locals_stack_size();
    auto stack_ptr = reinterpret_cast<std::uint8_t*>(_malloca(locals_stack_size));
    RED3LIB_ASSERT(stack_ptr);
    std::memset(stack_ptr, 0, locals_stack_size);

    std::unique_ptr<std::uint8_t, decltype(&_freea)> locals_stack(stack_ptr, &_freea);
    std::array<std::uint8_t, args_total_size + 1> params_stack{};
    std::array<std::uint8_t, 9 * args_count> code_stack{};

    CStackFrame frame(this, context, locals_stack.get(), params_stack.data(), code_stack.data());
    CStackFrameWriter writer(frame);

    std::size_t index = 0;
    (writer.write_value(params.entries[index++], std::forward<Args>(args)), ...);
    writer.end_params();

    detail::RelocFunc<bool, CFunction*, IScriptable*, CStackFrame&, R*> func(
        detail::addresses::CFunction::execute_native);

    if constexpr (std::is_same_v<R, void>)
    {
        func(this, context, frame, nullptr);
    }
    else
    {
        R result{};
        func(this, context, frame, &result);

        return result;
    }
}

template<typename R, typename... Args>
inline R CFunction::execute_scripted(IScriptable* context, Args&&... args)
{
    constexpr auto args_total_size = (0 + ... + sizeof(Args));
    std::array<std::uint8_t, args_total_size + 1> params_stack{};

    CStackFrameParamWriter writer(params_stack.data());
    (writer.write(std::forward<Args>(args)), ...);
    writer.write_end();

    detail::RelocFunc<bool, CFunction*, IScriptable*, std::uint8_t*, R*> func(
        detail::addresses::CFunction::execute_scripted);

    if constexpr (std::is_same_v<R, void>)
    {
        func(this, context, params_stack.data(), nullptr);
    }
    else
    {
        R result{};
        func(this, context, params_stack.data(), &result);

        return result;
    }
}
} // namespace red3lib
