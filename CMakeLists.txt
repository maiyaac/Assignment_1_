cmake_minimum_required(VERSION 3.15)
project(Assignment_1_)

set(CMAKE_CXX_STANDARD 11)

add_executable(Assignment_1_ include/Action.h include/Session.h include/User.h include/Watchable.h src/main.cpp src/Session.cpp src/Movie.cpp src/Watchable.cpp src/Episode.cpp src/Action.cpp src/CreateUser.cpp src/User.cpp src/ChangeActiveUser.cpp)