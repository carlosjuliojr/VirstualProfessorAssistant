###############################################################################
# @file CMakeLists.txt
# @project server for the simulations of processes
# @brief  CMakeLists.txt principal for  the simulations of processes
# @details this doc contains all requirements needs for the execution
# @author Ronald Sulbaran and Julio Jaimes R, ronaldanto03@gmail.com, carlosjuliojr@hotmail.com
# @date 15/10/2016
###############################################################################

cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME tester_dbhandler)

set(PROJECT_SRC
      main.cpp
      tester_dbhandler.cpp
      )

include_directories(

    ../../include
    )

add_executable(${PROJECT_NAME} ${PROJECT_SRC})
target_link_libraries(${PROJECT_NAME} gtest virtualprofessorassistant dataBaseGenerator)
