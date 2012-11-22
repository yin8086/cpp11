#include<iostream>
using namespace std;

class Debug
{
    bool sex;
    bool iq;
public:
    constexpr Debug(bool s=true):sex(s),iq(false){}
    constexpr Debug(bool s,bool i):sex(s),iq(i){}
};
constexpr int getinfo(Debug now)
{
	//cout<<"test"<<endl;
	return 1;
}
int main()
{
    constexpr Debug newp(true,false);
	constexpr int m=getinfo(newp);
	cout<<"end"<<endl;
}