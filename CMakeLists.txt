cmake_minimum_required(VERSION 3.10)
project(GameEngine)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# List of source files
# set(SOURCES src/main.cpp)
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add executable target
add_executable(GameEngine ${SOURCES})

# Find required packages
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(Threads REQUIRED)

# Include directories for the target
target_include_directories(GameEngine PRIVATE 
    ${OPENGL_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/src  # Include the src directory
)

# Link libraries to the target
target_link_libraries(GameEngine PRIVATE 
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    glfw
    Threads::Threads
)
