//
// Created by BranY on 2016/7/23.
// Contact at wyang@smail.nju.edu.cn
//
#include <iostream>
#include <vector>

using namespace std;
/**
 * Optimal Binary Search Tree
 * Page 212
 * Let n 个互异的关键字组成的序列K=<k1,k2,...kn>, 对每个关键字ki, 一次搜索ki的概率为pi
 * qi表示位于ki ~ ki+1间的概率
 * Let： e[i,j]表示搜索关键字ki~kj的最优二叉查找树的希望代价， e[1,n]
 * 1. if j=i-1, 此时只有虚拟键di-1, So, e[i,i-1]=qi-1
 * 2. if j >= i, 需要从关键字ki~kj选择一个根kr ：w(i,j) = sum(p[i,j]) + sum(q[i,j]) = w[i,r-1] + pr + w[r+1, j]
 *    e[i,j] = pr + (e[i,r-1] + w(i, r-1)) + (e[r+1,j] + w(r+1,j))
 *           = e[i,r-1] + e[r+1,j] + w[i,j]
 * e[i,j] = q[i]								if i == j
 *          min{e[i,r] + e[r+1,j] + w(i, j) 	if i <= j, 其中i<=r<j
 *
 * 其中w(i,j) = sum[i <= l < j] p[l] + sum[i<=l<=j]q[l]
 */
double optimal_BST(vector<double>& p1, vector<double>& q1) {
    vector<vector<double>> e(p1.size() + 1, vector<double>(p1.size()+ 1));
    vector<vector<double>> w(p1.size() + 1, vector<double>(p1.size()+ 1));

    for (int i = 0; i < e.size(); i++) {
        e[i][i] = q1[i];
        w[i][i] = q1[i];
    }

    for (int d = 1; d <= e.size(); d++) {
        for (int i = 0; i + d < e.size(); i++) {
            int j = i + d;

            w[i][j] = w[i][j-1] + p1[j-1] + q1[j];
            double min = e[i][i] + e[i+1][j] + w[i][j];
            for (int r = i + 1; r < j; r++) {
                double v = e[i][r] + e[r+1][j] + w[i][j];
                if (min > v) {
                    min = v;
                }
            }
            e[i][j] = min;
        }
    }

    return e[0][e.size() - 1];
}
int main()
{
    //p 关键字出现的概率
    //q 关键字不出现的概率

    vector<double> p1{0.15, 0.10, 0.05, 0.10, 0.20},
            q1{0.05, 0.10, 0.05, 0.05, 0.05, 0.10};

    vector<double> p2{0.04, 0.06, 0.08, 0.02, 0.10, 0.12, 0.14},
            q2{0.06, 0.06, 0.06, 0.06, 0.05, 0.05, 0.05, 0.05};

    cout << optimal_BST(p1, q1) << " " << optimal_BST(p2, q2) << endl;
    return 0;
}