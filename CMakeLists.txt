# libnitroshareutil
# Copyright (C) 2013  Nathan Osman

cmake_minimum_required(VERSION 2.8.9)
project(nitroshareutil)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

#============================================
# Check to make sure we have a C++11 compiler

# TODO:
# - check for MSVC++ 2010
# - report error if no C++11 compiler found
# - try_compile might be better

if(CMAKE_COMPILER_IS_GNUCXX)
    if(${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 4.6)
        message(FATAL_ERROR "GCC 4.6+ is required (" ${CMAKE_CXX_COMPILER_VERSION} " detected).")
    endif()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if(${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 3.1)
        message(FATAL_ERROR "Clang 3.1+ is required (" ${CMAKE_CXX_COMPILER_VERSION} " detected).")
    endif()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
endif()

#============================================

find_package(Qt5Core REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(include)

set(SRC
    src/asynctask.cpp
    src/parameterbuilder.cpp)
set(MOC
    include/nitroshare/util/asynctask.h
    include/nitroshare/util/parameterbuilder.h)

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
