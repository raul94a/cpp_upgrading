#include <string>

class Product {
    public:
        int id;
        std::string name;
        double price;

        Product();
        Product(int id, std::string name, double price);
        ~Product();

};

class StoragedProduct : public Product {
    public:
        int quantity;

        StoragedProduct();
        StoragedProduct(int id, std::string name, double price, int quantity);
        ~StoragedProduct();


        bool can_retire(int qty);
        bool retire(int qty);
        void add(int qty);
        void update(StoragedProduct *product);

    
};