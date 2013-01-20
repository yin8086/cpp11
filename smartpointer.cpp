#include<iostream>
#include<memory>
#include<list>
#include<vector>
#include<stdexcept>
using namespace std;

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const {
        return data->size();
    }
    bool empty() const {
        return data->empty();
    }
    void push_back(const std::string &t) {
        data->push_back(t);
    }
    void pop_back();
    
    std::string& front();
    std::string& back();
    
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob():data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il):data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size())
        throw out_of_range(msg);
}
string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}
string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

int main() {
    // 基础知识
    // shared_ptr<string> p1;  //NULL
    // shared_ptr<list<int>> p2;  //NULL
    // shared_ptr<int> p3 = make_shared<int>(42);  // =42
    // cout<<"p3="<<*p3<<endl;
    // shared_ptr<string> p4 = make_shared<string>(10, '9');  // ='9999999999'
    // cout<<"p4="<<*p4<<endl;
    // shared_ptr<int> p5 = make_shared<int>();// =default value 0
    // cout<<"p5="<<*p5<<endl;
    // auto p6 = make_shared<vector<string>>();
    
    // BlobStr 采用shared_ptr<vector>
    StrBlob b1;
    {
        StrBlob b2 = { "a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
    }
    string tmp;
    while( !b1.empty() ) {
        tmp = b1.back();
        cout<<tmp<<endl;
        b1.pop_back();
    }

    //里面参数类似emplace，填入参数为对应类型的构造函数参数
}
    