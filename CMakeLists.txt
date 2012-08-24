cmake_minimum_required(VERSION 2.8)
project(client)

#let's give support for c++11
SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++11")

#===================================
#set libraries
#===================================
add_library(cdebug SHARED debug.cpp)
add_library(proving SHARED proving.cpp)
set(LIBS cdebug proving)

#===================================
#app
#===================================
add_executable(template template.cpp)
target_link_libraries(template ${LIBS})
