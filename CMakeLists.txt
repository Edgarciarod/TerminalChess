cmake_minimum_required(VERSION 3.6)
project(TerminalChess)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp chess_ui.cpp chess_ui.h termcolor.h chess_engine.cpp chess_engine.h chess_piece.h)
add_executable(TerminalChess ${SOURCE_FILES})