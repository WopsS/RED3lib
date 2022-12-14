#pragma once

#include <cstdint>

#include <red3lib/detail/asserts.hpp>

namespace red3lib
{
struct rtti_function;
struct scriptable;

struct stack_frame
{
    scriptable* context;     // 00 - TODO: Increase reference counter when this class is constructed and decrease it!
    std::int64_t unk8;       // 08 - Seems to be the reference counter of the context.
    stack_frame* parent;     // 10
    rtti_function* function; // 18
    std::int8_t* locals;     // 20
    std::int8_t* params;     // 28
    std::int8_t* code;       // 30
    std::int32_t unk38;      // 38
    std::int8_t unk3C;       // 3C
    std::int64_t unk40;      // 40
    std::int64_t unk48;      // 48
    std::int64_t unk50;      // 50
    std::int64_t unk58;      // 58
    std::int64_t unk60;      // 60
    std::int64_t unk68;      // 68
    std::int64_t unk70;      // 70
    std::int64_t unk78;      // 78
    std::int64_t unk80;      // 80
    std::int64_t unk88;      // 88
    std::int64_t unk90;      // 90
    std::int64_t unk98;      // 98
    std::int64_t unkA0;      // A0
    std::int64_t unkA8;      // A8
    std::int64_t unkB0;      // B0
    std::int64_t unkB8;      // B8
    std::int64_t unkC0;      // C0
    std::int64_t unkC8;      // C8
    std::int64_t unkD0;      // D0
    std::int64_t unkD8;      // D8
    std::int64_t unkE0;      // E0
    std::int64_t unkE8;      // E8
    std::int64_t unkF0;      // F0
    std::int64_t unkF8;      // F8
    std::int64_t unk100;     // 100
    std::int32_t unk108;     // 108
    std::int64_t unk110;     // 110
    std::int64_t unk118;     // 118
};
RED3LIB_ASSERT_SIZE(stack_frame, 0x120);
RED3LIB_ASSERT_OFFSET(stack_frame, locals, 0x20);
RED3LIB_ASSERT_OFFSET(stack_frame, params, 0x28);
RED3LIB_ASSERT_OFFSET(stack_frame, code, 0x30);
} // namespace red3lib
