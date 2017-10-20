###############################################################################
# @file CMakeLists.txt
# @project server for the simulations of processes
# @brief  CMakeLists.txt principal for  the simulations of processes
# @details this doc contains all requirements needs for the execution
# @author Ronald Sulbaran and Julio Jaimes R, ronaldanto03@gmail.com, carlosjuliojr@hotmail.com
# @date 15/10/2016
###############################################################################

cmake_minimum_required(VERSION 3.5)
# Widgets finds its own dependencies (QtGui and QtCore).
find_package(Qt5Widgets PATHS "/home/julio/Qt/5.6/gcc_64/lib/cmake" REQUIRED)
add_definitions(-std=c++11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

include_directories(
    ../../../include
    )

set(PROJECT_SRC
      databasegenerator.cpp
      databasegenerator.h
      )

add_library(dataBaseGenerator ${PROJECT_SRC})
qt5_use_modules(dataBaseGenerator Widgets)






