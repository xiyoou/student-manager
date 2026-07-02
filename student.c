// student.c
#include <stdio.h>
#include <string.h>
#include "student.h"  // 必须包含自己对应的头文件，保证声明与实现一致

// 计算单科平均分
float calcAverage(const float *scores) {
    float sum = 0;
    for (int i = 0; i < SUBJECT_NUM; i++) {
        sum += scores[i];
    }
    return sum / SUBJECT_NUM;
}

// 添加学生信息
void addStudent(Student *students, int *count, int max_size) {
    if (*count >= max_size) {
        printf("学生数量已达上限，添加失败\n");
        return;
    }

    Student new_stu;
    printf("请输入学号: ");
    scanf("%d", &new_stu.id);

    // 简单校验：学号不能重复
    for (int i = 0; i < *count; i++) {
        if (students[i].id == new_stu.id) {
            printf("该学号已存在，添加失败\n");
            return;
        }
    }

    printf("请输入姓名: ");
    scanf("%s", new_stu.name);

    printf("请输入%d门科目成绩，用空格分隔: ", SUBJECT_NUM);
    for (int i = 0; i < SUBJECT_NUM; i++) {
        scanf("%f", &new_stu.scores[i]);
    }

    // 自动计算平均分
    new_stu.average = calcAverage(new_stu.scores);

    // 加入数组
    students[*count] = new_stu;
    (*count)++;
    printf("添加成功！当前共%d名学生\n", *count);
}

// 打印所有学生信息
void printAllStudents(const Student *students, int count) {
    if (count == 0) {
        printf("暂无学生数据\n");
        return;
    }

    printf("\n%-8s %-12s %-8s %-8s %-8s %-8s\n", 
           "学号", "姓名", "科目1", "科目2", "科目3", "平均分");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-8d %-12s ", students[i].id, students[i].name);
        for (int j = 0; j < SUBJECT_NUM; j++) {
            printf("%-8.1f ", students[i].scores[j]);
        }
        printf("%-8.1f\n", students[i].average);
    }
}

// 按学号查找学生，返回数组下标，找不到返回-1
int findStudentById(const Student *students, int count, int target_id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == target_id) {
            return i;
        }
    }
    return -1;
}

// 修改学生信息
void updateStudent(Student *students, int count, int target_id) {
    int index = findStudentById(students, count, target_id);
    if (index == -1) {
        printf("未找到该学号学生\n");
        return;
    }

    printf("找到学生：%s，请输入新的姓名: ", students[index].name);
    scanf("%s", students[index].name);

    printf("请输入新的%d门科目成绩，用空格分隔: ", SUBJECT_NUM);
    for (int i = 0; i < SUBJECT_NUM; i++) {
        scanf("%f", &students[index].scores[i]);
    }

    // 更新平均分
    students[index].average = calcAverage(students[index].scores);
    printf("修改成功\n");
}

// 删除学生信息
void deleteStudent(Student *students, int *count, int target_id) {
    int index = findStudentById(students, *count, target_id);
    if (index == -1) {
        printf("未找到该学号学生\n");
        return;
    }

    // 后续元素前移，覆盖被删除的位置
    for (int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }
    (*count)--;
    printf("删除成功\n");
}