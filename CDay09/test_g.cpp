// 设计一个动态数组，当数组空间不够时，它可以自动扩容。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* elements;    // 指向动态数组的指针
    int size;         // 当前元素数量
    int capacity;     // 当前数组容量
} Vector;

// 初始化动态数组（可选）
void vector_init(Vector* v) {
    v->elements = NULL;
    v->size = 0;
    v->capacity = 0;
}

// 销毁动态数组，释放内存
void vector_destroy(Vector* v) {
    free(v->elements);
    v->elements = NULL;
    v->size = v->capacity = 0;
}

// 内部扩容函数（容量不足时触发）
static void _resize(Vector* v, int new_capacity) {
    int* new_elements = (int*)malloc(new_capacity * sizeof(int));
    if (new_elements == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    // 复制旧数据到新内存
    if (v->elements != NULL) {
        memcpy(new_elements, v->elements, v->size * sizeof(int));
        free(v->elements); // 释放旧内存
    }

    v->elements = new_elements;
    v->capacity = new_capacity;
}

void vector_push_back(Vector* v, int value) {
    // 容量不足时扩容（初始容量为4，之后翻倍）
    if (v->size >= v->capacity) {
        int new_cap = (v->capacity == 0) ? 4 : v->capacity * 2;
        _resize(v, new_cap);
    }

    v->elements[v->size++] = value; // 追加元素
}

void vector_push_front(Vector* v, int value) {
    if (v->size >= v->capacity) {
        int new_cap = (v->capacity == 0) ? 4 : v->capacity * 2;
        _resize(v, new_cap);
    }

    // 所有元素后移一位
    for (int i = v->size; i > 0; i--) {
        v->elements[i] = v->elements[i - 1];
    }

    v->elements[0] = value;
    v->size++;
}

void vector_insert(Vector* v, int index, int value) {
    if (index < 0 || index > v->size) {
        fprintf(stderr, "Invalid insert position!\n");
        return;
    }

    if (v->size >= v->capacity) {
        int new_cap = (v->capacity == 0) ? 4 : v->capacity * 2;
        _resize(v, new_cap);
    }

    // 将插入位置后的元素后移
    for (int i = v->size; i > index; i--) {
        v->elements[i] = v->elements[i - 1];
    }

    v->elements[index] = value;
    v->size++;
}

int main() {
    Vector vec;
    vector_init(&vec);

    // 添加元素触发自动扩容
    for (int i = 0; i < 10; i++) {
        vector_push_back(&vec, i);
        printf("Size: %d, Capacity: %d\n", vec.size, vec.capacity);
    }

    // 头部插入元素
    vector_push_front(&vec, -1);
    printf("After push_front: %d\n", vec.elements[0]);

    // 中间插入元素
    vector_insert(&vec, 5, 99);
    printf("After insert: %d\n", vec.elements[5]);

    // 打印所有元素
    printf("Elements: ");
    for (int i = 0; i < vec.size; i++) {
        printf("%d ", vec.elements[i]);
    }

    // 释放内存
    vector_destroy(&vec);
    return 0;
}