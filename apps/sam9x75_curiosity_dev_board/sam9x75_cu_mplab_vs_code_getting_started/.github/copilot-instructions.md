<!-- Copied/merged guidance for AI coding agents working on this repo -->
# Copilot instructions for sam9x75_test_qspi

This repository is an embedded C project (Microchip SAM9X75) using generated CMake and MPLAB/XC32 toolchain files. The goal of these instructions is to make an AI coding agent productive quickly.

- **Big picture**: The project is a generated MCC/MPLAB-style embedded application. Sources and device configuration live under `My_MCC_Config/src` (this is the active source tree used by the MPLAB project). Generated CMake integration lives under `cmake/` and the CMake build tree is `_build/`.
- **Final artifacts**: The project expects final build outputs in `out/`. The MPLAB project file `.vscode/sam9x75_test_qspi.mplab.json` references `./out/sam9x75_test_qspi/default.elf` as the image used for simulation/flash.

- **Do not edit generated files**: Files under `cmake/...` and `cmake/.../.generated` are machine-generated. Do not edit `.generated/*` files directly. To customize build behavior, create `user.cmake` in the same directory (see `cmake/sam9x75_test_qspi/default/user.cmake`).

- **Where to put `boot.elf` / `boot.bin`**:
  - If you have a prebuilt `boot.elf` (or `.bin`) that you want the project/MPLAB tools to use, place it under the `out/` tree so the path matches the MPLAB `imagePath`. Example expected path for the default configuration:

    `out/sam9x75_test_qspi/default.elf`

  - To replace the built image with your file (PowerShell example):

    ```powershell
    Copy-Item C:\path\to\boot.elf -Destination .\out\sam9x75_test_qspi\default.elf
    # or for bin
    Copy-Item C:\path\to\boot.bin -Destination .\out\sam9x75_test_qspi\boot.bin
    ```

  - If you want the build system to emit artifacts into `out/`, add a `user.cmake` that sets `CMAKE_RUNTIME_OUTPUT_DIRECTORY` (or similar) instead of editing generated CMake files.

- **Build / dev workflow** (PowerShell examples):

  ```powershell
  # configure
  cmake -S . -B _build/sam9x75_test_qspi/default -DCMAKE_BUILD_TYPE=Release
  # build
  cmake --build _build/sam9x75_test_qspi/default --config Release
  ```

  After a successful build, check `out/` for final artifacts. The `_build/` tree contains CMake cache and intermediate files.

- **Key locations to inspect when debugging builds**:
  - `.vscode/sam9x75_test_qspi.mplab.json` — MPLAB project and `imagePath` used by the IDE.
  - `_build/sam9x75_test_qspi/default/` — CMake build tree and `CMakeCache.txt`.
  - `cmake/sam9x75_test_qspi/default/CMakeLists.txt` and `cmake/.../.generated/*` — generated CMake glue.
  - `My_MCC_Config/src/...` — primary C sources and config (device headers, initialization, startup and linker script `ddram.ld`).

- **Repo conventions & patterns**:
  - Many files are MCC-generated; prefer using the MCC UI or editing `My_MCC_Config` inputs rather than hand-editing generated headers.
  - The `packs/` directory contains device DFP headers and instances — use these for device register definitions.
  - `out/` is canonical for final images; `_build/` is for intermediate CMake data.

- **If making code changes**:
  - Keep changes inside `My_MCC_Config/src` (source and initialization code). Do not modify DFP files under `src/packs` unless necessary.
  - Run the build and verify `out/*.elf` exists before suggesting flashing steps.

If any of these paths or presets should be different for your environment, ask for the target tool (MPLAB IDE vs command-line) and I will adapt instructions or the `user.cmake` snippet.

---
Please tell me if any section is unclear or if you want examples for adding `user.cmake` or a PowerShell flash script.
