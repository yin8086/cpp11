#include<iostream>
#include<fstream>
#include<locale>
#include<cstdlib>

using namespace std;

void printStr(string&& rhs) {
    for(auto c: rhs) {
        cout<<sizeof(c)<<" "<<hex<<(unsigned short)c<<" ";
    }
}


void printStr(wstring&& rhs) {
    for(auto c: rhs) {
        cout<<sizeof(c)<<" "<<hex<<int(c)<<" ";
    }
}

void printStr(u16string&& rhs) {
    for(auto c: rhs) {
        cout<<sizeof(c)<<" "<<hex<<int(c)<<" ";
    }
}

void printStr(u32string&& rhs) {
    for(auto c: rhs) {
        cout<<sizeof(c)<<" "<<hex<<int(c)<<" ";
    }
}





int main(int argc, char *argv[]) {

    auto str1 = "中国";
    auto str2 = L"中国";
    auto str3 = u"中国";
    auto str4 = U"中国";
    auto strU8 = u8"中国";
    const char* mbstr = u8"z\u00df\u6c34\U0001d10b";

    char *testRaw = R"a(
<html>
    <head>
    </head>
            ()
    <body>
    </body>
</html>)a";

    cout <<str1 <<endl
        <<str2 <<endl
       <<str3 <<endl
      <<str4 <<endl <<strU8 <<endl
        <<mbstr<<endl;
    cout<<testRaw<<endl;
    printStr(str1);
    cout<<endl;
    printStr(str2);
    cout<<endl;
    printStr(str3);
    cout<<endl;
    printStr(str4);
    cout<<endl;
    printStr(strU8);
    cout<<endl;
}
