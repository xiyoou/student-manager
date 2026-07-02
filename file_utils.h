// file_utils.h
#ifndef FILE_UTILS_H  // 防卫式声明开头：防止头文件被重复包含
#define FILE_UTILS_H

#include "student.h"  // 因为函数用到了Student结构体，所以要包含它的定义

// 函数声明：只写函数名、参数、返回值，不写实现逻辑
// 功能：从文件加载学生数据到内存
void loadFromFile(Student *students, int *count, const char *filename);

// 功能：把内存里的学生数据保存到文件
void saveToFile(const Student *students, int count, const char *filename);

#endif // 防卫式声明结尾