#include<iostream>
#include<random>
#include<vector>

using namespace std;

vector<unsigned> good_randVec() {
    /*static*/ default_random_engine e;
    /*static*/ uniform_int_distribution<unsigned> u(0, 9);
    vector<unsigned> ret;
    for(size_t i = 0; i < 100; i++) {
        ret.push_back(u(e));
    }
    return ret;
}
bool play(bool who) {
    return true;
}

int main() {
    // default_random_engine e(8);
    // for(int i = 0; i < 10; i++) {
        // cout<<e()<<endl;
    // }

    //uniform_int_distribution<unsigned> u(0,9);
    //uniform_real_distribution<double> u(0,1);
    //uniform_real_distribution<> u(0,1);

//    normal_distribution<> n(4, 1.5);
//    vector<unsigned> vals(9);

    default_random_engine e;
    string resp;
    bernoulli_distribution b;
    do {
        bool first = b(e);
        cout << (first ? "We go first"
                       : "You get to go first") <<endl;
        cout << ((play(first)) ? "sorry, you lost"
                               : "congrats, yhou won") <<endl;
    }while (cin >> resp && resp[0] =='y');

//    for(size_t i = 0; i < 10; i++) {
//        cout << u(e) << " ";
//    }

//    for(size_t i = 0; i != 200; i++) {
//        unsigned v = lround(n(e));
//        if(v < vals.size())
//            ++vals[v];
//    }
//    for(size_t j = 0; j != vals.size(); j++) {
//        cout << j << ": " << string(vals[j], '*') <<endl;
//    }
//    vector<unsigned> v1(good_randVec());
//    vector<unsigned> v2(good_randVec());

//    cout<< ((v1 == v2) ? "equal" : "not equal") << endl;
}
