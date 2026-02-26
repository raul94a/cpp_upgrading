#include "product.h"
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

Product::Product(){}
Product::Product(int id, std::string name, double price) : 
            name(name), id(id), price(price) {}

Product::~Product(){
    std::cout << "Destruyendo " << this << std::endl;
}
StoragedProduct::StoragedProduct() : Product() {}
StoragedProduct::StoragedProduct(int id, std::string name, double price, int quantity) : Product(id,name,price) {
        this->quantity = quantity;
}

StoragedProduct::~StoragedProduct(){
    std::cout << "Destruyendo " << this << std::endl;
}


bool StoragedProduct::can_retire(int qty){
    return qty <= this->quantity;
}

bool StoragedProduct::retire(int qty){
    if (can_retire(qty)){
        this->quantity -= qty;
        //std::cout << "QTY: " << this->quantity <<std::endl;
        return true; 
    }
    return false;
}

void StoragedProduct::add(int qty){
    this->quantity += qty;
}

void StoragedProduct::update(StoragedProduct* ptr){
   this->id = ptr->id;
   this->name = ptr->name;
   this->price = ptr->price;
   this->quantity = ptr->quantity;
   std::cout << "Updating pointer " <<  this << " With " << ptr << std::endl;
}

void StoragedProduct::fromJson(const std::string& string) {
    json data = json::parse(string);
    this->id = data["id"];
    this->name = data["name"];
    this->price = data["price"];
    this->quantity = data["quantity"];
}

std::string StoragedProduct::toJson() {
    json j_object = {
        {"id", this->id},
        {"name", this->name},
        {"price", this->price},
        {"quantity", this->quantity}
    };
    return j_object.dump();
}

template class JsonSerializer<StoragedProduct>;