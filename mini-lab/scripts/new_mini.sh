#!/usr/bin/env bash
set -euo pipefail

if [[ $# -lt 1 ]]; then
  echo "Usage: $0 <mini-name>   e.g., $0 mini-02-foo"
  exit 1
fi

NAME="$1"
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DIR="$ROOT/projects/$NAME"

if [[ -e "$DIR" ]]; then
  echo "Directory already exists: $DIR"
  exit 1
fi

mkdir -p "$DIR/src"

cat > "$DIR/CMakeLists.txt" <<'EOF'
cmake_minimum_required(VERSION 3.16)
# Target name = folder name
get_filename_component(TGT ${CMAKE_CURRENT_SOURCE_DIR} NAME)
file(GLOB SRC_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(${TGT} ${SRC_FILES})
EOF

cat > "$DIR/NOTES.txt" <<EOF
Mini: $NAME
Goal: <describe>
EOF

cat > "$DIR/src/main.cpp" <<'EOF'
#include <iostream>
#include "ok.hpp"

int main(int argc, char** argv) {
  std::cout << "Hello from " << (argc > 0 ? argv[0] : "mini") << "\n";
  std::cout << "add(2, 3) = " << add(2, 3) << "\n";
  return 0;
}
EOF

cat > "$DIR/src/ok.hpp" <<'EOF'
#pragma once
int add(int a, int b);
EOF

cat > "$DIR/src/ok.cpp" <<'EOF'
#include "ok.hpp"
int add(int a, int b) { return a + b; }
EOF

echo "Created $DIR"
echo "Add more sources under $DIR/src/ if needed."
echo "IMPORTANT: From repo root, reconfigure so CMake discovers the new mini:"
echo "  cmake -S \"$ROOT\" -B \"$ROOT/build\" -G \"Unix Makefiles\""
echo "Then build + run:"
echo "  cmake --build \"$ROOT/build\" --target $NAME -j"
echo "  \"$ROOT/build/bin/$NAME\""
