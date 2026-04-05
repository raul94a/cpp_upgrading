#include "storage.h"
#include <algorithm>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <iostream>
using json = nlohmann::json;

Storage::Storage(){}
Storage::Storage(int id, std::string name, std::string city){
    this->id=id;
    this->name=name;
    this->city=city;
}
Storage::~Storage(){

}

void Storage::add_product(StoragedProduct* p){
    for (auto& pr : this->products){
        if(pr.id == p->id){
            std::cout << "[Warning] No se ha podido añadir el producto con id " << p->id <<std::endl;
            return;
        }
    }
    this->products.push_back(*p);
}
void Storage::add_products(size_t nr, StoragedProduct pr[]){
    // WHAT IF THE PRODUCT EXISTS IN THE LIST?
    auto prs = this->products;
    for(int i = 0; i < nr; i++){
        prs.push_back(pr[i]);
    }
}

bool Storage::sell(int id, int quantity){
    // magia! esto hace un deepcopy y no funciona correctamente
    // std::vector<StoragedProduct> products = this->products;
    auto storagedPtr = std::find_if(this->products.begin(), this->products.end(), [id](const auto& pr) { 
        return pr.id == id; 
    });
    if (storagedPtr != products.end()){
        if(storagedPtr->can_retire(quantity)){
            storagedPtr->retire(quantity);
            return true;
        }
        else {
             printf("\nStorage::sell() => Could not retire quantity for product {%d}. The storaged quantity is {%d}\n",id, storagedPtr->quantity);
             return false;
        }
    }
    else {
        printf("\nStorage::sell() => Element not found {%d}\n",id);
    }
    return false;
}

//  int id;
//         std::string name;
//         std::string city;
//         std::vector<StoragedProduct> products;
void Storage::fromJson(const std::string& string) {
    json data = json::parse(string);
    this->id = data["id"];
    this->name = data["name"];
    this->city = data["city"];
    this->products.clear();
    std::vector<StoragedProduct> prs;
    json products = data["products"];
    for(auto& el : products){
        StoragedProduct pr;
        pr.fromJson(el.dump());
        this->products.push_back(pr);
    }
}

std::string Storage::toJson() {
    
    json j_products = json::array();
    
    for (auto& pr : this->products) {
        j_products.push_back(json::parse(pr.toJson()));
    }

    json j_object = {
        {"id", this->id},
        {"name", this->name},
        {"city", this->city},
        {"products", j_products} 
    };
    
    return j_object.dump();
}

template class JsonSerializer<Storage>;