#include<iostream>
#include<memory>
using namespace std;

int main() {
    allocator<string> alloc;
    int n = 6;
    auto const p = alloc.allocate(n);
    auto q = p;
    alloc.construct(q++);
    alloc.construct(q++, 10, 'c'); // string(10, 'c') constructor
    alloc.construct(q++, "hi"); // string("hi") ctor
    
    for(int i = 0; i < 3; i++ ) {
        cout<<*(p+i)<<endl;
    }
    //构建后必须destroy
    while(q != p) {
        alloc.destroy(--q);
    }
    //destory之后应该deallocate
    alloc.deallocate(p, n);
}