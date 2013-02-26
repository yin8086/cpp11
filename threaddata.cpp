#include<iostream>
#include<vector>
#include<thread>
#include<mutex>

struct Counter {
    int value;
    //std::mutex mutex;

    void increment(){
        //mutex.lock();
        ++value;
        //mutex.unlock();
    }
    void decrement() {
        --value;
    }

};
struct CounterConcurrent {
    std::mutex mutex;
    Counter counter;

    void increment() {
        std::lock_guard<std::mutex> guard(mutex);
        counter.increment();
    }

    void decrement() {
        std::lock_guard<std::mutex> guard(mutex);
        counter.decrement();
    }
};

int main(){
    //Counter counter;
    CounterConcurrent ccer;
    std::vector<std::thread> threads;
    for(int i = 0; i < 5; ++i){
        threads.push_back(std::thread([&ccer](){
            for(int i = 0; i < 100; ++i){
                //counter.increment();
                ccer.increment();
            }
        }));
    }

    for(auto& thread : threads){
        thread.join();
    }

    std::cout << ccer.counter.value << std::endl;

    return 0;
}
