# 1. Crear carpeta de compilación y configurar
cmake -S . -B build

# 2. Compilar el proyecto
cmake --build build

# 3. Ejecutar el programa resultante (estará dentro de la carpeta build/src)
./build/src/app