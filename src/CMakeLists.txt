# Creamos una librería con la lógica del negocio para poder testearla después
add_library(storage test.cpp models/product.cpp)

# Directorios de inclusión para que otros (como los tests) encuentren los .h
target_include_directories(storage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# estas funciones se descomentan en caso de tener un exe.
# Creamos el ejecutable principal del programa
# add_executable(app main.cpp)

# Enlazamos la app con nuestra librería de lógica
# target_link_libraries(app PRIVATE LogicLib)