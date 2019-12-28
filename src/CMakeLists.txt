# This may change but for now matching the version I'm utilizing.
cmake_minimum_required(VERSION 3.14.5)
project(factorio-frame-host)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# TODO: Compiler flags

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

function(add_subdirectory_with_folder _folder_name _folder)
    add_subdirectory(${_folder} ${ARGN})
    set_property(DIRECTORY "${_folder}" PROPERTY FOLDER "${_folder_name}")
endfunction()

# Add conan libs to be visible by CMake.
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory_with_folder("factorio-frame-host" frame-host)
add_subdirectory_with_folder("factorio-frame-host" frame-host-api)

#enable_testing()
