// (d) 已知1970年1月1日是星期四，输入之后的某一天的年月日，判断它是星期几？

#include<stdio.h>

int dayOfMonth[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};

bool isLeapYear(int year){
    return (year%400==0)||(year%4==0&&year%100!=0);
}

int distance(int year, int month, int day) {
    int totalDays = 0;

    // 累加完整年份的天数
    for (int y = 1970; y < year; y++) {
        totalDays += isLeapYear(y) ? 366 : 365;
    }

    // 累加当年已过月份的天数
    for (int m = 1; m < month; m++) {
        totalDays += dayOfMonth[isLeapYear(year)][m];
    }

    // 累加当月已过天数（注意减1）
    totalDays += day - 1;

    return totalDays;
}

int weekday(int year, int month, int day) {
	int days = distance(year, month, day);
	return (4 + days) % 7;
}

int main() {
    int year, month, day;

    // 输入日期
    printf("Enter date (yyyy mm dd): ");
    if (scanf("%d%d%d", &year, &month, &day) != 3) {
        printf("Invalid input format.\n");
        return 1;
    }

    // 校验年份
    if (year < 1970) {
        printf("Year must be >= 1970.\n");
        return 1;
    }

    // 校验月份
    if (month < 1 || month > 12) {
        printf("Invalid month.\n");
        return 1;
    }

    // 校验日期
    int leap = isLeapYear(year);
    int maxDay = dayOfMonth[leap][month];
    if (day < 1 || day > maxDay) {
        printf("Invalid day. Max day for %d-%d is %d.\n", year, month, maxDay);
        return 1;
    }

    // 计算星期几
    const char* weekdays[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };
    int wd = weekday(year, month, day);

    // 输出结果
    printf("%d-%02d-%02d is %s\n", year, month, day, weekdays[wd]);

    return 0;
}