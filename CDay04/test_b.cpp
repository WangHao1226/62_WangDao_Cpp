// 假设 int n = 0xCAFE; 请用表达式完成下面操作 (拓展题：不要求每个同学都写)
#include <stdio.h>

int main() {
    unsigned int n = 0xCAFE;  // 原始值

    // (a) 测试最后4位是否至少有3个1
    int original_n = n;  // 保留原始值
    int bitCount = (n & 1) + ((n >> 1) & 1) + ((n >> 2) & 1) + ((n >> 3) & 1);
    int isAtLeastThree = (bitCount >= 3);
    printf("原始值: 0x%04X\n", original_n);
    printf("(a) 最后4位至少有3个1: %s\n\n", isAtLeastThree ? "是" : "否");

    // (b) 逆转字节序
    n = original_n;  // 恢复原始值
    n = ((n & 0xFF) << 8) | ((n >> 8) & 0xFF);
    printf("(b) 逆转字节序后: 0x%04X\n\n", n);

    // (c) 旋转4位（循环右移4位）
    n = original_n;  // 恢复原始值
    n = ((n >> 4) | (n << 12)) & 0xFFFF;  // 确保结果为16位
    printf("(c) 旋转4位后: 0x%04X\n", n);

    return 0;
}