#include<iostream>
#include<memory>
using namespace std;

int main() {
    unique_ptr<string> p1(new string("nihao"));
    cout<<*p1<<endl;
    unique_ptr<int> p2(new int(42));
    cout<<*p2<<endl;
    unique_ptr<string> p3(p1.release());
    cout<<*p3<<endl;
    unique_ptr<string> p4(new string("Trex"));
    cout<<*p4<<endl;
    p3.reset(p4.release());
    cout<<*p3<<endl;
}