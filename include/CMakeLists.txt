project(include)

file(GLOB srcs "*.cpp*")
file(GLOB hdrs "*.h*")

add_executable(include ${srcs} ${hdrs})

include_directories(include 
${antlr4-bin}/bin
${antlr4-bin}/include/antlr4-runtime
)

target_link_libraries(include PUBLIC  
${antlr4-bin}/lib/antlr4-runtime.lib 
)

add_custom_command(TARGET include
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${antlr4-bin}/bin/antlr4-runtime.dll ${CMAKE_BINARY_DIR}/bin/
)
