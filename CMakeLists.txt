cmake_minimum_required(VERSION 3.25.1)

set(CMAKE_CXX_STANDARD 20)

project(
  Lamb
  VERSION 0.0.1
  DESCRIPTION "A small functional programming language"
  LANGUAGES CXX
)

add_library(lamb_warnings INTERFACE)
include(cmake/CompilerWarnings.cmake)
set_project_warnings(lamb_warnings)

include(cmake/StaticAnalyzers.cmake)

add_subdirectory(src)

option(ENABLE_TESTING "Enable Test Builds" ON)
# target_precompile_headers(${PROJECT_NAME} PRIVATE include/pch.hpp)

add_subdirectory(tst)

