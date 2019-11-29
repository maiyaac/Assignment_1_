cmake_minimum_required(VERSION 3.15)
project(Assignment_1_)

set(CMAKE_CXX_STANDARD 11)

add_executable(Assignment_1_ include/Action.h include/Session.h include/Watchable.h src/main.cpp src/Session.cpp src/Movie.cpp src/Watchable.cpp src/Episode.cpp src/ChangeActiveUser.cpp src/Action.cpp src/DuplicateUser.cpp src/CreateUser.cpp src/DeleteUser.cpp src/PrintContentList.cpp src/PrintWatchHistory.cpp src/PrintActionsLog.cpp src/Exit.cpp src/LengthRecommenderUser.cpp src/RerunRecommenderUser.cpp src/Watch.cpp src/User.cpp include/User.h src/GenreRecommenderUser.cpp)