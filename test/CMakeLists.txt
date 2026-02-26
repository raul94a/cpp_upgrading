# Creamos el ejecutable de los tests
add_executable(UnitTests test_test.cpp 
                models/test_storaged_product.cpp 
                models/test_storage.cpp 
                persistence/test_file_persister.cpp
                json/test_janson.cpp
                )

# Enlazamos con:
# 1. GTest::gtest_main (provee el main() de los tests automáticamente)
# 2. LogicLib (tu código fuente)
target_link_libraries(UnitTests 
    GTest::gtest_main 
    storage
)

# Esto permite que los tests aparezcan en herramientas como 'ctest'
include(GoogleTest)
gtest_discover_tests(UnitTests)