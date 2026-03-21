# Common warnings
add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
)

# Debug / Release flags
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")