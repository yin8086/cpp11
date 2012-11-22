#include<typeinfo>
#include<iostream>
using namespace std;

int main()
{
    const int i=42;
    auto j=i;
    cout<<"Type of j:"<<typeid(j).name()<<endl;
    const auto &k=i;
    cout<<"Type of k:"<<typeid(k).name()<<endl;
    auto *p=&i;
    cout<<"Type of p:"<<typeid(p).name()<<endl;
    const auto j2=i,&k2=i;
    cout<<"Type of j2:"<<typeid(j2).name()<<endl;
    cout<<"Type of k2:"<<typeid(k2).name()<<endl;
}