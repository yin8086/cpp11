#pragma once
#include<vector>
#include<string>
#include<stdexcept>
using namespace std;

class StrBlobPtr;
class StrBlob {
    friend class StrBlobPtr;
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
    StrBlobPtr begin() {
        return StrBlobPtr(*this);
    }
    StrBlobPtr end() {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }
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
