/* 1004 成绩排名 （20 分）
解析：
1. scanf之后，需要清理缓冲区遗留的退格符(10)，然后才能继续使用scanf处理输入。
2. scanf("%[^\n]", temp_str)用于输入带空格的字符串。 
2. 字符串分割strtok()的使用。
3. 数组排序的使用。
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

int comfunc(const void *a, const void *b)
{
    return ((*(Student *)a).score - (*(Student *)b).score);
}

int main(int argc, char **argv)
{
    // 处理输入
    int n;
    if (scanf("%d", &n) != 1)
    {
        return EXIT_FAILURE;
    }
    // 处理scanf输入之后，缓冲区遗留的字符：退格(10)
    char temp;
    if (scanf("%c", &temp) != 1)
    {
        return EXIT_FAILURE;
    }
    char student_str[n][100];
    for (int i = 0; i < n; i++)
    {
        if (scanf("%[^\n]", student_str[i]) != 1)
        {
            return EXIT_FAILURE;
        }
        if (scanf("%c", &temp) != 1)
        {
            return EXIT_FAILURE;
        }
    }
    // 按照空格分割字符串并赋值给结构体数组
    Student student[n];
    char split[2] = " ";
    char *token;
    for (int i = 0; i < n; i++)
    {
        token = strtok(student_str[i], split);
        strcpy(student[i].name, token);
        token = strtok(NULL, split);
        strcpy(student[i].id, token);
        token = strtok(NULL, split);
        student[i].score = atoi(token);
    }
    // 结构体数组排序（升序）
    qsort(student, n, sizeof(Student), comfunc);
    // 处理输出
    printf("%s %s\n", student[n - 1].name, student[n - 1].id);
    printf("%s %s\n", student[0].name, student[0].id);

    return EXIT_SUCCESS;
}
