// 用链表实现队列的API

#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

typedef int E;

typedef struct node_s{
    E val;
    struct node_s* next;
}Node;

typedef struct queue_s{
    Node* head;
    Node* tail;
}Queue;

Queue* queue_create(){
    return (Queue*)calloc(1,sizeof(Queue));
}

void queue_destroy(Queue* q){
    Node* curr=q->head;
    while(curr!=NULL){
        Node* next=curr->next;
        free(curr);
        curr=next;
    }
    free(q);
}

bool queue_empty(Queue* q){
    return q->head==NULL;
}

void queue_push(Queue* q,E val){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Error:malloc failed in enqueue\n");
        exit(1);
    }
    newNode->val=val;
    newNode->next=NULL;

    if(q->tail==NULL){
        q->head=q->tail=newNode;
    }else{
        q->tail->next=newNode;
        q->tail=newNode;
    }
}

E queue_pop(Queue* q){
    if(queue_empty(q)){
        printf("Error:queue is empty\n");
        exit(1);
    }
    Node* node=q->head;
    E removeValue=node->val;

    q->head=node->next;
    if(q->head==NULL){
        q->tail=NULL;
    }

    free(node);
    return removeValue;
}

E peek(Queue* q){
    if(queue_empty(q)){
        printf("Error:queue is empty\n");
        exit(1);
    }

    return q->head->val;
}
