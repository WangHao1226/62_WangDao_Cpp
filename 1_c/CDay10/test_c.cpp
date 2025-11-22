// 反转单链表

// Node* reverse(Node* list);
// 输入: 1 --> 2 --> 3
// 输出: 3 --> 2 --> 1

#include<stdio.h>

typedef struct node{
    int val;
    struct node* next;
}Node;

Node* reverse(Node* list){
    Node* prev = NULL;    // 前驱节点指针
    Node* curr = list;    // 当前节点指针
    Node* next = NULL;    // 后继节点指针

    while (curr != NULL) {
        next = curr->next;  // 保存下一个节点
        curr->next = prev;  // 反转当前节点的指针
        prev = curr;        // 前驱指针后移
        curr = next;        // 当前指针后移
    }
    return prev;  // 新链表的头节点
}
