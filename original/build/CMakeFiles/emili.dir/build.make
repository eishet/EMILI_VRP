# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zildrok/EMILI_VRP/original

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zildrok/EMILI_VRP/original/build

# Include any dependencies generated for this target.
include CMakeFiles/emili.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/emili.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/emili.dir/flags.make

CMakeFiles/emili.dir/emilibase.cpp.o: CMakeFiles/emili.dir/flags.make
CMakeFiles/emili.dir/emilibase.cpp.o: ../emilibase.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zildrok/EMILI_VRP/original/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/emili.dir/emilibase.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/emili.dir/emilibase.cpp.o -c /home/zildrok/EMILI_VRP/original/emilibase.cpp

CMakeFiles/emili.dir/emilibase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emili.dir/emilibase.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zildrok/EMILI_VRP/original/emilibase.cpp > CMakeFiles/emili.dir/emilibase.cpp.i

CMakeFiles/emili.dir/emilibase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emili.dir/emilibase.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zildrok/EMILI_VRP/original/emilibase.cpp -o CMakeFiles/emili.dir/emilibase.cpp.s

CMakeFiles/emili.dir/emilibase.cpp.o.requires:

.PHONY : CMakeFiles/emili.dir/emilibase.cpp.o.requires

CMakeFiles/emili.dir/emilibase.cpp.o.provides: CMakeFiles/emili.dir/emilibase.cpp.o.requires
	$(MAKE) -f CMakeFiles/emili.dir/build.make CMakeFiles/emili.dir/emilibase.cpp.o.provides.build
.PHONY : CMakeFiles/emili.dir/emilibase.cpp.o.provides

CMakeFiles/emili.dir/emilibase.cpp.o.provides.build: CMakeFiles/emili.dir/emilibase.cpp.o


CMakeFiles/emili.dir/generalParser.cpp.o: CMakeFiles/emili.dir/flags.make
CMakeFiles/emili.dir/generalParser.cpp.o: ../generalParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zildrok/EMILI_VRP/original/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/emili.dir/generalParser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/emili.dir/generalParser.cpp.o -c /home/zildrok/EMILI_VRP/original/generalParser.cpp

CMakeFiles/emili.dir/generalParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emili.dir/generalParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zildrok/EMILI_VRP/original/generalParser.cpp > CMakeFiles/emili.dir/generalParser.cpp.i

CMakeFiles/emili.dir/generalParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emili.dir/generalParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zildrok/EMILI_VRP/original/generalParser.cpp -o CMakeFiles/emili.dir/generalParser.cpp.s

CMakeFiles/emili.dir/generalParser.cpp.o.requires:

.PHONY : CMakeFiles/emili.dir/generalParser.cpp.o.requires

CMakeFiles/emili.dir/generalParser.cpp.o.provides: CMakeFiles/emili.dir/generalParser.cpp.o.requires
	$(MAKE) -f CMakeFiles/emili.dir/build.make CMakeFiles/emili.dir/generalParser.cpp.o.provides.build
.PHONY : CMakeFiles/emili.dir/generalParser.cpp.o.provides

CMakeFiles/emili.dir/generalParser.cpp.o.provides.build: CMakeFiles/emili.dir/generalParser.cpp.o


CMakeFiles/emili.dir/main.cpp.o: CMakeFiles/emili.dir/flags.make
CMakeFiles/emili.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zildrok/EMILI_VRP/original/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/emili.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/emili.dir/main.cpp.o -c /home/zildrok/EMILI_VRP/original/main.cpp

CMakeFiles/emili.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emili.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zildrok/EMILI_VRP/original/main.cpp > CMakeFiles/emili.dir/main.cpp.i

CMakeFiles/emili.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emili.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zildrok/EMILI_VRP/original/main.cpp -o CMakeFiles/emili.dir/main.cpp.s

CMakeFiles/emili.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/emili.dir/main.cpp.o.requires

CMakeFiles/emili.dir/main.cpp.o.provides: CMakeFiles/emili.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/emili.dir/build.make CMakeFiles/emili.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/emili.dir/main.cpp.o.provides

CMakeFiles/emili.dir/main.cpp.o.provides.build: CMakeFiles/emili.dir/main.cpp.o


CMakeFiles/emili.dir/vrp/vrp.cpp.o: CMakeFiles/emili.dir/flags.make
CMakeFiles/emili.dir/vrp/vrp.cpp.o: ../vrp/vrp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zildrok/EMILI_VRP/original/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/emili.dir/vrp/vrp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/emili.dir/vrp/vrp.cpp.o -c /home/zildrok/EMILI_VRP/original/vrp/vrp.cpp

CMakeFiles/emili.dir/vrp/vrp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emili.dir/vrp/vrp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zildrok/EMILI_VRP/original/vrp/vrp.cpp > CMakeFiles/emili.dir/vrp/vrp.cpp.i

CMakeFiles/emili.dir/vrp/vrp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emili.dir/vrp/vrp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zildrok/EMILI_VRP/original/vrp/vrp.cpp -o CMakeFiles/emili.dir/vrp/vrp.cpp.s

CMakeFiles/emili.dir/vrp/vrp.cpp.o.requires:

.PHONY : CMakeFiles/emili.dir/vrp/vrp.cpp.o.requires

CMakeFiles/emili.dir/vrp/vrp.cpp.o.provides: CMakeFiles/emili.dir/vrp/vrp.cpp.o.requires
	$(MAKE) -f CMakeFiles/emili.dir/build.make CMakeFiles/emili.dir/vrp/vrp.cpp.o.provides.build
.PHONY : CMakeFiles/emili.dir/vrp/vrp.cpp.o.provides

CMakeFiles/emili.dir/vrp/vrp.cpp.o.provides.build: CMakeFiles/emili.dir/vrp/vrp.cpp.o


CMakeFiles/emili.dir/vrp/vrp_builder.cpp.o: CMakeFiles/emili.dir/flags.make
CMakeFiles/emili.dir/vrp/vrp_builder.cpp.o: ../vrp/vrp_builder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zildrok/EMILI_VRP/original/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/emili.dir/vrp/vrp_builder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/emili.dir/vrp/vrp_builder.cpp.o -c /home/zildrok/EMILI_VRP/original/vrp/vrp_builder.cpp

CMakeFiles/emili.dir/vrp/vrp_builder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emili.dir/vrp/vrp_builder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zildrok/EMILI_VRP/original/vrp/vrp_builder.cpp > CMakeFiles/emili.dir/vrp/vrp_builder.cpp.i

CMakeFiles/emili.dir/vrp/vrp_builder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emili.dir/vrp/vrp_builder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zildrok/EMILI_VRP/original/vrp/vrp_builder.cpp -o CMakeFiles/emili.dir/vrp/vrp_builder.cpp.s

CMakeFiles/emili.dir/vrp/vrp_builder.cpp.o.requires:

.PHONY : CMakeFiles/emili.dir/vrp/vrp_builder.cpp.o.requires

CMakeFiles/emili.dir/vrp/vrp_builder.cpp.o.provides: CMakeFiles/emili.dir/vrp/vrp_builder.cpp.o.requires
	$(MAKE) -f CMakeFiles/emili.dir/build.make CMakeFiles/emili.dir/vrp/vrp_builder.cpp.o.provides.build
.PHONY : CMakeFiles/emili.dir/vrp/vrp_builder.cpp.o.provides

CMakeFiles/emili.dir/vrp/vrp_builder.cpp.o.provides.build: CMakeFiles/emili.dir/vrp/vrp_builder.cpp.o


CMakeFiles/emili.dir/vrp/vrp_instance.cpp.o: CMakeFiles/emili.dir/flags.make
CMakeFiles/emili.dir/vrp/vrp_instance.cpp.o: ../vrp/vrp_instance.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zildrok/EMILI_VRP/original/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/emili.dir/vrp/vrp_instance.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/emili.dir/vrp/vrp_instance.cpp.o -c /home/zildrok/EMILI_VRP/original/vrp/vrp_instance.cpp

CMakeFiles/emili.dir/vrp/vrp_instance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emili.dir/vrp/vrp_instance.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zildrok/EMILI_VRP/original/vrp/vrp_instance.cpp > CMakeFiles/emili.dir/vrp/vrp_instance.cpp.i

CMakeFiles/emili.dir/vrp/vrp_instance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emili.dir/vrp/vrp_instance.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zildrok/EMILI_VRP/original/vrp/vrp_instance.cpp -o CMakeFiles/emili.dir/vrp/vrp_instance.cpp.s

CMakeFiles/emili.dir/vrp/vrp_instance.cpp.o.requires:

.PHONY : CMakeFiles/emili.dir/vrp/vrp_instance.cpp.o.requires

CMakeFiles/emili.dir/vrp/vrp_instance.cpp.o.provides: CMakeFiles/emili.dir/vrp/vrp_instance.cpp.o.requires
	$(MAKE) -f CMakeFiles/emili.dir/build.make CMakeFiles/emili.dir/vrp/vrp_instance.cpp.o.provides.build
.PHONY : CMakeFiles/emili.dir/vrp/vrp_instance.cpp.o.provides

CMakeFiles/emili.dir/vrp/vrp_instance.cpp.o.provides.build: CMakeFiles/emili.dir/vrp/vrp_instance.cpp.o


# Object files for target emili
emili_OBJECTS = \
"CMakeFiles/emili.dir/emilibase.cpp.o" \
"CMakeFiles/emili.dir/generalParser.cpp.o" \
"CMakeFiles/emili.dir/main.cpp.o" \
"CMakeFiles/emili.dir/vrp/vrp.cpp.o" \
"CMakeFiles/emili.dir/vrp/vrp_builder.cpp.o" \
"CMakeFiles/emili.dir/vrp/vrp_instance.cpp.o"

# External object files for target emili
emili_EXTERNAL_OBJECTS =

emili: CMakeFiles/emili.dir/emilibase.cpp.o
emili: CMakeFiles/emili.dir/generalParser.cpp.o
emili: CMakeFiles/emili.dir/main.cpp.o
emili: CMakeFiles/emili.dir/vrp/vrp.cpp.o
emili: CMakeFiles/emili.dir/vrp/vrp_builder.cpp.o
emili: CMakeFiles/emili.dir/vrp/vrp_instance.cpp.o
emili: CMakeFiles/emili.dir/build.make
emili: CMakeFiles/emili.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zildrok/EMILI_VRP/original/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable emili"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/emili.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/emili.dir/build: emili

.PHONY : CMakeFiles/emili.dir/build

CMakeFiles/emili.dir/requires: CMakeFiles/emili.dir/emilibase.cpp.o.requires
CMakeFiles/emili.dir/requires: CMakeFiles/emili.dir/generalParser.cpp.o.requires
CMakeFiles/emili.dir/requires: CMakeFiles/emili.dir/main.cpp.o.requires
CMakeFiles/emili.dir/requires: CMakeFiles/emili.dir/vrp/vrp.cpp.o.requires
CMakeFiles/emili.dir/requires: CMakeFiles/emili.dir/vrp/vrp_builder.cpp.o.requires
CMakeFiles/emili.dir/requires: CMakeFiles/emili.dir/vrp/vrp_instance.cpp.o.requires

.PHONY : CMakeFiles/emili.dir/requires

CMakeFiles/emili.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/emili.dir/cmake_clean.cmake
.PHONY : CMakeFiles/emili.dir/clean

CMakeFiles/emili.dir/depend:
	cd /home/zildrok/EMILI_VRP/original/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zildrok/EMILI_VRP/original /home/zildrok/EMILI_VRP/original /home/zildrok/EMILI_VRP/original/build /home/zildrok/EMILI_VRP/original/build /home/zildrok/EMILI_VRP/original/build/CMakeFiles/emili.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/emili.dir/depend

