// (b) 输入某一天的年月日，输出下一天的年月日。

#include<stdio.h>

int dayOfMonth[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};

bool isLeapYear(int year){
    return (year%400==0)||(year%4==0&&year%100!=0);
}

void addOneDay(int &year,int &month,int &day){
    day++;
    if(day>dayOfMonth[isLeapYear(year)][month]){
        month++;
        day=1;
    }
    if(month>12){
        year++;
        month=1;
    }
}

int main(){
    int year,month,day;
    scanf("%d%d%d",&year,&month,&day);
    addOneDay(year,month,day);
    printf("%04d年%02d月%02d日",year,month,day);

    return 0;
}
