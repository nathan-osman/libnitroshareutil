# libnitroshareutil
# Copyright (C) 2013  Nathan Osman

cmake_minimum_required(VERSION 2.8.9)
project(nitroshareutil)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# TODO: enable C++11 support
find_package(Qt5Core REQUIRED)

set(SRC "")
set(MOC "")

add_library(nitroshareutil SHARED ${SRC} ${MOC})
set_target_properties(nitroshareutil PROPERTIES
    VERSION   ${VERSION}
    SOVERSION ${VERSION_MAJOR})

install(DIRECTORY include/nitroshare/util
    DESTINATION include/nitroshare)
install(TARGETS nitroshareutil
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin)

