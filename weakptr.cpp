#include <iostream>
#include <memory>
#include "strblob.hpp"
#include "strblobptr.hpp"

using namespace std;

int main() {
    //auto p = make_shared<int>(42);
    //weak_ptr<int> wp(p);
    StrBlob b1 = { "a", "an", "the"};
    auto p = b1.begin();
    while(p) {
        cout<<p.deref()<<endl;
        p = p.incr();
    }
}