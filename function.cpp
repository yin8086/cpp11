#include<iostream>
#include<functional>
#include<map>
using namespace std;


int Add(int i, int j) {
    return i + j;
}
auto Mod = [](int i, int j) {
    return i % j;
};

struct Div {
    int operator()(int den, int divisor) {
        return den / divisor;
    }
};

int main() {
    function<int(int, int)> f1 = Add;
    function<int(int, int)> f2 = Mod;
    function<int(int, int)> f3 = Div();
    map<string, function<int(int, int)>> binops = {
        { "+", Add },
        { "-", std::minus<int>() },
        { "/", Div() },
        { "*", [](int i, int j) {
            return i * j;
            } },
        { "%", Mod }
    };

    // cout<<f1(4, 2)<<endl;
    // cout<<f2(8, 3)<<endl;
    // cout<<f3(9, 3)<<endl;
    cout<<binops["+"](10, 5)<<endl;
    cout<<binops["-"](10, 5)<<endl;
    cout<<binops["*"](10, 5)<<endl;
    cout<<binops["/"](10, 5)<<endl;
    cout<<binops["%"](10, 5)<<endl;
    
}
