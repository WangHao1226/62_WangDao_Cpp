// 合并两条有序的单向链表，使得合并后的链表也是有序的 (要求: 不能额外申请堆内存空间)。

// Node* mergeTwoLists(Node* list1, Node* list2);
// 输入：1 --> 3 --> 5
//      2 --> 4 --> 6
// 输出：1 --> 2 --> 3 --> 4 --> 5 --> 6

#include<stdio.h>

typedef struct node{
    int val;
    struct node* next;
}Node;

Node* mergeTwoLists(Node* list1,Node* list2){
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;

    Node* head=NULL;
    Node* tail=NULL;

    if(list1->val<=list2->val){
        head=list1;
        list1=list1->next;
    }else{
        head=list2;
        list2=list2->next;
    }
    tail=head;

    while (list1!=NULL&&list2!=NULL){
        if(list1->val>list2->val){
            tail->next=list1;
            list1=list1->next;
        }else{
            tail->next=list2;
            list2=list2->next;
        }
        tail=tail->next;
    }

    if(list1!=NULL){
        tail->next=list1;
    }else{
        tail->next=list2;
    }
    return head;    
}