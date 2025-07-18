cmake_minimum_required(VERSION 3.10)

# Project name and version
project(chip8-emulator VERSION 1.0 LANGUAGES C)

# Include directory for header files
include_directories(include)

# Collect all C source files in the src directory
file(GLOB SOURCES "src/*.c")

# Create a static library (change STATIC to SHARED if you want a dynamic library)
add_library(chip8 STATIC ${SOURCES})

# Optionally set the C standard
set_target_properties(chip8 PROPERTIES
    C_STANDARD 99
    C_STANDARD_REQUIRED YES
)

# ---------------------
# Enable and configure testing
# ---------------------
enable_testing()

# Collect all test source files in tests/
file(GLOB TEST_SOURCES "tests/*.c")

# Build each test file as a separate executable
foreach(TEST_SRC ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SRC} NAME_WE)

    add_executable(${TEST_NAME} ${TEST_SRC})
    target_link_libraries(${TEST_NAME} chip8)

    # Add the test to CTest
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()