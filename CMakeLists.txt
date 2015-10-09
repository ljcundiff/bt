cmake_minimum_required( VERSION 3.3 )
project( bt )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include( CMakeLocal.txt OPTIONAL )

set( CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build )
set( CMAKE_INCLUDE_CURRENT_DIR ON )

include_directories( ${BOOSTDIR} )

add_subdirectory( refid )
add_subdirectory( replace )
