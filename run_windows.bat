@echo off
set BUILD_DIR=build_dir
set EXE_PATH=%BUILD_DIR%\example\Release\main.exe

@REM rmdir /s /q %BUILD_DIR%
 
cmake -B %BUILD_DIR% ^
-G "Visual Studio 15 2017 Win64"

cmake --build %BUILD_DIR% --config Release

echo ---
echo %EXE_PATH%
echo ---
call %EXE_PATH%