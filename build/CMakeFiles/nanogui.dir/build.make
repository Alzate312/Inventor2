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

# Include any dependencies generated for this target.
include CMakeFiles/nanogui.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/nanogui.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nanogui.dir/flags.make

# Object files for target nanogui
nanogui_OBJECTS =

# External object files for target nanogui
nanogui_EXTERNAL_OBJECTS = \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/ext/nanovg/src/nanovg.c.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/darwin.mm.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/nanogui_resources.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/glutil.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/common.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/widget.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/theme.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/layout.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/screen.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/label.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/window.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/popup.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/checkbox.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/button.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/popupbutton.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/combobox.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/progressbar.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/slider.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/messagedialog.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/textbox.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/imagepanel.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/imageview.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/vscrollpanel.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/colorwheel.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/colorpicker.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/graph.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/stackedwidget.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/tabheader.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/tabwidget.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/glcanvas.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui-obj.dir/src/serializer.cpp.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/ext_build/glfw/src/CMakeFiles/glfw_objects.dir/context.c.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/ext_build/glfw/src/CMakeFiles/glfw_objects.dir/init.c.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/ext_build/glfw/src/CMakeFiles/glfw_objects.dir/input.c.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/ext_build/glfw/src/CMakeFiles/glfw_objects.dir/monitor.c.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/ext_build/glfw/src/CMakeFiles/glfw_objects.dir/vulkan.c.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/ext_build/glfw/src/CMakeFiles/glfw_objects.dir/window.c.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/ext_build/glfw/src/CMakeFiles/glfw_objects.dir/cocoa_init.m.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/ext_build/glfw/src/CMakeFiles/glfw_objects.dir/cocoa_joystick.m.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/ext_build/glfw/src/CMakeFiles/glfw_objects.dir/cocoa_monitor.m.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/ext_build/glfw/src/CMakeFiles/glfw_objects.dir/cocoa_window.m.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/ext_build/glfw/src/CMakeFiles/glfw_objects.dir/cocoa_time.c.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/ext_build/glfw/src/CMakeFiles/glfw_objects.dir/posix_tls.c.o" \
"/Users/sebastianalzate/Documents/GitHub/Inventor2/build/ext_build/glfw/src/CMakeFiles/glfw_objects.dir/nsgl_context.m.o"

libnanogui.dylib: CMakeFiles/nanogui-obj.dir/ext/nanovg/src/nanovg.c.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/darwin.mm.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/nanogui_resources.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/glutil.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/common.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/widget.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/theme.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/layout.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/screen.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/label.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/window.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/popup.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/checkbox.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/button.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/popupbutton.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/combobox.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/progressbar.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/slider.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/messagedialog.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/textbox.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/imagepanel.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/imageview.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/vscrollpanel.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/colorwheel.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/colorpicker.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/graph.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/stackedwidget.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/tabheader.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/tabwidget.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/glcanvas.cpp.o
libnanogui.dylib: CMakeFiles/nanogui-obj.dir/src/serializer.cpp.o
libnanogui.dylib: ext_build/glfw/src/CMakeFiles/glfw_objects.dir/context.c.o
libnanogui.dylib: ext_build/glfw/src/CMakeFiles/glfw_objects.dir/init.c.o
libnanogui.dylib: ext_build/glfw/src/CMakeFiles/glfw_objects.dir/input.c.o
libnanogui.dylib: ext_build/glfw/src/CMakeFiles/glfw_objects.dir/monitor.c.o
libnanogui.dylib: ext_build/glfw/src/CMakeFiles/glfw_objects.dir/vulkan.c.o
libnanogui.dylib: ext_build/glfw/src/CMakeFiles/glfw_objects.dir/window.c.o
libnanogui.dylib: ext_build/glfw/src/CMakeFiles/glfw_objects.dir/cocoa_init.m.o
libnanogui.dylib: ext_build/glfw/src/CMakeFiles/glfw_objects.dir/cocoa_joystick.m.o
libnanogui.dylib: ext_build/glfw/src/CMakeFiles/glfw_objects.dir/cocoa_monitor.m.o
libnanogui.dylib: ext_build/glfw/src/CMakeFiles/glfw_objects.dir/cocoa_window.m.o
libnanogui.dylib: ext_build/glfw/src/CMakeFiles/glfw_objects.dir/cocoa_time.c.o
libnanogui.dylib: ext_build/glfw/src/CMakeFiles/glfw_objects.dir/posix_tls.c.o
libnanogui.dylib: ext_build/glfw/src/CMakeFiles/glfw_objects.dir/nsgl_context.m.o
libnanogui.dylib: CMakeFiles/nanogui.dir/build.make
libnanogui.dylib: CMakeFiles/nanogui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX shared library libnanogui.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nanogui.dir/link.txt --verbose=$(VERBOSE)
	strip -u -r /Users/sebastianalzate/Documents/GitHub/Inventor2/build/libnanogui.dylib

# Rule to build all files generated by this target.
CMakeFiles/nanogui.dir/build: libnanogui.dylib

.PHONY : CMakeFiles/nanogui.dir/build

CMakeFiles/nanogui.dir/requires:

.PHONY : CMakeFiles/nanogui.dir/requires

CMakeFiles/nanogui.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nanogui.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nanogui.dir/clean

CMakeFiles/nanogui.dir/depend:
	cd /Users/sebastianalzate/Documents/GitHub/Inventor2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sebastianalzate/Documents/GitHub/Inventor2 /Users/sebastianalzate/Documents/GitHub/Inventor2 /Users/sebastianalzate/Documents/GitHub/Inventor2/build /Users/sebastianalzate/Documents/GitHub/Inventor2/build /Users/sebastianalzate/Documents/GitHub/Inventor2/build/CMakeFiles/nanogui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nanogui.dir/depend

