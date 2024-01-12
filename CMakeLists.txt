cmake_minimum_required(VERSION 3.27)
project(ohpc)

file(GLOB HEADER_FILES "inc/*.h")
file(GLOB SRC_FILES "src/*.cpp")

set(CMAKE_CXX_STANDARD 17)

add_executable(ohpc
        src/main.cpp
        inc/types.h
        inc/tvec.h
        src/tvec.cpp
        inc/frac.h
        src/frac.cpp
        inc/num.h
        src/num.cpp
        inc/element.h
        inc/operators.h
        src/operators.cpp
        inc/Equation.h
        src/Equation.cpp
        inc/Shuntingyard.h
        src/Shuntingyard.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE inc)
