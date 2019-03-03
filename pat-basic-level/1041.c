/* 1041 考试座位号 （15 分）
解析：
1. 数组作为字典，用于快速查询。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char id[15];
    int test;
    int formal;
} Exam;

int main(int argc, char *argv[])
{
    // 处理输入
    char temp;
    int n;
    if (scanf("%d", &n) != 1)
        return EXIT_FAILURE;
    if (scanf("%c", &temp) != 1)
        return EXIT_FAILURE;
    Exam exams[n + 1];
    for (int i = 0; i < n; i++)
    {
        Exam temp;
        if (scanf("%s %d %d", temp.id, &temp.test, &temp.formal) != 3)
            return EXIT_FAILURE;
        strcpy(exams[temp.test].id, temp.id);
        exams[temp.test].test = temp.test;
        exams[temp.test].formal = temp.formal;
        if (scanf("%c", &temp) != 1)
            return EXIT_FAILURE;
    }
    int m;
    if (scanf("%d", &m) != 1)
        return EXIT_FAILURE;
    if (scanf("%c", &temp) != 1)
        return EXIT_FAILURE;
    int searches[m];
    for (int i = 0; i < m; i++)
    {
        if (scanf("%d", &searches[i]) != 1)
            return EXIT_FAILURE;
    }
    // 处理输出
    for (int i = 0; i < m; i++)
    {
        printf("%s %d\n", exams[searches[i]].id, exams[searches[i]].formal);
    }

    return EXIT_SUCCESS;
}
