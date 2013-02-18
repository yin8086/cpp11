#include<iostream>
#include<regex>
#include<exception>

using namespace std;

int main() {
    string pattern = "[^c]ei";
    //pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    pattern = "\\w*" + pattern + "\\w*";
    regex r(pattern);
    smatch results;
    
    string test_str = "receipt freind theif receive";
    try {
        if(regex_search(test_str, results, r))
            cout<<results.str()<<endl;
    }
    catch(regex_error e)
    {
        cout<<e.what()<<" "<<e.code()<<endl;
    }
}