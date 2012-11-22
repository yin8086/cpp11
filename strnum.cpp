#include<iostream>
#include<string>
using namespace std;

int main()
{
	unsigned long a=stoul("1000",0,16);
	int b=stoi("1000");
	double d=stod("3.14");
	string c=to_string(0x20);
	cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
}