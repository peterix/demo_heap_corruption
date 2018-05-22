cmake_minimum_required(VERSION 2.8.11)
project(poc_heap_corruption)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

set(poc_heap_corruption_SRC
  src/main.cpp
  src/poc_heap_corruption.cpp
  src/LineSeparator.cpp
  src/WorldListPage.cpp
)

# Create code from a list of Qt designer ui files.
set(CMAKE_AUTOUIC ON)

add_executable(poc_heap_corruption ${poc_heap_corruption_SRC})
target_include_directories(poc_heap_corruption PRIVATE src)
target_link_libraries(poc_heap_corruption Qt5::Widgets)

install(TARGETS poc_heap_corruption DESTINATION bin)
