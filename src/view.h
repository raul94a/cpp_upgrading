#include <iostream>
#include <string>
#include "controller.h"

using namespace controller;

void println(std::string* str){
    std::cout << *str << std::endl;
}
void print(std::string* str){
    std::cout << *str;
}
typedef int menu_option;
typedef menu_option storage_id;
menu_option main_menu(){
    std::string header = "======  Bienvenido al programa de gestión de almacenes ======\n";
    std::string subtitle = "Elige la opción que desees";
    std::string option_manage_storages = "\t1. Gestionar almacenes";
    std::string option_create_storage = "\t2. Crear almacén almacenes";
    std::string select = "selecciona la opción deseada: ";
    println(&header);
    println(&subtitle);
    println(&option_manage_storages);
    println(&option_create_storage);
    print(&select); 
    int option = 0;
    std::cin >> option;
    return option;
}

storage_id select_storage_menu(StorageController* controller){

    std::vector<Storage> storages = controller->get_all();
    for(auto& st : storages){
        std::string str = "";
        str
            .append(std::to_string(st.id))
            .append(" ")
            .append(st.name)
            .append(" - ")
            .append(st.city);
        println(&str);
    }
    storage_id option = 0;
    std::string str = "Selecciona el almacén que quieras gestionar";
    print(&str);
    std::cin >> option;
    return option;

}

void handle_storage(Storage* storage, StorageController* controller){
    /*
    1. Listar productos
    2. Crear producto
    3. Eliminar producto
    4. Salvar datos.
    */
   menu_option option = 0;
   std::string str = "Elige la opción que desees: ";
   print(&str);
   std::cin >> option;
   if(option == 1){
        std::vector<StoragedProduct> products = storage->products;
        for(auto& product: products){
            std::string str = "";
            str
                .append("ID: ")
                .append(std::to_string(product.id))
                .append(" - ")
                .append(product.name)
                .append(" - ")
                .append(std::to_string(product.price))
                .append(" € ")
                .append(std::to_string(product.quantity)).append(" uds.");
            println(&str);
        }
   }
   else if(option == 2){
        int id;
        std::string nombre;
        double precio;
        int quantity;

        std::cin >> id;
        std::cin >> nombre;
        std::cin >> precio;
        std::cin >> quantity;

        StoragedProduct pr(id,nombre,precio,quantity);
        storage->add_product(&pr);

        controller->save_storages();

   }
   else if(option == 3){

   }
   else if (option == 4){

   }else {

   }
}

void view(StorageController* controller){
    
    std::string str = "";
    menu_option option = main_menu();
    switch (option)
    {
    case 1: {

  
        str = "Has elegido gestionar";
        int id = select_storage_menu(controller);
        Storage* storage = controller->get_storage(id);
        handle_storage(storage,controller);
        break;
    }
    case 2: {
        std::cout << "Option de crear almacen" <<std::endl;
        str = "Has elegido crear";
        Storage st = Storage(1,"Almacén Los Garrulos", "Martos");
        controller->add_storage(st);
        controller->save_storages();
        println(&str);
        break;
    }
    default:
        str = "Opción incorrecta";
        println(&str);
        break;
    }
}