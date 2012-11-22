#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
using namespace std::placeholders;
bool checkSize(const string &s, string::size_type sz) {
    return s.size() >= sz;
}
void print(string& mystr, const string &s, char c) {
    cout << mystr << s << c;
}
int main()
{
    vector<string> vs = {"zh","bb","cc","yin","zfsfsf"};
    // auto check6 = bind(checkSize, std::placeholders::_1, 6);
    // string s = "hello";
    // cout<<check6(s)<<endl;
    char c = '*';
    string tests = "nihao";
    // capture reference,good
    // for_each(vs.begin(), vs.end(), 
            // [&tests, c] (const string& s) { cout << c << tests <<" " << s <<" "; });
        
    // bind test, good
    for_each(vs.begin(), vs.end(),
            bind(print, ref(tests), _1, ' '));
}