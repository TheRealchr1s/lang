cmake_minimum_required(VERSION 3.10)

project(lang)

set(CMAKE_CXX_STANDARD 17)

# Add the include directory
include_directories(include)

# Add the source files
set(SOURCE_FILES
    src/lexer.cpp
    src/parser.cpp
    src/ast.cpp
    src/semantic_analysis.cpp
    src/code_generation.cpp
    main.cpp
)

# Create the executable
add_executable(lang ${SOURCE_FILES})
