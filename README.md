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
│   └── main.cpp
└── qml/
    └── Main.qml
```

## Requirements

* C++17-compatible compiler
* CMake
* Qt 6 with Qt Quick support

## Build

```bash
cmake -S . -B build
cmake --build build
```

Depending on the Qt installation, CMake may need to be provided with the location of Qt.

## Current Goal

Launch a minimal Qt Quick application with a QML-defined desktop interface.

Future development will add a C++ device/sensor model and connect backend state to the QML user interface.
