cmake_minimum_required(VERSION 3.0.0)
project(pazymiai VERSION 0.1.0)

add_executable(pazymiai mainvector.cpp studentasvector.cpp funkcijos.cpp)

set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

