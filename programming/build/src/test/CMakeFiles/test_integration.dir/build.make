# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/javierih/raider/Raider/programming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/javierih/raider/Raider/programming/build

# Include any dependencies generated for this target.
include src/test/CMakeFiles/test_integration.dir/depend.make

# Include the progress variables for this target.
include src/test/CMakeFiles/test_integration.dir/progress.make

# Include the compile flags for this target's objects.
include src/test/CMakeFiles/test_integration.dir/flags.make

src/test/CMakeFiles/test_integration.dir/test_integration.cpp.o: src/test/CMakeFiles/test_integration.dir/flags.make
src/test/CMakeFiles/test_integration.dir/test_integration.cpp.o: ../src/test/test_integration.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/javierih/raider/Raider/programming/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/test/CMakeFiles/test_integration.dir/test_integration.cpp.o"
	cd /home/javierih/raider/Raider/programming/build/src/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_integration.dir/test_integration.cpp.o -c /home/javierih/raider/Raider/programming/src/test/test_integration.cpp

src/test/CMakeFiles/test_integration.dir/test_integration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_integration.dir/test_integration.cpp.i"
	cd /home/javierih/raider/Raider/programming/build/src/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/javierih/raider/Raider/programming/src/test/test_integration.cpp > CMakeFiles/test_integration.dir/test_integration.cpp.i

src/test/CMakeFiles/test_integration.dir/test_integration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_integration.dir/test_integration.cpp.s"
	cd /home/javierih/raider/Raider/programming/build/src/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/javierih/raider/Raider/programming/src/test/test_integration.cpp -o CMakeFiles/test_integration.dir/test_integration.cpp.s

src/test/CMakeFiles/test_integration.dir/test_integration.cpp.o.requires:
.PHONY : src/test/CMakeFiles/test_integration.dir/test_integration.cpp.o.requires

src/test/CMakeFiles/test_integration.dir/test_integration.cpp.o.provides: src/test/CMakeFiles/test_integration.dir/test_integration.cpp.o.requires
	$(MAKE) -f src/test/CMakeFiles/test_integration.dir/build.make src/test/CMakeFiles/test_integration.dir/test_integration.cpp.o.provides.build
.PHONY : src/test/CMakeFiles/test_integration.dir/test_integration.cpp.o.provides

src/test/CMakeFiles/test_integration.dir/test_integration.cpp.o.provides.build: src/test/CMakeFiles/test_integration.dir/test_integration.cpp.o

# Object files for target test_integration
test_integration_OBJECTS = \
"CMakeFiles/test_integration.dir/test_integration.cpp.o"

# External object files for target test_integration
test_integration_EXTERNAL_OBJECTS =

bin/test_integration: src/test/CMakeFiles/test_integration.dir/test_integration.cpp.o
bin/test_integration: src/test/CMakeFiles/test_integration.dir/build.make
bin/test_integration: lib/libserialib.so
bin/test_integration: lib/libraider.so
bin/test_integration: lib/libbones.so
bin/test_integration: lib/libeye.so
bin/test_integration: /usr/local/lib/libopencv_videostab.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_video.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_ts.a
bin/test_integration: /usr/local/lib/libopencv_superres.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_stitching.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_photo.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_ocl.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_objdetect.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_nonfree.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_ml.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_legacy.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_imgproc.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_highgui.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_gpu.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_flann.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_features2d.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_core.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_contrib.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_calib3d.so.2.4.8
bin/test_integration: lib/libserialib.so
bin/test_integration: /usr/local/lib/libopencv_nonfree.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_ocl.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_gpu.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_photo.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_objdetect.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_legacy.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_video.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_ml.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_calib3d.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_features2d.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_highgui.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_imgproc.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_flann.so.2.4.8
bin/test_integration: /usr/local/lib/libopencv_core.so.2.4.8
bin/test_integration: src/test/CMakeFiles/test_integration.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/test_integration"
	cd /home/javierih/raider/Raider/programming/build/src/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_integration.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/test/CMakeFiles/test_integration.dir/build: bin/test_integration
.PHONY : src/test/CMakeFiles/test_integration.dir/build

src/test/CMakeFiles/test_integration.dir/requires: src/test/CMakeFiles/test_integration.dir/test_integration.cpp.o.requires
.PHONY : src/test/CMakeFiles/test_integration.dir/requires

src/test/CMakeFiles/test_integration.dir/clean:
	cd /home/javierih/raider/Raider/programming/build/src/test && $(CMAKE_COMMAND) -P CMakeFiles/test_integration.dir/cmake_clean.cmake
.PHONY : src/test/CMakeFiles/test_integration.dir/clean

src/test/CMakeFiles/test_integration.dir/depend:
	cd /home/javierih/raider/Raider/programming/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/javierih/raider/Raider/programming /home/javierih/raider/Raider/programming/src/test /home/javierih/raider/Raider/programming/build /home/javierih/raider/Raider/programming/build/src/test /home/javierih/raider/Raider/programming/build/src/test/CMakeFiles/test_integration.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/test/CMakeFiles/test_integration.dir/depend

