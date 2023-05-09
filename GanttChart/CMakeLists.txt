cmake_minimum_required(VERSION 3.24)
project(GanttChart C)

set(CMAKE_C_STANDARD 99)

add_executable(GanttChart main.c userDefineChart.c moreFunctions.h additionalFunctions.c asciiArt.c)
