param(
  [Parameter(Mandatory = $true)]
  [string]$Name
)

$ErrorActionPreference = "Stop"

$Root = (Split-Path -Parent $PSScriptRoot)
$Dir  = Join-Path $Root "projects\$Name"

if (Test-Path $Dir) {
  throw "Directory already exists: $Dir"
}

New-Item -ItemType Directory -Force -Path (Join-Path $Dir "src") | Out-Null

# Per-mini CMakeLists.txt (single-quoted here-string to prevent PS expansion)
@'
cmake_minimum_required(VERSION 3.16)

# Target name = folder name
get_filename_component(TGT ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Compile all .cpp in src/
file(GLOB SRC_FILES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

if (SRC_FILES)
  add_executable(${TGT} ${SRC_FILES})
  target_include_directories(${TGT} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
else()
  message(WARNING "Skipping ${TGT}: no .cpp files in src/")
endif()
'@ | Set-Content -Encoding UTF8 (Join-Path $Dir "CMakeLists.txt")

# Notes (expand $Name here is fine)
@"
Mini: $Name
Goal: <describe>
"@ | Set-Content -Encoding UTF8 (Join-Path $Dir "NOTES.txt")

# Sample sources
@'
#include <iostream>
#include "ok.hpp"

int main(int argc, char** argv) {
  std::cout << "Hello from " << (argc > 0 ? argv[0] : "mini") << "\n";
  std::cout << "add(2, 3) = " << add(2, 3) << "\n";
  return 0;
}
'@ | Set-Content -Encoding UTF8 (Join-Path $Dir "src/main.cpp")

@'
#pragma once
int add(int a, int b);
'@ | Set-Content -Encoding UTF8 (Join-Path $Dir "src/ok.hpp")

@'
#include "ok.hpp"
int add(int a, int b) { return a + b; }
'@ | Set-Content -Encoding UTF8 (Join-Path $Dir "src/ok.cpp")

Write-Host "Created $Dir"
Write-Host "IMPORTANT: From repo root, reconfigure, then build + run:"
Write-Host "  cmake -S `"$Root`" -B `"$Root/build`" -G Ninja"
Write-Host "  cmake --build `"$Root/build`" --target $Name -j"
Write-Host "  `"$Root/build/bin/$Name.exe`""
