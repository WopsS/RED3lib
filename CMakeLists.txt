cmake_minimum_required(VERSION 3.21)

project(
  RED3lib
  VERSION 0.1.0
  LANGUAGES CXX
)

# -----------------------------------------------------------------------------
# General configuration / options / variables
# -----------------------------------------------------------------------------
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
elseif(CMAKE_CXX_STANDARD LESS 20)
  message(FATAL_ERROR "RED3lib requires C++20 or higher.")
endif()

if(PROJECT_IS_TOP_LEVEL)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

option(RED3LIB_USE_PCH "Use precompiled headers to speed up compilation time." OFF)

set(RED3LIB_CMAKE_DIR "${PROJECT_SOURCE_DIR}/cmake")
set(RED3LIB_CMAKE_TEMPLATES_DIR "${RED3LIB_CMAKE_DIR}/templates")
set(RED3LIB_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/")

# -----------------------------------------------------------------------------
# Options related to compiler warnings
# -----------------------------------------------------------------------------
if(PROJECT_IS_TOP_LEVEL)
  option(RED3LIB_EXTRA_WARNINGS "Enable extra warnings." OFF)
  if(RED3LIB_EXTRA_WARNINGS)
    if(MSVC)
      add_compile_options(/W4)
    else()
      message(
        FATAL_ERROR
        "The compiler options to enable extra warnings is not known for \
        '${CMAKE_CXX_COMPILER_ID}'"
      )
    endif()
  endif()

  option(RED3LIB_TREAT_WARNINGS_AS_ERRORS "Treat compiler warnings as errors." OFF)
  if(RED3LIB_TREAT_WARNINGS_AS_ERRORS)
    if(MSVC)
      add_compile_options(/WX)
    else()
      message(
        FATAL_ERROR
        "The compiler option to treat warnings as errors is not known for \
        '${CMAKE_CXX_COMPILER_ID}'"
      )
    endif()
  endif()
endif()

# -----------------------------------------------------------------------------
# Main library
# -----------------------------------------------------------------------------
set(
  RED3LIB_HEADER_FILES
    include/red3lib/RED3lib.hpp

    include/red3lib/CNameHash.hpp
    include/red3lib/CNamePool.hpp

    include/red3lib/CClass.hpp
    include/red3lib/TTypedClass.hpp
    include/red3lib/IClassBuilder.hpp
    include/red3lib/CFunction.hpp
    include/red3lib/IRTTIBaseObject.hpp
    include/red3lib/CProperty.hpp
    include/red3lib/CRTTISystem.hpp
    include/red3lib/IRTTIType.hpp

    include/red3lib/IReferencable.hpp
    include/red3lib/IScriptable.hpp

    include/red3lib/CStackFrame.hpp
    include/red3lib/CStackFrameWriter.hpp
    include/red3lib/CStackFrameCodeWriter.hpp
    include/red3lib/CStackFrameParamWriter.hpp

    include/red3lib/detail/Addresses.hpp
    include/red3lib/detail/Asserts.hpp
    include/red3lib/detail/Common.hpp
    include/red3lib/detail/Relocation.hpp

    include/red3lib/containers/TDynArray.hpp
    include/red3lib/containers/THashMap.hpp
)

set(
  RED3LIB_SRC_FILES
    src/RED3lib.cpp

    src/CNameHash.cpp
    src/CNamePool.cpp

    src/CClass.cpp
    src/CFunction.cpp

    src/CStackFrame.cpp
    src/CStackFrameWriter.cpp
    src/CStackFrameCodeWriter.cpp
    src/CStackFrameParamWriter.cpp

    src/detail/Relocation.cpp
)

get_property(RED3LIB_USE_FOLDERS GLOBAL PROPERTY USE_FOLDERS)
if(RED3LIB_USE_FOLDERS)
  source_group(cmake REGULAR_EXPRESSION cmake_pch.*)

  source_group(
    TREE "${RED3LIB_INCLUDE_DIR}/red3lib"
    FILES ${RED3LIB_HEADER_FILES}
  )

  source_group(
    TREE "${PROJECT_SOURCE_DIR}/src"
    FILES ${RED3LIB_SRC_FILES}
  )
endif()

add_library(
  RED3lib STATIC
  ${RED3LIB_HEADER_FILES}
  ${RED3LIB_SRC_FILES}
)
add_library(RED3lib::RED3lib ALIAS RED3lib)

target_include_directories(
  RED3lib
    PUBLIC
      "$<BUILD_INTERFACE:${RED3LIB_INCLUDE_DIR}>"
      "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

target_compile_options(
  RED3lib
    PRIVATE
      ${RED3LIB_EXTRA_WARNINGS_FLAGS}
      ${RED3LIB_TREAT_WARNINGS_AS_ERRORS_FLAG}
)

if(RED3LIB_USE_PCH)
    set(RED3LIB_PCH_FILE "${PROJECT_BINARY_DIR}/red3lib_pch.hpp")
    set(RED3LIB_PCH_FILE_IN "${RED3LIB_CMAKE_TEMPLATES_DIR}/pch.hpp.in")

    configure_file(
      "${RED3LIB_PCH_FILE_IN}"
      "${RED3LIB_PCH_FILE}"
      COPYONLY
    )

    target_precompile_headers(RED3lib PRIVATE "${RED3LIB_PCH_FILE}")
endif()

# -----------------------------------------------------------------------------
# Examples
# -----------------------------------------------------------------------------
option(RED3LIB_BUILD_EXAMPLES "Build the examples." OFF)
if(RED3LIB_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

# -----------------------------------------------------------------------------
# Install
# -----------------------------------------------------------------------------
if(NOT CMAKE_SKIP_INSTALL_RULES)
  option(RED3LIB_INSTALL "Generate the install target." ${PROJECT_IS_TOP_LEVEL})
  if(RED3LIB_INSTALL)
    include(CMakePackageConfigHelpers)
    include(GNUInstallDirs)

    set(RED3LIB_EXPORT_NAME RED3lib)
    set(RED3LIB_EXPORT_TARGETS "${RED3LIB_EXPORT_NAME}Targets")

    set(RED3LIB_CMAKE_CONFIG_DIR "${PROJECT_BINARY_DIR}")

    set(RED3LIB_CMAKE_PROJECT_CONFIG_FILE "${RED3LIB_CMAKE_CONFIG_DIR}/${RED3LIB_EXPORT_NAME}Config.cmake")
    set(RED3LIB_CMAKE_PROJECT_CONFIG_FILE_IN "${RED3LIB_CMAKE_TEMPLATES_DIR}/${RED3LIB_EXPORT_NAME}Config.cmake.in")
    set(RED3LIB_CMAKE_PROJECT_VERSION_FILE "${RED3LIB_CMAKE_CONFIG_DIR}/${RED3LIB_EXPORT_NAME}ConfigVersion.cmake")

    set(RED3LIB_INSTALL_CONFIG_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${RED3LIB_EXPORT_NAME}")

    configure_package_config_file(
      "${RED3LIB_CMAKE_PROJECT_CONFIG_FILE_IN}"
      "${RED3LIB_CMAKE_PROJECT_CONFIG_FILE}"
      INSTALL_DESTINATION "${RED3LIB_INSTALL_CONFIG_DIR}"
    )

    write_basic_package_version_file(
      "${RED3LIB_CMAKE_PROJECT_VERSION_FILE}"
      VERSION ${PROJECT_VERSION}
      COMPATIBILITY ExactVersion
    )

    install(
      DIRECTORY "${RED3LIB_INCLUDE_DIR}/"
      DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    )

    install(
      TARGETS RED3lib
      EXPORT ${RED3LIB_EXPORT_TARGETS}
      INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
      PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
      LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
      ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
      RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    )

    install(
      FILES
        "${RED3LIB_CMAKE_PROJECT_CONFIG_FILE}"
        "${RED3LIB_CMAKE_PROJECT_VERSION_FILE}"
      DESTINATION "${RED3LIB_INSTALL_CONFIG_DIR}"
    )

    install(
      EXPORT ${RED3LIB_EXPORT_TARGETS}
      NAMESPACE RED3lib::
      DESTINATION "${RED3LIB_INSTALL_CONFIG_DIR}"
    )

    # -------------------------------------------------------------------------
    # pkg-config
    # -------------------------------------------------------------------------
    set(RED3LIB_PKG_CONFIG_FILE "${RED3LIB_CMAKE_CONFIG_DIR}/${RED3LIB_EXPORT_NAME}.pc")
    set(RED3LIB_PKG_CONFIG_FILE_IN "${RED3LIB_CMAKE_TEMPLATES_DIR}/${RED3LIB_EXPORT_NAME}.pc.in")
    set(RED3LIB_INSTALL_PKG_CONFIG_DIR "${RED3LIB_INSTALL_CONFIG_DIR}/pkgconfig")

    if (IS_ABSOLUTE "${CMAKE_INSTALL_INCLUDEDIR}")
        set(RED3LIB_PKG_CONFIG_INCLUDE_DIR "${CMAKE_INSTALL_INCLUDEDIR}")
    else()
        set(RED3LIB_PKG_CONFIG_INCLUDE_DIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}")
    endif()

    if (IS_ABSOLUTE "${CMAKE_INSTALL_LIBDIR}")
        set(RED3LIB_PKG_CONFIG_LIB_DIR "${CMAKE_INSTALL_LIBDIR}")
    else()
        set(RED3LIB_PKG_CONFIG_LIB_DIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")
    endif()

    configure_file(
      "${RED3LIB_PKG_CONFIG_FILE_IN}"
      "${RED3LIB_PKG_CONFIG_FILE}"
      @ONLY
    )

    install(
      FILES "${RED3LIB_PKG_CONFIG_FILE}"
      DESTINATION "${RED3LIB_INSTALL_PKG_CONFIG_DIR}"
    )
  endif()
endif()
