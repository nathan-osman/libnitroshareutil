# libnitroshareutil
# Copyright (C) 2013  Nathan Osman

project(tests)

find_package(Qt5Test REQUIRED)

set(SRC
    main.cpp)
set(MOC
    )

add_executable(tests ${SRC} ${MOC})

qt5_use_modules(tests Test)
target_link_libraries(tests nitroshareutil)
