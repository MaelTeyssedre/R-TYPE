project(RTYPE)
cmake_minimum_required(VERSION 3.10)

if (UNIX)
    add_definitions("-W -Wall -Wextra -Werror -fPIC -Wnon-virtual-dtor -Wuninitialized -Wunreachable-code")
endif (UNIX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CONAN_DISABLE_CHECK_COMPILER TRUE CACHE INTERNAL "")

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(KEEP_RPATHS)
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

file(
    GLOB_RECURSE
    SOURCES_SERVER
    ${PROJECT_SOURCE_DIR}/Sources/Server/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/*.cpp
    ${PROJECT_SOURCE_DIR}/Sources/Commons/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Commons/*.cpp
)

file(
    GLOB_RECURSE
    SOURCES_CLIENT
    ${PROJECT_SOURCE_DIR}/Sources/Client/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Client/*.cpp
)

add_executable(rtype_client ${SOURCES_CLIENT})
add_executable(rtype_server ${SOURCES_SERVER})


target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/PlayerData/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/Room/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/RoomManager/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/Buffer/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/Entity/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/Registry/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/SparseArray/
)

target_link_libraries(rtype_client ${CONAN_LIBS})
target_link_libraries(rtype_server ${CONAN_LIBS})