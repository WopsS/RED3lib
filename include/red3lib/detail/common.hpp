#pragma once

#ifndef RED3LIB_NO_DEFAULT_CONSTRUCTOR
#define RED3LIB_NO_DEFAULT_CONSTRUCTOR(cls) cls() = delete
#endif

#ifndef RED3LIB_NO_DEFAULT_DESTRUCTOR
#define RED3LIB_NO_DEFAULT_DESTRUCTOR(cls) ~cls() = delete
#endif

#ifndef RED3LIB_NO_DEFAULT_CONSTRUCTOR_AND_DESTRUCTOR
#define RED3LIB_NO_DEFAULT_CONSTRUCTOR_AND_DESTRUCTOR(cls)                                                             \
    RED3LIB_NO_DEFAULT_CONSTRUCTOR(cls);                                                                               \
    RED3LIB_NO_DEFAULT_DESTRUCTOR(cls)
#endif

#ifndef RED3LIB_NON_COPYABLE
#define RED3LIB_NON_COPYABLE(cls)                                                                                      \
    cls(const cls&) = delete;                                                                                          \
    cls& operator=(const cls&) = delete
#endif

#ifndef RED3LIB_NON_MOVABLE
#define RED3LIB_NON_MOVABLE(cls)                                                                                       \
    cls(cls&&) = delete;                                                                                               \
    cls& operator=(cls&&) = delete
#endif

#ifndef RED3LIB_NON_COPYABLE_AND_NON_MOVABLE
#define RED3LIB_NON_COPYABLE_AND_NON_MOVABLE(cls)                                                                      \
    RED3LIB_NON_COPYABLE(cls);                                                                                         \
    RED3LIB_NON_MOVABLE(cls)
#endif
