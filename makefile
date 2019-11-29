# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
CC = g++
CFLAGS  = -g -Wall -Weffc++ -std=c++11
LFLAGS  = -L/usr/lib

# All Targets
all: splflix

# Tool invocations
splflix: bin/Main.o bin/Session.o bin/User.o bin/Watchable.o bin/Action.o
	@echo 'Building target: Main'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/splflix bin/Main.o bin/Session.o bin/User.o bin/Watchable.o bin/Action.o $(LFLAGS)
	@echo 'Finished building target: Main'
	@echo ' '

# Depends on the source and header files
bin/Main.o: src/Main.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Main.o src/Main.cpp
bin/Action.o: src/Action.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Action.o src/Action.cpp
bin/Session.o: src/Session.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Session.o src/Session.cpp
bin/Watchable.o: src/Watchable.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Watchable.o src/Watchable.cpp
bin/User.o: src/User.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/User.o src/User.cpp
bin/CreateUser.o: src/CreateUser.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/CreateUser.o src/CreateUser.cpp
bin/ChangeActiveUser.o: src/ChangeActiveUser.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/ChangeActiveUser.o src/ChangeActiveUser.cpp
bin/DuplicateUser.o: src/DuplicateUser.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/DuplicateUser.o src/DuplicateUser.cpp
bin/DeleteUser.o: src/DeleteUser.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/DeleteUser.o src/DeleteUser.cpp
bin/Exit.o: src/Exit.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Exit.o src/Exit.cpp
bin/Episode.o: src/Episode.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Episode.o src/Episode.cpp
bin/GenreRecommenderUser.o: src/GenreRecommenderUser.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/GenreRecommenderUser.o src/GenreRecommenderUser.cpp
bin/LengthRecommenderUser.o: src/LengthRecommenderUser.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/LengthRecommenderUser.o src/LengthRecommenderUser.cpp
bin/PrintActionsLog.o: src/PrintActionsLog.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PrintActionsLog.o src/PrintActionsLog.cpp
bin/PrintContentList.o: src/PrintContentList.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PrintContentList.o src/PrintContentList.cpp
bin/PrintWatchHistory.o: src/PrintWatchHistory.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PrintWatchHistory.o src/PrintWatchHistory.cpp
bin/RerunRecommenderUser.o: src/RerunRecommenderUser.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/RerunRecommenderUser.o src/RerunRecommenderUser.cpp
bin/Movie.o: src/Movie.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Movie.o src/Movie.cpp
#Clean the build directory
clean: 
	rm -f bin/*
