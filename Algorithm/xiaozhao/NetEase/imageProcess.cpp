//
// Created by BranY on 2016/9/17.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// http://www.lai18.com/content/8783884.html

#include <iostream>
#include <cstring>

using namespace std;
int N,M;
int arr1[100][100];
int arr2[100][100];

int x0,y0,x1,y1,val;

void operate(int op) {
    if(op == 1) {
        for(int i = 0; i < M; i++) {
            for(int j = 0;j < N;j++)
                arr2[i][j] = arr1[N-1-j][i];
        }
        int temp = N;
        N = M;
        M = temp;
        memcpy(arr1, arr2, sizeof(arr2));
    } else if(op == 2) {
        for(int i = 0;i < M; i++) {
            for(int j = 0;j < N;j++)
                arr2[i][j] = arr1[j][M-1-i];
        }
        int temp=N;
        N = M;
        M = temp;
        memcpy(arr1, arr2, sizeof(arr2));
    } else if(op == 3) {
        for(int i = 0; i < N; i++) {
            for(int j=0;j<M;j++)
                arr2[i][j] = arr1[N-1-i][j];
        }
        memcpy(arr1,arr2,sizeof(arr2));
    } else if(op == 4) {
        for(int i = 0; i < N;i++) {
            for(int j = 0; j < M;j++)
                arr2[i][j] = arr1[i][M-1-j];
        }
        memcpy(arr1, arr2, sizeof(arr2));
    } else if(op == 5) {
        for(int i = x0; i <= x1;i++) {
            for(int j = y0; j <= y1;j++) {
                arr1[i][j] += val;
                if(arr1[i][j] >= 255)
                    arr1[i][j] = 255;
            }
        }
    } else if(op == 6) {
        for(int i = x0; i <= x1;i++) {
            for(int j = y0; j <= y1;j++) {
                arr1[i][j] -= val;
                if(arr1[i][j] <= 0)
                    arr1[i][j] = 0;
            }
        }
    } else {
        for(int i = x0; i <= x1;i++) {
            for(int j = y0; j <= y1;j++) {
                arr2[i-x0][j-y0] = arr1[i][j];
            }
        }
        N = x1 - x0 + 1;
        M = y1 - y0 + 1;
        memcpy(arr1, arr2, sizeof(arr2));
    }
}

int main() {
    int S,T,op;
    cin >> S;
    while(S--) {
        cin >> N >> M;
        memset(arr1,-1,sizeof(arr1));
        memset(arr2,-1,sizeof(arr2));
        for(int i = 0; i < N;i++) {
            for(int j = 0; j < M;j++) {
                cin >> arr1[i][j];
            }
        }
        cin >> T;
        while(T--) {
            cin >> op;
            if(op < 5) operate(op);
            else if(op < 7) {
                cin >> x0 >> y0 >> x1 >> y1 >> val;
                operate(op);
            } else {
                cin >> x0 >> y0 >> x1 >> y1;
                operate(op);
            }
        }
        int sum = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                sum += arr1[i][j];
            }
        }
        cout << N << " " << M << " " << arr1[0][0] << " " << sum << endl;
    }
    return 0;
}
