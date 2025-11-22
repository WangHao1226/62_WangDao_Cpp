// 查找一个数组中第k大的元素 (思考: 能否将时间复杂度降低到O(n)呢)

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

//随机分区函数
int partition(int arr[],int left,int right){
    int random_index=left+rand()%(right-left+1);
    swap(&arr[random_index],&arr[right]);
    int pivot=arr[right];

    int i=left-1;

    for(int j=left;j<right;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[right]);
    return i+1;
}

//快速选择算法
int quickSelect(int arr[],int left,int right,int k){
    if(left==right){
        return arr[left];
    }

    int pivot_index=partition(arr,left,right);
    int pos=pivot_index-left+1;

    if(k==pos){
        return arr[pivot_index];
    }else if(k<pos){
        return quickSelect(arr,left,pivot_index-1,k);
    }else{
        return quickSelect(arr,pivot_index+1,right,k-pos);
    }
}

//查找第k大的元素
int findKthLargest(int arr[],int n,int k){
    srand(time(NULL));
    return quickSelect(arr,0,n-1,n-k+1);
}

int main() {
    int arr[] = {3, 2, 1, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // 测试各种k值
    for (int k = 1; k <= n; k++) {
        int kth = findKthLargest(arr, n, k);
        printf("第%d大的元素是: %d\n", k, kth);
    }
    
    // 测试包含重复元素的数组
    int arr2[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("\n包含重复元素的数组:\n");
    for (int k = 1; k <= n2; k++) {
        int kth = findKthLargest(arr2, n2, k);
        printf("第%d大的元素是: %d\n", k, kth);
    }
    
    return 0;
}
