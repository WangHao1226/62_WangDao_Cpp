//写一个程序，实现分数相加。用户以分子/分母的形式输入分数，程序打印相加后的结果(化为最简分数)。如：
//
//输入:
//Enter first fraction: 5/6
//Enter second fraction: 3/4
//输出：
//The sum is 19/12

#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b){
    a=abs(a);
    b=abs(b);
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

int main() {
    int num1=0,deno1=0;
    printf("Enter first fraction:\n");
    scanf("%d/%d",&num1,&deno1);

    int num2=0,deno2=0;
    printf("Enter second fraction:\n");
    scanf("%d/%d",&num2,&deno2);

    int result_num=num1*deno2+num2*deno1;
    int result_deno=deno1*deno2;
    int result_gcd=gcd(result_num,result_deno);

    printf("The sum is %d/%d\n",result_num/result_gcd,result_deno/result_gcd);

    return 0;
}
