/* 1019 数字黑洞 （20 分）
解析：
1. 返回函数返回数组，最好是传入要返回的数组，函数内部直接操作数组。
2. printf()填充空格。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int cmp_asc(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

int cmp_desc(const void *a, const void *b)
{
    return *(char *)b - *(char *)a;
}

void itos(int n, char string[])
{
    for (int i = 3; i >= 0; i--)
    {
        string[i] = n % 10 + '0';
        n = n / 10;
    }
}

int stoi(char string[], int n)
{
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        num += (string[i] - '0') * ((int)pow(10, i));
    }
    return num;
}

int is_all_same(char string[], int n)
{
    char first = string[0];
    for (int i = 1; i < n; i++)
    {
        if (first != string[i])
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    // 处理输入
    int n;
    if (scanf("%d", &n) != 1)
        return EXIT_FAILURE;
    // 处理数字
    int const_num = 6174;
    int count = INT_MAX;
    while (1)
    {
        char string[4];
        itos(n, string);
        if (is_all_same(string, 4))
        {
            printf("%04d - %04d = 0000", n, n);
            break;
        }
        else
        {
            qsort(string, 4, sizeof(char), cmp_asc);
            int larger = stoi(string, 4);
            qsort(string, 4, sizeof(char), cmp_desc);
            int smaller = stoi(string, 4);
            n = larger - smaller;
            char larger_str[4];
            itos(larger, larger_str);
            char smaller_str[4];
            itos(smaller, smaller_str);
            char n_str[4];
            itos(n, n_str);
            // 处理输出
            printf("%04d - %04d = %s\n", larger, smaller, n_str);
            if (n == const_num)
            {
                break;
            }
        }
    }

    return EXIT_SUCCESS;
}
