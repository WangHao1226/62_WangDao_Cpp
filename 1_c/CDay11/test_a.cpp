// 用数组实现栈的 API (要求能够自动扩容)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *data;      // 存储栈元素的数组
    int top;        // 栈顶索引（指向下一个空闲位置）
    int capacity;   // 当前栈的容量
} Stack;

// 创建栈并初始化
Stack* createStack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = 4;  // 初始容量设为4
    stack->top = 0;
    stack->data = (int*)malloc(sizeof(int) * stack->capacity);
    return stack;
}

// 销毁栈并释放内存
void destroyStack(Stack *stack) {
    free(stack->data);
    free(stack);
}

// 检查栈是否为空
int isEmpty(Stack *stack) {
    return stack->top == 0;
}

// 返回栈中元素数量
int size(Stack *stack) {
    return stack->top;
}

// 内部扩容函数（当栈满时调用）
static void resize(Stack *stack) {
    int newCapacity = stack->capacity * 2;  // 容量翻倍
    int *newData = (int*)realloc(stack->data, sizeof(int) * newCapacity);
    if (!newData) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->data = newData;
    stack->capacity = newCapacity;
    printf("Resized stack to capacity: %d\n", newCapacity);  // 可选：显示扩容信息
}

// 压入元素
void push(Stack *stack, int value) {
    if (stack->top == stack->capacity) {
        resize(stack);  // 栈满时自动扩容
    }
    stack->data[stack->top++] = value;
}

// 弹出栈顶元素
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return INT_MIN;  // 返回特殊值表示错误
    }
    return stack->data[--stack->top];
}

// 查看栈顶元素（不弹出）
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->data[stack->top - 1];
}

// 测试函数
int main() {
    Stack *s = createStack();
    
    // 测试压栈
    for (int i = 0; i < 10; i++) {
        push(s, i * 10);
        printf("Pushed: %d, Size: %d, Capacity: %d\n", 
               i * 10, size(s), s->capacity);
    }
    
    // 测试查看栈顶
    printf("\nTop element: %d\n", peek(s));
    
    // 测试出栈
    printf("\nPopping all elements:\n");
    while (!isEmpty(s)) {
        printf("Popped: %d, Size: %d\n", pop(s), size(s));
    }
    
    // 测试空栈弹出
    printf("\nAttempt to pop empty stack: ");
    pop(s);
    
    destroyStack(s);
    return 0;
}