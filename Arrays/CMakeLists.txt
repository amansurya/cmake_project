# Private CMakeLists for Fault Catch reset data example BFData  

cmake_minimum_required(VERSION 3.13.1)


target_sources(cpp_app PRIVATE
    "Array_Basics.cpp"
    "String_Basics.cpp"
    "String_Assignment.cpp"
)

target_include_directories(cpp_app PUBLIC "./")
