#include<iostream>

using namespace std;

int main() {
    enum color { red, yellow, green};
    //enum light { red, yellow, green};
    enum class peppers {red, yellow, green};
    color eyes = green;
    //peppers p = green;
    color hair = color::red;
    peppers p2 = peppers::red;
}
