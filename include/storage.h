


#include "product.h"

#include <string>
#include <vector>

class Storage {
    public:
        int id;
        std::string name;
        std::string city;
        std::vector<StoragedProduct> products;

        Storage();
        Storage(int id, std::string name, std::string city);
        ~Storage();

        void add_product(StoragedProduct* p);
        void add_products(size_t nr, StoragedProduct pr[]);

        bool sell(int id, int quantity);
        

};