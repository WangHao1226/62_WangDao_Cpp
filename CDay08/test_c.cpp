// 请总结字符串的一些惯用法 (搜索字符串的末尾、复制字符串)
// 一、搜索字符串末尾
// 1. 手动遍历字符串
// c
// char str[] = "hello";
// char *p = str;
// while (*p != '\0') {  // 遍历直到遇到 '\0'
//     p++;
// }
// // 此时 p 指向字符串末尾的 '\0'
// 2. 直接定位末尾
// c
// char str[] = "world";
// char *end = str + strlen(str); // end 指向 '\0'
// 3. 反向查找字符
// c
// char str[] = "test.txt";
// char *last_dot = strrchr(str, '.'); // 找到最后一个 '.' 的位置
// if (last_dot != NULL) {
//     printf("文件扩展名: %s\n", last_dot + 1); // 输出 "txt"
// }
// 二、复制字符串
// 1. 使用 strcpy
// c
// char src[] = "source";
// char dest[20];
// strcpy(dest, src); // dest = "source"
// 风险：若 dest 空间不足，会导致缓冲区溢出。

// 2. 安全复制（strncpy + 手动添加 \0）
// c
// char src[] = "safe copy";
// char dest[10];
// strncpy(dest, src, sizeof(dest) - 1); // 最多复制 sizeof(dest)-1 字符
// dest[sizeof(dest) - 1] = '\0';        // 确保终止符
// 3. 使用 snprintf（推荐）
// c
// char src[] = "example";
// char dest[10];
// snprintf(dest, sizeof(dest), "%s", src); // 自动添加 '\0'
// 4. 动态内存复制（strdup）
// c
// char *src = "dynamic";
// char *dest = strdup(src); // 分配堆内存并复制
// // 使用后必须释放
// free(dest);
// 5. 手动实现字符串复制
// c
// char *src = "manual";
// char dest[20];
// char *d = dest;
// const char *s = src;
// while ((*d++ = *s++) != '\0'); // 逐字符复制
// 三、常见惯用法场景
// 1. 字符串拼接
// c
// char path[100] = "/home/user/";
// const char *filename = "file.txt";
// strncat(path, filename, sizeof(path) - strlen(path) - 1); // 安全拼接
// 2. 截断字符串
// c
// char str[] = "hello world";
// str[5] = '\0'; // 截断为 "hello"
// 3. 遍历字符串字符
// c
// char str[] = "iterate";
// for (char *p = str; *p != '\0'; p++) {
//     putchar(*p); // 逐个输出字符
// }
// 4. 检查空字符串
// c
// if (str[0] == '\0') {  // 等价于 if (strlen(str) == 0)
//     printf("空字符串\n");
// }