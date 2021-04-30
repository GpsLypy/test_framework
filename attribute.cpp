/*************************************************************************
	> File Name: attribute.cpp
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

void func1() {
    printf("function 1\n");
}

void func2() {
    printf("function 2\n");
}

void func3() {
    printf("function 3\n");
}

void func4() {
    printf("function 4\n");
}

void (*func[4])(); //定义函数指针数组

__attribute__((constructor)) //attribute关键字可以设置函数属性，如果设置成构造函数，则先于主函数执行
void init_func() { //这个函数的作用是初始化一个函数指针数组（使对应的函数指针指向对应的函数)
    func[0] = func1;//也就是把四个功能函数地址存储到一个存储区中(注册函数)
    func[1] = func2;
    func[2] = func3;
    func[3] = func4;
    return ;
}

int main() {
    srand(time(0));
    func[rand() % 4]();
    return 0;
}
