# This file is apart of LastExpanse.
# Copyright (c) 2025 Soviet-Cat
# See LICENSE.md for license details.

cmake_minimum_required(VERSION 3.20)
project(LastExpanse)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}")

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Engine

option(BUILD_ENGINE "Builds \"Engine\" library." ON)
option(INSTALL_ENGINE "Installs \"Engine\" library." ON)

set(Engine_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Engine")
set(Engine_INC_DIR "${CMAKE_INSTALL_PREFIX}/Include")
set(Engine_LINK_DIR "${CMAKE_INSTALL_PREFIX}/Bin")
set(Engine_OUTPUT_NAME "LastExpanseEngine")

file(GLOB_RECURSE Engine_SOURCES
    "${Engine_DIR}/**/*.c" "${Engine_DIR}/*.c" # c
    "${Engine_DIR}/**/*.cpp" "${Engine_DIR}/*.cpp" # cpp
)
file(GLOB_RECURSE Engine_HEADERS 
    "${Engine_DIR}/**/*.h" "${Engine_DIR}/*.h" # c
    "${Engine_DIR}/**/*.hpp" "${Engine_DIR}/*.hpp" # cpp
    "${Engine_DIR}/**/*.inl" "${Engine_DIR}/*.inl" # c/cpp
)
file(GLOB_RECURSE Engine_PRV_HEADERS
    "${Engine_DIR}/**/*.prv.h" "${Engine_DIR}/*.prv.h" # c
    "${Engine_DIR}/**/*.prv.hpp" "${Engine_DIR}/*.prv.hpp" # cpp
    "${Engine_DIR}/**/*.prv.inl" "${Engine_DIR}/*.prv.inl" # c/cpp
)

if(${BUILD_ENGINE})
    add_library(Engine SHARED ${Engine_SOURCES})
    set_target_properties(Engine PROPERTIES
        OUTPUT_NAME ${Engine_OUTPUT_NAME}
    )
    target_include_directories(Engine PRIVATE ${Engine_DIR} 
        "${Engine_DIR}/Math" "${Engine_DIR}/Memory" "${Engine_DIR}/Platform"
    )
    target_compile_definitions(Engine PRIVATE ENGINE_EXPORT)

    if(${INSTALL_ENGINE})
        install(
            TARGETS Engine
            RUNTIME DESTINATION Bin
            ARCHIVE DESTINATION Bin
            LIBRARY DESTINATION Bin
        )
    endif()
endif()

if(${INSTALL_ENGINE})
    set(Engine_PUB_HEADERS ${Engine_HEADERS})
    list(REMOVE_ITEM Engine_PUB_HEADERS ${Engine_PRV_HEADERS})
    foreach(header IN LISTS Engine_PUB_HEADERS)
        install(
            FILES ${header}
            DESTINATION Include
        )
    endforeach()
endif()

# Engine Tests

option(BUILD_ENGINETESTS "Builds \"EngineTests\" executable." ON)
option(INSTALL_ENGINETESTS "Installs \"EngineTests\" executable." ON)

set(EngineTests_DIR "${CMAKE_CURRENT_SOURCE_DIR}/EngineTests")

file(GLOB_RECURSE EngineTests_SOURCES
    "${EngineTests_DIR}/**/*.c" "${EngineTests_DIR}/*.c" # c
    "${EngineTests_DIR}/**/*.cpp" "${EngineTests_DIR}/*.cpp" # c
)

if(${BUILD_ENGINETESTS})
    add_executable(EngineTests ${EngineTests_SOURCES})
    set_target_properties(EngineTests PROPERTIES
        OUTPUT_NAME "LastExpanseEngineTests"
    )
    target_include_directories(EngineTests PRIVATE ${Engine_INC_DIR})
    target_link_directories(EngineTests PRIVATE ${Engine_LINK_DIR})
    target_link_libraries(EngineTests PRIVATE ${Engine_OUTPUT_NAME})

    if(${INSTALL_ENGINETESTS})
        install(
            TARGETS EngineTests
            RUNTIME DESTINATION Bin
            ARCHIVE DESTINATION Bin
            LIBRARY DESTINATION Bin
        )
    endif()
endif()

# Editor

option(BUILD_EDITOR "Builds \"Editor\" executable." ON)
option(INSTALL_EDITOR "Installs \"Editor\" executable." ON)

set(Editor_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Editor")

file(GLOB_RECURSE Editor_SOURCES
    "${Editor_DIR}/**/*.c" "${Editor_DIR}/*.c" # c
    "${Editor_DIR}/**/*.cpp" "${Editor_DIR}/*.cpp" # c
)

if(${BUILD_EDITOR})
    add_executable(Editor ${Editor_SOURCES})
    set_target_properties(Editor PROPERTIES
        OUTPUT_NAME "LastExpanseEditor"
    )
    target_include_directories(Editor PRIVATE ${Engine_INC_DIR})
    target_link_directories(Editor PRIVATE ${Engine_LINK_DIR})
    target_link_libraries(Editor PRIVATE ${Engine_OUTPUT_NAME})

    if(${INSTALL_EDITOR})
        install(
            TARGETS Editor
            RUNTIME DESTINATION Bin
            ARCHIVE DESTINATION Bin
            LIBRARY DESTINATION Bin
        )
    endif()
endif()

# Game

option(BUILD_GAME "Builds \"Game\" executable." ON)
option(INSTALL_GAME "Installs \"Game\" executable." ON)

set(Game_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Game")

file(GLOB_RECURSE Game_SOURCES
    "${Game_DIR}/**/*.c" "${Game_DIR}/*.c" # c
    "${Game_DIR}/**/*.cpp" "${Game_DIR}/*.cpp" # c
)

if(${BUILD_GAME})
    add_executable(Game ${Game_SOURCES})
    set_target_properties(Game PROPERTIES
        OUTPUT_NAME "LastExpanseGame"
    )
    target_include_directories(Game PRIVATE ${Engine_INC_DIR})
    target_link_directories(Game PRIVATE ${Engine_LINK_DIR})
    target_link_libraries(Game PRIVATE ${Engine_OUTPUT_NAME})

    if(${INSTALL_GAME})
        install(
            TARGETS Game
            RUNTIME DESTINATION Bin
            ARCHIVE DESTINATION Bin
            LIBRARY DESTINATION Bin
        )
    endif()
endif()