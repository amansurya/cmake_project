# Private CMakeLists for Pointers folder

cmake_minimum_required(VERSION 3.13.1)


target_sources(cpp_app PRIVATE
    "Functions_Basics.cpp"
)

target_include_directories(cpp_app PUBLIC "./")
