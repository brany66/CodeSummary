//
// Created by BranY on 2016/8/30.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>

using namespace std;
string convert(string s, int numRows) {
    if (numRows <= 1) return s;
    auto len = s.size();
    string zigzag = "";
    for (int lineIndex = 0; lineIndex < numRows; lineIndex++) {
        int rowIndex = lineIndex;
        while (rowIndex < len) {
            //first line and last line
            if (lineIndex == 0 || numRows - 1 == lineIndex) {
                zigzag = zigzag + s[rowIndex];
            } else {
                //除去第一行和最后一行，每行的起始
                if (rowIndex == lineIndex)
                    zigzag = zigzag + s[rowIndex];
                else {
                    zigzag = zigzag + s[rowIndex - 2 * lineIndex];
                    zigzag = zigzag + s[rowIndex];
                }
            }
            rowIndex += 2 * (numRows - 1);
        }
       if ((lineIndex > 0) && (lineIndex < numRows - 1) && (rowIndex - 2 * lineIndex < len))
           zigzag = zigzag + s[rowIndex - 2 * lineIndex];
    }
    return zigzag;
}
int main() {
    string str;
    int n;
    while(getline(cin, str)) {
        while (cin >> n) {
         cout << convert(str, n) << endl;
        }
    }
    return 0;
}
