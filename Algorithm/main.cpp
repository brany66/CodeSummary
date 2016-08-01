#include <iostream>
#include <vector>
#include <windef.h>
#include <winbase.h>

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

//    const DWORD busy = 10;
//    const DWORD int idle = busy;
//    INT64 start = 0;
//    while (true) {
//        DWORD start = GetTickCount();
//        while ((GetTickCount() - start) <= busy) ;
//
//        Sleep(idle);
//    }
    return 0;
}