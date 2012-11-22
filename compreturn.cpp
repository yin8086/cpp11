#include<iostream>
using namespace std;
int odd[]={1,3,5,7,9};
int even[]={2,4,6,8,10};
auto func(int i)->int (*)[5]
{
    return (i%2) ? &odd :&even;
}
decltype(odd) *func2(int i)
{
    return (i%2) ? &odd :&even;
}
int main()
{
    cout<<"auto 3:"<<endl;
    int *pi,i;
    // for(i=0,pi=*func(3);i<sizeof(pi);i++)
        // cout<<pi[i]<<' ';
    for(auto al:(*func(3)))
        cout<<al<<' ';
    cout<<endl;
    cout<<"auto 6:"<<endl;
    // for(i=0,pi=*func(6);i<sizeof(pi);i++)
        // cout<<pi[i]<<' ';
    for(auto al:(*func(6)))
        cout<<al<<' ';
    cout<<endl;
    cout<<"decltype 7:"<<endl;
    // for(i=0,pi=*func2(7);i<sizeof(pi);i++)
        // cout<<pi[i]<<' ';
    for(auto al:(*func2(7)))
        cout<<al<<' ';
    cout<<endl;
    cout<<"decltype 8:"<<endl;
    // for(i=0,pi=*func2(8);i<sizeof(pi);i++)
        // cout<<pi[i]<<' ';
    for(auto al:(*func2(8)))
        cout<<al<<' ';
    cout<<endl;
    
}