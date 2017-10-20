###############################################################################
# @file CMakeLists.txt
# @project server for the simulations of processes
# @brief  CMakeLists.txt principal for  the simulations of processes
# @details this doc contains all requirements needs for the execution
# @author Ronald Sulbaran and Julio Jaimes R, ronaldanto03@gmail.com, carlosjuliojr@hotmail.com
# @date 15/10/2016
###############################################################################

cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME generatorDB)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Widgets finds its own dependencies (QtGui and QtCore).
find_package(Qt5Widgets PATHS "/home/julio/Qt/5.6/gcc_64/lib/cmake" REQUIRED)
add_definitions(-std=c++11 -g)


include_directories(
    ../../../include
    )

set(PROJECT_SRC
      main.cpp
      )


  add_executable(${PROJECT_NAME} ${PROJECT_SRC})
target_link_libraries(${PROJECT_NAME} dataBaseGenerator)

qt5_use_modules(${PROJECT_NAME} Widgets)



