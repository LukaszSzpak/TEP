# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\RC\Documents\GitHub\TEP\Lista2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\RC\Documents\GitHub\TEP\Lista2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lista2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lista2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lista2.dir/flags.make

CMakeFiles/Lista2.dir/main.cpp.obj: CMakeFiles/Lista2.dir/flags.make
CMakeFiles/Lista2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\RC\Documents\GitHub\TEP\Lista2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lista2.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lista2.dir\main.cpp.obj -c C:\Users\RC\Documents\GitHub\TEP\Lista2\main.cpp

CMakeFiles/Lista2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lista2.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\RC\Documents\GitHub\TEP\Lista2\main.cpp > CMakeFiles\Lista2.dir\main.cpp.i

CMakeFiles/Lista2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lista2.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\RC\Documents\GitHub\TEP\Lista2\main.cpp -o CMakeFiles\Lista2.dir\main.cpp.s

CMakeFiles/Lista2.dir/CTable.cpp.obj: CMakeFiles/Lista2.dir/flags.make
CMakeFiles/Lista2.dir/CTable.cpp.obj: ../CTable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\RC\Documents\GitHub\TEP\Lista2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lista2.dir/CTable.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lista2.dir\CTable.cpp.obj -c C:\Users\RC\Documents\GitHub\TEP\Lista2\CTable.cpp

CMakeFiles/Lista2.dir/CTable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lista2.dir/CTable.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\RC\Documents\GitHub\TEP\Lista2\CTable.cpp > CMakeFiles\Lista2.dir\CTable.cpp.i

CMakeFiles/Lista2.dir/CTable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lista2.dir/CTable.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\RC\Documents\GitHub\TEP\Lista2\CTable.cpp -o CMakeFiles\Lista2.dir\CTable.cpp.s

# Object files for target Lista2
Lista2_OBJECTS = \
"CMakeFiles/Lista2.dir/main.cpp.obj" \
"CMakeFiles/Lista2.dir/CTable.cpp.obj"

# External object files for target Lista2
Lista2_EXTERNAL_OBJECTS =

Lista2.exe: CMakeFiles/Lista2.dir/main.cpp.obj
Lista2.exe: CMakeFiles/Lista2.dir/CTable.cpp.obj
Lista2.exe: CMakeFiles/Lista2.dir/build.make
Lista2.exe: CMakeFiles/Lista2.dir/linklibs.rsp
Lista2.exe: CMakeFiles/Lista2.dir/objects1.rsp
Lista2.exe: CMakeFiles/Lista2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\RC\Documents\GitHub\TEP\Lista2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Lista2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lista2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lista2.dir/build: Lista2.exe

.PHONY : CMakeFiles/Lista2.dir/build

CMakeFiles/Lista2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lista2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lista2.dir/clean

CMakeFiles/Lista2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\RC\Documents\GitHub\TEP\Lista2 C:\Users\RC\Documents\GitHub\TEP\Lista2 C:\Users\RC\Documents\GitHub\TEP\Lista2\cmake-build-debug C:\Users\RC\Documents\GitHub\TEP\Lista2\cmake-build-debug C:\Users\RC\Documents\GitHub\TEP\Lista2\cmake-build-debug\CMakeFiles\Lista2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lista2.dir/depend

