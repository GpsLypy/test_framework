/*************************************************************************
	> File Name: define.cpp
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
using namespace std;

#define PI 3.1415926
#define S(a, b) a * b

int main() {
    printf("%lf\n", 2 * PI);
    printf("S(3, 4) = %d\n", S(3, 4));
    printf("S(5 + 7, 6) = %d\n", S(5 + 7, 6));
    printf("__FILE__ = %s\n", __FILE__);
    printf("__LINE__ = %d\n", __LINE__);
    printf("__func__ = %s\n", __func__);
    printf("__PRETTY_FUNCTION__ = %s\n", __PRETTY_FUNCTION__);
    int n;
    S(int, p) = &n;
    return 0;
}
