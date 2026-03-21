file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS *.cpp)

foreach(file ${SRC_FILES})
    get_filename_component(name ${file} NAME_WE)
    get_filename_component(dir ${file} DIRECTORY)
    get_filename_component(folder ${dir} NAME)

    set(target "${folder}_${name}")

    add_executable(${target} ${file})

    target_include_directories(${target}
        PRIVATE ${PROJECT_SOURCE_DIR}/include
    )

    target_link_libraries(${target}
        PRIVATE CLI11::CLI11
    )
endforeach()