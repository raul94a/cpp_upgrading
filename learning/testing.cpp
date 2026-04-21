#include <iostream>
#include <chrono>
#include <utility>





static int _id = 0;
class Tester {
    private:
        int create_id(){
            return ++_id;
        }
    public:
        int id;
        long long timestamp;
        Tester(){
            using namespace std::chrono;
            int64_t timestamp = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
            this->id = create_id();
            this->timestamp = timestamp;
        }
        Tester& operator=(const Tester& t){
            this->id = t.id;
            this->timestamp = t.timestamp;
            return *this;
        }
        Tester(const Tester& t){
            this->id = t.id;
            this->timestamp = t.timestamp;
        }
        Tester(Tester&& t){
            this->id = t.id;
            this->timestamp = t.timestamp;
            t.id = 0; 
            t.timestamp = 0;
        }
        ~Tester(){}

        void change_id(int id){
            this->id = id;
        }

     
};


void println(std::string str){
    std::cout << str << std::endl;
}

int main() {
    Tester t1 = Tester();

    using namespace std;
    cout << "ID de t1 es " << t1.id << endl;
    cout << "Moviendo t1 a t2" << endl;
    Tester t2 = std::move(t1);
    cout << "ID de t1 es " << t1.id << endl;
    cout << "address de t1.id es " << &t1.id << endl;

    //t2.change_id(9999);
    cout << "ID de t2 es " << t2.id << endl;
    cout << "address de t2.id es " << &t2.id << endl;

    size_t size = 100000;
    vector<Tester> v1(size);
    println("Preparando vector de tamaño " + to_string(sizeof(v1)));
    
    v1[0] = Tester();
    v1[size - 1] = Tester();
    println(to_string(v1[0].id));
    println(to_string(v1[size - 1].id));

    auto now = std::chrono::high_resolution_clock::now();

    vector<Tester> v2 = v1;

    auto endCopy = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double,std::milli> delta = endCopy - now;
    std::cout << "Tiempo de copia " << delta.count() << " ms." << std::endl;
    
    now = std::chrono::high_resolution_clock::now();
    //std::cout << "[Premove]Address id en v1 para elemento 0: " << &(v1[0].id) << std::endl;

    vector<Tester> v3 = std::move(v1);
    //std::cout << "Address id en v3 para elemento 0: " << &(v3[0].id) << std::endl;
    //std::cout << "Address id en v1 para elemento 0: " << &(v1[0].id) << std::endl;
    //std::cout << "id en v3 para elemento 0: " << (v3[0].id) << std::endl;
   // std::cout << "id en v1 para  elemento 0: " << (v1[0].id) << std::endl;

    auto endMove = std::chrono::high_resolution_clock::now();
    delta = endMove - now;
    std::cout << "Tiempo de mover " << delta.count() << " ms." << std::endl;

    return 0;
}
