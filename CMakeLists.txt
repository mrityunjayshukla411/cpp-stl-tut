cmake_minimum_required(VERSION 3.28)
project(cpp_lab)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/compiler_options.cmake)
include(cmake/dependencies.cmake)

add_subdirectory(src)
add_subdirectory(projects)