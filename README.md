![Windows build](https://github.com/MaelTeyssedre/R-TYPE/actions/workflows/R-TYPE_Windows.yml/badge.svg)
![Ubuntu build](https://github.com/MaelTeyssedre/R-TYPE/actions/workflows/R-TYPE_Ubuntu.yml/badge.svg)
[![Doxygen Generation](https://github.com/MaelTeyssedre/R-TYPE/actions/workflows/Doxygen.yml/badge.svg)](https://maelteyssedre.github.io/R-TYPE)
<div id="top"></div>

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

<p align="right">(<a href="#top">back to top</a>)</p>


## Build With
   
   - [C++20](https://en.cppreference.com/w/cpp/20)
   - [Visual Studio 16](https://visualstudio.microsoft.com/fr/)
   - [SFML 2.5.1](https://www.sfml-dev.org/)
   - [Asio 1.19.2](https://think-async.com/Asio/)
   - [Nlohmann_json 3.10.4](https://github.com/nlohmann/json)

<p align="right">(<a href="#top">back to top</a>)</p>

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

<p align="right">(<a href="#top">back to top</a>)</p>

## Building

Build by executing the script correspondint to your OS.

### Windows

``` bash
> ./Script\SetupWindows.ps1 # Setup

> ./Script\MakeWindows.ps1 # Build

> ./Script\AllWindows.ps1 # Setup and Build

> ./Script\CleanWindows.ps1 # Clean
```

### Linux

``` bash
> ./Script\SetupLinux.ps1 # Setup

> ./Script\MakeLinux.ps1 # Build

> ./Script\AllLinux.ps1 # Setup and Build

> ./Script\CleanLinux.ps1 # Clean
```

<p align="right">(<a href="#top">back to top</a>)</p>

## Contact

Romain Gabet:
   - romain.gabet@epitech.eu

Maël Teyssèdre 
   - mael.teyssedre@epitech.eu

Jules Savang 
   - jules.savang@epitech.eu

Alban Bodénès 
   - alban.bodenes@epitech.eu

<p align="right">(<a href="#top">back to top</a>)</p>

## Acknowledgments

[cppreference](https://en.cppreference.com/w/)
[SFML documentation](https://www.sfml-dev.org/)
[c++.com](https://www.cplusplus.com/)

