file(GLOB cpp_files ./*.cpp)

message("-- cpp_files: ${cpp_files}")

set(PCH_HEADER "data.hpp")

add_library(pch INTERFACE)
target_precompile_headers(pch INTERFACE ${PCH_HEADER})

foreach(file ${cpp_files})
    get_filename_component(filename_cpp ${file} NAME)
    get_filename_component(filename ${file} NAME_WE)
    add_executable(${filename} ${filename_cpp})

    target_link_libraries(${filename} PRIVATE pch)
endforeach()
