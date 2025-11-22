// 分别用循环和递归方式求解 n 的阶乘 n!。
#include<stdio.h>

//循环
long long factorial1(int n){
    if(n==0){
        return 1;
    }
    long long result=1;
    for(int i=1;i<=n;i++){
        result*=i;
    }
    return result;
}

//递归
long long factorial2(int n){
    if(n==0){
        return 1;
    }
    return n*factorial2(n-1);
}
int main(){
    printf("请输入n:");
    int n;
    scanf("%d",&n);
    printf("循环结果为:%d!=%d\n",n,factorial1(n));
    printf("递归结果为:%d!=%d\n",n,factorial2(n));
    return 0;
}