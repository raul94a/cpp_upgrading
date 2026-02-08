#!/bin/bash

# 1. Configurar: Definimos origen (-S) y destino (-B) de forma explícita
cmake -S . -B build

# 2. Compilar: Apuntamos a la carpeta de build definida arriba
cmake --build build

# 3. Testear: Usamos --test-dir para no tener que andar entrando y saliendo de carpetas
ctest --test-dir build --verbose