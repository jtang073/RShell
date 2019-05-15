MAKE_MINIMUM_REQUIRED(VERSION 2.8)
ADD_SUBDIRECTORY(googletest)
SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
        test.cpp
        RShell.cpp
        Instruction.hpp
        Command.cpp
        And.cpp
        Or.cpp
        Semicolon.cpp
        Connector.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

