cmake_minimum_required(VERSION 3.0)
project(poc_heap_corruption)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets CONFIG REQUIRED)

set(poc_heap_corruption_SRC
  src/poc.cpp
)

add_executable(poc_heap_corruption ${poc_heap_corruption_SRC})
target_include_directories(poc_heap_corruption PRIVATE src)
target_link_libraries(poc_heap_corruption Qt5::Widgets)

install(TARGETS poc_heap_corruption DESTINATION bin)
