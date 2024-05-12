cmake_minimum_required(VERSION 3.10)

project(GameEngine)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "src/*.cpp")
add_executable(GameEngine ${SOURCES})

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(Threads REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS})

target_link_libraries(GameEngine PRIVATE 
    ${OPENGL_LIBRARIES} 
    ${GLEW_LIBRARIES} 
    glfw 
    Threads::Threads)
