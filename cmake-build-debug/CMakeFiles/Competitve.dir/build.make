# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\admin\Desktop\CS\Competitive

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\admin\Desktop\CS\Competitive\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Competitve.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Competitve.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Competitve.dir/flags.make

CMakeFiles/Competitve.dir/analyse.cpp.obj: CMakeFiles/Competitve.dir/flags.make
CMakeFiles/Competitve.dir/analyse.cpp.obj: ../analyse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\admin\Desktop\CS\Competitive\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Competitve.dir/analyse.cpp.obj"
	C:\PROGRA~2\MinGW\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Competitve.dir\analyse.cpp.obj -c C:\Users\admin\Desktop\CS\Competitive\analyse.cpp

CMakeFiles/Competitve.dir/analyse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Competitve.dir/analyse.cpp.i"
	C:\PROGRA~2\MinGW\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\admin\Desktop\CS\Competitive\analyse.cpp > CMakeFiles\Competitve.dir\analyse.cpp.i

CMakeFiles/Competitve.dir/analyse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Competitve.dir/analyse.cpp.s"
	C:\PROGRA~2\MinGW\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\admin\Desktop\CS\Competitive\analyse.cpp -o CMakeFiles\Competitve.dir\analyse.cpp.s

# Object files for target Competitve
Competitve_OBJECTS = \
"CMakeFiles/Competitve.dir/analyse.cpp.obj"

# External object files for target Competitve
Competitve_EXTERNAL_OBJECTS =

Competitve.exe: CMakeFiles/Competitve.dir/analyse.cpp.obj
Competitve.exe: CMakeFiles/Competitve.dir/build.make
Competitve.exe: CMakeFiles/Competitve.dir/linklibs.rsp
Competitve.exe: CMakeFiles/Competitve.dir/objects1.rsp
Competitve.exe: CMakeFiles/Competitve.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\admin\Desktop\CS\Competitive\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Competitve.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Competitve.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Competitve.dir/build: Competitve.exe

.PHONY : CMakeFiles/Competitve.dir/build

CMakeFiles/Competitve.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Competitve.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Competitve.dir/clean

CMakeFiles/Competitve.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\admin\Desktop\CS\Competitive C:\Users\admin\Desktop\CS\Competitive C:\Users\admin\Desktop\CS\Competitive\cmake-build-debug C:\Users\admin\Desktop\CS\Competitive\cmake-build-debug C:\Users\admin\Desktop\CS\Competitive\cmake-build-debug\CMakeFiles\Competitve.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Competitve.dir/depend

