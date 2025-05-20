cmake_minimum_required(VERSION 3.16)
project(DSAG)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
enable_testing()

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


add_library(DSAG ${DSAG_SOURCES} ${DSAG_HEADERS})
target_include_directories(DSAG PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_precompile_headers(DSAG PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/pch.hpp)

# Google Test

add_subdirectory(external/googletest)

file(GLOB_RECURSE TEST_SOURCES "test/*.cpp")

foreach(TEST_SOURCE ${TEST_SOURCES})
  get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_SOURCE})
  target_link_libraries(${TEST_NAME}
    PRIVATE DSAG
    PRIVATE gtest
    PRIVATE gtest_main
  )
  target_precompile_headers(${TEST_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/pch.hpp)
  add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
  message(STATUS "[DSAG test]: ${TEST_NAME}")
endforeach()
