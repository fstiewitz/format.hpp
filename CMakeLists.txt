cmake_minimum_required(VERSION 3.10)
project(format_hpp)

set(CMAKE_CXX_STANDARD 17)

add_library(format_hpp INTERFACE)
target_include_directories(format_hpp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(format_hpp_test main.cpp)
target_link_libraries(format_hpp_test PUBLIC format_hpp)

install(FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/include/format.hpp
        DESTINATION include)
