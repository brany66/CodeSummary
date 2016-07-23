#include <iostream>
#include <vector>
using namespace std;
int maxPaLen(string& str);
int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        vector<string> res(N, "");
        for (int i = 0; i < N; i++) {
            cin >> res[i];
        }
        for (int i = 0; i < N; i++) {
            cout << maxPaLen(res[i]) << endl;
        }
    }
    return 0;
}
int maxPaLen(string& str) {
    int strSz = str.size();
    if (strSz <= 1) return strSz;
    int len = strSz*2 + 2;
    int* s = new int[len +1];
    s[0] = '$';
    for (int i =1, j= 0; j < strSz; j++) {
        s[i++] = '#';
        s[i++] = str[j];
    }
    s[len-1]='#';
    s[len]='\0';

    int id = 0;
    int mx = 0;
    int longestNum = 1;
    //int longestId = 0;
    int* p = new int[len];
    for(int i=1; i<len; i++)
    {
        if(mx > i)
            p [i] = min(p[id*2-i], mx - i);
        else
            p[i] = 1;
        while(s[i+p[i]] == s[i-p[i]])
            p[i]++;
        if(p[i]+i>mx)
        {
            mx=p[i]+i;
            id=i;
        }
        if(p[i]>longestNum)
        {
            longestNum=p[i];
           // longestId = i;
        }
    }
    delete[] p;
    delete[] s;
    //cout<<"Longest Palindromic Num:"<<longestnum-1<<endl;
    //cout<<str.substr((longestId-1)>>1-(longestNum-1)>>1,longestNum-1)<<endl;
    return longestNum-1;
}