// 约瑟夫环：n 个人站成一圈，每 m 个人处决一个人。假设这 n 个人的编号为 1, 2, …, n，并且从 1 开始数，问最终活下来的人编号是多少？

#include<stdio.h>

int joseph(int n,int m){
    if(n==1){
        return 0;
    }
    return (joseph(n-1,m)+m)%n;
}

int main(){
    printf("n 个人站成一圈，每 m 个人处决一个人\n");
    printf("输入n和m(空格分隔):");
    int n,m;
    scanf("%d %d",&n,&m);

    printf("最终活下来的人是:%d",joseph(n,m)+1);

    return 0;
}