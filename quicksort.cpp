/*************************************************************************
	> File Name: test.cpp
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
#include <cstring>
#include <kaikeba/ktest.h>
using namespace std;


void quicksort_v1(int *arr,int l,int r){
    if(l>=r) return;//如果区间元素小于等于1
    int temp=arr[l];//选取基准值
    int left=l,right=r;//确定头尾指针
    while(left<right){
      while(left<right && arr[right]>=temp) --right;
      if(left<right) arr[left++]=arr[right];
      while(left<right && arr[left]<=temp) ++left;
      if(left<right) arr[right--]=arr[left];
    }
    arr[left]=temp;
    quicksort_v1(arr,l,left-1);
    quicksort_v1(arr,left+1,r);
    return;
}

void quicksort_v2(int *arr,int l,int r){
    if(l>=r) return;//如果区间元素小于等于1
    
   while(l<r){
        int temp=arr[l];//选取基准值
        int left=l,right=r;//确定头尾指针
        while(left<right){
            while(left<right && arr[right]>=temp) --right;
            if(left<right) arr[left++]=arr[right];
            while(left<right && arr[left]<=temp) ++left;
            if(left<right) arr[right--]=arr[left];
        }
    arr[left]=temp;
    //quicksort_v1(arr,l,left-1);
    quicksort_v1(arr,left+1,r);
    r=left-1;
  }
    return;
}
#define MAX_N 10000000
int *arr;

int check(int* arr,int n){
    for(int ii=1;ii<n;ii++){
        if(arr[ii-1]>arr[ii]) return 0;
    }
    return 1;
}

int *getRandData(int n){
    int *arr=(int *)malloc(sizeof(int)*n);
    for(int ii=0;ii<n;ii++) arr[ii]=rand()%n;
    return arr;
}

TEST(test1, quicksort_v1) {
    int *temp=(int*)malloc(sizeof(int)*MAX_N);
    memcpy(temp,arr,sizeof(int)*MAX_N);
    quicksort_v1(temp,0,MAX_N-1);
    EXPECT_EQ(check(temp,MAX_N),1);
    free(temp);
}

TEST(test2, quicksort_v2) {
    int *temp=(int*)malloc(sizeof(int)*MAX_N);
    memcpy(temp,arr,sizeof(int)*MAX_N);
    quicksort_v2(temp,0,MAX_N-1);
    EXPECT_EQ(check(temp,MAX_N),1);
    free(temp);
}

int main() {
    srand(time(0));
    arr=getRandData(MAX_N);
    return RUN_ALL_TESTS();
}
