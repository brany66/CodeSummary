#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    unsigned  u = 10;
    int i = -42;
    cout << i + i << endl;
    cout << u + i << endl;
    auto sss = "AAAAAAAAAAAAAAAAAAAAAA";
    string s1(10, 'A');
    for (auto c : s1)
        cout << c << "," ;
    decltype(s1.size()) p = 0;
    string::size_type n;
    vector<int> x;

    vector<int>::iterator it = x.begin();
    auto it1 = x.begin();
    return 0;
}