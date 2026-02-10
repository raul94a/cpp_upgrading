#include "product.h"
#include <string>
#include <iostream>

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
