cmake_minimum_required(VERSION 3.16)
project(Examples)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
file( GLOB APP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp )
foreach( sourcefile ${APP_SOURCES} )
    file(RELATIVE_PATH filename ${CMAKE_CURRENT_SOURCE_DIR} ${sourcefile})
    string( REPLACE ".cpp" "" file ${filename} )
    add_executable( ${file} ${sourcefile} )
endforeach( sourcefile ${APP_SOURCES} )