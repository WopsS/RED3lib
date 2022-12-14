#pragma once

#include <array>
#include <cstdint>
#include <memory>
#include <type_traits>

#include <red3lib/containers/dyn_array.hpp>
#include <red3lib/detail/addresses.hpp>
#include <red3lib/detail/asserts.hpp>
#include <red3lib/detail/relocation.hpp>
#include <red3lib/name_hash.hpp>
#include <red3lib/rtti_object.hpp>
#include <red3lib/stack_frame.hpp>
#include <red3lib/stack_frame_writer.hpp>

namespace red3lib
{
struct rtti_class;
struct rtti_property;
struct scriptable;

// CRTTI: CFunction
struct rtti_function : rtti_object
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
    R execute(scriptable* context, Args&&... args);

    // void execute_scripted(void* context, std::int8_t* params_stack, void* out);

    rtti_class* owner;                // 08
    red3lib::name_hash name;          // 10
    std::int32_t flags;               // 14
    std::int64_t return_type;         // 18
    dyn_array<rtti_property*> params; // 20
    dyn_array<rtti_property*> locals; // 2C
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
    R execute_native(scriptable* context, Args&&... args);

    template<typename R, typename... Args>
    R execute_scripted(scriptable* context, Args&&... args);

    std::size_t calculate_locals_stack_size() const;
};
RED3LIB_ASSERT_SIZE(rtti_function, 0xC0);
RED3LIB_ASSERT_OFFSET(rtti_function, owner, 0x8);
RED3LIB_ASSERT_OFFSET(rtti_function, name, 0x10);
RED3LIB_ASSERT_OFFSET(rtti_function, flags, 0x14);
RED3LIB_ASSERT_OFFSET(rtti_function, return_type, 0x18);
RED3LIB_ASSERT_OFFSET(rtti_function, params, 0x20);
RED3LIB_ASSERT_OFFSET(rtti_function, locals, 0x2C);
RED3LIB_ASSERT_OFFSET(rtti_function, registration_offset, 0xA8);

template<typename R, typename... Args>
inline R rtti_function::execute(scriptable* context, Args&&... args)
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
inline R rtti_function::execute_native(scriptable* context, Args&&... args)
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

    stack_frame frame(this, context, locals_stack.get(), params_stack.data(), code_stack.data());
    stack_frame_writer writer(frame);

    std::size_t index = 0;
    (writer.write_value(params.entries[index++], std::forward<Args>(args)), ...);
    writer.end_params();

    detail::reloc_func<bool, rtti_function*, scriptable*, stack_frame&, R*> func(
        detail::addresses::rtti_function::execute_native);

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
inline R rtti_function::execute_scripted(scriptable* context, Args&&... args)
{
    constexpr auto args_total_size = (0 + ... + sizeof(Args));
    std::array<std::uint8_t, args_total_size + 1> params_stack{};

    stack_frame_param_writer writer(params_stack.data());
    (writer.write(std::forward<Args>(args)), ...);
    writer.write_end();

    detail::reloc_func<bool, rtti_function*, scriptable*, std::uint8_t*, R*> func(
        detail::addresses::rtti_function::execute_scripted);

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
