// (a) 动态内存分配函数有哪些？它们的功能是什么？

// 1. malloc —— 分配未初始化的内存块
// 函数原型：
// c
// void* malloc(size_t size);
// 功能：
// 分配 size字节的连续内存块，内存内容未初始化（值为随机垃圾数据）。

// 若分配成功，返回指向内存块起始地址的 void*指针；失败则返回 NULL。

// 示例：
// c
// int *arr = (int*)malloc(10 * sizeof(int)); // 分配10个int的空间
// if (arr == NULL) {
//     // 处理内存分配失败
// }
// 2. calloc —— 分配并初始化内存块
// 函数原型：
// c
// void* calloc(size_t num, size_t size);
// 功能：
// 分配 num * size字节的连续内存块，并将所有位初始化为 0。

// 适用于需要清零内存的场景（如数组、结构体）。

// 返回值同 malloc。

// 示例：
// c
// int *arr = (int*)calloc(10, sizeof(int)); // 分配并清零10个int的空间
// 3. realloc —— 调整已分配内存块的大小
// 函数原型：
// c
// void* realloc(void* ptr, size_t new_size);
// 功能：
// 调整 ptr 指向的内存块大小为 new_size字节。

// 若 new_size > 原大小：扩展内存，新增部分未初始化。

// 若 new_size < 原大小：截断内存，保留前 new_size 字节。

// 若 ptr 为 NULL，则等价于 malloc(new_size)。

// 可能 移动内存块到新地址（原数据被复制到新位置）。

// 失败时返回 NULL，但 原内存块仍有效，需手动释放。

// 示例：
// c
// int *arr = (int*)malloc(5 * sizeof(int));
// int *new_arr = (int*)realloc(arr, 10 * sizeof(int)); // 扩展为10个int
// if (new_arr == NULL) {
//     free(arr); // 失败时需释放原内存
// } else {
//     arr = new_arr; // 更新指针
// }
// 4. free —— 释放动态分配的内存
// 函数原型：
// c
// void free(void* ptr);
// 功能：
// 释放 ptr 指向的内存块（由 malloc、calloc 或 realloc 分配）。

// 不可重复释放同一指针（会导致未定义行为）。

// 释放后应将指针置为 NULL，避免悬垂指针。

// 示例：
// c
// int *arr = (int*)malloc(10 * sizeof(int));
// free(arr);
// arr = NULL; // 防止误用