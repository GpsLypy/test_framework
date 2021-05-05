/*************************************************************************
> File Name:     tt.cpp
> Author:        想名字多费事
> 微信公众号:    还没弄好
> Created Time:  2021年05月03日 星期一 21时29分17秒
> Description:   
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

class MyLinkedList {
public:
    // 定义链表节点结构体
    struct ListNode{
        int val;
        struct ListNode* next;
        ListNode(int x) :val(0),next(nullptr) {}
    };
    // 初始化链表
    MyLinkedList() {
      m_dummy= new ListNode(0);// 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
      m_size=0;
    }
   
    int get(int index) {
         if(index>=m_size||index<0) return -1;
         ListNode* cur=m_dummy;
         for(int ii=0;ii<=index;ii++){
          if(cur->next) cur=cur->next;
         }
         return cur->val;
    }
    
    // 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
    void addAtHead(int val) {
         ListNode* node=new ListNode(val);
         node->next=m_dummy->next;
         m_dummy->next=node;
         m_size++;
    }
      
  
     // 在链表最后面添加一个节点
    void addAtTail(int val) {
        ListNode* node=new ListNode(val);
        ListNode* temp=m_dummy;
        while(temp->next!=nullptr) temp=temp->next;
        temp->next=node;
        m_size++;
    }

    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    void addAtIndex(int index, int val) {
      if(index>m_size){ 
         return;
       }
      else if(index<0){
          addAtHead(val);
          return;
      }else{
          ListNode* cur=m_dummy;
          ListNode* node=new ListNode(val);
          for(int ii=0;ii<index;ii++){
              cur=cur->next;
          }
          node=cur->next;
          cur->next=node;
          m_size++;
          return;
      }
      return;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
         ListNode* cur=m_dummy;
         for(int ii=0;ii<index;ii++){
          cur=cur->next;
         }
         cur->next=cur->next->next;
         m_size--;
    }
private:
   ListNode* m_dummy;
   int m_size;
};

int main(){
/* 
    MyLinkedList linkedList = new MyLinkedList();
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
    cout<<linkedList.get(1)<<endl;            //返回2
    linkedList.deleteAtIndex(1);  //现在链表是1-> 3
    cout<<linkedList.get(1)<<endl;            //返回3
*/
    return 0;

}
