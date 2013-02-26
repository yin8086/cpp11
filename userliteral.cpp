#include<iostream>

using namespace std;


// used as conversion
inline constexpr long double operator"" _deg ( long double deg )
{
    return deg*3.141592/180;
}

void operator"" _print ( const char* str )
{
    std::cout << str;
}

int main() {
    double x = 90.0_deg; // x = 1.570796
    cout<<x<<endl;
    0x123ABC_print;
}
