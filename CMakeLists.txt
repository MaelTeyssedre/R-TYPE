project(RTYPE)
cmake_minimum_required(VERSION 3.10)

if (UNIX)
    add_definitions("-W -Wall -Wextra -fPIC  -Wnon-virtual-dtor -Wuninitialized -Wunreachable-code -std=c++17")
endif (UNIX)

if (MSVC)
    add_definitions("/MP")
endif (MSVC)

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
    ${PROJECT_SOURCE_DIR}/Sources/Commons/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Commons/*.cpp
)

file(
    GLOB 
    SOURCES_BASIC_MONSTER
    ${PROJECT_SOURCE_DIR}/Sources/Server/Libs/IElement.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/Component/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/Component/*.cpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/JsonWrapper/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/JsonWrapper/*.cpp
)

file(
    GLOB_RECURSE 
    SOURCES_BASIC_MONSTER
    ${PROJECT_SOURCE_DIR}/Sources/Server/Libs/AMonster.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Server/Libs/AMonster.cpp
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/Entity/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/Entity/*.cpp
    ${PROJECT_SOURCE_DIR}/Sources/DynamicLibraries/*.cpp
    ${PROJECT_SOURCE_DIR}/Sources/DynamicLibraries/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/Registry/*.hpp
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/Registry/*.cpp
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/SparseArray/*.hpp
)

add_executable(rtype_client ${SOURCES_CLIENT})

if (UNIX)
    add_executable(rtype_server ${SOURCES_SERVER} ${PROJECT_SOURCE_DIR}/Sources/LibLoader/Unix/DlLoaderUnix.hpp ${PROJECT_SOURCE_DIR}/Sources/LibLoader/Unix/DlLoaderUnix.cpp)
endif (UNIX)
if (WIN32)
    add_executable(rtype_server ${SOURCES_SERVER} ${PROJECT_SOURCE_DIR}/Sources/LibLoader/Windows/DlLoaderWindows.hpp ${PROJECT_SOURCE_DIR}/Sources/LibLoader/Windows/DlLoaderWindows.cpp)
endif (WIN32)

add_library(basic_monster SHARED ${SOURCES_BASIC_MONSTER})

target_include_directories(
    basic_monster
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/JsonWrapper/
)

target_include_directories(
    basic_monster
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Client/
)

target_include_directories(
    basic_monster
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/Element/
)

target_include_directories(
    basic_monster
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/DynamicLibrairies/
)

target_include_directories(
    basic_monster
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/Libs/
)

target_include_directories(
    basic_monster
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/Component
)

target_include_directories(
    basic_monster
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/systems
)

target_include_directories(
    basic_monster
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/Entity
)

target_include_directories(
    basic_monster
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/Registry
)

target_include_directories(
    basic_monster
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
    ${PROJECT_SOURCE_DIR}/Sources/Server/Game/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/Component/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/Room/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/Iterator/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/Iterator/
)

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/Systems/UpdateTime/
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

target_include_directories(
    rtype_server
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Server/PacketManager/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/Entity/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/Registry/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Client/GraphicalLib/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Client/Components/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Client/Systems/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Client/Systems/UpdateGraph/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Client/Systems/UpdateTime/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Client/Systems/UpdateNetwork/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Client/Systems/UpdateClickable/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/ECS/SparseArray/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Client/Systems/UpdatePosition/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Client/Systems/UpdateDirection/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Client/Systems/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Client/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/INetwork/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Client/Network/TCP/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Client/Network/UDP/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Client/Network/Packet/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Client/Network/TCP/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Client/Network/NetworkManager/
)


target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/Logger/
)

target_include_directories(
    rtype_client
    PUBLIC
    ${PROJECT_SOURCE_DIR}/Sources/Commons/Buffer/
)

target_link_libraries(rtype_client ${CONAN_LIBS})
target_link_libraries(rtype_server ${CONAN_LIBS})
