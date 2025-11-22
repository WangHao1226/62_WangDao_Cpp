// (a) 下面结构体类型的变量的内存布局是怎样的？

// typedef struct stundent_s {
//     int number;
//     char name[25];
//     char gender;
//     int chinese;
//     int math;
//     int english;
// } Student;

// Student s;

// 1. 成员定义与对齐规则
// c
// typedef struct student_s {
//     int number;     // 4字节，对齐要求4字节
//     char name[25];  // 25字节，对齐要求1字节
//     char gender;    // 1字节，对齐要求1字节
//     int chinese;    // 4字节，对齐要求4字节
//     int math;       // 4字节，对齐要求4字节
//     int english;    // 4字节，对齐要求4字节
// } Student;
// 2. 内存布局步骤分析
// (1) 起始地址
// 假设结构体起始地址为 0，各成员按声明顺序排列。

// (2) number 的布局
// 类型：int（4字节）

// 对齐要求：4字节对齐。

// 地址范围：0~3。

// (3) name[25] 的布局
// 类型：char[25]（25字节）

// 对齐要求：1字节对齐。

// 地址范围：4~28（紧跟 number，无需填充）。

// (4) gender 的布局
// 类型：char（1字节）

// 对齐要求：1字节对齐。

// 地址范围：29（紧跟 name，无需填充）。

// (5) 填充字节
// 原因：下一个成员 chinese 是 int，需满足4字节对齐。

// 填充长度：3字节（地址 30~32 填充空数据）。

// 对齐后地址：chinese 起始地址为 32。

// (6) chinese, math, english 的布局
// 类型：int（各4字节）

// 地址范围：

// chinese：32~35

// math：36~39

// english：40~43

// 3. 结构体总大小
// 总长度：44 字节。

// 尾部填充：无（44 是最大对齐值 4 的整数倍）。

// 4. 内存布局图示
// 地址范围	成员	大小（字节）	备注
// 0~3	number	4	起始地址对齐到4
// 4~28	name[25]	25	连续存放
// 29	gender	1	紧跟 name
// 30~31	填充	2	对齐到 chinese
// 32~35	chinese	4	对齐到4
// 36~39	math	4	连续存放
// 40~43	english	4	连续存放
