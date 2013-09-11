# libnitroshareutil
# Copyright (C) 2013  Nathan Osman

cmake_minimum_required(VERSION 2.8.9)
project(nitroshareutil)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

# TODO: enable C++11 support

find_package(Qt5Core REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(include)

set(SRC
    src/promise.cpp)
set(MOC
    include/nitroshare/util/promise.h)

add_library(nitroshareutil SHARED ${SRC} ${MOC})
set_target_properties(nitroshareutil PROPERTIES
    VERSION   ${VERSION}
    SOVERSION ${VERSION_MAJOR})

qt5_use_modules(nitroshareutil Core)

install(DIRECTORY include/nitroshare/util
    DESTINATION include/nitroshare)
install(TARGETS nitroshareutil
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/nitroshareutil.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/nitroshare.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/nitroshare.pc
    DESTINATION lib/pkgconfig)
