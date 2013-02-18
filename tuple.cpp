#include<iostream>
#include<tuple>
#include<vector>
#include<list>

using namespace std;

int main() {
    //tuple<size_t, size_t, size_t> threeD;
    //tuple<size_t, size_t, size_t> threeD = {1, 2, 3}; //不可以，这个事隐式
    tuple<size_t, size_t, size_t> threeD{1, 2, 3}; //可以，这个调用initialize_list版本ctor
    tuple<string, vector<double>, int, list<int>> someVal(
            "constants",
            {3.14, 2,718},
            42,
            {0, 1, 2, 3, 4, 5});
    //构造函数为explicit，因此必须显示调用.
    
    auto item  = make_tuple("0-999-999", 6, 20.00);
    auto book  = get<0>(item);
    auto cnt   = get<1>(item);
    auto price = get<2>(item) / cnt;
    cout<<book<<" "<<cnt<<" "<<price<<endl;
    get<2>(item) *= 0.8;
    cout<<book<<" "<<cnt<<" "<<get<2>(item)<<endl;
    
    typedef decltype(item) trans;
    size_t sz = tuple_size<trans>::value;
    tuple_element<1, trans>::type cnt2 = get<1>(item);
    cout<<sz<<" "<<cnt2<<endl;
            
    
}