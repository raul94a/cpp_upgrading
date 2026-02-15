#include "product.h"
#include "storage.h"
#include <algorithm>
#include <string>
#include <vector>


Storage::Storage(){}
Storage::Storage(int id, std::string name, std::string city){}
Storage::~Storage(){

}

void Storage::add_product(StoragedProduct p){
    this->products.push_back(p);
}
void Storage::add_products(size_t nr, StoragedProduct pr[]){
    auto prs = this->products;
    for(int i = 0; i < nr; i++){
        prs.push_back(pr[i]);
    }
}

bool Storage::sell(int id, int quantity){
    std::vector<StoragedProduct> products = this->products;
    auto storagedPtr = std::find_if(products.begin(), products.end(), [id](const auto& pr) { 
        return pr.id == id; 
    });
    if (storagedPtr != products.end()){
        if(storagedPtr->can_retire(quantity)){
            storagedPtr->retire(quantity);
            return true;
        }
        else {
             printf("\nCould not retire quantity for product {%d}. The storaged quantity is {%d}\n",id, storagedPtr->quantity);
             return false;
        }
    }
    else {
        printf("\nElement not found {%d}\n",id);
    }
    return false;
}