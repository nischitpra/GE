cmake_minimum_required(VERSION 3.10)

project(GameEngine)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "src/*.cpp")
add_executable(GameEngine ${SOURCES})

find_package(Threads REQUIRED)
target_link_libraries(GameEngine PRIVATE Threads::Threads)