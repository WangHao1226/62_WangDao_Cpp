// 请实现选择排序和冒泡排序，并分析它们的时间复杂度，空间复杂度和稳定性。

#include<stdio.h>

//选择排序
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }

        int temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
}

//冒泡排序
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int swapped=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=1;
            }
        }
        if(!swapped) break;
    }
}

// 打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {64, 25, 12, 22, 11};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("原始数组 (选择排序): ");
    printArray(arr1, n1);
    selectionSort(arr1, n1);
    printf("选择排序后: ");
    printArray(arr1, n1);
    
    int arr2[] = {5, 1, 4, 2, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("\n原始数组 (冒泡排序): ");
    printArray(arr2, n2);
    bubbleSort(arr2, n2);
    printf("冒泡排序后: ");
    printArray(arr2, n2);
    
    return 0;
}


// 算法分析：
// 1. 选择排序 (Selection Sort)
// 时间复杂度：

// 最好/最坏/平均：O(n²)
// （无论数据如何分布，都需要进行 n(n-1)/2 次比较）

// 空间复杂度：O(1)
// （原地排序，仅使用常数级额外空间）

// 稳定性：❌ 不稳定
// 原因：元素交换可能破坏相对顺序（例：[3, 3, 2] → 第一个3与2交换后移到第二个3之后）

// 2. 冒泡排序 (Bubble Sort)
// 时间复杂度：

// 最好：O(n)（已有序时，通过优化提前退出）

// 最坏/平均：O(n²)（完全逆序时需完整执行）

// 空间复杂度：O(1)
// （原地排序，仅使用常数级额外空间）

// 稳定性：✅ 稳定
// 原因：相等元素不会交换（只有前>后才交换），保持原始相对顺序