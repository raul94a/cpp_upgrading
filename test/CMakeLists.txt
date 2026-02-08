# Creamos el ejecutable de los tests
add_executable(UnitTests test_test.cpp)

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