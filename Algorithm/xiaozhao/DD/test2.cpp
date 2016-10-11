//
// Created by BranY on 2016/9/18.
// Cantact at wyang@smail.nju.edu.cn
// Copyright(c) 2016 NJU PASA Lab All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
int n, m, p;
int mapp[20][20];
int life[20][20];
int route[20][20];
int step[4][3] = {{0,1, -1}, {0, -1, -1}, {1, 0, 0}, {-1, 0, -3}};
struct Node {
    int value;
    int x, y;
    Node(int v, int a, int b) : value(v), x(a), y(b){}
};
bool operator < (Node a, Node b){
    return a.value < b.value;
}
void dfs() {
    priority_queue<Node, vector<Node>, less<Node>> que;
    int i;
    Node *p = new Node(life[0][0], 0, 0);
    que.push(*p);
    while(!que.empty()) {
        Node top = que.top();
        que.pop();
        for (int i =0; i < 4; i++){
            p = new Node(top.value+step[i][2], top.x+step[i][0], top.y+step[i][1]);
            if (p->x < 0 || p->y >= n || p->y < 0 || p->y >=m || p->value <0 ||mapp[p->x][p->y] == 0 || life[p->x][p->y] > p->value) continue;
            life[p->x][p->y] = p->value;
            route[p->x][p->y] = route[top.x][top.y]+ 1;
            que.push(*p);
        }
    }
}
void process() {
    stack<Node> st;
    int i;
    Node *p =new Node(route[0][m-1], 0, m-1);
    st.push(*p);
    while (1){
        Node q = st.top();
        if (q.value == 1) break;
        for (i =0; i <4; i++){
            p = new Node(q.value-1, q.x+step[i][0], q.y+step[i][1]);
            if (p->x < 0 || p->y >= n || p->y < 0 || p->y >=m || p->value <0 ||mapp[p->x][p->y] == 0 ||route[p->x][p->y] != p->value) continue;
            st.push(*p);
        }
    }
    cout << "[" << st.top().x << "," << st.top().y << "]";
    st.pop();
    while (!st.empty()){
        cout << ",[" << st.top().x << "," << st.top().y << "]";
        st.pop();
    }
    cout << endl;
}
void  bfs(vector<vector<int>> &res, int &life, vector<vector<int>> &mat, int i, int j) {
    if (i == 0 && j == mat[0].size() - 1){
        res.push_back(vector<int>{i, j});
        return;
    }
    //left
    if (j + 1 < mat[0].size() && mat[i][j+1] == 1) {
        res.push_back(vector<int> {i, j+1});
        life += 1;
        bfs(res, life, mat, i, j + 1);
    }
    //down
    if (i + 1 < mat.size() && mat[i+1][j] == 1){
        res.push_back(vector<int>{i+1, j});
        bfs(res, life, mat, i+1, j);
    }
    // up
    if (i > 0 && j < mat[0].size() && mat[i-1][j] == 1){
        life += 3;
        res.push_back(vector<int>{i-1, j});
        bfs(res, life, mat, i-1, j);
    }
}
int main() {
    int i, j;
    while(cin >> n >> m >> p) {
        for (i =0; i<n;i++){
            for (j=0; j < m; j++) {
                cin >> mapp[i][j];
                life[i][j] = -1;
                route[i][j] = 0;
            }
        }
        life[0][0] =p;
        dfs();
        if (life[0][m-1] < 0) cout << "Can not escape!\n";
        else
            process();
    }
    return 0;
}

