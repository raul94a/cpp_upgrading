# Creamos una librería con la lógica del negocio para poder testearla después
add_library(storage 
                    models/product.cpp 
                    models/storage.cpp 
                    persistence/file_persister.cpp
                    controller/storage_controller.cpp
            )

# Directorios de inclusión para que otros (como los tests) encuentren los .h
target_include_directories(storage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

target_link_libraries(storage PUBLIC nlohmann_json::nlohmann_json)
# estas funciones se descomentan en caso de tener un exe.
# Creamos el ejecutable principal del programa
add_executable(app main.cpp)

# Enlazamos la app con nuestra librería de lógica
# target_link_libraries(app PRIVATE LogicLib)
target_link_libraries(app PRIVATE storage)