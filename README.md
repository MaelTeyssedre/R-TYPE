![Windows build](https://github.com/MaelTeyssedre/R-TYPE/actions/workflows/R-TYPE_Windows.yml/badge.svg)
![Ubuntu build](https://github.com/MaelTeyssedre/R-TYPE/actions/workflows/R-TYPE_Ubuntu.yml/badge.svg)
[![Doxygen Generation](https://github.com/MaelTeyssedre/R-TYPE/actions/workflows/Doxygen.yml/badge.svg)](https://maelteyssedre.github.io/R-TYPE)

## R-TYPE

The goal of the R-Type project is to create an online multiplayer
   copy of the classic R-Type game (1987).
   
   -   Sources separated in three part, Server, Client and Common.
   -   Use of modern [CMake](https://cmake.org/) for much easier compiling
   -   Continuous testing with [GitHub Actions](https://github.com/features/actions).
   -   Code documentation with [Doxygen](https://maelteyssedre.github.io/R-TYPE)

# Structure

``` text
├───.github
│   └───workflows
├───.vscode
├───build
│   └───bin
├───CMakeFiles
│   ├───3.21.3
│   │   ├───CompilerIdC
│   │   │   ├───Debug
│   │   │   │   └───CompilerIdC.tlog
│   │   │   └───tmp
│   │   ├───CompilerIdCXX
│   │   │   ├───Debug
│   │   │   │   └───CompilerIdCXX.tlog
│   │   │   └───tmp
│   │   └───x64
│   │       └───Debug
│   │           └───VCTargetsPath.tlog
│   └───CMakeTmp
├───Doc
├───doxygen
├───ressources
├───Script
└───Sources
    ├───Client
    │   ├───Components
    │   ├───GraphicalLib
    │   ├───Network
    │   │   ├───NetworkManager
    │   │   ├───Packet
    │   │   ├───TCP
    │   │   └───UDP
    │   └───Systems
    ├───Commons
    │   ├───Buffer
    │   ├───ECS
    │   │   ├───Entity
    │   │   ├───Registry
    │   │   └───SparseArray
    │   ├───INetwork
    │   └───Logger
    ├───Doc
    ├───DynamicLibraries
    ├───LibLoader
    │   ├───Unix
    │   └───Windows
    └───Server
        ├───Component
        ├───Element
        ├───JsonWrapper
        ├───Libs
        ├───Network
        │   ├───NetworkManager
        │   ├───Packet
        │   ├───TCP
        │   ├───UDP
        │   └───User
        ├───PacketManager
        ├───PlayerData
        ├───Room
        └───RoomManager
```
