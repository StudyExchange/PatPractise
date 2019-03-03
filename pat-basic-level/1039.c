/* 1039 到底买不买 （20 分）
解析：
1. int数组作为统计用的字典。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // 处理输入
    char real[1001], want[1001];
    if (scanf("%s", real) != 1)
        return EXIT_FAILURE;
    if (scanf("%s", want) != 1)
        return EXIT_FAILURE;
    // 统计珠串
    int len_real = strlen(real);
    int len_want = strlen(want);
    int stat_real[128] = {0};
    int stat_want[128] = {0};
    for (int i = 0; i < len_real; i++)
    {
        stat_real[(int)real[i]]++;
    }
    for (int i = 0; i < len_want; i++)
    {
        stat_want[(int)want[i]]++;
    }
    // 对比珠串
    int stat_diff[128] = {0};
    for (int i = 0; i < 128; i++)
    {
        stat_diff[i] = stat_real[i] - stat_want[i];
    }
    int is_yes = 1;
    int result_count = 0;
    for (int i = 0; i < 128; i++)
    {
        if (stat_diff[i] < 0)
        {
            is_yes = 0;
        }
    }
    // 处理输出
    if (is_yes == 1)
    {
        result_count = len_real - len_want;
        printf("Yes %d", result_count);
    }
    else
    {
        for (int i = 0; i < 128; i++)
        {
            if (stat_diff[i] < 0)
            {
                result_count += stat_diff[i];
            }
        }
        result_count *= -1;
        printf("No %d", result_count);
    }

    return EXIT_SUCCESS;
}
