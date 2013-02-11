#include<iostream>

using namespace std;

template<typename T>
ostream &print(ostream &os, const T &t) {
    return os<<t;
}

template<typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest) {
    os<<t<<", ";
    //递归调用本函数，进行参数拆包
    return print(os, rest...);
}
int main() {
    int i = 88;
    string s = "nihao";
    print(cout, i, s, 42);
}