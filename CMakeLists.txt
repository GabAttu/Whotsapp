cmake_minimum_required(VERSION 3.20)
project(Whotsapp)

set(CMAKE_CXX_STANDARD 20)

# GoogleTest setup
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Core Library
add_library(WhotsappLib STATIC
        src/User/User.cpp
        src/User/User.h
        src/Message/Message.cpp
        src/Message/Message.h
        src/Chat/Chat.cpp
        src/Chat/Chat.h
        src/ProgramManager/ProgramManager.cpp
        src/ProgramManager/ProgramManager.h
        src/TextUserInterface/TextUserInterface.cpp
        src/TextUserInterface/TextUserInterface.h
        src/Exceptions.h
)
target_include_directories(WhotsappLib PUBLIC src)

# Main Executable
add_executable(Whotsapp main.cpp)
target_link_libraries(Whotsapp PRIVATE WhotsappLib)

# Tests Executable
add_executable(WhotsappTests tests/tests.cpp)
target_link_libraries(WhotsappTests PRIVATE WhotsappLib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(WhotsappTests DISCOVERY_TIMEOUT 60)
