cmake_minimum_required(VERSION 3.20)

project(
    DotenvLoader
    VERSION 1.0.0
    LANGUAGES CXX
)

# ============================================================
# C++
# ============================================================

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ============================================================
# Options
# ============================================================

option(ENVCPP_BUILD_EXAMPLES "Build examples" OFF)

# ============================================================
# clangd
# ============================================================

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ============================================================
# Library
# ============================================================

add_library(dotenv-cpp STATIC
    src/env.cpp
)

add_library(dotenv::dotenv ALIAS dotenv-cpp)

target_include_directories(dotenv-cpp
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(dotenv-cpp
    PUBLIC
        cxx_std_20
)

# ============================================================
# Examples
# ============================================================

if(ENVCPP_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
