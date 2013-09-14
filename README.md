## libnitroshareutil

This shared library contains a number of utility classes used by NitroShare client applications. Some of these include:

 - `AsyncTask` - a base class for asynchronous tasks
 - `ParameterBuilder` - simple syntax for constructing a `QVariantMap`

### Requirements

In order to build the library, the following dependencies must be met:

 - C++11 compiler:
   - Visual Studio 2010+
   - GCC 4.6+
   - Clang 3.1+
 - CXX11.cmake (available [here](https://github.com/NitroShare/CXX11-CMake-Macros))
 - Qt 5.0+

