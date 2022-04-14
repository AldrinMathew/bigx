cmake_minimum_required(VERSION 3.16.3)

project(BIGX
        VERSION 0.1.0
        DESCRIPTION "Big Numbers for C++"
        HOMEPAGE_URL "https://github.com/aldrinsartfactory/bigx")

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_COMPILER /usr/bin/clang++-13)
SET(CMAKE_CXX_FLAGS "-Os -std=c++20")
add_link_options("-fuse-ld=lld")
add_library(bigint 
                big_int.cpp
                exceptions.cpp)