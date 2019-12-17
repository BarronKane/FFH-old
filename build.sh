#!/bin/bash

set -e

cd "`dirname "$0"`"

mkdir -p build/

pushd build/
cmake ../src/
cmake --build .
popd > /dev/null
