## libnitroshareutil

[![Build Status](https://travis-ci.org/nitroshare/libnitroshareutil.png?branch=master)](https://travis-ci.org/nitroshare/libnitroshareutil)

This shared library contains a number of utility classes used by NitroShare client applications. Some of these include:

 - `AsyncTask` and `BlockingAsyncTask` - base classes for asynchronous tasks
 - `FileHeader` - storage for file metadata
 - `FileHeaderList` - collection of headers and directory enumeration
 - `ParameterBuilder` - simple syntax for constructing a `QVariantMap`

### Requirements

In order to build the library, the following dependencies must be met:

 - C++11 compiler:
   - Visual Studio 2010+
   - GCC 4.6+
   - Clang 3.1+
 - CXX11.cmake (available [here](https://github.com/NitroShare/CXX11-CMake-Macros))
 - Qt 5.0+

### Building

To build the shared library, please follow the steps below:

1. Begin by creating a directory for the compiled files and change to that directory:

        mkdir build
        cd build

2. Run CMake:

        cmake <source path>

   The source path is the directory containing the libnitroshareutil source code.

3. Build and install the shared library:

        make
        sudo make install
