//
// Created by BranY on 2016/8/11.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>

using namespace std;
/**
 * 1. 阶乘末尾0的个数
 *   N！= K * 10^M, N!=(2^x)*(3^y)*(5^z)....
 *   M只跟x，z有关，但是2的倍数出现的频率大于5的倍数出现的频率
 *   so M = z
 * 2. 阶乘中最低位1的位置
 * @return
 */

/**
 * [n/5]表示不大于N的数中5的倍数贡献一个5
 * sum = [n/5] + [n/25] + [n/5^3] + .....
 * @param n
 * @return
 */
int countZero(int n) {
    int sum = 0;
    int ret = n;
    while (ret) {
        sum += ret / 5;
        ret /= 5;
    }
    return sum;
}


/**
 * [n/2]
 * sum = [n/2] + [n/4] + [n/2^3] + .....
 * @param n
 * @return
 */
int indexOfLastOneBit(int n) {
    int sum = 0;
    int ret = n;
    while (ret) {
        ret >>= 1;
        sum += ret;
    }
    return sum+1;
}
int main() {
    int n;
    while (cin >> n) {
        cout << countZero(n) << " " << indexOfLastOneBit(n) << endl;
    }
    return 0;
}