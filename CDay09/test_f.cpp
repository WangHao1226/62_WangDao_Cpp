// © 什么叫垃圾？什么是内存泄漏？如何避免内存泄漏？

// 1. 什么是“垃圾”（Garbage）？
// 定义：
// “垃圾”指的是程序中 动态分配但不再被任何指针引用 的内存块。这些内存无法再被程序访问或使用，但仍占用系统资源。

// 示例：

// c
// int *ptr = malloc(sizeof(int));  // 分配内存
// ptr = malloc(sizeof(int));      // 重新分配，原内存块变为“垃圾”
// 第二次调用 malloc 后，原内存块未被释放且无指针指向它，成为垃圾。

// 关键点：
// C语言 没有自动垃圾回收机制，垃圾内存必须手动通过 free 释放，否则会导致内存泄漏。

// 2. 什么是内存泄漏（Memory Leak）？
// 定义：
// 内存泄漏指程序 动态分配内存后，无法释放已不再需要的内存。这些内存会持续占用系统资源，直到程序终止。

// 常见场景：

// 忘记调用 free：

// c
// int *arr = malloc(10 * sizeof(int));
// // 忘记 free(arr);
// 指针丢失：

// c
// int *ptr = malloc(sizeof(int));
// ptr = NULL;  // 原内存块地址丢失，无法释放
// 复杂逻辑中遗漏释放（如条件分支、循环、函数返回等）。

// 危害：
// 长期运行的程序中，内存泄漏会逐渐消耗系统内存，导致性能下降或崩溃。

// 3. 如何避免内存泄漏？
// (1) 基本原则：配对使用 malloc 和 free
// 谁分配，谁释放：确保每个 malloc/calloc/realloc 都有对应的 free。

// 示例：

// c
// int *create_array(int size) {
//     int *arr = malloc(size * sizeof(int));
//     return arr;
// }

// int main() {
//     int *data = create_array(10);
//     // 使用data...
//     free(data);  // 调用者负责释放
//     data = NULL; // 避免悬垂指针
//     return 0;
// }
// (2) 使用工具检测内存泄漏
// Valgrind（Linux/macOS）：

// bash
// valgrind --leak-check=full ./your_program
// AddressSanitizer（ASan）（GCC/Clang）：

// bash
// gcc -fsanitize=address -g your_program.c -o your_program
// (3) 编程规范与技巧
// 初始化指针为 NULL：

// c
// int *ptr = NULL;  // 避免野指针
// 释放后置指针为 NULL：

// c
// free(ptr);
// ptr = NULL;  // 防止重复释放或误用
// 避免复杂的指针操作：
// 简化内存管理逻辑，减少指针重新赋值。

// 封装内存管理函数：
// 例如，自定义安全的分配/释放函数：

// c
// void* safe_malloc(size_t size) {
//     void *ptr = malloc(size);
//     if (ptr == NULL) {
//         fprintf(stderr, "内存分配失败！\n");
//         exit(EXIT_FAILURE);
//     }
//     return ptr;
// }

// void safe_free(void **ptr) {
//     free(*ptr);
//     *ptr = NULL;
// }
// (4) 数据结构中的内存管理
// 链表/树等动态结构：
// 确保释放所有节点，例如递归释放链表：

// c
// void free_list(Node *head) {
//     if (head == NULL) return;
//     free_list(head->next);
//     free(head);
// }
// 多维数组：
// 逐层释放：

// c
// int **matrix = malloc(rows * sizeof(int*));
// for (int i = 0; i < rows; i++) {
//     matrix[i] = malloc(cols * sizeof(int));
// }
// // 释放：
// for (int i = 0; i < rows; i++) {
//     free(matrix[i]);
// }
// free(matrix);