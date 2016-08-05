#include <iostream>
#include <vector>
#include <windef.h>
#include <winbase.h>
#include <hash_set>
#include <set>
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
    string s;
    set<int> aaa;
    std::auto_ptr<string> ps(new std::string(s));
    std::shared_ptr<string> ps1(new string(s));
    std::unique_ptr<string> ps2(new string(s));

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