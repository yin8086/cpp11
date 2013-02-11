#include<iostream>

using namespace std;



template<typename T> class Pal;

class C {
    friend class Pal<C>;
    template<typename T> friend class Pal2;
public:
    C():i(23) {}
private:
    int i;
};

template<typename T> class C2 {
    friend T;
    friend class Pal<T>;
    template<typename X> friend class Pal2; // X必须不同，且由于是所有实例无需前置声明
    friend class Pal3;
public:
    C2():i(25) {}
private:
    int i;
};

template<typename T> class Pal {
public:
    void output(const C &rhs) {
        cout<<rhs.i<<endl;
    }
    void output(const C2<T> &rhs) {
        cout<<rhs.i<<endl;
    }
private:
    int i;
};

template<typename T> class Pal2 {
public:
    void output(const C &rhs) {
        cout<<rhs.i<<endl;
    }
    template<typename X> void output(const C2<X> &rhs) {
        cout<<rhs.i<<endl;
    }
private:
    int i;
};
class Pal3 {
public:
    template<typename T> void output(const C2<T> &rhs) {
        cout<<rhs.i<<endl;
    }    
};
int main() {
    C objC;
    C2<C> objC2;
    Pal<C> objP; 
    Pal2<int> objP2;
    Pal3 objP3;
    objP.output(objC); //Pal<C>是C的友元，nontemplate指定template实例
    objP.output(objC2); //Pal2<C>是C2<C>的友元，template间一一对应
    objP2.output(objC); //Pal2<*>为C的友元
    objP2.output(objC2); //每一个C2的实例，都有所有的Pal2 template实例作为友元
    objP3.output(objC2); //Pal3为所有C2市里的友元
}