#pragma once

#include <cstdint>

#include <red3lib/containers/dyn_array.hpp>
#include <red3lib/detail/asserts.hpp>
#include <red3lib/name.hpp>
#include <red3lib/rtti_object.hpp>
#include <red3lib/stack_frame.hpp>

namespace red3lib
{
struct rtti_class;
struct rtti_property;

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

    // TODO: Maybe this should be a template.
    void execute_native(void* context, stack_frame& frame, void* out);
    void execute_scripted(void* context, std::int8_t* params_stack, void* out);

    rtti_class* owner;                // 08
    red3lib::name name;               // 10
    std::int32_t flags;               // 14
    std::int64_t retType;             // 18
    dyn_array<rtti_property*> params; // 20
    dyn_array<rtti_property*> locals; // 2C
    std::int64_t unk38;               // 38
    std::int32_t unk40;               // 40
    std::int32_t unk44;               // 44
    std::int32_t unk48;               // 48
    std::int32_t unk4C;               // 4C
    std::int32_t stackSize;           // 50
    unk unk58;                        // 58
    std::int32_t registrationOffset;  // A8
    std::int64_t unkB0;               // B0
    std::int64_t unkB8;               // B8
};
RED3LIB_ASSERT_SIZE(rtti_function, 0xC0);
RED3LIB_ASSERT_OFFSET(rtti_function, owner, 0x8);
RED3LIB_ASSERT_OFFSET(rtti_function, name, 0x10);
RED3LIB_ASSERT_OFFSET(rtti_function, flags, 0x14);
RED3LIB_ASSERT_OFFSET(rtti_function, retType, 0x18);
RED3LIB_ASSERT_OFFSET(rtti_function, params, 0x20);
RED3LIB_ASSERT_OFFSET(rtti_function, locals, 0x2C);
RED3LIB_ASSERT_OFFSET(rtti_function, registrationOffset, 0xA8);
} // namespace red3lib
