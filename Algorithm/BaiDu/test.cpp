//
// Created by BranY on 2016/9/13.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <memory>


using namespace std;

int main() {
    char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
    char **cp[] = { c+3, c+2, c+1, c };
    char ***cpp = cp;

    printf("%s", **++cpp);
    printf("%s", *--*++cpp+3);
    printf("%s", *cpp[-2]+3);
    printf("%s\n", cpp[-1][-1]+1);

    shared_ptr<int> p(new int(1014));
    return 0;
}
