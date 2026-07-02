#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include <windows.h>
#include "file_utils.h"

#define MAX_STUDENT 100  // 基础版本固定容量

int main() {
    SetConsoleOutputCP(65001);  // 设置输出编码
    SetConsoleCP(65001); 
    Student students[MAX_STUDENT];
    int stu_count = 0;
    int choice;

    // 程序启动：加载本地数据
    loadFromFile(students, &stu_count, "data.dat");

    while (1) {
        printf("\n========== 学生成绩管理系统 ==========\n");
        printf("1. 添加学生信息\n");
        printf("2. 查看所有学生\n");
        printf("3. 按学号查询\n");
        printf("4. 修改学生信息\n");
        printf("5. 删除学生信息\n");
        printf("6. 保存并退出\n");
        printf("请输入选项: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &stu_count, MAX_STUDENT);
                break;
            case 2:
                printAllStudents(students, stu_count);
                break;
            case 3: {
                int id;
                printf("请输入要查询的学号: ");
                scanf("%d", &id);
                int index = findStudentById(students, stu_count, id);
                if (index >= 0) {
                    // 可自行补充打印单个学生信息的逻辑
                } else {
                    printf("未找到该学号学生\n");
                }
                break;
            }
            case 4: {
                int id;
                printf("请输入要修改的学号: ");
                scanf("%d", &id);
                updateStudent(students, stu_count, id);
                break;
            }
            case 5: {
                int id;
                printf("请输入要删除的学号: ");
                scanf("%d", &id);
                deleteStudent(students, &stu_count, id);
                break;
            }
            case 6:
                saveToFile(students, stu_count, "data.dat");
                printf("数据已保存，程序退出\n");
                return 0;
            default:
                printf("输入无效，请重新选择\n");
        }
    }
    return 0;
}
