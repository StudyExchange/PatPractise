/* 1017 A除以B （20 分）
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // 处理输入
    char a[1000];
    int b;
    if (scanf("%s %d", a, &b) != 2)
        return EXIT_FAILURE;
    // 处理数据
    char result[1000] = "";
    int len = strlen(a);
    int current = 0, count = 0, quotient;
    for (int i = 0; i < len; i++)
    {
        current = 10 * current + (a[i] - '0');
        if (current >= b)
        {
            quotient = current / b;
            current = current % b;
            result[count] = quotient + '0';
            count++;
        }
        else
        {
            if (i != 0)
            {
                result[count] = '0';
                count++;
            }
            else
            {
                if (len == 1)
                {
                    result[count] = '0';
                    count++;
                }
            }
        }
    }
    result[count] = '\0';
    // 处理输出
    printf("%s %d", result, current);
    return EXIT_SUCCESS;
}
