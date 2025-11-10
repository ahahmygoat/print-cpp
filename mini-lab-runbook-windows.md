# mini-lab — Windows Runbook (MSYS2 MinGW/Ninja)

**Run all commands from the repo root** (folder containing `CMakeLists.txt`).

## Prereqs

- MSYS2 with MinGW64 toolchain (`C:\msys64\mingw64\bin\g++.exe`, `gdb.exe`).
- Recommended: Ninja (`pacman -S mingw-w64-x86_64-ninja` or `choco install ninja`).
- VS Code with C/C++ extension (and optionally CMake Tools).

## Configure & Build

````powershell
cmake -S . -B build -G Ninja
cmake --build build -j
Prefer Ninja. If you want MinGW Makefiles instead:

powershell
Copy code
cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_MAKE_PROGRAM=C:/msys64/mingw64/bin/mingw32-make.exe
cmake --build build -j
Create a new mini
PowerShell:

powershell
Copy code
Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass  # once per session
.\scripts\new_mini.ps1 -Name mini-02-foo
cmake -S . -B build -G Ninja
cmake --build build --target mini-02-foo -j
.\build\bin\mini-02-foo.exe
MSYS2 bash:

bash
Copy code
chmod +x scripts/new_mini.sh
scripts/new_mini.sh mini-02-foo
cmake -S . -B build -G Ninja
cmake --build build --target mini-02-foo -j
./build/bin/mini-02-foo.exe
VS Code
Build: Tasks → “CMake: Build (target)” (enter target like mini-01-market-data)

Debug: F5 → “Debug mini (MinGW gdb)” (enter target)

Binaries: build\bin\<target>.exe.

pgsql
Copy code

---

# NEW: `.vscode/c_cpp_properties.json`
```json
{
  "version": 4,
  "configurations": [
    {
      "name": "Win32",
      "includePath": [
        "${workspaceFolder}/**",
        "C:/msys64/mingw64/include",
        "C:/msys64/mingw64/include/c++/*",
        "C:/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/*/include"
      ],
      "defines": ["UNICODE", "_UNICODE"],
      "compilerPath": "C:/msys64/mingw64/bin/g++.exe",
      "cStandard": "c17",
      "cppStandard": "c++20",
      "intelliSenseMode": "windows-gcc-x64"
    }
  ]
}
````
