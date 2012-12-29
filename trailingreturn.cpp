#include<iostream>
using namespace std;

int odd[] = {1, 3, 5, 7, 9};

decltype(odd) *arrPtr(int i);
auto func(int i) -> int(*)[5];

int main()
{
    auto tmp1 = arrPtr(3);
    auto tmp2 = func(3);
    for(auto i: *tmp1)
    {
        printf("%d ", i);
    }
    for(auto i: *tmp2)
    {
        printf("%d ", i);
    }
}

decltype(odd) *arrPtr(int i)
{
    return &odd;
}

auto func(int i) -> int(*)[5]
{
    return &odd;
}