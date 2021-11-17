project(RTYPE)
cmake_minimum_required(VERSION 3.10)

if (UNIX)
    add_definitions("-W -Wall -Wextra -fPIC -Wnon-virtual-dtor -Wuninitialized -Wunreachable-code")
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
    ${PROJECT_SOURCE_DIR}/Sources/Server/Network/NetworkManager/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/Network/NetworkManager/*.cpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/Network/Packet/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/Network/Packet/*.cpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/Network/PacketManager/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/Network/PacketManager/*.cpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/Network/TCP/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/Network/TCP/*.cpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/Network/UDP/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/Network/UDP/*.cpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/Network/User/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/Network/User/*.cpp
    ${PROJECT_SOURCE_DIR}/Sources/Commons/INetwork/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/JsonWrapper/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/JsonWrapper/*.cpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/Element/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/Element/*.cpp
)

file(
    GLOB_RECURSE
    SOURCES_CLIENT
    ${PROJECT_SOURCE_DIR}/Sources/Client/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Client/*.cpp
)


file(
    GLOB 
    SOURCES_BALKANY_MONSTER
    ${PROJECT_SOURCE_DIR}/Sources/Server/Libs/IElement.hpp
    ${PROJECT_SOURCE_DIR}/Sources/DynamicLibraries/BalkanyMonster.cpp
    ${PROJECT_SOURCE_DIR}/Sources/DynamicLibraries/BalkanyMonster.hpp
)

file(
    GLOB_RECURSE 
    SOURCES_BALKANY_MONSTER
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/Entity/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/Entity/*.cpp
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/Registry/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/Registry/*.cpp
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/SparseArray/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/components/components.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/systems/systems.hpp
)

add_executable(rtype_client ${SOURCES_CLIENT})

if (UNIX)
    add_executable(rtype_server ${SOURCES_SERVER} ${PROJECT_SOURCE_DIR}/Sources/LibLoader/Unix/DlLoaderUnix.hpp ${PROJECT_SOURCE_DIR}/Sources/LibLoader/Unix/DlLoaderUnix.cpp)
endif (UNIX)
if (WIN32)
    add_executable(rtype_server ${SOURCES_SERVER} ${PROJECT_SOURCE_DIR}/Sources/LibLoader/Windows/DlLoaderWindows.hpp ${PROJECT_SOURCE_DIR}/Sources/LibLoader/Windows/DlLoaderWindows.cpp)
endif (WIN32)

add_library(BalkanyMonster SHARED ${SOURCES_BALKANY_MONSTER})


target_include_directories(
    BalkanyMonster
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/Libs/
)

target_include_directories(
    BalkanyMonster
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/components
)

target_include_directories(
    BalkanyMonster
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/systems
)

target_include_directories(
    BalkanyMonster
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/Entity
)

target_include_directories(
    BalkanyMonster
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/Registry
)

target_include_directories(
    BalkanyMonster
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/SparseArray
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/Libs/
)

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
    ${PROJECT_SOURCE_DIR}/Sources/Server/Element/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/Buffer/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/components
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/systems
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

if (UNIX)
    target_include_directories(
        rtype_server
        PUBLIC 
        ${PROJECT_SOURCE_DIR}/Sources/LibLoader/Unix
    )
endif (UNIX)
if (WIN32)
    target_include_directories(
        rtype_server 
        PUBLIC 
        ${PROJECT_SOURCE_DIR}/Sources/LibLoader/Windows
    )
endif (WIN32)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/Network/NetworkManager/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/Network/Packet/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/Network/TCP/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/Network/UDP/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/Network/User/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/INetwork/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/JsonWrapper/
)


target_link_libraries(rtype_client ${CONAN_LIBS})
target_link_libraries(rtype_server ${CONAN_LIBS})
