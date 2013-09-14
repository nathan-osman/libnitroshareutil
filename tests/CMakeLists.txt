# libnitroshareutil
# Copyright (C) 2013  Nathan Osman

project(tests)

find_package(Qt5Test REQUIRED)

set(test_SRC
    main.cpp
    nonblockingtask.cpp
    testasynctask.cpp
    testparameterbuilder.cpp)
qt5_wrap_cpp(test_MOC
    nonblockingtask.h
    testasynctask.h
    testparameterbuilder.h)

add_executable(tests ${test_SRC} ${test_MOC})

qt5_use_modules(tests Test)
target_link_libraries(tests nitroshareutil)
