cmake_minimum_required(VERSION 3.14)
project(MiProyecto CXX)

# Estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Descarga de Google Test vía FetchContent ---
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# Previene problemas de compatibilidad en Windows con el runtime de C
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# ---- JSON ----
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
FetchContent_MakeAvailable(json)

# --- Subdirectorios ---
add_subdirectory(src)

# Habilitamos los tests solo si es el proyecto principal
enable_testing()
add_subdirectory(test)