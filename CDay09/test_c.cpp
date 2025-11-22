// ©(学生信息处理)有这样一种学生结构体类型，其数据成员有包括学号，性别，姓名和3门课程的成绩。实现下列功能：

// 从键盘输入5个学生的信息，将这些同学的信息采用结构体数组的方式存储起来。
// 输出每门课程最高分的学生信息。
// 输出每门课程的平均分。
// 按照总分从高到低对学生进行排序，并输出排序后的学生信息。

#include<stdio.h>

typedef struct student_s{
    int number;
    char name[25];
    char gender;
    int chinese;
    int math;
    int english;
}Student;

void print_stu_info(struct student_s *p){
    printf("%d %s %c %d %d %d\n",p->number,p->name,p->gender,p->chinese,p->math,p->english);
}

int total_score(Student *p){
    return p->chinese+p->math+p->english;
}

int cmp(Student *p1,Student *p2){
    int total1=total_score(p1);
    int total2=total_score(p2);

    return total2-total1;
}

void swap(Student *arr[],int i,int j){
    Student *tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
}

void sort_student(Student *arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIdx=i;
        for(int j=i+1;j<n;j++){
            if(cmp(arr[j],arr[minIdx])<0){
                minIdx=j;
            }
        }
        swap(arr,i,minIdx);
    }
}

void print_score(Student students[],int n){
    int idx1=0;
    int idx2=0;
    int idx3=0;

    for(int i=1;i<n;i++){
        if(students[i].chinese>students[idx1].chinese){
            idx1=i;
        }
        if(students[i].math>students[idx1].math){
            idx1=i;
        }
        if(students[i].english>students[idx1].english){
            idx1=i;
        }
    }

    print_stu_info(&students[idx1]);
    print_stu_info(&students[idx2]);
    print_stu_info(&students[idx3]);
}

void print_average_score(Student students[],int n){
    double avg1=0;
    double avg2=0;
    double avg3=0;

    for(int i=0;i<n;i++){
        avg1+=students[i].chinese;
        avg2+=students[i].math;
        avg3+=students[i].english;
    }

    printf("Average score of chinese:%2lf\n",avg1/n);
    printf("Average score of math:%2lf\n",avg2/n);
    printf("Average score of english:%2lf\n",avg3/n);
}

int main(){
    Student students[5];
    for(int i=0;i<5;i++){
        scanf("%d%s %c%d%d%d",&students[i].number,students[i].name,&students[i].gender,&students[i].chinese,&students[i].math,&students[i].english);
    }
    print_score(students,5);
    print_average_score(students,5);
    Student* pstus[]={students,students+1,students+2,students+3,students+4};
    sort_student(pstus,5);
    for(int i=0;i<5;i++){
        print_stu_info(pstus[i]);
    }
    return 0;
}