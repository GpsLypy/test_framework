/*************************************************************************
	> File Name: color.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

#define COLOR(msg, code) "\033[0;" #code "m" msg "\033[0m"//#是字符串化，将code变成一个字符串
#define RED(msg)     COLOR(msg, 31)
#define GREEN(msg)   COLOR(msg, 32)
#define YELLOW(msg)  COLOR(msg, 33)
#define BLUE(msg)    COLOR(msg, 34)

int main() {
    //printf("\033[0;" "31" "m" "hello kaikeba" "\033[0m\n");
    printf("\033[0; 31 m hello kaikeba \033[0m\n");
    printf(GREEN("hello kaikeba\n"));
    printf(YELLOW("hello kaikeba\n"));
    printf(BLUE("hello kaikeba\n"));
    printf("hello kaikeba\n");
    return 0;
}
