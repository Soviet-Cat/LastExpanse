rem This file is apart of LastExpanse.
rem Copyright (c) 2025 Soviet-Cat
rem     See LICENSE.md for license details.

@echo off

cls

echo CLEANING

if exist "%CD%\Build" ( rmdir /s /q "%CD%\Build" )
if exist "%CD%\Bin" ( rmdir /s /q "%CD%\Bin" )
if exist "%CD%\Include" ( rmdir /s /q "%CD%\Include" )

echo FINISHED

echo ENGINE PARSE

echo CONFIGURING
cmake -S . -B Build -G Ninja -D BUILD_ENGINE=ON -D INSTALL_ENGINE=ON -D BUILD_ENGINETESTS=OFF -D INSTALL_ENGINETESTS=OFF -D BUILD_EDITOR=OFF -D INSTALL_EDITOR=OFF -D BUILD_GAME=OFF -D INSTALL_GAME=OFF
echo BUILDING
cmake --build Build
echo INSTALLING
cmake --install Build
echo FINISHED

echo ENGINETESTS PARSE

echo CONFIGURING
cmake -S . -B Build -G Ninja -D BUILD_ENGINE=OFF -D INSTALL_ENGINE=OFF -D BUILD_ENGINETESTS=ON -D INSTALL_ENGINETESTS=ON -D BUILD_EDITOR=OFF -D INSTALL_EDITOR=OFF -D BUILD_GAME=OFF -D INSTALL_GAME=OFF
echo BUILDING
cmake --build Build
echo INSTALLING
cmake --install Build
echo FINISHED

if exist "%CD%\Bin\LastExpanseEngineTests.exe" (
    echo RUNNING ENGINETESTS
    cd "Bin"
    LastExpanseEngineTests.exe
    cd ..
    echo FINISHED
)

echo EDITOR PARSE

echo CONFIGURING
cmake -S . -B Build -G Ninja -D BUILD_ENGINE=OFF -D INSTALL_ENGINE=OFF -D BUILD_ENGINETESTS=OFF -D INSTALL_ENGINETESTS=OFF -D BUILD_EDITOR=ON -D INSTALL_EDITOR=ON -D BUILD_GAME=OFF -D INSTALL_GAME=OFF
echo BUILDING
cmake --build Build
echo INSTALLING
cmake --install Build
echo FINISHED

echo GAME PARSE

echo CONFIGURING
cmake -S . -B Build -G Ninja -D BUILD_ENGINE=OFF -D INSTALL_ENGINE=OFF -D BUILD_ENGINETESTS=OFF -D INSTALL_ENGINETESTS=OFF -D BUILD_EDITOR=OFF -D INSTALL_EDITOR=OFF -D BUILD_GAME=ON -D INSTALL_GAME=ON
echo BUILDING
cmake --build Build
echo INSTALLING
cmake --install Build
echo FINISHED

pause
cls