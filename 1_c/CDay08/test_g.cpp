//设计一个动态数组，当数组空间不够时，它可以自动扩容。

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct {
    int* elements;   // 指向堆空间的数组
    int size;	// 元素的个数
    int capacity; // 数组的容量
} Vector;

static void _resize(Vector* v,int new_capacity){
    int* new_elements=(int*)malloc(sizeof(int)*new_capacity);
    if(v->elements!=NULL){
        memcpy(new_elements,v->elements,sizeof(int)*v->size);
        free(v->elements);
    }
    v->elements=new_elements;
    v->capacity=new_capacity;
}

// 请实现下面方法
void push_back(Vector* v, int val){
    if(v->size==v->capacity){
        int new_capacity=(v->capacity==0)?4:v->capacity*2;
        _resize(v,new_capacity);
    }
    v->elements[v->size++]=val;
}

// 在数组最前面添加元素，所有元素依次后移
void push_front(Vector* v, int val){
    if(v->size==v->capacity){
        int new_capacity=(v->capacity==0)?4:v->capacity*2;
        _resize(v,new_capacity);
    }

    for(int i=v->size;i>0;i--){
        v->elements[i]=v->elements[i-1];
    }
    v->elements[0]=val;
    v->size++;
}


// 将元素val添加到索引为idx的位置，idx后面的元素依次后移
void insert(Vector* v, int idx, int val){
    if(idx<0||idx>v->size){
        return;
    }

    if(v->size==v->capacity){
        int new_capacity=(v->capacity==0)?4:v->capacity*2;
        _resize(v,new_capacity);
    }

    for(int i=v->size;i>idx;i--){
        v->elements[i]=v->elements[i-1];
    }
    v->elements[idx]=val;
    v->size++;
}

int main() {
    Vector v = {NULL, 0, 0};
    // 测试 push_back
    for (int i = 0; i < 5; i++) {
        push_back(&v, i);
    }
    // v.elements: [0,1,2,3,4] (capacity=8)

    // 测试 push_front
    push_front(&v, -1);
    // v.elements: [-1,0,1,2,3,4] (size=6)

    // 测试 insert
    insert(&v, 3, 99);
    // v.elements: [-1,0,1,99,2,3,4] (size=7)

    // 最终释放内存
    free(v.elements);
    return 0;
}


