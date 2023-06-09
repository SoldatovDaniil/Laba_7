cmake_minimum_required(VERSION 3.24)
SET (CMAKE_CXX_STANDARD 17)

project(expression2 CXX)



set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE})

set(antlr4-bin ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/antlr4/runtime/Cpp/build/bin)



include_directories( 
${antlr4-bin}/lib 3rdparty/antlr4/runtime/Cpp/build/bin/bin/ 
${antlr4-bin}/include/
)

add_subdirectory(include)
