#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <random>
#include <string>

using namespace std;

mutex m; 

void compute(int seconds, unsigned int *data){
    std::random_device rd; 
    std::uniform_int_distribution<> distrib(1, 100);
    std::mt19937 gen(rd()); 
    unsigned int rand_base = seconds;
    int rand = distrib(gen);

    
    unique_lock<mutex> lock { m };
    cout << "compute() in thread " << this_thread::get_id() 
    << " waiting for " << seconds << " s. for modifying " << *data << ""
    << endl;
    cout << " number selected for thread " << this_thread::get_id() << " is " << rand << endl;
    if(true) this_thread::sleep_for(
        chrono::duration_cast<chrono::milliseconds>(chrono::seconds(seconds))
    );
    cout << "New data is " << rand << " updating...";
    *data = rand;
    cout << "compute() finished" << " for thread "  << this_thread::get_id() << endl;
    
}

int main(){

    unsigned int data = 100;
    thread t1 {compute, 20, &data};
    thread t2 {compute, 1, &data};

    t1.join();
    t2.join();

    return 1;
}