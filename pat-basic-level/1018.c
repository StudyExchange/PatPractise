/* 1018 锤子剪刀布 （20 分）
解析：
1. 多行字符输入的时候，换行符需要单独一行处理，免得识别有问题：
if (scanf("%c %c", &hands[i][0], &hands[i][1]) != 2)
    return EXIT_FAILURE;
if (scanf("%c", &temp) != 1)
    return EXIT_FAILURE;
2. 求数组中最大值的位置，使用一个最小值哨兵。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

enum Sample
{
    B = 0,
    C = 1,
    J = 2,
    Z = 3
};

typedef struct
{
    int is_win;
    enum Sample sample;
} Result;

Result comp(char a, char b)
{
    Result result = {0, Z};
    if (a == 'C')
    {
        switch (b)
        {
        case 'C':
            result.is_win = 0;
            result.sample = Z;
            return result;
        case 'J':
            result.is_win = 1;
            result.sample = C;
            return result;
        case 'B':
            result.is_win = -1;
            result.sample = B;
            return result;
        }
    }
    else if (a == 'J')
    {
        switch (b)
        {
        case 'C':
            result.is_win = -1;
            result.sample = C;
            return result;
        case 'J':
            result.is_win = 0;
            result.sample = Z;
            return result;
        case 'B':
            result.is_win = 1;
            result.sample = J;
            return result;
        }
    }
    else
    {
        switch (b)
        {
        case 'C':
            result.is_win = 1;
            result.sample = B;
            return result;
        case 'J':
            result.is_win = -1;
            result.sample = J;
            return result;
        case 'B':
            result.is_win = 0;
            result.sample = Z;
            return result;
        }
    };
    return result;
}

int main(int argc, char *argv[])
{
    // 处理输入
    long n;
    if (scanf("%ld", &n) != 1)
        return EXIT_FAILURE;
    char temp;
    if (scanf("%c", &temp) != 1)
        return EXIT_FAILURE;
    char hands[n][2];
    for (long i = 0; i < n; i++)
    {
        if (scanf("%c %c", &hands[i][0], &hands[i][1]) != 2)
            return EXIT_FAILURE;
        if (scanf("%c", &temp) != 1)
            return EXIT_FAILURE;
    }

    // 统计
    int jia[3] = {0}, jia_sample[3] = {0};
    int yi[3] = {0}, yi_sample[3] = {0};
    for (long i = 0; i < n; i++)
    {
        Result result = comp(hands[i][0], hands[i][1]);
        if (result.is_win == 1)
        {
            jia[0]++;
            yi[2]++;
            jia_sample[result.sample]++;
        }
        else if (result.is_win == 0)
        {
            jia[1]++;
            yi[1]++;
        }
        else
        {
            jia[2]++;
            yi[0]++;
            yi_sample[result.sample]++;
        }
    }
    // 求数组中最大值的位置
    int max_jia = INT_MIN, max_yi = INT_MIN;
    char max_jia_sample = 'Z', max_yi_sample = 'Z';
    char samples[3] = {'B', 'C', 'J'};
    for (int i = 0; i < 3; i++)
    {
        if (jia_sample[i] > max_jia)
        {
            max_jia = jia_sample[i];
            max_jia_sample = samples[i];
        }
        if (yi_sample[i] > max_yi)
        {
            max_yi = yi_sample[i];
            max_yi_sample = samples[i];
        }
    }

    // 处理输出
    printf("%d %d %d\n", jia[0], jia[1], jia[2]);
    printf("%d %d %d\n", yi[0], yi[1], yi[2]);
    printf("%c %c\n", max_jia_sample, max_yi_sample);
    return EXIT_SUCCESS;
}
