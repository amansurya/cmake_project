# Private CMakeLists for Fault Catch reset data example BFData  

cmake_minimum_required(VERSION 3.13.1)


target_sources(cpp_app PRIVATE
    "Array_Basics.cpp"
if(CONFIG_ENABLE_MODULE_STRINGS)
    "String_Basics.cpp"
    "String_Assignment.cpp"
endif() #excluding strings to make it ubuntu ready. work in progress.
)

target_include_directories(cpp_app PUBLIC "./")
