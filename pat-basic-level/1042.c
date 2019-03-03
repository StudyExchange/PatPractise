/* 1042 字符统计 （20 分）
解析：
1. int数组作为统计用的字典。
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 处理输入
    char str[1001];
    int count = 0;
    for (int i = 0; i < 1001; i++)
    {
        if (scanf("%c", &str[i]) != 1)
            return EXIT_FAILURE;
        if (str[i] == '\n')
        {
            break;
        }
        count++;
    }
    // 统计字符串
    int dict[128] = {0};
    for (int i = 0; i < count; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            dict[(int)str[i]]++;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            dict[(int)(str[i] - 'A' + 'a')]++;
        }
        else
        {
            continue;
        }
    }
    char max_char = 'a';
    int max_count = 0;
    for (char i = 'a'; i <= 'z'; i++)
    {
        if (dict[(int)i] > max_count)
        {
            max_char = i;
            max_count = dict[(int)i];
        }
    }
    // 处理输出
    printf("%c %d", max_char, max_count);

    return EXIT_SUCCESS;
}
