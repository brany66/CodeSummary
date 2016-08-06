#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
struct node {
    int val;
    bool operator < (const node& a) const {
        return val < a.val ? false : true;
    }
};
class cmp {
public :
    bool operator() (const node &a, const node &b) const {
        return a < b;
    }
};
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
//    std::auto_ptr<string> ps(new std::string(s));
//    std::shared_ptr<string> ps1(new string(s));
//    std::unique_ptr<string> ps2(new string(s));

    priority_queue<node, vector<node>, cmp> q;
    node a, b, c, d;
    a.val = 5;
    b.val = 4;
    c.val = 2;
    d.val = 10;
    q.push(a);
    q.push(b);
    q.push(c);
    q.push(d);
    while (!q.empty()) {
        cout << q.top().val << "  ";
        q.pop();
    }
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