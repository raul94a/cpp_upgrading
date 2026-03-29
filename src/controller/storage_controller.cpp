#include "controller.h"
#include "product.h"
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

controller::StorageController::StorageController(FilePersister persister){
    this->persist = persister;
}

controller::StorageController::~StorageController(){

}
void controller::StorageController::add_storage(Storage storage) {
    this->storages.push_back(storage);
}
std::vector<Storage> controller::StorageController::get_all() {
    return this->storages;
}

// TODO: IMPLEMENT
Storage controller::StorageController::get_storage(int id) {
    return Storage(); 
}


void controller::StorageController::save_storages() {
    std::string header = "[";
    std::string tail= "]";
    std::string data = "";
    data.append(header);
    std::cout << "Storages: " <<  this->storages.size() << std::endl;

    for(size_t i = 0; i < this->storages.size(); ++i) {

        Storage& storage = this->storages[i];
        std::cout << "STORAGE OBTENIDO" << std::endl;
        
        data.append(storage.toJson());
        
        if(i < this->storages.size() - 1) {
            data.append(",");
        }
    }
    data.append(tail);
    std::cout << data <<std::endl;
    this->persist.write("./data.json", data,std::ios::out);
}

std::vector<Storage> controller::StorageController::read_storages() {
    std::string data = this->persist.read("./data.json");
    if (data.empty()){
        return {};
    }
    this->storages.clear();
    json parsed_data = json::parse(data);
    
    for(auto& el : parsed_data){
       Storage storage = Storage();
       storage.fromJson(el.dump());
       this->storages.push_back(storage);
    }
    return this->storages;
}