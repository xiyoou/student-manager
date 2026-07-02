// file_utils.c
// 功能：文件操作模块的具体实现，二进制方式读写学生数据
#include <stdio.h>
#include "file_utils.h"  // 必须包含对应头文件，保证声明与实现一致

/**
 * 从二进制文件加载学生数据到内存
 * 文件不存在时自动初始化空数据，不报错
 */
void loadFromFile(Student *students, int *count, const char *filename) {
    // 以「二进制只读」模式打开文件
    FILE *fp = fopen(filename, "rb");
    
    // 文件打开失败（通常是首次运行、文件还不存在）
    if (fp == NULL) {
        *count = 0;  // 学生数量置0
        return;
    }

    *count = 0;
    // 循环读取：每次读1个Student大小的数据，读到数组中
    // fread返回成功读取的元素个数，不等于1说明读完了
    while (fread(&students[*count], sizeof(Student), 1, fp) == 1) {
        (*count)++;  // 注意括号：++优先级高于*，必须先解引用再自增
    }

    fclose(fp);  // 用完必须关闭文件
}

/**
 * 将内存中的学生数据保存到二进制文件
 * 覆盖式写入，保存最新的全部数据
 */
void saveToFile(const Student *students, int count, const char *filename) {
    // 以「二进制只写」模式打开文件，文件不存在会自动创建，存在会清空重写
    FILE *fp = fopen(filename, "wb");
    
    if (fp == NULL) {
        printf("错误：无法打开文件 %s 进行保存\n", filename);
        return;
    }

    // 一次性写入 count 个学生数据
    fwrite(students, sizeof(Student), count, fp);

    fclose(fp);
}