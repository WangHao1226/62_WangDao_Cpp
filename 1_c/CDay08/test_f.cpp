// © 删除字符串中指定的字符。

// void delete_character(char* str, char c);
// 输入: "abcdaefaghiagkl", 'a'
// 输出: "bcdefghigkl"

#include<stdio.h>
#include<string.h>

void delete_character(char* str,char c){
    if(str==NULL){
        return;
    }

    int j=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!=c){
            str[j++]=str[i];
        }
    }
    str[j]='\0';
}

int main(){
    char arr[]="abcdaefaghiagkl";
    delete_character(arr,'a');
    printf("替换后结果: %s\n", arr);
    return 0;
}