//
// Created by BranY on 2016/9/5.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int uniquePaths(int m, int n) {
    vector<vector<int>> grid(m, vector<int>(n, 0));
    //int[][] grid = new int[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0||j == 0) grid[i][j] = 1;
            else grid[i][j] = grid[i][j-1] + grid[i-1][j];
        }
    }
    return grid[m-1][n-1];

}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid.empty()) {
        return 0;
    }
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();

    if(obstacleGrid[0][0]==1) {
        return 0;
    } else {
        obstacleGrid[0][0] = -1;
    }

    for(int i=1;i<col;i++) {
        if(obstacleGrid[0][i]==1){
            obstacleGrid[0][i] = 0;
        } else {
            obstacleGrid[0][i] = obstacleGrid[0][i-1];
        }
    }
    for(int i=1;i<row;i++) {
        if(obstacleGrid[i][0]==1){
            obstacleGrid[i][0] = 0;
        } else {
            obstacleGrid[i][0] = obstacleGrid[i-1][0];
        }
    }
    for(int i=1;i<row;i++) {
        for(int j=1;j<col;j++) {
            if(obstacleGrid[i][j]==1) {
                obstacleGrid[i][j] = 0;
            } else {
                obstacleGrid[i][j] = obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
            }
        }
    }
    return -obstacleGrid[row-1][col-1];
}
int main() {
    return 0;
}
