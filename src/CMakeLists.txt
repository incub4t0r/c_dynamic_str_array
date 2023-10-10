add_library(CMakeDynamicLib alloc_funcs.c array.c)
target_include_directories(CMakeDynamicLib PUBLIC "${PROJECT_SOURCE_DIR}/include")
