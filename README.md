![Windows build](https://github.com/MaelTeyssedre/R-TYPE/actions/workflows/R-TYPE_Windows.yml/badge.svg)
![Ubuntu build](https://github.com/MaelTeyssedre/R-TYPE/actions/workflows/R-TYPE_Ubuntu.yml/badge.svg)
[![Doxygen Generation](https://github.com/MaelTeyssedre/R-TYPE/actions/workflows/Doxygen.yml/badge.svg)](https://maelteyssedre.github.io/R-TYPE)
<div id="top"></div>

# R-TYPE

<details>
   <summary>Table of Contents</summary>
   <ol>
      <li><a href="#Introduction">Introduction</a></li>
      <li><a href="#Stack">Stack</a></li>
      <li><a href="#Structure">Structure</a></li>
      <li><a href="#Building">Building</a></li>
      <li><a href="#Usage">Usage</a></li>
      <li><a href="#Documentation">Documentation</a></li>
      <li><a href="#Contact">Contact</a></li>
      <li><a href="#Acknowledgments">Acknowledgments</a></li>
   </ol>
</details>

## Introduction

The goal of the R-Type project is to create an online multiplayer
   copy of the classic R-Type game (1987).
   
   
   -   Sources separated in three part, Server, Client and Common.
   -   Is working under Windows and Linux distribution
   -   Playing with four other member
   -   Use of [CMake](https://cmake.org/) for compiling
   -   Use of Script for much easier utilisation.
   -   Use of [Conan](https://conan.io/) to compile external librairies on linux and windows
   -   Use of [TCP and UDP](https://github.com/MaelTeyssedre/R-TYPE/blob/main/Sources/Doc/rfc.txt) for server client communication
   -   Continuous integration with [GitHub Actions](https://github.com/features/actions).
   -   Code documentation with [Doxygen](https://maelteyssedre.github.io/R-TYPE) and [UML]()

## Stack
   
   - [C++17](https://en.cppreference.com/w/cpp/17)
   - [Conan](https://conan.io/)
   - [SFML](https://www.sfml-dev.org/)
   - [Asio](https://think-async.com/Asio/)
   - [Nlohmann_json](https://github.com/nlohmann/json)

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

Build by executing the script matching with your OS.

### Windows

``` bash
> .\Script\SetupWindows.ps1 # Setup

> .\Script\MakeWindows.ps1 # Build

> .\Script\AllWindows.ps1 # Setup and Build

> .\Script\CleanWindows.ps1 # Clean
```

### Linux

``` bash
> ./Script/SetupLinux.ps1 # Setup

> ./Script/MakeLinux.ps1 # Build

> ./Script/AllLinux.ps1 # Setup and Build

> ./Script/CleanLinux.ps1 # Clean
```

<p align="right">(<a href="#top">back to top</a>)</p>

## Usage

   -  Clone the repo
``` bash
   git clone git@github.com:MaelTeyssedre/R-TYPE.git
```
   
   -  Build with the script above
   -  Launch the server

Windows

``` bash
> .\rtype_server.exe <port>

> .\build\bin\rtype_server.exe <port> # If first option has strange behaviour
```
Linux

``` bash
> .\rtype_server <port>

> .\build\bin\rtype_server <port> # If first option has strange behaviour
```

   -  Launch client

Windows
   
``` bash
> .\rtype_client.exe <IP> <port>

> .\build\bin\rtype_client.exe <IP> <port> # If first option has strange behaviour
```

Linux
   
``` bash
> .\rtype_client <IP> <port>

> .\build\bin\rtype_client <IP> <port> # If first option has strange behaviour
```

<p align="right">(<a href="#top">back to top</a>)</p>

## Documentation

   -  [Doxygen](https://maelteyssedre.github.io/R-TYPE)
   -  [UML](https://github.com/MaelTeyssedre/R-TYPE/blob/main/Sources/Doc/R-Type%20UML.png)
   -  [RFC](https://github.com/MaelTeyssedre/R-TYPE/blob/main/Sources/Doc/rfc.txt)

<p align="right">(<a href="#top">back to top</a>)</p>

## Contact

Romain Gabet:
   - romain.gabet@epitech.eu
   - [Github](https://github.com/Romain-GABET)
   - [LinkedIn](https://www.linkedin.com/in/romain-gabet-3b7047197//)

Maël Teyssèdre 
   - mael.teyssedre@epitech.eu
   - [Github](https://github.com/MaelTeyssedre)
   - [LinkedIn](https://www.linkedin.com/in/maeltey/)

Jules Savang 
   - jules.savang@epitech.eu
   - [Github](https://github.com/Jsavang)
   - [LinkedIn](https://www.linkedin.com/in/jules-savang-916aa9180/)

Alban Bodénès 
   - alban.bodenes@epitech.eu
   - [Github](https://github.com/Alban-Bodenes)
   - [LinkedIn](https://www.linkedin.com/in/alban-bodenes-236bba1a1/)

<p align="right">(<a href="#top">back to top</a>)</p>

## Acknowledgments

   -  [cppreference](https://en.cppreference.com/w/)
   -  [SFML documentation](https://www.sfml-dev.org/)
   -  [Asio Documentation](https://think-async.com/Asio/Documentation.html)
   -  [This Man](https://github.com/Eldriann)

<p align="right">(<a href="#top">back to top</a>)</p>
