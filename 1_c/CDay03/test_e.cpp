// (e) 输入1970年之后任意一年的年份，输出该年的年历。对话如下：(拓展题，不要求每个同学作答)
// 输入：
// Please input the year whose calendear you want to know?
// 2004
// 输出：
// |=====================The Calendar of Year 2004====================|
// :  1  SUN MON TUE WED THU FRI SAT   7  SUN MON TUE WED THU FRI SAT :
// :                       1   2   3                        1   2   3 :
// :       4   5   6   7   8   9  10        4   5   6   7   8   9  10 :
// :      11  12  13  14  15  16  17       11  12  13  14  15  16  17 :
// :      18  19  20  21  22  23  24       18  19  20  21  22  23  24 :
// :      25  26  27  28  29  30  31       25  26  27  28  29  30  31 :
// :  2  SUN MON TUE WED THU FRI SAT   8  SUN MON TUE WED THU FRI SAT :
// :       1   2   3   4   5   6   7        1   2   3   4   5   6   7 :
// :       8   9  10  11  12  13  14        8   9  10  11  12  13  14 :
// :      15  16  17  18  19  20  21       15  16  17  18  19  20  21 :
// :      22  23  24  25  26  27  28       22  23  24  25  26  27  28 :
// :      29                               29  30  31                 :
// :  3  SUN MON TUE WED THU FRI SAT   9  SUN MON TUE WED THU FRI SAT :
// :           1   2   3   4   5   6                    1   2   3   4 :
// :       7   8   9  10  11  12  13        5   6   7   8   9  10  11 :
// :      14  15  16  17  18  19  20       12  13  14  15  16  17  18 :
// :      21  22  23  24  25  26  27       19  20  21  22  23  24  25 :
// :      28  29  30  31                   26  27  28  29  30         :
// :  4  SUN MON TUE WED THU FRI SAT  10  SUN MON TUE WED THU FRI SAT :
// :                       1   2   3                            1   2 :
// :       4   5   6   7   8   9  10        3   4   5   6   7   8   9 :
// :      11  12  13  14  15  16  17       10  11  12  13  14  15  16 :
// :      18  19  20  21  22  23  24       17  18  19  20  21  22  23 :
// :      25  26  27  28  29  30           24  25  26  27  28  29  30 :
// :                                       31                         :
// :  5  SUN MON TUE WED THU FRI SAT  11  SUN MON TUE WED THU FRI SAT :
// :                               1            1   2   3   4   5   6 :
// :       2   3   4   5   6   7   8        7   8   9  10  11  12  13 :
// :       9  10  11  12  13  14  15       14  15  16  17  18  19  20 :
// :      16  17  18  19  20  21  22       21  22  23  24  25  26  27 :
// :      23  24  25  26  27  28  29       28  29  30                 :
// :      30  31                                                      :
// :  6  SUN MON TUE WED THU FRI SAT  12  SUN MON TUE WED THU FRI SAT :
// :               1   2   3   4   5                    1   2   3   4 :
// :       6   7   8   9  10  11  12        5   6   7   8   9  10  11 :
// :      13  14  15  16  17  18  19       12  13  14  15  16  17  18 :
// :      20  21  22  23  24  25  26       19  20  21  22  23  24  25 :
// :      27  28  29  30                   26  27  28  29  30  31     :
// |==================================================================|

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

struct month_info {
    int weeks_num;
    char weeks[6][22];
};

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int get_month_days(int year, int month) {
    if (month == 2) {
        return is_leap_year(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

void generate_month(int year, int month, struct month_info *minfo) {
    struct tm t = {0};
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = 1;
    t.tm_isdst = -1;

    mktime(&t);
    int first_day = t.tm_wday; // 0 = Sunday, ..., 6 = Saturday
    int days = get_month_days(year, month);

    int total = days + first_day;
    int weeks_num = (total + 6) / 7;
    minfo->weeks_num = weeks_num;

    for (int i = 0; i < 6; ++i) {
        if (i < weeks_num) {
            char week_str[22] = {0};
            for (int j = 0; j < 7; ++j) {
                int day = i * 7 + j - first_day + 1;
                if (day >= 1 && day <= days) {
                    sprintf(week_str + j * 3, "%3d", day);
                } else {
                    sprintf(week_str + j * 3, "   ");
                }
            }
            strcpy(minfo->weeks[i], week_str);
        } else {
            strcpy(minfo->weeks[i], "                     "); // 21 spaces
        }
    }
}

int main() {
    int year;
    printf("Please input the year whose calendar you want to know?\n");
    scanf("%d", &year);

    struct month_info months[12];
    for (int m = 1; m <= 12; ++m) {
        generate_month(year, m, &months[m - 1]);
    }

    // Print top border
    char title[60];
    int title_len = snprintf(title, sizeof(title), "The Calendar of Year %d", year);
    int equals_left = (60 - title_len - 2) / 2;
    int equals_right = 60 - title_len - 2 - equals_left;
    printf("|");
    for (int i = 0; i < equals_left; ++i) putchar('=');
    printf("%s", title);
    for (int i = 0; i < equals_right; ++i) putchar('=');
    printf("|\n");

    // Print each month pair
    for (int m = 0; m < 6; ++m) {
        struct month_info *left = &months[m];
        struct month_info *right = &months[m + 6];

        // Header line
        printf(": %2d  SUN MON TUE WED THU FRI SAT   %2d  SUN MON TUE WED THU FRI SAT :\n", m + 1, m + 7);

        int max_weeks = left->weeks_num > right->weeks_num ? left->weeks_num : right->weeks_num;
        for (int i = 0; i < max_weeks; ++i) {
            char left_line[25], right_line[25];
            const char *left_week = i < left->weeks_num ? left->weeks[i] : "                     ";
            const char *right_week = i < right->weeks_num ? right->weeks[i] : "                     ";
            snprintf(left_line, sizeof(left_line), "   %s", left_week);
            snprintf(right_line, sizeof(right_line), "   %s", right_week);
            printf(": %s   %s :\n", left_line, right_line);
        }
    }

    // Print bottom border
    printf("|");
    for (int i = 0; i < 58; ++i) putchar('=');
    printf("|\n");

    return 0;
}