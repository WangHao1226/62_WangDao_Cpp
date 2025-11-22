// 编程题

// 假设：所有字符串的长度不会超过100。

// (a) 将字符串中的字符和数字分开，使得字符串中前一部分是数字，后一部分是字母。

// void seperate(char* str);
// 输入: "h1ell2o3"
// 输出: "123hello"

#include<stdio.h>
#include<string.h>

void seperate(char* str){
    int d=0;
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]<=57&&str[i]>=48){
            char temp=str[i];
            for(int j=i;j>d;j--){
                str[j]=str[j-1];
            }
            str[d]=temp;
            d++;
        }
    }
}

int main() {
    // 方式1: 固定测试用例
    char str1[] = "h1ell2o3";
    printf("原始字符串: %s\n", str1);
    seperate(str1);
    printf("处理后结果: %s\n\n", str1);  // 输出: 123hello

    // 方式2: 用户输入测试
    char str2[101];  // 假设字符串最大长度100
    printf("请输入一个字符串（长度不超过100）: ");
    
    // 安全读取输入（包含空格）
    if (fgets(str2, sizeof(str2), stdin) ){
        // 去除末尾的换行符
        str2[strcspn(str2, "\n")] = '\0';
        
        printf("原始字符串: %s\n", str2);
        seperate(str2);
        printf("处理后结果: %s\n", str2);
    } else {
        printf("输入错误！\n");
    }

    return 0;
}
