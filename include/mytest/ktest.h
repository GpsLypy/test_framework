/*************************************************************************
	> File Name: ktest.h
	> Author: yupeng
	> Mail: 498988598@qq.com
	> Created Time: 
 ************************************************************************/

#ifndef _KTEST_H
#define _KTEST_H

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
extern int test_flag;//声明这个变量

/*
 extern int i; //声明，不是定义
 int i; //声明，也是定义
*/


#define LOG(frm, args...) { \
    printf("[%s : %s : %d] ", __FILE__, __func__, __LINE__); \
    printf(frm, ##args); \
    printf("\n"); \
}

//实现color系列封装
#define COLOR(msg, code) "\033[0;" #code "m" msg "\033[0m"
#define RED(msg)     COLOR(msg, 31)
#define GREEN(msg)   COLOR(msg, 32)
#define YELLOW(msg)  COLOR(msg, 33)
#define BLUE(msg)    COLOR(msg, 34)

//#define test_flag int test_flag   
//int test_flag;
//二次封装宏(实现EXPECT系列的封装)
#define EXPECT(a, comp, b) { \
    __typeof(a) __a=(a),__b=(b);\
    if (!(__a comp __b)) { \
        test_flag=0;\
        printf(YELLOW(  "%s:%d:Failure\n"),__FILE__,__LINE__); \
        printf(YELLOW(  "Expected:((%s)%s (%s)),actual:%d vs %d\n"),#a,#comp,#b,__a,__b);\
    } \
}

#define EXPECT_EQ(a, b) EXPECT(a, ==, b)
#define EXPECT_NE(a, b) EXPECT(a, !=, b)
#define EXPECT_LT(a, b) EXPECT(a, <, b)
#define EXPECT_LE(a, b) EXPECT(a, <=, b)
#define EXPECT_GT(a, b) EXPECT(a, >, b)
#define EXPECT_GE(a, b) EXPECT(a, >=, b)

//4
#define TEST_FUNC_NAME(a,b) BasedGoogle_##a##_##b
#define TEST(a,b) \
  void TEST_FUNC_NAME(a,b)();\
  void add_test_function(void (*func)(),const char* func_name);\
  __attribute__((constructor))\
  void reg_##a##_##b() {\
      add_test_function(TEST_FUNC_NAME(a,b),#a"."#b);\
      return ;\
  }\
  void TEST_FUNC_NAME(a,b)()

//1实现RUN_ALL_TEST,功能是遍历所有的测试用例的
 int RUN_ALL_TESTS();

#endif
