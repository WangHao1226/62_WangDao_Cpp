// 矩阵乘法。写一个函数实现两个矩阵相乘，其中 M=3, Q=4, N=5.
// void matrix_multiply(int A[M][Q], int B[Q][N], int C[M][N]);
// 矩阵乘法的计算方法: 对于矩阵A[M][Q]*B[Q][N],相乘的结果为矩阵C[M][N]，且对于矩阵C中每一项都有 
// C[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j] + … + A[i][Q]*B[Q][j]

#include<stdio.h>
#define M 3
#define Q 4
#define N 5

void matrix_multiply(int A[M][Q],int B[Q][N],int C[M][N]){
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            C[i][j]=0;
            for(int k=0;k<Q;k++){
                C[i][j]=A[i][k]*B[k][j];
            }
        }
    }
}
