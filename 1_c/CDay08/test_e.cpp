// (b) 将字符串中的空格替换成 %020 (假定原字符数组能够存放替换后的字符串)。

// void substitute_space(char* str);
// 输入: "hello world how "
// 输出: "hello%020world%020how%020"

#include<stdio.h>
#include<string.h>

void substitute_space(char* str){
    int space_count=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' '){
            space_count++;
        }
    }

    int old_len=strlen(str);
    int new_len=old_len+3*space_count;

    int i=old_len-1;
    int j=new_len-1;

    while(i>=0){
        if(str[i]==' '){
            str[j--]='0';
            str[j--]='2';
            str[j--]='0';
            str[j--]='%';
            i--;
        }else{
            str[j--]=str[i--];
        }
    }
    str[new_len]='\0';
}

int main() {
    char str[] = "hello world how ";
    printf("原始字符串: %s\n", str);
    substitute_space(str);
    printf("替换后结果: %s\n", str);  // 输出 hello%020world%020how%020
    return 0;
}