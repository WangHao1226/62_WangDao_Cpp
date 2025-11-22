// 设计一个输入函数：它不会跳过前面的空白字符，如果遇到换行符或者读取了n个字符就停止读取，后面的字符不读取。并且不存储换行符。函数原型如下：

// // n 表示能够读取字符的最大个数
// // 返回值表示最终存储字符串的长度
// int readLine(char str[], int n);

#include<stdio.h>

int readLine(char str[],int n){
    if(n<=0){
        return 0;
    }

    int ch;
    int i=0;

    while (i<n&&(ch=getchar())!='\n'&&ch!=EOF){
        str[i++]=ch;
    }

    str[i]='\0';
    return i;
    
}

int main() {
    char buffer[10];
    int len;
    
    // 测试用例 1：读取不超过 n 的字符
    printf("输入 'hello\\n'（n=5）: ");
    len = readLine(buffer, 5);
    printf("结果: len=%d, str=%s\n", len, buffer); // len=5, str=hello

    // 测试用例 2：遇到换行符提前停止
    printf("输入 'hi\\n'（n=5）: ");
    len = readLine(buffer, 5);
    printf("结果: len=%d, str=%s\n", len, buffer); // len=2, str=hi

    // 测试用例 3：处理前导空白字符
    printf("输入 '   space\\n'（n=6）: ");
    len = readLine(buffer, 6);
    printf("结果: len=%6, str=%s\n", len, buffer); // len=6, str=   spa

    // 测试用例 4：输入流直接结束（EOF）
    printf("输入 'EOF'（无换行符，按 Ctrl+D/Z）: ");
    len = readLine(buffer, 5);
    printf("结果: len=%d, str=%s\n", len, buffer); // 取决于实际输入长度
}