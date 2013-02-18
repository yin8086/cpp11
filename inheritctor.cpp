#include<iostream>
#include<memory>
using namespace std;

struct Base1 {
    Base1() = default;
    Base1(const string& rhs) {}
    Base1(std::shared_ptr<int> rhs) {}
};

struct Base2 {
    Base2() = default;
    Base2(const string& rhs) {}
    Base2(std::shared_ptr<int> rhs) {}
};

struct D1:public Base1, public Base2{
    using Base1::Base1;
    using Base2::Base2;
    //必须自己定义
    D1(const string& rhs):Base1(rhs), Base2(rhs) {}
    D1() = default;
};

int main() {

}
