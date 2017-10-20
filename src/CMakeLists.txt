###############################################################################
# @file CMakeLists.txt
# @project server for the simulations of processes
# @brief  CMakeLists.txt principal for  the simulations of processes
# @details this doc contains all requirements needs for the execution
# @author Ronald Sulbaran and Julio Jaimes R, ronaldanto03@gmail.com, carlosjuliojr@hotmail.com
# @date 15/10/2016
###############################################################################

set (PROJECT VirtualProfessorAssistant)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)


 # Widgets finds its own dependencies (QtGui and QtCore).
find_package(Qt5Widgets PATHS "/home/julio/Qt/5.6/gcc_64/lib/cmake" REQUIRED)
add_definitions(-std=c++11 -g)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(../include)
include_directories(.)

add_subdirectory(libs)
add_subdirectory(Ui)

set(VPA_Libs
     CMakeLists.txt
     ../include/databasestructs.h
     ../include/person.h
     ../include/calification.h
     ../include/course.h
     ../include/student.h
     ../include/assistance.h
     ../include/dbhandler.h
     ../include/evaluation.h
     ../include/model.h

    person.cpp
    course.cpp
    calification.cpp
    student.cpp
    assistance.cpp
    dbhandler.cpp
    evaluation.cpp
    model.cpp
    databasestructs.cpp
    )


add_library(virtualprofessorassistant ${VPA_Libs})

add_executable(${PROJECT} main.cpp)


target_link_libraries(${PROJECT} virtualprofessorassistant gui dataBaseGenerator)
qt5_use_modules(virtualprofessorassistant Widgets)
qt5_use_modules(${PROJECT} Widgets)



