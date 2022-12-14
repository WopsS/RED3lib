add_library(RED3lib.ExecuteFunctions SHARED)

set(
  RED3LIB_EXECUTE_FUNCTIONS_SRC_FILES
    main.cpp
)

source_group(
  TREE
    "${CMAKE_CURRENT_SOURCE_DIR}"
  FILES
    ${RED3LIB_EXECUTE_FUNCTIONS_SRC_FILES}
)

target_sources(
  RED3lib.ExecuteFunctions
    PRIVATE
      ${RED3LIB_EXECUTE_FUNCTIONS_SRC_FILES}
)

target_link_libraries(
  RED3lib.ExecuteFunctions
    PRIVATE
      RED3lib::RED3lib
)

set_target_properties(
  RED3lib.ExecuteFunctions
    PROPERTIES
      FOLDER
        "Examples"
)
