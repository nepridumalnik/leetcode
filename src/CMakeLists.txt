file(GLOB cpp_files ./*.cpp)

message("-- cpp_files: ${cpp_files}")

foreach(file ${cpp_files})
    get_filename_component(filename_cpp ${file} NAME)
    get_filename_component(filename ${file} NAME_WE)
    add_executable(${filename} ${filename_cpp})
    target_precompile_headers(${filename} PRIVATE data.hpp)
endforeach()
