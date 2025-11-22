#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// 哈希表大小（素数，减少冲突）
#define TABLE_SIZE 53

// 哈希表节点结构
typedef struct HashNode {
    char letter;          // 字母（存储小写形式）
    int count;            // 出现次数
    struct HashNode *next; // 解决冲突的链表指针
} HashNode;

// 哈希表结构
typedef struct {
    HashNode **buckets;   // 桶数组
    int size;             // 哈希表大小
} HashTable;

// 创建哈希表
HashTable* createHashTable(int size) {
    HashTable *table = (HashTable*)malloc(sizeof(HashTable));
    table->size = size;
    table->buckets = (HashNode**)calloc(size, sizeof(HashNode*));
    return table;
}

// 哈希函数：将字母映射到索引
int hashFunction(char letter, int tableSize) {
    // 确保字母是小写
    char c = tolower(letter);
    // 简单哈希：字母的ASCII值取模
    return (c - 'a') % tableSize;
}

// 在哈希表中插入或更新字母计数
void insertOrUpdate(HashTable *table, char letter) {
    // 只处理字母字符
    if (!isalpha(letter)) return;
    
    // 转换为小写
    char c = tolower(letter);
    int index = hashFunction(c, table->size);
    
    // 查找该桶中是否已有此字母
    HashNode *current = table->buckets[index];
    while (current != NULL) {
        if (current->letter == c) {
            current->count++;
            return;
        }
        current = current->next;
    }
    
    // 创建新节点
    HashNode *newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->letter = c;
    newNode->count = 1;
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;
}

// 从哈希表中获取字母计数
int getCount(HashTable *table, char letter) {
    char c = tolower(letter);
    int index = hashFunction(c, table->size);
    
    HashNode *current = table->buckets[index];
    while (current != NULL) {
        if (current->letter == c) {
            return current->count;
        }
        current = current->next;
    }
    
    return 0; // 字母不存在
}

// 打印哈希表内容
void printHashTable(HashTable *table) {
    printf("\n字母频率统计表（不区分大小写）：\n");
    printf("┌───────┬───────┐\n");
    printf("│ 字母  │ 频率  │\n");
    printf("├───────┼───────┤\n");
    
    // 为字母排序准备数据
    HashNode *letters[26] = {NULL};
    int totalLetters = 0;
    
    // 收集所有字母节点
    for (int i = 0; i < table->size; i++) {
        HashNode *current = table->buckets[i];
        while (current != NULL) {
            int idx = current->letter - 'a';
            letters[idx] = current;
            totalLetters += current->count;
            current = current->next;
        }
    }
    
    // 按字母顺序打印
    for (int i = 0; i < 26; i++) {
        if (letters[i] != NULL) {
            printf("│   %c   │ %5d │\n", letters[i]->letter, letters[i]->count);
        }
    }
    
    printf("└───────┴───────┘\n");
    printf("总计字母数: %d\n\n", totalLetters);
}

// 可视化字母频率
void visualizeFrequencies(HashTable *table) {
    printf("字母频率可视化：\n");
    printf("(每个 '*' 代表100次出现)\n\n");
    
    // 为字母排序准备数据
    HashNode *letters[26] = {NULL};
    int maxCount = 0;
    
    // 收集所有字母节点并找到最大计数
    for (int i = 0; i < table->size; i++) {
        HashNode *current = table->buckets[i];
        while (current != NULL) {
            int idx = current->letter - 'a';
            letters[idx] = current;
            if (current->count > maxCount) {
                maxCount = current->count;
            }
            current = current->next;
        }
    }
    
    // 计算比例因子
    int scale = (maxCount > 500) ? 100 : 10;
    if (maxCount <= 10) scale = 1;
    
    // 按字母顺序打印
    for (int i = 0; i < 26; i++) {
        if (letters[i] != NULL) {
            int count = letters[i]->count;
            int bars = (int)round((double)count / scale);
            
            printf("%c: %5d | ", letters[i]->letter, count);
            for (int j = 0; j < bars; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
    
    printf("\n比例: 每个 '*' = %d 次出现\n", scale);
}

// 释放哈希表内存
void freeHashTable(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        HashNode *current = table->buckets[i];
        while (current != NULL) {
            HashNode *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}

// 主函数
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("使用方法: %s <文件名>\n", argv[0]);
        printf("示例: %s sample.txt\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        perror("打开文件失败");
        return 1;
    }
    
    printf("正在分析文件: %s\n", filename);
    
    // 创建哈希表
    HashTable *table = createHashTable(TABLE_SIZE);
    
    // 读取文件并统计字母
    int ch;
    while ((ch = fgetc(file))) {
        if (ch == EOF) break;
        insertOrUpdate(table, (char)ch);
    }
    
    fclose(file);
    
    // 打印结果
    printHashTable(table);
    visualizeFrequencies(table);
    
    // 释放内存
    freeHashTable(table);
    
    return 0;
}
