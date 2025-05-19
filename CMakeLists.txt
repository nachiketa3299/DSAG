project(DSAG)

file(GLOB_RECURSE DSAG_SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

file(GLOB_RECURSE DSAG_HEADERS
  "${CMAKE_CURRENT_SOURCE_DIR}/include/DSAG/*.hpp"
)

message(STATUS "[DSAG] Detected sources: ")
foreach(file ${DSAG_SOURCES})
  message(STATUS "\t\t- ${file}")
endforeach()

message(STATUS "[DSAG] Detected headers: ")
foreach(file ${DSAG_HEADERS})
  message(STATUS "\t\t- ${file}")
endforeach()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(DSAG ${DSAG_SOURCES} ${DSAG_HEADERS})
target_include_directories(DSAG PUBLIC ${CMAKE_CURRENT_SOURCES}/include/)