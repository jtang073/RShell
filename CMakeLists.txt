CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
ADD_SUBDIRECTORY(googletest)
SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
        ${PROJECT_SOURCE_DIR}/src/test.cpp
        ${PROJECT_SOURCE_DIR}/src/RShell.cpp
        ${PROJECT_SOURCE_DIR}/src/Instruction.hpp
        ${PROJECT_SOURCE_DIR}/src/Command.cpp
        ${PROJECT_SOURCE_DIR}/src/And.cpp
        ${PROJECT_SOURCE_DIR}/src/Or.cpp
        ${PROJECT_SOURCE_DIR}/src/Semicolon.cpp
        ${PROJECT_SOURCE_DIR}/src/Connector.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

