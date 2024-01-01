cmake_minimum_required(VERSION 2.84 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)

project(Monopoly)

include_directories(include)

add_library(${PROJECT_NAME} SHARED
src/Cell.cpp src/GameField.cpp src/Player.cpp src/PlayerNPC.cpp)

add_executable(main src/main.cpp)

target_link_libraries(main ${PROJECT_NAME})