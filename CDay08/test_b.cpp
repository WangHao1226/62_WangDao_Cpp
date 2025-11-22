// (b) 请总结一下今天学过的和字符串相关的库函数。
// 一、基本字符串操作
// 1. strlen
// 功能：计算字符串长度（不包含 \0）。

// 原型：size_t strlen(const char *str);

// 示例：

// c
// char str[] = "hello";
// int len = strlen(str); // len = 5
// 2. strcpy 和 strncpy
// 功能：复制字符串（strncpy 可指定最大复制长度）。

// 原型：

// c
// char *strcpy(char *dest, const char *src);
// char *strncpy(char *dest, const char *src, size_t n);
// 注意：

// strcpy 不安全（可能缓冲区溢出），推荐使用 strncpy 或 snprintf。

// strncpy 不会自动添加 \0，需手动处理。

// 3. strcat 和 strncat
// 功能：拼接字符串（将 src 追加到 dest 末尾）。

// 原型：

// c
// char *strcat(char *dest, const char *src);
// char *strncat(char *dest, const char *src, size_t n);
// 注意：需确保 dest 有足够空间。

// 二、字符串比较
// 1. strcmp 和 strncmp
// 功能：比较两个字符串（按字典序）。

// 原型：

// c
// int strcmp(const char *s1, const char *s2);
// int strncmp(const char *s1, const char *s2, size_t n);
// 返回值：

// 0：字符串相等。

// 正数：s1 > s2。

// 负数：s1 < s2。

// 三、字符串查找
// 1. strchr 和 strrchr
// 功能：查找字符在字符串中的位置。

// 原型：

// c
// char *strchr(const char *str, int c);  // 从左向右找
// char *strrchr(const char *str, int c); // 从右向左找
// 返回值：找到返回指针，否则返回 NULL。

// 2. strstr
// 功能：查找子串在字符串中的位置。

// 原型：char *strstr(const char *haystack, const char *needle);

// 示例：

// c
// char str[] = "hello world";
// char *p = strstr(str, "world"); // p指向"world"
