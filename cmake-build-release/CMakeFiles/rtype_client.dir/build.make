# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ratha\rtype\R-TYPE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ratha\rtype\R-TYPE\cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles\rtype_client.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\rtype_client.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\rtype_client.dir\flags.make

CMakeFiles\rtype_client.dir\Client\main.cpp.obj: CMakeFiles\rtype_client.dir\flags.make
CMakeFiles\rtype_client.dir\Client\main.cpp.obj: ..\Client\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ratha\rtype\R-TYPE\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rtype_client.dir/Client/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\rtype_client.dir\Client\main.cpp.obj /FdCMakeFiles\rtype_client.dir\ /FS -c C:\Users\ratha\rtype\R-TYPE\Client\main.cpp
<<

CMakeFiles\rtype_client.dir\Client\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rtype_client.dir/Client/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\rtype_client.dir\Client\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ratha\rtype\R-TYPE\Client\main.cpp
<<

CMakeFiles\rtype_client.dir\Client\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rtype_client.dir/Client/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\rtype_client.dir\Client\main.cpp.s /c C:\Users\ratha\rtype\R-TYPE\Client\main.cpp
<<

# Object files for target rtype_client
rtype_client_OBJECTS = \
"CMakeFiles\rtype_client.dir\Client\main.cpp.obj"

# External object files for target rtype_client
rtype_client_EXTERNAL_OBJECTS =

bin\rtype_client.exe: CMakeFiles\rtype_client.dir\Client\main.cpp.obj
bin\rtype_client.exe: CMakeFiles\rtype_client.dir\build.make
bin\rtype_client.exe: CMakeFiles\rtype_client.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ratha\rtype\R-TYPE\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin\rtype_client.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\rtype_client.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\rtype_client.dir\objects1.rsp @<<
 /out:bin\rtype_client.exe /implib:lib\rtype_client.lib /pdb:C:\Users\ratha\rtype\R-TYPE\cmake-build-release\bin\rtype_client.pdb /version:0.0 /machine:X86   /INCREMENTAL:NO  /subsystem:console   -LIBPATH:C:\Users\ratha\.conan\data\sfml\2.5.1\bincrafters\stable\package\0ef0596dda67009438ddf62cf64d905a8c92d376\lib  -LIBPATH:C:\Users\ratha\.conan\data\freetype\2.10.4\_\_\package\27b2733304cef577b19f699fec3a5bdbefb36d16\lib  -LIBPATH:C:\Users\ratha\.conan\data\openal\1.21.0\_\_\package\3fb49604f9c2f729b85ba3115852006824e72cab\lib  -LIBPATH:C:\Users\ratha\.conan\data\flac\1.3.3\_\_\package\becff00909fb3d957c6b4ca60fa64d4e6a32a540\lib  -LIBPATH:C:\Users\ratha\.conan\data\vorbis\1.3.7\_\_\package\becff00909fb3d957c6b4ca60fa64d4e6a32a540\lib  -LIBPATH:C:\Users\ratha\.conan\data\libpng\1.6.37\_\_\package\ce650d9f1f1c1c0839cf0694a55c1351ddbed859\lib  -LIBPATH:C:\Users\ratha\.conan\data\bzip2\1.0.8\_\_\package\d16a91eadaaf5829b928b12d2f836ff7680d3df5\lib  -LIBPATH:C:\Users\ratha\.conan\data\brotli\1.0.9\_\_\package\3fb49604f9c2f729b85ba3115852006824e72cab\lib  -LIBPATH:C:\Users\ratha\.conan\data\ogg\1.3.4\_\_\package\3fb49604f9c2f729b85ba3115852006824e72cab\lib  -LIBPATH:C:\Users\ratha\.conan\data\zlib\1.2.11\_\_\package\3fb49604f9c2f729b85ba3115852006824e72cab\lib  sfml-main.lib sfml-graphics-s.lib sfml-window-s.lib sfml-network-s.lib sfml-audio-s.lib sfml-system-s.lib freetype.lib OpenAL32.lib FLAC++.lib FLAC.lib vorbisenc.lib vorbisfile.lib vorbis.lib libpng16.lib bz2.lib brotlidec-static.lib brotlienc-static.lib brotlicommon-static.lib ogg.lib zlib.lib gdi32.lib ws2_32.lib winmm.lib ole32.lib shell32.lib User32.lib opengl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\rtype_client.dir\build: bin\rtype_client.exe
.PHONY : CMakeFiles\rtype_client.dir\build

CMakeFiles\rtype_client.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\rtype_client.dir\cmake_clean.cmake
.PHONY : CMakeFiles\rtype_client.dir\clean

CMakeFiles\rtype_client.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\ratha\rtype\R-TYPE C:\Users\ratha\rtype\R-TYPE C:\Users\ratha\rtype\R-TYPE\cmake-build-release C:\Users\ratha\rtype\R-TYPE\cmake-build-release C:\Users\ratha\rtype\R-TYPE\cmake-build-release\CMakeFiles\rtype_client.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\rtype_client.dir\depend

