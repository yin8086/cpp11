#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vi;
    vi={3,3,2,5,7,4};
    for(auto &vie:vi)
    {
        //cout<<vie<<' ';
        vie=4;
    }
    cout<<endl;
    for(auto vie:vi)
    {
        cout<<vie<<' ';
    }
    cout<<endl;
}
