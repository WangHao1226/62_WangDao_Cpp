// 查找数组中最大的元素和第二大的元素，并将它们分别存放在由 largest 和 second_largest 指向的变量中。

#include <stdio.h>

void find_two_largest(int arr[], int n, int* largest, int* second_largest);

int main() {
    // 定义测试用例
    int test_cases[][5] = {
        {3, 5, 2, 7, 1},   // 正常情况：最大7，次大5
        {5, 5, 3},         // 重复最大值：最大5，次大5
        {10},               // 单元素数组：最大和次大均为10
        {}                  // 空数组（长度为0）
    };
    int sizes[] = {5, 3, 1, 0};  // 每个测试用例的长度

    // 遍历所有测试用例
    for (int i = 0; i < 4; i++) {
        int* arr = test_cases[i];
        int n = sizes[i];
        int largest, second_largest;

        // 调用函数
        find_two_largest(arr, n, &largest, &second_largest);

        // 打印结果
        printf("测试用例 %d:\n", i + 1);
        if (n == 0) {
            printf("  数组为空，无结果\n");
        } else {
            printf("  数组内容: [");
            for (int j = 0; j < n; j++) {
                printf("%d", arr[j]);
                if (j < n - 1) printf(", ");
            }
            printf("]\n");
            printf("  最大值: %d, 次大值: %d\n", largest, second_largest);
        }
        printf("\n");
    }

    return 0;
}

// 之前的函数实现
void find_two_largest(int arr[], int n, int* largest, int* second_largest) {
    if (n == 0) {
        return;
    } else if (n == 1) {
        *largest = arr[0];
        *second_largest = arr[0];
        return;
    }

    if (arr[0] > arr[1]) {
        *largest = arr[0];
        *second_largest = arr[1];
    } else {
        *largest = arr[1];
        *second_largest = arr[0];
    }

    for (int i = 2; i < n; i++) {
        int current = arr[i];
        if (current > *largest) {
            *second_largest = *largest;
            *largest = current;
        } else if (current > *second_largest) {
            *second_largest = current;
        }
    }
}