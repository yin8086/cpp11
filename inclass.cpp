#include<cstdio>
using namespace std;
struct Test
{
    int mema=4;
    float memb{4.34};
};
int main()
{
    Test a;
    printf("a.mema=%d,a.memb=%f\n",a.mema,a.memb);
}