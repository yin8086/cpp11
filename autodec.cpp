#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> av={1,2,3,4,5};
    auto len=av.size();
    for(auto ai:av)
        cout<<ai<<' ';
    cout<<endl;
    int aba[]={3,4,6,3,6,7};
    for(auto i=begin(aba);i<end(aba);i++)
        cout<<*i<<' ';
    cout<<endl;
    int ma[][3]={{8,9,10},{3,4,5},{7,5,6}};
    for(auto &line:ma)
    {
        for(auto ele:line)
        {
            cout<<ele<<' ';
        }
        cout<<endl;
    }
}