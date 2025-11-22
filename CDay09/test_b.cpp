// (b) 如何通过结构体获取成员，如何通过指向结构体的指针获取成员？

// 1. 通过结构体变量访问成员
// 使用 . 运算符 直接访问成员：

// c
// typedef struct student_s {
//     int number;
//     char name[25];
// } Student;

// int main() {
//     Student s;  // 定义结构体变量
//     s.number = 1001;           // 直接访问成员
//     strcpy(s.name, "Alice");   // 操作成员数组
//     return 0;
// }
// 2. 通过指向结构体的指针访问成员
// 使用 -> 运算符 或 (*指针).成员 访问成员：

// c
// typedef struct student_s {
//     int number;
//     char name[25];
// } Student;

// int main() {
//     Student s;
//     Student *p = &s;  // 定义指向结构体的指针

//     // 方式1: 使用 -> 运算符
//     p->number = 1002;         // 等效于 (*p).number = 1002
//     strcpy(p->name, "Bob");   // 操作指针指向的成员

//     // 方式2: 解引用后使用 . 运算符
//     (*p).number = 1003;       // 与 p->number 等价
//     strcpy((*p).name, "Charlie");

//     return 0;
// }