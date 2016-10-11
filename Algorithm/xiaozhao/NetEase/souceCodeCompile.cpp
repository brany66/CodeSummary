//
// Created by BranY on 2016/9/17.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// http://hihocoder.com/contest/ntest2016spring1/problems

#include <iostream>
#include <vector>
#include <map>
const int MAX_SIZE = 1002;
using namespace std;


typedef struct FileNode {
    string name;
    int dependCnt;
    int visited;

    FileNode() {
        visited = 0;
    }
}cppFile;

cppFile cpp[MAX_SIZE];
map<int, vector<int>>  fileDependMap;

int main() {
    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        fileDependMap.clear();
        for (int i = 0;i < n;++i) {
            cpp[i].dependCnt=0;
            cpp[i].visited = 0;
        }

        for (int i = 0;i < n;++i) {
            cin >> cpp[i].name;
            cin >> cpp[i].dependCnt;

            for (int j = 0; j < cpp[i].dependCnt; ++j) {
                int tmpDepend;
                cin >> tmpDepend;


                if(fileDependMap.count(tmpDepend) > 0) {
                    vector<int> tmpV = fileDependMap[tmpDepend];
                    tmpV.push_back(i);
                }else {
                    vector<int> tmpV;
                    tmpV.push_back(i);
                    fileDependMap[tmpDepend] = tmpV;
                }
            }
        }

        //字典序排序
        for (int i = 0;i < n-1; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(cpp[i].name > cpp[j].name ) {
                    cppFile tmp = cpp[i];
                    cpp[i] = cpp[j];
                    cpp[j] = tmp;
                }
            }
        }

        while (1) {
            int flag = 0;
            int errorFlag = 0;
            for (int i = 0;i < n;++i) {

                if(cpp[i].dependCnt == 1)
                    errorFlag = 1;

                if( cpp[i].visited == 0 && cpp[i].dependCnt == 0 ) {

                    for (int j = 0; j < fileDependMap[i].size(); ++j) {
                        cpp[fileDependMap[i][j]].dependCnt--;
                    }
                    cpp[i].visited = 1;
                    flag = 1;
                    cout<<cpp[i].name<<endl;
                }
            }

            if(flag == 0 && errorFlag == 1) {
                cout<<"ERROR"<<endl<<endl;
                break;
            } else if(flag == 0 && errorFlag == 0) {
                cout<<endl;
                break;
            }
        }

    }
    return 0;
}
