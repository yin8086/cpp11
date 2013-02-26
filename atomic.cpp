#include <iostream>
#include <atomic>
#include <thread>
#include <vector>


struct Counter {
    int value;

    void increment(){
        ++value;
    }

    void decrement(){
        --value;
    }

    int get(){
        return value;
    }

    void set(int &&rval) {
        value = rval;
    }
};

struct AtomicCounter {
    std::atomic<int> value;

    void increment(){
        ++value;
    }

    void decrement(){
        --value;
    }

    int get(){
        return value.load();
    }
    void set(int&& rval) {
        value.store(rval);
    }
};
int main() {
    AtomicCounter ac;
    ac.set(34);

    Counter ct;
    ct.set(34);

    std::vector<std::thread> threads;
    for(int i = 0; i < 5; ++i){
        threads.push_back(std::thread([&ct](){
            for(int i = 0; i < 10000; ++i){
                ct.increment();
            }
        }));
    }

    for(auto& thread : threads){
        thread.join();
    }

    std::cout <<ct.get() <<std::endl;
}


