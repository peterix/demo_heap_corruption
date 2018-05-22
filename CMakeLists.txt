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
)

# Create code from a list of Qt designer ui files.
#set(CMAKE_AUTOUIC ON) # use this if you have CMake 3.x instead of the following
qt5_wrap_ui(poc_heap_corruption_SRC src/poc_heap_corruption.ui)

# Tell CMake to create the helloworld executable
add_executable(poc_heap_corruption ${poc_heap_corruption_SRC})

# Use the Widgets module from Qt 5.
target_link_libraries(poc_heap_corruption Qt5::Widgets)

# Install the executable
install(TARGETS poc_heap_corruption DESTINATION bin)
