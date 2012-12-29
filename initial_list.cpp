#include<iostream>
#include<string>
#include<cstdarg>
using namespace std;
void error_message(initializer_list<string> pal)
{
    for(auto str:pal)
        cout<<str<<' ';
    cout<<endl;
}
void message2(const char* str1, ...)
{
    va_list ap;
    va_start(ap,str1);
    cout<<str1<<' ';
    while(true)
    {
        string tmpstr(va_arg(ap,const char*));
        cout<<tmpstr<<' ';
        if(tmpstr=="998"||tmpstr=="886")
            break;
    }
    cout<<endl;
}
int main()
{
    int getin=0;
    while(cin>>getin)
    {
        if(getin==-1) break;
        else
        {
            if(getin>5)
            {
                error_message({"Hello","Shabi","886"});
                message2("Hello","Shabi","886");
            }
            else
            {
                error_message({"Shabi","DaShabi","998"});
                message2("Shabi","DaShabi","998");
            }
        }
    }
}