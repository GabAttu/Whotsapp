cmake_minimum_required(VERSION 4.1)
project(Whotsapp)

set(CMAKE_CXX_STANDARD 20)

add_executable(Whotsapp main.cpp
        User/User.cpp
        User/User.h
        Message/Message.cpp
        Message/Message.h
        Chat/Chat.cpp
        Chat/Chat.h
        ChatRegister/ChatRegister.cpp
        ChatRegister/ChatRegister.h)

add_executable(WhotsappTests tests.cpp
        User/User.cpp
        Message/Message.cpp
        Chat/Chat.cpp
        ChatRegister/ChatRegister.cpp)
