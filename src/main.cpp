#include <string>
#include <iostream>
#include "product.h"
using namespace std;
int main(){

    string str = "ejemplo";
    string sub = "empl";
    int index = str.find(sub,0);
    cout << "\nEl indice donde se encuentra la subcadena " << sub << " en ";
    cout << str << " es " << index;
    cout << endl;
    cout << "Puedo obtener la subcadena usando el índice y la longitud de la subcadena => ";
    cout << str.substr(index, sub.length());
    cout << "\n" << endl;

    // podría hacerse así, pero cuando inicializamos el vector son copiadas y es un malgasto de recursos
    // Product pr1 = Product(1,"camiseta", 99.99);
    // Product pr2 = Product(2,"camiseta algodon", 99.99);
    // Product pr3 = Product(3,"pantalones", 99.99);
    vector<Product> products;
    // si sabemos de antemano el número de elementos, podemos reservar memoia
    products.reserve(3);
    // con emplace_back creamos el objeto directamente en el vector
    products.emplace_back(1,"camiseta", 99.99);
    products.emplace_back(2,"camiseta algodon", 99.99);
    products.emplace_back(3,"pantalones", 99.99);
    try{
        
    
        string to_search = "seta";
        cout << "Buscando " << to_search <<endl;
        for(auto& pr: products){
            if(pr.name.find(to_search) != string::npos){
                cout << "Coincidencia para el producto con id " << pr.id << endl;
            }
            else {
               // throw out_of_range("FUCK!");
               cout << "No se ha encontrado coincidencia para " << pr.name << endl;
            }
        }
    } catch(out_of_range& M){
        cout << "out of range exception: finishing program\n" << M.what() << endl;
        return 1;
    }
    cout << "Finish search\n"<<endl;


    return 0;
}