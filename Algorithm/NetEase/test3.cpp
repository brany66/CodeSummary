//
// Created by BranY on 2016/9/18.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include<cstdio>
#include<tr1/unordered_set>

using namespace std;
int arr[1001];
int main(){
    int num, N, L;
    cin >> num;
    std::tr1::unordered_set<int> set1;
    for(int i = 0; i < num; i++){
        cin >> N >> L;
        //scanf("%d%d", &N, &L);
        for(int j = 0; j < L; j++){
            scanf("%d", &arr[j]);
        }
        bool flag = true;
        for(int j = 0; j < N; j ++){
            int k = j;
            flag = true;
            set1.clear();
            for(int m = 0; m < j; m ++){
                if(set1.find(arr[m]) != set1.end()){
                    flag = false;
                    break;
                }else{
                    set1.insert(arr[m]);
                }
            }
            int huihe = 1;
            while(k < L){
                set1.clear();
                for( ; k < j + huihe * N  && k < L; k++){
                    if(set1.find(arr[k]) != set1.end()){
                        flag = false;
                        break;
                    }else{
                        set1.insert(arr[k]);
                    }
                }
                huihe ++;
            }
            if(flag){
                printf("CAN'T DECIDE\n");
                break;
            }
        }
        if(!flag){
            printf("B\n");
        }
    }
}


