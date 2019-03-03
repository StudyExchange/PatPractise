/* 1021 个位数统计 （15 分）
解析：
1. 数组用作整数键值的字典。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // 处理输入
    char str[1001];
    if (scanf("%s", &str) != 1)
        return EXIT_FAILURE;
    int len_str = strlen(str);
    // 统计
    int stat[10] = {0};
    for (int i = 0; i < len_str; i++)
    {
        stat[str[i] - '0']++;
    }
    // 处理输出
    for (int i = 0; i < 10; i++)
    {
        if (stat[i] > 0)
        {
            printf("%d:%d\n", i, stat[i]);
        }
    }
    return EXIT_SUCCESS;
}
