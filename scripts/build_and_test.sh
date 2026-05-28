#!/usr/bin/env bash
set -euo pipefail

BUILD_DIR="${BUILD_DIR:-build}"
CONFIG="${CONFIG:-Release}"

cmake -S . -B "${BUILD_DIR}" -DCMAKE_BUILD_TYPE="${CONFIG}" -DBUILD_TESTING=ON
cmake --build "${BUILD_DIR}" --config "${CONFIG}" --parallel
ctest --test-dir "${BUILD_DIR}" --output-on-failure
cpack --config "${BUILD_DIR}/CPackConfig.cmake"
