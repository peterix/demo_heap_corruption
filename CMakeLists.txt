cmake_minimum_required(VERSION 3.0)
project(demo_heap_corruption)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets CONFIG REQUIRED)

set(demo_heap_corruption_SRC
  src/demo.cpp
)

add_executable(demo_heap_corruption ${demo_heap_corruption_SRC})
target_include_directories(demo_heap_corruption PRIVATE src)
target_link_libraries(demo_heap_corruption Qt5::Widgets)

install(TARGETS demo_heap_corruption DESTINATION bin)
