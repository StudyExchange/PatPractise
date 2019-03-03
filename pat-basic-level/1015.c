/* 1016 部分A+B （15 分）
解析：
1. 字符串与int值。
2. math.h中pow求幂。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int statistic(char string[], char c)
{
    int len = strlen(string);
    int count = 0;
    int num = 0;
    for (int i = 0; i < len; i++)
    {
        if (string[i] == c)
        {
            num += (c - '0') * ((int)pow(10, count));
            count++;
        }
    }
    return num;
}

int main(int argc, char *argv[])
{
    // 处理输入
    char da, db;
    char a[10], b[10];
    if (scanf("%s %c %s %c", a, &da, b, &db) != 4)
        return EXIT_FAILURE;
    // 处理数据
    int sum = statistic(a, da) + statistic(b, db);
    // 处理输出
    printf("%d", sum);
    return EXIT_SUCCESS;
}
