#include<iostream>
#include<mutex>

struct Complex {
    //std::mutex mutex;
    std::recursive_mutex mutex;
    int i;

    Complex() : i(71) {}

    void mul(int x){
        //std::lock_guard<std::mutex> lock(mutex);
        std::lock_guard<std::recursive_mutex> lock(mutex);
        i *= x;
    }

    void div(int x){
        //std::lock_guard<std::mutex> lock(mutex);
        std::lock_guard<std::recursive_mutex> lock(mutex);
        i /= x;
    }
    void both(int x, int y){
        //std::lock_guard<std::mutex> lock(mutex);
        std::lock_guard<std::recursive_mutex> lock(mutex);
        mul(x);
        div(y);
    }

};

int main(){
    Complex complex;
    complex.both(32, 23);
    // can not recursively lock()
    std::cout << complex.i <<std::endl;
    return 0;
}
