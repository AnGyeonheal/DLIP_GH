# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\heal\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\heal\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\heal\source\repos\DLIP_GH

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug

# Include any dependencies generated for this target.
include LAB\CMakeFiles\OpenCV_header.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include LAB\CMakeFiles\OpenCV_header.dir\compiler_depend.make

# Include the progress variables for this target.
include LAB\CMakeFiles\OpenCV_header.dir\progress.make

# Include the compile flags for this target's objects.
include LAB\CMakeFiles\OpenCV_header.dir\flags.make

LAB\CMakeFiles\OpenCV_header.dir\clean:
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\LAB
	$(CMAKE_COMMAND) -P CMakeFiles\OpenCV_header.dir\cmake_clean.cmake
	cd C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug
.PHONY : LAB\CMakeFiles\OpenCV_header.dir\clean

LAB\CMakeFiles\OpenCV_header.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\heal\source\repos\DLIP_GH C:\Users\heal\source\repos\DLIP_GH\LAB C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\LAB C:\Users\heal\source\repos\DLIP_GH\cmake-build-debug\LAB\CMakeFiles\OpenCV_header.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : LAB\CMakeFiles\OpenCV_header.dir\depend
