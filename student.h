#ifndef STUDENT_H
#define STUDENT_H
#define MAX_NAME_LENGTH 30
#define SUBJECT_NUM 3
typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    float scores[SUBJECT_NUM];
    float average;
} Student;
void addStudent(Student *students, int *count, int max_size);
void printAllStudents(const Student *students, int count);
int findStudentById(const Student *students, int count, int target_id);
void updateStudent(Student *students, int count, int target_id);
void deleteStudent(Student *students, int *count, int target_id);
float calcAverage(const float *scores);
#endif