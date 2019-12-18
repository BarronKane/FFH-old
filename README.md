# Factorio Frame Host

## What is this?

 This will be a C++ restfull web api capable of running Factorio in a
 sub-process. This should be able to receive commands via web sockets to do 
 anything from manage mods, to starting/stoping server, to managing admins, etc.

 # Building

 ## Requirements

 1. A modern C++ compiler.
 2. Python 3.6 or newer.

Python virtualenv is **highly** recommended to localize packages per-project.
Installation is simple:

`python -m pip install virtualenv`

Then in your project directory run:

`virtualenv env`

Run the 'activate' script matching your OS/terminal to activate the environment
under 'env/Scripts' and run:

`python -m pip install -r requirements.txt`

Add the conan repository:

`conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan`

## Build

You can run either of the build scripts provided, but often you need custom
arguments. We use [conan](https://conan.io/) so you might benefit from exploring
their documentation.

1. mkdir build && cd build
2. conan install ../src/
3. cmake ../src/
4. cmake --build .
