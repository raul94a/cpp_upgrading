#include "controller.h"
#include "product.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

controller::StorageController::StorageController(FilePersister persister){
    this->persist = persister;
}

controller::StorageController::~StorageController(){

}

// Devuelve el vector de storages
std::vector<Product> controller::StorageController::get_all() {
    return this->products;
}

// Devuelve un storage específico por ID
StoragedProduct controller::StorageController::get_storage(int id) {
    return StoragedProduct(); 
}


void controller::StorageController::save_storages() {
    std::string header = "[";
    std::string tail= "]";
    std::string data = "";
    data.append(header);
    for(size_t i = 0; i < this->products.size(); ++i) {
        // Obtenemos referencia al producto
        Product& product = this->products[i];
        
        // Hacemos el cast (asegúrate del virtual ~Product)
        StoragedProduct& pr = dynamic_cast<StoragedProduct&>(product);
        
        data.append(pr.toJson());
        
        // Añadimos coma si no es el último elemento
        if(i < this->products.size() - 1) {
            data.append(",");
        }
    }
    data.append(tail);
    this->persist.write("./data.json", data);
}

// Lee los datos desde el disco
std::vector<Product*> controller::StorageController::read_storages() {
    std::string data = this->persist.read("./data.json");
    if (data.empty()){
        return {};
    }
    json parsed_data = json::parse(data);
    std::vector<Product*> prs;
    for(auto& el : parsed_data){
       StoragedProduct* pr = new StoragedProduct();
       pr->fromJson(el.dump());
       prs.push_back(pr);
    }
    return prs;
}