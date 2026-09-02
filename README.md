# Qt/QML Device Monitor

A cross-platform desktop application built with C++, Qt 6, and QML.

This project is being developed as a hands-on refresher in modern C++ and Qt/QML application development, with an emphasis on:

* Qt Quick and QML user interfaces
* C++ backend development
* `QObject`
* Signals and slots
* `Q_PROPERTY`
* C++ and QML integration
* Event-driven application design
* CMake-based cross-platform builds

## Project Structure

```text
qt-qml-device-monitor/
├── CMakeLists.txt
├── README.md
├── src/
│   ├── main.cpp
│   ├── TemperatureSensor.cpp
│   └── TemperatureSensor.h
└── qml/
    └── Main.qml
```

## Requirements

* C++17-compatible compiler
* CMake
* Qt 6 with Qt Quick support
* Ninja or another supported CMake build system

## Build

Configure the project:

```powershell
qt-cmake.bat -G Ninja `
  -DCMAKE_CXX_COMPILER="C:\Qt\Tools\mingw1310_64\bin\g++.exe" `
  -S . `
  -B build
```

Build the application:

```powershell
cmake --build build
```

On Windows, deploy the required Qt runtime dependencies:

```powershell
windeployqt.exe --qmldir .\qml .\build\QtQmlDeviceMonitor.exe
```

Run the application:

```powershell
.\build\QtQmlDeviceMonitor.exe
```

The exact Qt and compiler paths may vary depending on the local Qt installation.

## Current State

The application currently includes:

* A Qt Quick/QML desktop interface
* A C++ `TemperatureSensor` backend
* A temperature property exposed from C++ to QML
* Reactive UI updates when the temperature changes
* A control for increasing the simulated temperature
* An overheating warning displayed at 75°F or higher

## Development Workflow

After the project has been configured and the Qt runtime dependencies have been deployed once, the normal edit-test cycle is:

```powershell
cmake --build build
.\build\QtQmlDeviceMonitor.exe
```

Run `windeployqt` again when deployment dependencies need to be refreshed:

```powershell
windeployqt.exe --qmldir .\qml .\build\QtQmlDeviceMonitor.exe
```
