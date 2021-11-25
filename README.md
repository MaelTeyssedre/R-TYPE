![Windows build](https://github.com/MaelTeyssedre/R-TYPE/actions/workflows/R-TYPE_Windows.yml/badge.svg)
![Ubuntu build](https://github.com/MaelTeyssedre/R-TYPE/actions/workflows/R-TYPE_Ubuntu.yml/badge.svg)
[![Doxygen Generation](https://github.com/MaelTeyssedre/R-TYPE/actions/workflows/Doxygen.yml/badge.svg)](https://maelteyssedre.github.io/R-TYPE)

# R-TYPE

The goal of the R-Type project is to create an online multiplayer
   copy of the classic R-Type game (1987).
   
   -   Sources separated in three part, Server, Client and Common.
   -   Is working under Windows and Linux distribution
   -   Use of modern [CMake](https://cmake.org/) for much easier compiling
   -   Use of Script for much easier utilisation.
   -   Use of [Conan](https://conan.io/) for external libraries
   -   Continuous testing with [GitHub Actions](https://github.com/features/actions).
   -   Code documentation with [Doxygen](https://maelteyssedre.github.io/R-TYPE)

## Structure

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

## Building

Build by executing the script correspondint to your OS.

### Windows
Setup

``` text
   ./Script\SetupWindows.ps1
```

Build

``` text
   ./Script\MakeWindows.ps1
```

All

``` text
   ./Script\AllWindows.ps1
```

Clean

``` text
   ./Script\CleanWindows.ps1
```

### Linux

Setup

``` text
   ./Script\SetupLinux.ps1
```

Build

``` text
   ./Script\SetupLinux.ps1
```


All

``` text
   ./Script\AllSetup.ps1
```

Clean

``` text
   ./Script\CleanSetup.ps1
```
