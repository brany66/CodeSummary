//
// Created by BranY on 2016/7/31.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;
//1 :判断奇偶 a&1 == 1 为奇数
void swap(int &a, int &b) {
    if (a != b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
}
int changeSign(int a) {
    return ~a + 1;
}
int my_abs(int a) {
    int i = a >> 31;
    return i == 0 ? a : (~a + 1);
}
/**
 * 数组中只出现一次的两个数字，其他的都出现了两次
 * @return
 */
void findTwoNotRepeat(vector<int>& a, int &PN1, int &PN2) {
    int i, j, tmp;
    tmp = 0;
    int n = a.size();
    for (i = 0; i< a.size(); i++)
        tmp ^= a[i];

    //找第一个为1的位
    for (j = 0; j < sizeof(int) * 8; j++)
        if ( ((tmp >> j) & 1) == 1)
             break;
    PN1 = 0;
    PN2 = 0;
    for (i = 0; i < n; i++) {
        if ((a[i] >> j)  &1 == 0)
            PN1 ^= a[i];
        else
            PN2 ^= a[i];
    }
}
/**
 * 数组中除了一个数字外，其他数都出现了三次
 * @return
 */
int findNotRepeatNum(vector<int>& a, int times) {
    int i, j, n = a.size();
    vector<int> bits(32, 0);
    for (i = 0; i < n; i++)
        for (j = 0; j < 32; j++)
            bits[j] += ((a[i] >> j) & 1);
    int res = 0;
    for (j = 0; j < 32; j++) {
        if (bits[j] % times != 0)
            res += (1 << j);
    }
    return res;
}
uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    uint32_t A[32];
    for (int i = 31; i>=0; i--)
        A[31-i] = pow(2.0, i);
    for (int j = 0; j< 32; j++) {
        if (n & 1) {
            res += A[j];
        }
        n >>= 1;
    }
    return res;
}
/**
 * https://leetcode.com/problems/repeated-dna-sequences/
 * Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * Return:
 * ["AAAAACCCCC", "CCCCCAAAAA"].
 * @param s
 * @return
 */
vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> m;
    vector<string> res;
    int t = 0, i = 0, ss = s.size();
    while (i < ss) {
        if (m[t = (t << 3 | s[i++]) & 0x3FFFFFFF]++ == 1)
            res.push_back(s.substr(i-10, 10));
    }
    return res;
}
vector<string> findRepeatedDnaSequences_2(string s) {
    vector <string>  ans;
    map <int,int> mp;
    map <char,int> cur;
    set<string> st;
    cur['A'] = 0;
    cur['T'] = 1;
    cur['C'] = 2;
    cur['G'] = 3;
//    if (s.length() < 10)
//        return ans;

    int temp = 0;
    for(int i = 0;i < 10;i++)
    {
        temp <<= 2;
        temp |= cur[s[i]];
//        cout << temp << endl;
    }
   //cout << temp << " ****** " << endl;
    mp[temp]++;
    for(int i = 10;i < s.length(); i++)
    {
        temp <<= 2;
        temp |= cur[s[i]];
        temp &= ~(0x300000);//去掉最高的2位
        mp[temp]++;
        if(mp[temp] >= 2)
            st.insert(s.substr(i-9,10));
    }
    set<string>::iterator it;
    for(it = st.begin(); it!= st.end(); it++)
        ans.push_back(*it);

    return ans;
}
/**
 * 78:https://leetcode.com/problems/subsets/
 * subsets
 * @return
 */
void helper(vector<int>& nums, vector<int> tmp, int i , vector<vector<int>>& ans) {
    if (i == nums.size()) {
        ans.push_back(tmp);
        return;
    }
    tmp.push_back(nums[i]);
    helper(nums, tmp, i+1, ans);
    tmp.erase(tmp.end() - 1);
    helper(nums, tmp, i+1, ans);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    vector<int> tmp;
    helper(nums, tmp, 0, ans);
    return ans;
}
vector<vector<int>> subsets_2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = pow(2, nums.size());
    vector<vector<int>> ans(n, vector<int>());
    for (int i = 0; i < nums.size(); i++)
    {

        for (int j = 0; j < n; j++)
        {
            if ((j >> i) & 1 == true)
                ans[j].push_back(nums[i]);
        }
    }
    return ans;
}
int main()
{
    vector<int> test{1,2,3,1,4,3,5,4,1,2,3,2,4};
    cout << findNotRepeatNum(test, 3) << endl;
//    int n;
//    cin >> n;
//    cout << reverseBits(n) << endl;

    string testS = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    cout << "ATCG\n";
    vector<string> res = findRepeatedDnaSequences_2(testS);
    for (auto a : res)
        cout << a << " ";
    cout << endl;

    vector<int> list{1,2, 3};
    vector<vector<int>> ans = subsets_2(list);
    for(auto c : ans) {
        cout << "[";
        if (c.size() != 0) {
            for(auto a: c)
                cout << a << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}