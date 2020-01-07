#!/bin/bash

set -e

cd "`dirname "$0"`"

mkdir -p build/

source $(pwd)/env/bin/activate

pushd build/
conan install ../src/ --build missing -s build_type=Debug

if [[ "$OSTYPE" == "darwin"* ]]; then
	cmake ../src/ -G "Xcode"
else
	cmake ../src/
fi

cmake --build .
popd > /dev/null

deactivate
