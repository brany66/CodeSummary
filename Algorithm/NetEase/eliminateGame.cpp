//
// Created by BranY on 2016/9/17.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// http://46aae4d1e2371e4aa769798941cef698.devproxy.yunshipei.com/loststephon/article/details/51223040

#include <iostream>
#include <cstdio>

using namespace std;
int N, M;
char arr[20][20];
int res = 0;
void cal() {

    for(int i = 0;i<N;i++) {
        for(int j=0;j<M;j++) {
            //遇到非空格字符的时候才开始判断
            if(arr[i][j]!='.') {
                int x=i,y=j;//最终消除区域的中心
                int a=i,b=j,c=i,d=j;
                int sum=0;
                int temp=0;
                //先开始纵向搜索
                while((--a)>=0&&arr[a][j]==arr[i][j])temp++;
                while((++c)<N&&arr[c][j]==arr[i][j])temp++;
                //若纵向搜索可找到消除的列
                if(temp>=2) {
                    sum+=temp;
                    temp=0;
                    int maxum=0;
                    //开始在这个纵向列上以每个字符为中心开始横向搜索
                    for(int k=a+1;k<=c;k++) {
                        int cnt=0;
                        int b1=j,d1=j;
                        while((--b1)>=0&&arr[k][b1]==arr[i][j])cnt++;
                        while((++d1)<M&&arr[k][d1]==arr[i][j])cnt++;
                        //若横向搜索可找到消除的行
                        if(cnt>=2&&cnt>maxum) {
                            maxum=cnt;
                            //更新中心点
                            x=k;
                            y=j;
                            //更新左右边界
                            b=b1;
                            d=d1;
                        }
                    }
                    sum+=maxum;
                } else { //若纵向搜索找不到消除的列
                    temp=0;
                    a=i,b=j,c=i,d=j;
                    //开始重新横向搜索
                    while((--b)>=0&&arr[i][b]==arr[i][j])temp++;
                    while((++d)<M&&arr[i][d]==arr[i][j])temp++;
                    //若横向搜索可找到消除的行
                    if(temp>=2) {
                        sum+=temp;
                        temp=0;
                        int maxum=0;
                        //开始在这个横向行上以每个字符为中心开始纵向搜索
                        for(int k=b+1;k<d;k++) {
                            int cnt=0;
                            int a1=i,c1=i;
                            while((--a1)>=0&&arr[a1][k]==arr[i][j])cnt++;
                            while((++c1)<N&&arr[c1][k]==arr[i][j])cnt++;
                            //若纵向搜索可找到消除的列
                            if(cnt>=2&&cnt>maxum) {
                                maxum=cnt;
                                //更新中心点
                                x=i;
                                y=k;
                                //更新上下边界
                                a=a1;
                                c=c1;
                            }
                        }
                        sum+=maxum;
                    }
                }
                //若符合消除的条件
                if(sum>=2) {
                    res+=sum;
                    sum=0;
                    res++;
                    //若纵向上有消除的列，则消除后合并
                    if(c-a>=3) {
                        for(int e=a;e>=0;e--)arr[e+c-1-a][y]=arr[e][y];
                        for(int e=0;e<c-a-1;e++)arr[e][y]='.';
                    }
                    //若横向上有消除的行，则消除后合并
                    if(d-b>=4) {
                        for(int e=b+1;e<d;e++) {
                            for(int f=x-1;f>=0;f--)arr[f+1][e]=arr[f][e];
                            arr[0][e]='.';
                        }
                    }
                    //开始向下回溯
                    cal();
                }
            }
        }
    }
}
int main() {
    int S, x0, y0, x1, y1;
    cin >> S;
    while(S--) {
        cin >> N >> M;
        for(int i = 0; i < N; i++) {
            for(int j = 0;j < M; j++)
                cin >> arr[i][j];
        }
        scanf("%d %d %d %d",&x0,&y0,&x1,&y1);
        char temp = arr[x0][y0];
        arr[x0][y0] = arr[x1][y1];
        arr[x1][y1] = temp;

        cal();
        printf("%d\n",res);
        res = 0;
    }
    return 0;
}
