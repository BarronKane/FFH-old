#!/bin/bash

set -e

cd "`dirname "$0"`"

mkdir -p build/

pushd build/
conan install ..\src\ --build missing -s build_type=Debug
cmake ../src/
cmake --build .
popd > /dev/null
