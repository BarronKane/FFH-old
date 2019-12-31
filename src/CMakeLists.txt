# This may change but for now matching the version I'm utilizing.
cmake_minimum_required(VERSION 3.14.5)
project(factorio-frame-host)

include(GenerateExportHeader)
include(${CMAKE_SOURCE_DIR}/cmake/helpers.cmake)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# TODO: Compiler flags

if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

    add_compile_definitions(
        _WIN32_WINNT=0x0601
    )
endif(WIN32)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # -std=c++xx instead of -std=gnu++xx

# Platform agnostic installation trees.
include(GNUInstallDirs)

# This function is used to organize targets for Visual Studio and other IDEs.
set_property(GLOBAL PROPERTY USE_FOLDERS TRUE)
define_property(
    TARGET
    PROPERTY FOLDER
    INHERITED
    BRIEF_DOCS "Set the folder name."
    FULL_DOCS  "Use to organize targets in an IDE."
)

# Add conan libs to be visible by CMake.
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory_with_folder("utilities" utilities)

add_subdirectory_with_folder("factorio-frame-host" frame-host)
add_subdirectory_with_folder("factorio-frame-host" frame-host-api)

#enable_testing()
