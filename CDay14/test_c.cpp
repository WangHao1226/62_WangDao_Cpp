// 测试 7 种比较排序的性能：分别排序 10000，20000，40000，80000，16000个元素。并验证一下各个排序算法的时间复杂度 (提示：使用 clock() 函数)。

// (注意事项：1.数据的分布应该一致; 2.不要把排序后的数组传递给下一个待测函数; 3.如果栈空间不够用,可以在堆上申请空间)。

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

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

//插入排序
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

//希尔排序
void shellSort(int arr[],int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=arr[i];
            int j;
            for(j=i;j>=gap&&arr[j-gap]>temp;j-=gap){
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
    }
}

//归并排序辅助函数
void merge(int arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;

    int *L=(int*)malloc(n1*sizeof(int));
    int *R=(int*)malloc(n2*sizeof(int));

    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[m+1+j];
    }

    int i=0,j=0,k=l;
    while (i<n1&&j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    while ((i<n1)){
        arr[k]=L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

//归并排序
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

//快速排序辅助函数
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=(low-1);

    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return (i+1);
}

//快速排序
void quickSort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

//堆排序辅助函数
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n&&arr[left]>arr[largest]){
        largest=left;
    }

    if(right<n&&arr[right]>arr[largest]){
        largest=right;
    }

    if(largest!=i){
        int swap=arr[i];
        arr[i]=arr[largest];
        arr[largest]=swap;
        heapify(arr,n,largest);
    }
}

//堆排序
void heapSort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }

    for(int i=n-1;i>0;i--){
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr,i,0);
    }
}

//生成随机数组
int* generateRandomArray(int size){
    int* arr=(int*)malloc(size*sizeof(int));
    for(int i=0;i<size;i++){
        arr[i]=rand()%1000000;
    }
    return arr;
}

//复制数组
int* copyArray(int* original,int size){
    int* copy=(int*)malloc(size*sizeof(int));
    memcpy(copy,original,size*sizeof(int));
    return copy;
}

//验证数组是否有序
int isSorted(int arr[],int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            return 0;
        }
    }
    return 1;
}

//测试算法性能
void testSortPerformance(void(*sortFunc)(int[],int),const char* name,int size){
    int* original=generateRandomArray(size);
    int* arr=copyArray(original,size);

    clock_t start=clock();
    sortFunc(arr,size);
    clock_t end=clock();

    double elapsed=(double)(end-start)*1000.0/CLOCKS_PER_SEC;

    if(!isSorted(arr,size)){
        printf("错误：%s排序失败!\n",name);
    }

    printf("%-15s | %7d | %10.2f ms\n", name, size, elapsed);

    free(original);
    free(arr);
}

//测试归并和快速排序
void testRecursiveSort(void(*sortFunc)(int[],int,int),const char* name,int size){
    int* original=generateRandomArray(size);
    int* arr=copyArray(original,size);

    clock_t start=clock();
    sortFunc(arr,0,size-1);
    clock_t end=clock();

    double elapsed=(double)(end-start)*1000.0/CLOCKS_PER_SEC;

    if (!isSorted(arr, size)) {
        printf("错误: %s 排序失败!\n", name);
    }
    
    printf("%-15s | %7d | %10.2f ms\n", name, size, elapsed);
    
    free(original);
    free(arr);
}

int main() {
    srand(time(NULL)); // 初始化随机种子
    
    int sizes[] = {10000, 20000, 40000, 80000, 160000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("排序算法        | 元素个数 | 执行时间\n");
    printf("----------------|----------|------------\n");
    
    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        
        // 测试非递归排序
        testSortPerformance(bubbleSort, "冒泡排序", size);
        testSortPerformance(selectionSort, "选择排序", size);
        testSortPerformance(insertionSort, "插入排序", size);
        testSortPerformance(shellSort, "希尔排序", size);
        testSortPerformance(heapSort, "堆排序", size);
        
        // 测试递归排序
        testRecursiveSort(mergeSort, "归并排序", size);
        testRecursiveSort(quickSort, "快速排序", size);
        
        printf("\n");
    }
    
    return 0;
}