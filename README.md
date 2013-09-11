## libnitroshareutil

This shared library contains a number of utility classes used by NitroShare client applications. Some of these include:

 - `Promise` - an object returned by asynchronous tasks that emits signals indicating the progress of the task
 - `AsyncTask` - a base class for asynchronous tasks that run in a separate thread

### Requirements

In order to build the library, the following dependencies must be met:

 - C++11 compiler:
   - Visual Studio 2010+
   - GCC 4.6+
   - Clang 3.1+
 - Qt 5.0+

