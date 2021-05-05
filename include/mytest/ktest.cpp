/*************************************************************************
	> File Name: ktest.cpp
	> Author: yupeng
	> Mail: 498988598@qq.com
	> Created Time: 
 ************************************************************************/
#include"mytest/ktest.h"
int test_flag=0;//在此定义一个全局变量
  
//2定义一片存储区，存放不同的测试用例      
struct FuncData{
  void (*func)();//函数指针，用来指向测试用例的那个函数
  const char *func_name;//存放相关测试用例的名字
}func_arr[100];

int func_cnt=0;//表示当前的系统中注册了多少个测试用例


//3添加测试用例的函数
void add_test_function(void (*func)(),const char* func_name){
    func_arr[func_cnt].func=func;
    func_arr[func_cnt].func_name=func_name;
    func_cnt++;
    return;
}

const char* RUN = GREEN("[ RUN ]");
const char* OK = GREEN("[ OK  ]");
const char* FAILED=RED("[FAILED]");

//1实现RUN_ALL_TEST,功能是遍历所有的测试用例的
int RUN_ALL_TESTS(){
     //foreach test case
    for(int i=0;i<func_cnt;i++){
        printf("%s %s\n",RUN,func_arr[i].func_name);
        test_flag=1;
        long long b=clock();
        func_arr[i].func();
        long long e=clock();
        if(test_flag){
            printf("%s %s(%lld ms)\n",OK,func_arr[i].func_name,100*(e-b)/CLOCKS_PER_SEC);
        }else{
            printf("%s %s(%lld ms)\n",FAILED,func_arr[i].func_name,100*(e-b)/CLOCKS_PER_SEC);
        }
    }
    return 0;
}

