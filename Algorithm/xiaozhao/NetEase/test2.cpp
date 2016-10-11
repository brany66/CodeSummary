#include <iostream>
#include <vector>
using namespace std;

const int N = 8;

void solve(vector<vector<char> > & map, int x, int y, int c) {
    int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
    char ch;
    if (c == 1) {
        map[x][y] = 'o';
        ch = 'o';
    } else if (c == 0){
        map[x][y] = '*';
        ch = '*';
    }

    for (int i = 0; i < 8; ++i) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (ch == '*') {
            while (nx >= 0 && nx <= N && ny >= 0 && ny <= N && map[nx][ny] == 'o')
                nx += dir[i][0], ny += dir[i][1];
            if (nx >= 0 && nx <= N && ny >= 0 && ny <= N && map[nx][ny] == '*') {
                nx -= dir[i][0], ny -= dir[i][1];
                while (map[nx][ny] == 'o') {
                    map[nx][ny] = '*';
                    nx -= dir[i][0], ny -= dir[i][1];
                }
            }
        } else if (ch == 'o') {
            while (nx >= 0 && nx <= N && ny >= 0 && ny <= N && map[nx][ny] == '*')
                nx += dir[i][0], ny += dir[i][1];
            if (nx >= 0 && nx <= N && ny >= 0 && ny <= N && map[nx][ny] == 'o') {
                nx -= dir[i][0], ny -= dir[i][1];
                while (map[nx][ny] == '*')
                {
                    map[nx][ny] = 'o';
                    nx -= dir[i][0], ny -= dir[i][1];
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--){
        char ch;
        vector<vector<char> > map(10, vector<char>(10, '.'));
        cin >> ch;
        map[1][1] = ch;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (i == 1 && j == 1) continue;
                cin >> ch;
                map[i][j] = ch;
            }
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            int x, y, c;

            cin >> x >> y >> c;
            solve(map, x+1, y+1, c);
        }
        int count1 =0, count2= 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (map[i][j] == '*') ++count1;
                else if (map[i][j] == 'o') ++count2;
            }
        }
        cout << "res  " << count1 << " " << count2 << endl;
    }
    return 0;
}
