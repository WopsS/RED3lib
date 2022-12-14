#pragma once

#include <cstdint>

namespace red3lib
{
struct rtti_function;

struct stack_frame
{
    std::int64_t context;
    std::int64_t unk8;
    stack_frame* previous;
    rtti_function* function;
    std::int64_t unk20;
    std::int64_t unk28;
    char* code;
    std::int32_t unk38;
    std::int8_t unk3C;
    std::int64_t unk40;
    std::int64_t unk48;
    std::int64_t unk50;
    std::int64_t unk58;
    std::int64_t unk60;
    std::int64_t unk68;
    std::int64_t unk70;
    std::int64_t unk78;
    std::int64_t unk80;
    std::int64_t unk88;
    std::int64_t unk90;
    std::int64_t unk98;
    std::int64_t unkA0;
    std::int64_t unkA8;
    std::int64_t unkB0;
    std::int64_t unkB8;
    std::int64_t unkC0;
    std::int64_t unkC8;
    std::int64_t unkD0;
    std::int64_t unkD8;
    std::int64_t unkE0;
    std::int64_t unkE8;
    std::int64_t unkF0;
    std::int64_t unkF8;
    std::int64_t unk100;
    std::int32_t unk108;
    std::int64_t unk110;
    std::int64_t unk118;
};
} // namespace red3lib
