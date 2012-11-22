#include<typeinfo>
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    /*
    int i=42,*p=&i;
    decltype(i+0) b;
    decltype(*p) c=i;
    decltype((i)) d;
    decltype(i) e;
    */
    int a=3,b=4;
    decltype(a) c=a;
    //decltype((b)) d=a;
    decltype(a=b) d=a;
    printf("a=%d,b=%d,c=%d,d=%d\n",a,b,c,d);
    c+=2;d+=5;
    printf("a=%d,b=%d,c=%d,d=%d\n",a,b,c,d);
}