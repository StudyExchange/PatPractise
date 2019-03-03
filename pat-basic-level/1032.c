/* 1032 挖掘机技术哪家强 （20 分）
解析：
1. 预定义作为字典的数组的长度，固定为10^5+1。
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 处理输入
    long int n;
    if (scanf("%ld", &n) != 1)
        return EXIT_FAILURE;
    char temp;
    if (scanf("%c", &temp) != 1)
        return EXIT_FAILURE;
    long int grades[10 * 10000 + 1];
    for (long int i = 0; i < n + 1; i++)
    {
        grades[i] = 0;
    }
    for (long int i = 0; i < n; i++)
    {
        long int school_num;
        long int grade;
        if (scanf("%ld %ld", &school_num, &grade) != 2)
            return EXIT_FAILURE;
        grades[school_num] += grade;
    }
    // 找出成绩最好的学校
    long int best_school_num = 0, best_grade = grades[0];
    for (long int i = 1; i <= n + 1; i++)
    {
        if (grades[i] > best_grade)
        {
            best_school_num = i;
            best_grade = grades[i];
        }
    }
    // 处理输出
    printf("%ld %ld", best_school_num, best_grade);

    return EXIT_SUCCESS;
}
