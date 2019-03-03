/* 1004 成绩排名 （20 分）
解析：
1. 结构体的使用。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[15];
    char id[15];
    int score;
} Student;

int main(int argc, char **argv)
{
    // 处理输入
    int n;
    if (scanf("%d", &n) != 1)
    {
        return EXIT_FAILURE;
    }
    Student student[n], student_max = {"", "", 0}, student_min = {"", "", 100};
    for (int i = 0; i < n; i++)
    {
        if (scanf("%s%s%d", student[i].name, student[i].id, &student[i].score) != 3)
        {
            return EXIT_FAILURE;
        }
        if (student[i].score >= student_max.score)
        {
            student_max = student[i];
        }
        if (student[i].score <= student_min.score)
        {
            student_min = student[i];
        }
    }
    // 处理输出
    printf("%s %s\n", student_max.name, student_max.id);
    printf("%s %s\n", student_min.name, student_min.id);

    return EXIT_SUCCESS;
}
