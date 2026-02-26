cmake_minimum_required(VERSION 3.20)

project(ElectroMagnetism VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output binary in build/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

# Include headers
include_directories(include)

# Build SDL3 from vendored source
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

# Explicitly list source files
add_executable(ElectroMagnetism
    src/main.cpp
    src/Particle.cpp
    src/PhysicsVector.cpp
)

# Link SDL3 target
target_link_libraries(ElectroMagnetism PRIVATE SDL3::SDL3)