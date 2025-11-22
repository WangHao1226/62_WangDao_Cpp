// 请实现下列二分查找的变种：
// // 查找最后一个与 key 相等的元素
// int binary_search1(int arr[], int n, int key);
// // 查找最后一个小于等于 key 值的元素
// int binary_search2(int arr[], int n, int key);

#include<stdio.h>

// 查找最后一个与 key 相等的元素
int binary_search1(int arr[], int n, int key){
    int left=0;
    int right=n-1;
    int result=-1;

    while(left<=right){
        int mid=left+(right-left)/2;

        if(arr[mid]==key){
            result=mid;
            left=mid+1;
        }else if(arr[mid]<key){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }

    return result;
}

// 查找最后一个小于等于 key 值的元素
int binary_search2(int arr[], int n, int key){
    int left=0;
    int right=n-1;
    int result=-1;

    while(left<=right){
        int mid=left+(right-left)/2;

        if(arr[mid]<=key){
            result=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }

    return result;
}


// 测试函数
int main() {
    // 测试数组 (已排序)
    int arr[] = {1, 2, 2, 2, 3, 4, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // 测试 binary_search1
    printf("查找最后一个与key相等的元素:\n");
    int keys[] = {2, 4, 5, 0, 8};
    for (int i = 0; i < sizeof(keys)/sizeof(keys[0]); i++) {
        int idx = binary_search1(arr, n, keys[i]);
        if (idx != -1) {
            printf("最后一个 %d 在位置 %d (arr[%d]=%d)\n", 
                   keys[i], idx, idx, arr[idx]);
        } else {
            printf("未找到 %d\n", keys[i]);
        }
    }
    
    printf("\n查找最后一个小于等于key的元素:\n");
    for (int i = 0; i < sizeof(keys)/sizeof(keys[0]); i++) {
        int idx = binary_search2(arr, n, keys[i]);
        if (idx != -1) {
            printf("最后一个 <= %d 的元素是 %d (位置 %d)\n", 
                   keys[i], arr[idx], idx);
        } else {
            printf("没有元素 <= %d\n", keys[i]);
        }
    }
    
    return 0;
}