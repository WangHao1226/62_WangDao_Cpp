// 假设结点定义如下，请完成下列题目。

// typedef struct node {
//     int val;
//     struct node* next;
// } Node;
// 求链表中间结点的值。

// int middleElement(Node* list);
// 输入: 1 --> 2 -->; 3
// 输出: 2
// 输入: 1 --> 2 --> 3 --> 4
// 输出: 3

#include<stdio.h>

typedef struct node{
    int val;
    struct node* next;
}Node;

int middleElement(Node* list){
    if(list==NULL){
        return -1;
    }
    Node* slow=list;
    Node* fast=list;

    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow->val;
}
