/* 1038 统计同成绩学生 （20 分）
解析：
1. int数组作为字典。
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 处理输入
    int n;
    int m;
    char temp;

    if (scanf("%d", &n) != 1)
        return EXIT_FAILURE;
    int grades[n];
    if (scanf("%c", &temp) != 1)
        return EXIT_FAILURE;
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &grades[i]) != 1)
            return EXIT_FAILURE;
    }
    if (scanf("%c", &temp) != 1)
        return EXIT_FAILURE;

    if (scanf("%d", &m) != 1)
        return EXIT_FAILURE;
    int searches[m];
    if (scanf("%c", &temp) != 1)
        return EXIT_FAILURE;
    for (int i = 0; i < m; i++)
    {
        if (scanf("%d", &searches[i]) != 1)
            return EXIT_FAILURE;
    }
    // 查询
    int grade_dict[101] = {0};
    for (int i = 0; i < n; i++)
    {
        grade_dict[grades[i]]++;
    }
    // 处理输出
    for (int i = 0; i < m; i++)
    {
        if (i != m - 1)
        {
            printf("%d ", grade_dict[searches[i]]);
        }
        else
        {
            printf("%d", grade_dict[searches[i]]);
        }
    }

    return EXIT_SUCCESS;
}
