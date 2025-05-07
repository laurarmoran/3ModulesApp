cmake_minimum_required(VERSION 3.29)
project(3ModulesApp)

set(CMAKE_CXX_STANDARD 20)

add_executable(3ModulesApp cmake-build-debug/src/main.cpp
        cmake-build-debug/src/IModule.h
        cmake-build-debug/src/BytesGen.cpp
        cmake-build-debug/src/BytesGenerator.cpp
        cmake-build-debug/src/BytesGenerator.h
        cmake-build-debug/src/SequenceFinder.cpp
        cmake-build-debug/src/SequenceFinder.h)
