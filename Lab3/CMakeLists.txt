cmake_minimum_required(VERSION 4.3)
project(Lab3)

set(CMAKE_CXX_STANDARD 23)

add_executable(Lab3 main.cpp
        cameraParams.cpp
        cameraParams.hpp
        point.cpp
        point.hpp
        fib.cpp
        fib.hpp

)
