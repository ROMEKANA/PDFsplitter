cmake_minimum_required(VERSION 3.16)

project(PDF-spliter VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS
        Widgets
        Pdf
        PdfWidgets
)

qt_standard_project_setup()

qt_add_executable(PDF-spliter
        WIN32 MACOSX_BUNDLE
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

target_link_libraries(PDF-spliter PRIVATE
        Qt6::Widgets
        Qt6::Pdf
        Qt6::PdfWidgets
)

qt_finalize_executable(PDF-spliter)