# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /users/studs/bsc/2020/maiy/Clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /users/studs/bsc/2020/maiy/Clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /users/studs/bsc/2020/maiy/CLionProjects/Ass1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /users/studs/bsc/2020/maiy/CLionProjects/Ass1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Assignment_1_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment_1_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment_1_.dir/flags.make

CMakeFiles/Assignment_1_.dir/src/main.cpp.o: CMakeFiles/Assignment_1_.dir/flags.make
CMakeFiles/Assignment_1_.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/maiy/CLionProjects/Ass1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assignment_1_.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_1_.dir/src/main.cpp.o -c /users/studs/bsc/2020/maiy/CLionProjects/Ass1/src/main.cpp

CMakeFiles/Assignment_1_.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_1_.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/maiy/CLionProjects/Ass1/src/main.cpp > CMakeFiles/Assignment_1_.dir/src/main.cpp.i

CMakeFiles/Assignment_1_.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_1_.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/maiy/CLionProjects/Ass1/src/main.cpp -o CMakeFiles/Assignment_1_.dir/src/main.cpp.s

CMakeFiles/Assignment_1_.dir/src/Session.cpp.o: CMakeFiles/Assignment_1_.dir/flags.make
CMakeFiles/Assignment_1_.dir/src/Session.cpp.o: ../src/Session.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/maiy/CLionProjects/Ass1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Assignment_1_.dir/src/Session.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_1_.dir/src/Session.cpp.o -c /users/studs/bsc/2020/maiy/CLionProjects/Ass1/src/Session.cpp

CMakeFiles/Assignment_1_.dir/src/Session.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_1_.dir/src/Session.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/maiy/CLionProjects/Ass1/src/Session.cpp > CMakeFiles/Assignment_1_.dir/src/Session.cpp.i

CMakeFiles/Assignment_1_.dir/src/Session.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_1_.dir/src/Session.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/maiy/CLionProjects/Ass1/src/Session.cpp -o CMakeFiles/Assignment_1_.dir/src/Session.cpp.s

CMakeFiles/Assignment_1_.dir/src/Movie.cpp.o: CMakeFiles/Assignment_1_.dir/flags.make
CMakeFiles/Assignment_1_.dir/src/Movie.cpp.o: ../src/Movie.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/maiy/CLionProjects/Ass1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Assignment_1_.dir/src/Movie.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_1_.dir/src/Movie.cpp.o -c /users/studs/bsc/2020/maiy/CLionProjects/Ass1/src/Movie.cpp

CMakeFiles/Assignment_1_.dir/src/Movie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_1_.dir/src/Movie.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/maiy/CLionProjects/Ass1/src/Movie.cpp > CMakeFiles/Assignment_1_.dir/src/Movie.cpp.i

CMakeFiles/Assignment_1_.dir/src/Movie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_1_.dir/src/Movie.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/maiy/CLionProjects/Ass1/src/Movie.cpp -o CMakeFiles/Assignment_1_.dir/src/Movie.cpp.s

CMakeFiles/Assignment_1_.dir/src/Watchable.cpp.o: CMakeFiles/Assignment_1_.dir/flags.make
CMakeFiles/Assignment_1_.dir/src/Watchable.cpp.o: ../src/Watchable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/maiy/CLionProjects/Ass1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Assignment_1_.dir/src/Watchable.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_1_.dir/src/Watchable.cpp.o -c /users/studs/bsc/2020/maiy/CLionProjects/Ass1/src/Watchable.cpp

CMakeFiles/Assignment_1_.dir/src/Watchable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_1_.dir/src/Watchable.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/maiy/CLionProjects/Ass1/src/Watchable.cpp > CMakeFiles/Assignment_1_.dir/src/Watchable.cpp.i

CMakeFiles/Assignment_1_.dir/src/Watchable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_1_.dir/src/Watchable.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/maiy/CLionProjects/Ass1/src/Watchable.cpp -o CMakeFiles/Assignment_1_.dir/src/Watchable.cpp.s

CMakeFiles/Assignment_1_.dir/src/Episode.cpp.o: CMakeFiles/Assignment_1_.dir/flags.make
CMakeFiles/Assignment_1_.dir/src/Episode.cpp.o: ../src/Episode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/maiy/CLionProjects/Ass1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Assignment_1_.dir/src/Episode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_1_.dir/src/Episode.cpp.o -c /users/studs/bsc/2020/maiy/CLionProjects/Ass1/src/Episode.cpp

CMakeFiles/Assignment_1_.dir/src/Episode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_1_.dir/src/Episode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/maiy/CLionProjects/Ass1/src/Episode.cpp > CMakeFiles/Assignment_1_.dir/src/Episode.cpp.i

CMakeFiles/Assignment_1_.dir/src/Episode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_1_.dir/src/Episode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/maiy/CLionProjects/Ass1/src/Episode.cpp -o CMakeFiles/Assignment_1_.dir/src/Episode.cpp.s

# Object files for target Assignment_1_
Assignment_1__OBJECTS = \
"CMakeFiles/Assignment_1_.dir/src/main.cpp.o" \
"CMakeFiles/Assignment_1_.dir/src/Session.cpp.o" \
"CMakeFiles/Assignment_1_.dir/src/Movie.cpp.o" \
"CMakeFiles/Assignment_1_.dir/src/Watchable.cpp.o" \
"CMakeFiles/Assignment_1_.dir/src/Episode.cpp.o"

# External object files for target Assignment_1_
Assignment_1__EXTERNAL_OBJECTS =

Assignment_1_: CMakeFiles/Assignment_1_.dir/src/main.cpp.o
Assignment_1_: CMakeFiles/Assignment_1_.dir/src/Session.cpp.o
Assignment_1_: CMakeFiles/Assignment_1_.dir/src/Movie.cpp.o
Assignment_1_: CMakeFiles/Assignment_1_.dir/src/Watchable.cpp.o
Assignment_1_: CMakeFiles/Assignment_1_.dir/src/Episode.cpp.o
Assignment_1_: CMakeFiles/Assignment_1_.dir/build.make
Assignment_1_: CMakeFiles/Assignment_1_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/users/studs/bsc/2020/maiy/CLionProjects/Ass1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Assignment_1_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Assignment_1_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment_1_.dir/build: Assignment_1_

.PHONY : CMakeFiles/Assignment_1_.dir/build

CMakeFiles/Assignment_1_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Assignment_1_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Assignment_1_.dir/clean

CMakeFiles/Assignment_1_.dir/depend:
	cd /users/studs/bsc/2020/maiy/CLionProjects/Ass1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /users/studs/bsc/2020/maiy/CLionProjects/Ass1 /users/studs/bsc/2020/maiy/CLionProjects/Ass1 /users/studs/bsc/2020/maiy/CLionProjects/Ass1/cmake-build-debug /users/studs/bsc/2020/maiy/CLionProjects/Ass1/cmake-build-debug /users/studs/bsc/2020/maiy/CLionProjects/Ass1/cmake-build-debug/CMakeFiles/Assignment_1_.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Assignment_1_.dir/depend

