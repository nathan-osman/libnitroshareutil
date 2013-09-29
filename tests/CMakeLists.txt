# libnitroshareutil
# Copyright (C) 2013  Nathan Osman

project(tests)

find_package(Qt5Test REQUIRED)

set(test_SRC
    blockingtask.cpp
    main.cpp
    task.cpp
    testasynctask.cpp
    testfileheader.cpp
    testparameterbuilder.cpp)
qt5_wrap_cpp(test_MOC
    blockingtask.h
    task.h
    testasynctask.h
    testfileheader.h
    testparameterbuilder.h)

add_executable(tests ${test_SRC} ${test_MOC})

qt5_use_modules(tests Test)
target_link_libraries(tests nitroshareutil)
