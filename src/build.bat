@echo off
setlocal
pushd .
cd %~dp0
rem *HOW TO MAKE THE DLL FILE WITH Visual C++
rem * - Build the Lua 5.1.4 binary from source files.
rem * - Copy header files (*.h) to INCDIR specified below.
set INCDIR=..\lua
rem * - Copy lua51.lib to LIBDIR specified below.
set LIBDIR=..\lua
rem * - Enable the use of command line tools in VC++
rem *   by invoking vcvarsall.bat
rem * - Run this batch file.
:start
set CC=cl /O2
set SRC=shutwindown.c
%CC% /I%INCDIR% /LD /MD %SRC% %LIBDIR%\lua51.lib User32.lib advapi32.lib
popd
endlocal
:exit
