//
// Created by BranY on 2016/7/23.
// Contact at wyang@smail.nju.edu.cn
//
/**
 * 它用于寻找最有可能产生观测事件序列的-维特比路径-隐含状态序列,特别是在马尔可夫信息源上下文和隐马尔可夫模型中。
 * 术语“维特比路径”和“维特比算法”也被用于寻找观察结果最有可能解释相关的动态规划算法。
 * http://www.jianshu.com/p/218c1e4f0891
 * 以下是具体的做法：
 * 1. 从点S出发。对于第一层的4个节点，算出它们的距离d(S,A1),d(S,A2),d(S,A3),d(S,A4)，因为只有一步，所以这些距离都是S到它们各自的最短距离。
 * 2. 对于B层的所有节点(B1,B2,B3,B4)，要计算出S到它们的最短距离。
 *   我们知道，对于特定的节点B2，从S到它的路径可以经过A层的任何一个节点(A1,A2,A3,A4)
 *   对应的路径长就是d(S,B2)=d(S,Ai)+d(Ai,B2)(其中i=1,2,3,4)
 *   由于A层有4个节点（即i有4个取值），我们要一一计算，然后找到最小值。这样，对于B层的每个节点，都需要进行4次运算，而B层有4个节点，所以共有4X4=16次运算。
 * 3. 这一步是该算法的核心。我们从2计算得出的结果只保留4个最短路径值（每个节点保留一个）。
 *    那么，若从B层走向C层来说，该步骤的基数已经不再是4X4，而是变成了4！也就是说，
 *    从B层到C层的最短路径只需要基于B层得出的4个结果来计算。这种方法一直持续到最后一个状态，
 *    每一步计算的复杂度为相邻两层的计算复杂度为4X4乘积的正比！再通俗点说，连接这两两相邻层的计算符合变成了“+”号，
 *    取代了原先的“X”号。用这种方法，只需进行4X4X2=32次计算！
 *
 */
#include <iostream>
const int x = 9999;
using namespace std;
#define max 9999
int data[10][10];
int dist[10];//记录最短路径为多少
int path[10];//记录最短路径
int kmin(int,int);
void fpath(int a[][10]);
int froute(int a[][10]);

int main()
{
    int i,m;
    int a[10][10]=
            {
                    {x,4,2,3,x,x,x,x,x,x},
                    {x,x,x,x,10,9,x,x,x,x},
                    {x,x,x,x,6,7,10,x,x,x},
                    {x,x,x,x,x,3,8,x,x,x},
                    {x,x,x,x,x,x,x,4,8,x},
                    {x,x,x,x,x,x,x,9,6,x},
                    {x,x,x,x,x,x,x,5,4,x},
                    {x,x,x,x,x,x,x,x,x,8},
                    {x,x,x,x,x,x,x,x,x,4},
                    {x,x,x,x,x,x,x,x,x,x}
            };
    fpath(a);
    cout << "Min Path Length is :" << dist[9] << endl;
    for (i = m-1; i>=0; i--) {
        cout << path[i] << " " << endl;
    }
    return 0;
}
void fpath(int a[][10])
{
    int i,j,k;
    dist[0]=0;
    for(i=1;i<10;i++)
    {
        k=max;
        for(j=0;j<i;j++)
        {
            if(a[j][i]!=x)
            if((dist[j]+a[j][i])<k)
                k=dist[j]+a[j][i];
        }
        dist[i]=k;
    }
}
int froute(int a[][10])
{
    int j,b,k=1,i=9;
    path[0]=10;
    while(i>0)
    {
        for(j=i-1;j>=0;j--)
        {
            if(a[j][i]!=x)
            {
                b=dist[i]-a[j][i];
                if(b==dist[j])
                {
                    path[k++]=j+1;
                    i=j;
                    break;
                }
            }
        }
    }
    return k;
}