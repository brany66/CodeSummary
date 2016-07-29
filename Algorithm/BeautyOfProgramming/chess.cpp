//
// Created by BranY on 2016/7/29.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

/**
 * Chinese Chess Problem
 * Use Only One variable to store each other General position
 */
#include <iostream>
#include <stdio.h>
using namespace std;
/**
 * 1. Use byte to store 18 position, High 4 bit store A's position, Low 4 bit store B's position
 * Example:
 * 1. 将Byte b:10100101的右边四位，设置为n1:0011
 * 首先：清除b右边的bits,同时保持左边的不变： 10100101 & 11110000(LMASK) = 10100000
 * 然后：上一步的结果与n做或运算，将n存入b的左边。10100000 | 00000011(n1) = 10100011
 *
 * 2. 将Byte b:10100101的左边四位，设置为n2:0011
 * 首先：清除b左边的bits,同时保持左边的不变： 10100101 & 00001111(MASK) = 00000101
 * n左移4位： n<<4=00110000
 * 然后：上一步的结果与n做或运算，将n存入b的左边。00000101 | 00110000(n) = 00110101
 *
 *3. 获取byte b 10100101 右边的4位
 * 10100101 & 00001111(RMASK) = 00000101
 *
 * 4. 获取byte b 10100101 左边的4位
 * 10100101 & 11110000(LMASK) = 10100000
 *
 * @return
 */

const int HALF_BITS_LENGTH = 4;
const int FULLMASK = 255;
const int LMASK = FULLMASK << HALF_BITS_LENGTH;
const int RMASK = FULLMASK >> HALF_BITS_LENGTH;
#define RSET(b, n) (b = ((LMASK & b) | (n)))
#define LSET(b, n) (b = ((RMASK & b) | ((n) << HALF_BITS_LENGTH)))
#define RGET(b) (RMASK & b)
#define LGET(b) ((LMASK & b) >> HALF_BITS_LENGTH)
#define GRIDW 3

void slove() {
    unsigned char b;
    for (LSET(b, 1); LGET(b) <= GRIDW * GRIDW; LSET(b, (LGET(b) + 1)))
        for (RSET(b, 1); RGET(b) <= GRIDW * GRIDW; RSET(b, (RGET(b) + 1)))
            if (LGET(b) % GRIDW != RGET(b) % GRIDW)
                cout << "A = " << LGET(b) << " , " << "B = " << RGET(b) << endl;
}

struct unit {
    unsigned char a:4;
    unsigned char b:4;
} i;
void slove_2() {
    for (i.a = 1; i.a <= 9; i.a++) {
        for (i.b = 1; i.b <= 9; i.b++)
            if (i.a % 3 != i.b % 3)
                printf("A = %d , B = %d\n", i.a, i.b);
                //cout << "A = " << i.a << " , " << "B = " << i.b << endl;
    }
}
int main()
{
    //slove();
    slove_2();
    return 0;
}