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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sebastianalzate/Documents/GitHub/Inventor2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sebastianalzate/Documents/GitHub/Inventor2/build

# Utility rule file for mkdoc.

# Include the progress variables for this target.
include CMakeFiles/mkdoc.dir/progress.make

CMakeFiles/mkdoc:
	python3 /Users/sebastianalzate/Documents/GitHub/Inventor2/docs/mkdoc_rst.py -fvisibility=hidden -Wall -Wextra -std=c++14 -flto=thin -stdlib=libc++ -I/Users/sebastianalzate/Documents/GitHub/Inventor2/ext/eigen -I/Users/sebastianalzate/Documents/GitHub/Inventor2/ext/glfw/include -I/Users/sebastianalzate/Documents/GitHub/Inventor2/ext/nanovg/src -I/Users/sebastianalzate/Documents/GitHub/Inventor2/include -I/Users/sebastianalzate/Documents/GitHub/Inventor2/build -I/Users/sebastianalzate/Documents/GitHub/Inventor2/build -I/Users/sebastianalzate/Documents/GitHub/Inventor2/ext/coro -I/Users/sebastianalzate/Documents/GitHub/Inventor2/ext/pybind11/include -I/System/Library/Frameworks/Python.framework/Versions/2.7/include/python2.7 -DCORO_SJLJ -DNANOGUI_PYTHON -DNANOGUI_SHARED -DNVG_SHARED -DGLAD_GLAPI_EXPORT -DDOXYGEN_DOCUMENTATION_BUILD /Users/sebastianalzate/Documents/GitHub/Inventor2/include/nanogui/*.h > /Users/sebastianalzate/Documents/GitHub/Inventor2/python/py_doc.h

mkdoc: CMakeFiles/mkdoc
mkdoc: CMakeFiles/mkdoc.dir/build.make

.PHONY : mkdoc

# Rule to build all files generated by this target.
CMakeFiles/mkdoc.dir/build: mkdoc

.PHONY : CMakeFiles/mkdoc.dir/build

CMakeFiles/mkdoc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mkdoc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mkdoc.dir/clean

CMakeFiles/mkdoc.dir/depend:
	cd /Users/sebastianalzate/Documents/GitHub/Inventor2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sebastianalzate/Documents/GitHub/Inventor2 /Users/sebastianalzate/Documents/GitHub/Inventor2 /Users/sebastianalzate/Documents/GitHub/Inventor2/build /Users/sebastianalzate/Documents/GitHub/Inventor2/build /Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/mkdoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mkdoc.dir/depend
