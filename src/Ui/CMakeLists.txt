###############################################################################
# @file CMakeLists.txt
# @project server for the simulations of processes
# @brief  CMakeLists.txt principal for  the simulations of processes
# @details this doc contains all requirements needs for the execution
# @author Ronald Sulbaran and Julio Jaimes R, ronaldanto03@gmail.com, carlosjuliojr@hotmail.com
# @date 15/10/2016
###############################################################################

cmake_minimum_required(VERSION 3.5)

project (gui)
set (PROJECT gui)


# Widgets finds its own dependencies (QtGui and QtCore).
find_package(Qt5Widgets PATHS "/home/julio/Qt/5.6/gcc_64/lib/cmake" REQUIRED)
add_definitions(-std=c++11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB_RECURSE COMMON_SOURCE  "*.h" "*.cpp")

include_directories(${PROJECT_BINARY_DIR})
include_directories(../../include)
include_directories(../../images)
include_directories(.)
add_library(${PROJECT} STATIC ${COMMON_SOURCE})
target_link_libraries(${PROJECT} virtualprofessorassistant)
qt5_use_modules(${PROJECT} Widgets)









