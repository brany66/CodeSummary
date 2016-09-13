//
// Created by BranY on 2016/9/12.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>

using namespace::std ;

void scan(vector<vector<int>>& vec, vector<int>& first ) {
    for (int i = 1; i < vec.size(); ++ i ) {
        for (int j = 1; j < vec[0].size(); ++ j ) {
            int tmp = 0 ;
            for (int n = i; (n < i + 3 ) && ( n < vec.size() ); ++ n ) {
                for (int m = j; (m < j + 3 ) && ( m < vec[0].size() ); ++ m ) {
                    if ( vec[n][m] > 0 )
                        ++tmp;
                }
            }
            if ( tmp > first[2] ) {
                first[0] = i ;
                first[1] = j ;
                first[2] = tmp ;
            }
        }
    }
}

int main() {
    int n, m, k ;

    while ( cin >> n >> m >> k ) {
        vector<vector<int>> vec(n + 1, vector<int>(m + 1, 0));
        for ( int i = 0; i < k; ++ i ) {
            int x, y ;
            cin >> x >> y;
            ++ vec[x][y];
        }

        vector<int> first(3, 0);
        vector<int> next(3, 0);

        scan(vec, first) ;

        int result = first[2] ;
        for ( int i = first[0]; ( i < first[0] + 3 ) && ( i < vec.size() ); ++ i ) {
            for ( int j = first[1]; ( j < first[1] + 3 ) && ( j < vec[0].size() ); ++ j ) {
                if ( vec[i][j] > 0 ) -- vec[i][j] ;
            }
        }

        scan( vec, next ) ;
        result += next[2] ;

        cout << result << endl ;
    }

    return 0 ;
}