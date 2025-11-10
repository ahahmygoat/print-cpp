# mini-lab — Runbook (macOS/Linux)

A copy‑paste guide for navigating, creating new minis, and building C++ projects with CMake.

> **Run all commands from the repo root** — the folder that contains `CMakeLists.txt` and the `projects/` directory.
> The shell prompt `mini-lab $` below means your current directory is the repo root.

---

## TL;DR (Cheat Sheet)

```bash
# 1) configure (first time and whenever you add a new mini)
mini-lab $ cmake -S . -B build -G "Unix Makefiles"

# 2) build everything
mini-lab $ cmake --build build -j

# 3) create a new mini (auto-generates sample main.cpp/ok.hpp/ok.cpp)
mini-lab $ chmod +x scripts/new_mini.sh
mini-lab $ scripts/new_mini.sh mini-02-foo

# 4) reconfigure so CMake discovers it
mini-lab $ cmake -S . -B build -G "Unix Makefiles"

# 5) build & run the new target
mini-lab $ cmake --build build --target mini-02-foo -j
mini-lab $ ./build/bin/mini-02-foo
```

---

## Layout (repo root)

```
mini-lab/
├─ CMakeLists.txt
├─ projects/
│  └─ mini-01-market-data/
│     ├─ CMakeLists.txt
│     ├─ src/                   # add your .cpp here (e.g., main.cpp, ok.cpp)
│     └─ NOTES.txt
└─ scripts/
   └─ new_mini.sh               # scaffolds a new mini WITH sample sources
```

Check you're at the root:

```bash
mini-lab $ pwd
.../mini-lab
mini-lab $ ls
CMakeLists.txt  projects  scripts  ...
```

---

## First-time configure (and when adding a new mini)

```bash
mini-lab $ cmake -S . -B build -G "Unix Makefiles"
```

> Toolchain: macOS `xcode-select --install`. Optional: `brew install cmake ninja` and use `-G Ninja` consistently.

---

## Build everything

```bash
mini-lab $ cmake --build build -j
```

Executables land in `build/bin/<target>`.

---

## Create a new mini — end-to-end

```bash
# 1) scaffold (auto creates CMakeLists.txt, NOTES.txt, and sample sources)
mini-lab $ chmod +x scripts/new_mini.sh      # first time only
mini-lab $ scripts/new_mini.sh mini-02-foo

# 2) RECONFIGURE (discover the new subproject)
mini-lab $ cmake -S . -B build -G "Unix Makefiles"

# 3) build just the new target
mini-lab $ cmake --build build --target mini-02-foo -j

# 4) run it
mini-lab $ ./build/bin/mini-02-foo
```

Sample sources created for you:

- `projects/mini-02-foo/src/main.cpp` — contains `int main()` and prints the program name; calls `add(2,3)`
- `projects/mini-02-foo/src/ok.hpp` — declares `int add(int,int)`
- `projects/mini-02-foo/src/ok.cpp` — defines `add`

You can immediately modify these files and rebuild.

---

## Verify targets / Debug

List known targets:

```bash
mini-lab $ cmake --build build --target help
# or (Makefile generator):
mini-lab $ (cd build && make help)
```

Common fixes:

- **No rule to make target** → Re-run configure: `cmake -S . -B build`.
- **Binary missing** → Ensure a `src/main.cpp` exists for the mini and build succeeded.
- **Generator mismatch** → Stick to the same `-G` (e.g., Unix Makefiles vs Ninja) or `rm -rf build` then reconfigure.
- **Wrong directory** → Confirm `pwd` shows the repo root.

Clean build:

```bash
mini-lab $ rm -rf build
mini-lab $ cmake -S . -B build -G "Unix Makefiles"
mini-lab $ cmake --build build -j
```

---

## Conventions

- One mini per folder in `projects/`.
- **Target name = folder name** (e.g., `projects/mini-02-foo` → `mini-02-foo`).
- Executables go to `build/bin/`.
- Keep minis self-contained; extract shared code to a lib later if useful.
