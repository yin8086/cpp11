#include<iostream>
#include<vector>
using namespace std;

struct People
{
	string name="";
	int old=0;
	People(string n,int o):name(n),old(o){}
};
int main()
{
	vector<People> vp;
	vp.push_back(People("nihao",3));
	vp.emplace_back("zaijian",7);
	for(auto vpe:vp)
	{
		cout<<vpe.name<<' '<<vpe.old<<endl;
	}
}