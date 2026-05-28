# RK2 SOLID CMake project

This repository contains an RK2 assignment project based on the SOLID examples from `pelocpp/cpp_design_patterns/Patterns/SOLID`.

The project demonstrates the Single Responsibility Principle: `Journal` stores entries, and `SavingManager` is responsible for saving them to an output stream.

## Project contents

- `CMakeLists.txt` - CMake build file with CTest and CPack DEB packaging.
- `include/rk2_journal.hpp` - public header.
- `src/journal.cpp` - implementation.
- `app/main.cpp` - demo executable.
- `tests/test_journal.cpp` - one unit test.
- `scripts/build_and_test.sh` - Linux automation script.
- `.github/workflows/build-test-package.yml` - GitHub Actions workflow.

## Local build and test

```bash
bash scripts/build_and_test.sh
```

Manual commands:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=ON
cmake --build build --parallel
ctest --test-dir build --output-on-failure
cpack --config build/CPackConfig.cmake
```

After `cpack`, a `.deb` package is created in the repository root.

## GitHub Release

The workflow publishes the generated `.deb` file to a GitHub Release when a tag beginning with `v` is pushed.

Example:

```bash
git tag v1.0.0
git push origin v1.0.0
```

Or with GitHub CLI after the package is built:

```bash
gh release create v1.0.0 *.deb --title "v1.0.0" --notes "RK2 SOLID DEB package"
```
