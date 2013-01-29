#include<iostream>

using namespace std;

int main() {
    int i = 42;
    int &r = i; // l ref bind to lval: OK
    //int &&r1 = i; //r ref bind to lval: error
    //int &r2 = i * 42; // l ref bind to rval: error
    const int &r3 = i * 42; // l ref bind to const rval: OK
        
    int &&rr1 = 42; //OK
    //int &&rr2 = rr1; //error, rr1 is a variable,and of course a lvalue.
    int &&rr3 = std::move(rr1);
}