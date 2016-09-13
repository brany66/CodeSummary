//
// Created by BranY on 2016/8/14.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;
long long  numTrees(int n) {
    if (n <= 0) return 0;
    long long  part1 = 1, part2 = 1;
    int i;
    for (i = 2 * n; i > 1; --i) part1 *= i;
    for (i = n; i > 1; --i) part2 *= i;
    part1 /= part2;
    part1 /= part2;
    part1 /= n+1;
    return part1;
}
int numTrees_2(int n) {
    if(n <= 0){
        return 0;
    }
    vector<int> f(n + 1);
    f[0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            f[i] += f[j - 1] * f[i - j];
        }
    }
    return f[n];
}


int result[25001];
void sovle(int n)
{
    int i,j,len,carry,current;
    result[0] = 1;
    len = 1;
    for (i = 2;i <= n; i++) {
        carry = 0;
        for (j = 0;j < len; j++) {
            current = result[j];
            result[j] = (i*current+carry)%10;
            carry = (current*i+carry)/10;
        }
        while (carry>0){
            current = carry;
            carry = current/10;
            result[len] = current%10;
            len++;
        }
    }

    for (i = len-1;i >= 0; --i){
        cout << result[i];
    }
    cout << endl;
}
int countWays(int n) {
    // write code here
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 2;
    int a = 1, b = 2;
    int res;
    int mod = 1000000007;
    for (int i = 4; i <= n; i++) {
        res = (a + b) % mod;
        a = b % mod;
        b = res % mod;
    }
    return res % mod;
}

double cal(int n) {
    if(n==0)
        return 0;
    // return n+n/2+getDistance(n/2);
    double result = 0.0;

    while(n!=0){
        result +=n + n/2;
        n/=2;
    }
    return result;
}
int calcDistance(int A, int B, int C, int D) {
    // write code here
    int res = 0;
   // res += cal(A) + cal(B) + cal(C) + cal(D);
    return 3 * ( A + B + C + D);
}
//
class A{
public:
    virtual ~A() {
        cout << "AAAA" << endl;
    }
};
class B: public A {
public:
    ~B() {
        cout << "BBBB" << endl;
    }
};
#define AA 4 + 5
#define BB AA * AA

int f(int a, int b, int c) {
    return  0;
}
int x= 4;
void incre() {
    static int x=1;
    x *= x+1;
    cout << x << endl;
}
enum etest {
    e1,
    e2,
    e3 = 10,
    e4,
    e5 = 'a',
    e6
}epr;
struct testA {
    char ch;
    int a;
    short s;


};
struct st_t {
    int st;
    short *pda;
    char err[32];
};
class X {
public:
    void x00() {}
};
//值类型和引用类型
// 子进程继承了父进程的那些
// CPU使用率过高，load过高的原因


int main() {
    char str[10] = "abcdefg";
    strcpy(str, "123456");
    memcpy(str, "147258", 5);
    cout << str << endl;

    cout << sizeof(X) << endl;
    st_t st[16];
    char *p = (char*)(st[2].err + 32);
    cout << (p - (char*)(st)) << endl;

    cout << pow(3,4) << endl;
//    const int N = 10;
//    const int M = 2;
//    int *a = new int[N];
//    for (int i = 0; i < N; i++)
//        a[i] = (0 == i%2) ?i+2 : i+0;
//    int (*b)[N/M] = (int(*)[N/M])a;
//    for (int i = 0; i < M; ++i)
//        for (int j = 0; j < N/M; ++j)
//            cout << b[i][j];
//    cout << endl;

    //cout << sizeof(testA) << endl;

    //cout << e4 <<  " " << e6 << endl;

    //char *p[] = {"TENCENT", "CAMPUS", "RECUR"};
   // char **pp[] = {p+2, p+1, p};
    //char  ***ppp = pp;
    //cout << **++ppp << "  " << *++*++ppp << endl;


    //for (int i = 1; i < x; i++)
    //    incre();
    //return f(printf("a"), printf("b"), printf("c"));
    //cout << BB * BB << endl;
    //A *p = new B();
   // delete p;

//    int N;
//    cout << ceil(2.5) <<  " " << ceil(7.25) <<  " " << ceil(4.6) << endl;
//    cout << floor(2.5) << " " << floor(7.25) <<  " " << floor(4.6) << endl;
//    cout << cal(8) << endl;
//    cout << "res  " << calcDistance(100, 90, 80, 70) << endl;
//    while (cin >> N) {
//        //cout << numTrees(N) << "   " << numTrees_2(N)<< endl;
//        cout << countWays(N) <<  endl;
//    }

    return 0;
}

