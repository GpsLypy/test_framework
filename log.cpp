/*************************************************************************
	> File Name: log.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
//#include <queue>
//#include <stack>
//#include <algorithm>
//#include <string>
//#include <map>
//#include <set>
//#include <vector>
//#include <getopt.h>
using namespace std;

#ifndef DEBUG

#define LOG(frm, args...) { \
    printf("[%s : %s : %d] ", __FILE__, __func__, __LINE__); \
    printf(frm, ##args); \
    printf("\n"); \
}

#else 

#define LOG(frm, args...) 

#endif

#define CAT(a, b) a##b

int main() {
    LOG("hello kaikeba");
    int kaikeba_cs = 9973;
    CAT(kaikeba, _cs) = 10000;
    LOG("kaikeba_cs = %d", kaikeba_cs);
    int a = 1, b = 2, c = 3;
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    LOG("a = %d, b = %d, c = %d", a, b, c);
    LOG("a = %d, b = %d, c = %d", a, b, c);
    return 0;
}
