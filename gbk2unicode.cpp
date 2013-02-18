#include<iostream>
#include<fstream>
#include<locale>
#include<cstdlib>
#include<codecvt> //not supported in gcc 4.7.2

using namespace std;


int main(int argc, char* argv[]) {
    setlocale(LC_ALL, ".936");
    
    if(argc < 2) {
        cout <<"*.exe [fileName]";
        return -1;
    }

    ifstream fin(argv[1], ios_base::binary|ios_base::in);
    if(!fin.is_open()) {
        cout<<"read_error"<<endl;
        return -2;
    }

    auto oriC = fin.tellg();
    fin.seekg(0, ios_base::end);
    auto fSize = fin.tellg();
    fin.seekg(oriC);

    char *buf = new char[fSize];
    fin.read(buf, fSize);
    fin.close();

    //supported in vs2010 and above, gcc 4.7.2

    wchar_t *outBuf = new wchar_t[fSize];
    auto len = std::mbstowcs(outBuf, buf, fSize);

    //supported in vs2010 and above, gcc 4.7.2
    ofstream fout(argv[1]+string(".txt"), ios_base::binary|ios_base::out);
    unsigned short BOM = 0xfeff;
    fout.write(reinterpret_cast<char *>(&BOM), 2);
    fout.write(reinterpret_cast<char *>(outBuf), sizeof(wchar_t)*len);
    fout.close();

    //supported in vs2010 and above, not supported in gcc 4.7.2
    wstring outStr(outBuf, len);
    std::wstring_convert<std::codecvt_utf8<wchar_t> > conv1;
    string u8Str = conv1.to_bytes(outStr);
    fout.open(argv[1]+string("u8.txt"), ios_base::binary|ios_base::out);
    fout.write(u8Str.c_str(), u8Str.size());
    fout.close();

    delete[] buf;
    delete[] outBuf;
}
