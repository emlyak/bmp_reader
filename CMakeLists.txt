cmake_minimum_required(VERSION 3.12)

project(bmp_reader
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    main.cpp
    bmp_reader.cpp
)

set(HEADERS
    bmp_reader.h
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})