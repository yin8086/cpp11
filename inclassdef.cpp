#include<iostream>
using namespace std;
struct Sales_data
{
    int mema=4;
    float memb{4.34};
    Sales_data()=default;
    Sales_data(int a, float b):mema(a),memb(b){}
};

int main()
{
    Sales_data sa;
    Sales_data sb(5,3.55);
    cout<<sa.mema<<' '<<sa.memb<<endl;
    cout<<sb.mema<<' '<<sb.memb<<endl;
}