#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    //vector<string> vs = {"zh","bb","cc","yin","zfsfsf"};
    vector<int> vi={1,-3,4,-5,6};
    // Capture List
    /* int sz = 3;
    auto wc = find_if(vs.begin(),vs.end(),
            // [sz](const string &a)
            [=](const string &a)
            { return a.size() >= sz; } );
    cout<<*wc<<endl; */
        
    // Capture time
    /* size_t v1 = 42;
    // auto f = [v1] { return v1; } ;
    auto f = [v1] () mutable { return ++v1; } ;
    v1 = 0;
    cout<<f()<<" "<<v1<<endl;  */
    
    transform(vi.begin(), vi.end(), vi.begin(),
             // [](int i) { return i < 0 ? -i : i;});
            //[](int i) { if (i < 0) return -i; else return i;}); //据Primer讲无法推断，但gcc 4.7.0可以
            [](int i) -> int { if (i < 0) return -i; else return i;}); 
    for(int x :vi) {
        cout<<x<<" ";
    }
    
    
}