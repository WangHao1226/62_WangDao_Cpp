// © 输入某两天的年月日，输出这两天的相距多少天。

#include <stdio.h>
#include <stdbool.h>  // 添加bool类型支持

int dayOfMonth[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},  // 平年
    {0,31,29,31,30,31,30,31,31,30,31,30,31}   // 闰年
};

bool isLeapYear(int year) {
    return (year%400 == 0) || (year%4 == 0 && year%100 != 0);
}

void addOneDay(int *year, int *month, int *day) {  // 改用指针修改值
    (*day)++;
    int leap = isLeapYear(*year);
    if (*day > dayOfMonth[leap][*month]) {
        (*month)++;
        *day = 1;
        if (*month > 12) {
            (*year)++;
            *month = 1;
        }
    }
}

// 比较日期先后：date1晚于date2返回1，否则返回0
bool isLater(int y1, int m1, int d1, int y2, int m2, int d2) {
    if (y1 != y2) return y1 > y2;
    if (m1 != m2) return m1 > m2;
    return d1 > d2;
}

int main() {
    int y1, m1, d1, y2, m2, d2;
    
    // 输入并验证日期有效性
    printf("Enter first date (yyyy mm dd): ");
    if (scanf("%d%d%d", &y1, &m1, &d1) != 3 || m1 < 1 || m1 > 12 || d1 < 1 || d1 > dayOfMonth[isLeapYear(y1)][m1]) {
        printf("Invalid first date!\n");
        return 1;
    }
    
    printf("Enter second date (yyyy mm dd): ");
    if (scanf("%d%d%d", &y2, &m2, &d2) != 3 || m2 < 1 || m2 > 12 || d2 < 1 || d2 > dayOfMonth[isLeapYear(y2)][m2]) {
        printf("Invalid second date!\n");
        return 1;
    }

    // 统一处理方向：总让date1是更晚的日期
    if (isLater(y2, m2, d2, y1, m1, d1)) {
        // 交换两个日期
        int t = y1; y1 = y2; y2 = t;
        t = m1; m1 = m2; m2 = t;
        t = d1; d1 = d2; d2 = t;
    }

    int days = 0;
    // 持续增加较早的日期直到两者相等
    while (y1 != y2 || m1 != m2 || d1 != d2) {
        addOneDay(&y2, &m2, &d2);
        days++;
    }

    printf("Days between: %d\n", days);
    return 0;
}