cmake_minimum_required(VERSION 3.29)
project(3ModulesApp)

set(CMAKE_CXX_STANDARD 20)

add_executable(3ModulesApp src/main.cpp
        include/IModule.h
        src/Generator_M1.cpp
        include/Generator_M1.h
        src/SequenceFinder.cpp
        include/SequenceFinder.h
        src/Recorder_M3.cpp
        include/Recorder_M3.h)
