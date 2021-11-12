project(RTYPE)
cmake_minimum_required(VERSION 3.10)
if (UNIX)
    add_definitions("-W -Wall -Wextra -fPIC")
endif (UNIX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CONAN_DISABLE_CHECK_COMPILER TRUE CACHE INTERNAL "")
#set(LIB_TYPE SHARED)
if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(KEEP_RPATHS)
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()
if (UNIX)
    file(GLOB_RECURSE SOURCES_SERVER ${PROJECT_SOURCE_DIR}/Server/*.hpp ${PROJECT_SOURCE_DIR}/Server/*.cpp ${PROJECT_SOURCE_DIR}/LibLoader/Unix/*.cpp ${PROJECT_SOURCE_DIR}/LibLoader/Unix/*.hpp)
endif (UNIX)
if (WIN32)
    file(GLOB_RECURSE SOURCES_SERVER ${PROJECT_SOURCE_DIR}/Server/*.hpp ${PROJECT_SOURCE_DIR}/Server/*.cpp ${PROJECT_SOURCE_DIR}/LibLoader/Windows/*.cpp ${PROJECT_SOURCE_DIR}/LibLoader/Windows/*.hpp)
endif (WIN32)
file(GLOB_RECURSE SOURCES_CLIENT ${PROJECT_SOURCE_DIR}/Client/*.hpp ${PROJECT_SOURCE_DIR}/Client/*.cpp)
add_executable(rtype_client ${SOURCES_CLIENT})
add_executable(rtype_server ${SOURCES_SERVER})
if (UNIX)
    target_include_directories(rtype_server PUBLIC ${PROJECT_SOURCE_DIR}/LibLoader/Unix)
endif (UNIX)
if (WIN32)
    target_include_directories(rtype_server PUBLIC ${PROJECT_SOURCE_DIR}/LibLoader/Windows)
endif (WIN32)
target_include_directories(rtype_server PUBLIC ${PROJECT_SOURCE_DIR}/DynamicLibraries)
target_include_directories(rtype_server PUBLIC ${PROJECT_SOURCE_DIR}/Server/Libs/)
target_link_libraries(rtype_client ${CONAN_LIBS})
target_link_libraries(rtype_server ${CONAN_LIBS})

#add_library(BasicMonster ${LIB_TYPE} ${PROJECT_SOURCE_DIR}/DynamicLibraries/BasicMonster.cpp ${PROJECT_SOURCE_DIR}/DynamicLibraries/BasicMonster.hpp ${PROJECT_SOURCE_DIR}/Server/Element/IElement.hpp)
add_library(BasicMonster SHARED ${PROJECT_SOURCE_DIR}/DynamicLibraries/BasicMonster.hpp ${PROJECT_SOURCE_DIR}/DynamicLibraries/BasicMonster.cpp)



# Allow the developer to select if Dynamic or Static libraries are built
#OPTION (BUILD_SHARED_LIBS "Build Shared Libraries" OFF)
# Set the LIB_TYPE variable to STATIC
#set(LIB_TYPE SHARED)
#IF (BUILD_SHARED_LIBS)
  # User wants to build Dynamic Libraries,
  # so change the LIB_TYPE variable to CMake keyword 'SHARED'
#  SET (LIB_TYPE SHARED)
#ENDIF (BUILD_SHARED_LIBS)

# Create a target for the library
#ADD_LIBRARY(BasicMonster ${LIB_TYPE} MyLibrary.cpp)

#add_library(BasicMonster ${LIB_TYPE} ${PROJECT_SOURCE_DIR}/DynamicLibraries/BasicMonster.cpp)