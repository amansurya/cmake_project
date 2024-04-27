# Private CMakeLists for C++ Cmake Project Learning

cmake_minimum_required(VERSION 3.13.1)
set(CMAKE_CXX_STANDARD 14)

project(cpp_app)
add_executable(cpp_app)

# Include the Config.cmake file
include(Config.cmake)
if( ENABLE_MODULE_POINTERS )
    add_subdirectory("Pointers" Pointers)
    add_compile_definitions(CONFIG_ENABLE_MODULE_POINTERS)
endif()
if( ENABLE_MODULE_ARRAYS )
    add_subdirectory("Arrays" Arrays)
    add_compile_definitions(CONFIG_ENABLE_MODULE_ARRAYS)
    if ( ENABLE_MODULE_STRINGS )
        add_compile_definitions(CONFIG_ENABLE_MODULE_STRINGS)
    endif()
    if( ENABLE_MODULE_STRINGS_ASSIGNMENTS )
        add_compile_definitions(CONFIG_ENABLE_MODULE_STRINGS_ASSIGNMENTS)
    endif()
endif()
if( ENABLE_MODULE_FUNCTIONS )
    add_subdirectory("Functions" Functions)
    add_compile_definitions(CONFIG_ENABLE_MODULE_FUNCTIONS)
endif()

target_sources(cpp_app PRIVATE
    "main.cpp"
)
target_include_directories(cpp_app PUBLIC "./")
