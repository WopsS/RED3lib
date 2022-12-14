#pragma once

#ifndef RED3LIB_ASSERT_SIZE
#define RED3LIB_ASSERT_SIZE(obj, size)                                                                                 \
    static_assert(sizeof(obj) == size, "The size of '" #obj "' does not match the expected size of " #size " bytes")
#endif

#ifndef RED3LIB_ASSERT_OFFSET
#define RED3LIB_ASSERT_OFFSET(cls, mbr, offset)                                                                        \
    static_assert(offsetof(cls, mbr) == offset, #cls "::" #mbr " is not on the expected offset (" #offset ")")
#endif

#ifndef RED3LIB_ASSERT_ESCAPE
#define RED3LIB_ASSERT_ESCAPE(...) __VA_ARGS__
#endif
