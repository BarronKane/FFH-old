@echo off
setlocal enableextensions
pushd "%~dp0"

md build
pushd build
cmake ..\src\ -G "Visual Studio 16 2019"
cmake --build .
popd

if ERRORLEVEL 1 goto error
goto :EOF

:error
rem Error occured, waiting for keypress.
pause
