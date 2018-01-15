cmake_minimum_required(VERSION 3.8)
project(ttt2_application)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "-O2 -Wall")

include_directories(
        "${CMAKE_SOURCE_DIR}/lib/tic-tac-toe/"
)

add_subdirectory(lib)
add_subdirectory(src)
