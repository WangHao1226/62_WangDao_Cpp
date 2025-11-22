// 编写函数：
// void split_time(long total_sec, int* hour, int* minute, int* second);
// total_sec 表示从午夜12:00:00开始计算的秒数。请将 total_sec 转化以
// 时(0-23)、分(0-59)、秒(0-59)表示的时间，并存放到由 hour, minute, second 指向的变量中。

#include<stdio.h>

void split_time(long total_sec, int* hour, int* minute, int* second){
    total_sec=total_sec%84600;
    if(total_sec<0){
        total_sec+=84600;
    }

    *hour=total_sec/3600;
    int remaining_sec=total_sec%3600;
    *minute=remaining_sec/60;
    *second=remaining_sec%60;
}

int main() {
    int h, m, s;

    // 测试正常时间
    split_time(3661, &h, &m, &s);
    printf("3661秒 → %02d:%02d:%02d\n", h, m, s);  // 输出 01:01:01

    // 测试午夜
    split_time(0, &h, &m, &s);
    printf("0秒 → %02d:%02d:%02d\n", h, m, s);     // 输出 00:00:00

    // 测试负数
    split_time(-100, &h, &m, &s);
    printf("-100秒 → %02d:%02d:%02d\n", h, m, s);  // 输出 23:58:20

    // 测试超过一天
    split_time(90125, &h, &m, &s);
    printf("90125秒 → %02d:%02d:%02d\n", h, m, s); // 输出 01:02:05

    return 0;
}