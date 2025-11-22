// 判断单链表是否有环?

// bool hasCircle(Node* list);

#include<stdio.h>

typedef struct node {
    int val;
    struct node* next;
} Node;

bool hasCircle(Node* list){
    if(list==NULL){
        return false;
    }
    Node* slow=list;
    Node* fast=list;

    do{
        if(fast==NULL&&fast->next==NULL){
            return false;
        }
        fast=fast->next->next;
        slow=slow->next;
    }while(slow!=fast);
    return true;
}