#include <gtest/gtest.h>
#include <filesystem>
#include "persister.h"

TEST(Persister, ReadsFile) {
    FilePersister pr; // No es necesario el = FilePersister() en C++
    
    // 1. Obtenemos la ruta actual para depurar si falla
    std::filesystem::path cwd = std::filesystem::current_path();
    std::cout << "[ DEBUG ] Ejecutando desde: " << cwd << std::endl;

    // 2. Definimos el archivo (asumiendo que está en la raíz del proyecto)
    // Si ejecutas desde /build, el archivo suele estar en "../CMakeLists.txt"
    std::string filename = "../../CMakeLists.txt";

    // 3. Verificación lógica: ¿Existe el archivo antes de probar?
    ASSERT_TRUE(std::filesystem::exists(filename)) 
        << "Error: El archivo " << filename << " no se encuentra en " << cwd;

    // 4. Ejecución
    // Si tu método read no devuelve nada (void), al menos probamos que no crashea

    EXPECT_NO_THROW(pr.read(filename));

    std::string summ = pr.read(filename);
    ASSERT_GT(summ.length(), 10);
}

TEST(Persister, WritesFile) {
    FilePersister pr; // No es necesario el = FilePersister() en C++
    
    // 1. Obtenemos la ruta actual para depurar si falla
    std::filesystem::path cwd = std::filesystem::current_path();
    std::cout << "[ DEBUG ] Ejecutando desde: " << cwd << std::endl;

    // 2. Definimos el archivo (asumiendo que está en la raíz del proyecto)
    // Si ejecutas desde /build, el archivo suele estar en "../CMakeLists.txt"
    std::string filename = "../../test.txt";

    
    // 4. Ejecución
    // Si tu método read no devuelve nada (void), al menos probamos que no crashea
    EXPECT_NO_THROW(pr.write(filename,"pruebaDOS",std::ios::app));

   

}


