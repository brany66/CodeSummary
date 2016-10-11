//
// Created by BranY on 2016/9/18.
// Contact at wyang@smail.nju.edu.cn
// Copyright(c) 2016 NJU PASA Lab All rights reserved.
//
#include <iostream>
#include<cstdio>
#include<tr1/unordered_set>
#include<algorithm>
#include<string.h>
using namespace std;
int t[50001];
int s[50001];
int e[50001];
int tArrived[50001];


int main(){
    //freopen("1032.txt","r",stdin);
    int T, N;
    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        scanf("%d", &N);
        bool up = true;
        int forward = 1;
        int time = 0;
        int curStop = 0;
        int wait = false;
        int des = 0;

        for(int j = 0; j < N; j++){
            scanf("%d%d%d", &t[j],&s[j],&e[j]);
        }
        for(int k = 0; k < N; k++){
            tArrived[k] =  -1;
        }
        bool flag = true;

        while(++time && flag){
            if(!des){
                for(int j = 0; j < N; j++){
                    if(tArrived[j]  == -1 && t[j] <= time){
                        if(forward == 1){
                            des =  e[j]  > des ? e[j] : des;
                        }else{
                            des =  e[j]  <  des ? e[j] : des;
                        }
                    }
                }
                forward = !forward;
            }
            if(des > curStop){
                forward = 1;
                curStop ++;
                for(int j = 0; j < N; j++){
                    if(tArrived[j]  == -1 && t[j] <= time && s[j] == curStop ){
                        tArrived[j] = time - t[j];
                        if(e[j] > des){
                            des = e[j];
                        }
                    }
                }
            }
            if (des < curStop){
                forward = 0;
                curStop --;
                for(int j = 0; j < N; j++){
                    if(tArrived[j]  == -1 && t[j] <= time && s[j] == curStop ){
                        tArrived[j] = time - t[j];
                        if(e[j] < des){
                            des = e[j];
                        }
                    }
                }
            }

            if(des == curStop){
                des = 0;
            }

            bool flag2 = true;
            for(int j = 0; j < N; j++){
                if(tArrived[j] ==  -1){
                    flag2= false;
                    break;
                }
            }
            if(flag2 ){
                flag  = false;
            }

        }
        for(int j = 0; j < N; j++){
            printf("%d\n", tArrived[j]);
        }
        printf("\n");
    }

}

