#include<iostream>
using namespace std;

class Foo {
public:
    Foo() = default;
    Foo(const Foo&) = default;
};

int main() {
    Foo x;
    Foo y(x);
    Foo z(std::move(x));
}