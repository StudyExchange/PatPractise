/* 1031 查验身份证 （15 分）
*/

#include <stdio.h>
#include <stdlib.h>

int is_all_num(char id[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if ((id[i] - '0') < 0 || (id[i] - '0') > 9)
        {
            return 0;
        }
    }
    return 1;
}

int is_last_char_valid(char id[], int len)
{
    int weights[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    int sum = 0;
    for (int i = 0; i < len - 1; i++)
    {
        int num = id[i] - '0';
        sum += num * weights[i];
    }
    int z = sum % 11;
    int z_check[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    char last = z_check[z];
    if (last == id[len - 1])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int is_valid(char id[], int len)
{
    if (is_all_num(id, len - 1) && is_last_char_valid(id, len))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char *argv[])
{
    // 处理输入
    int n;
    int len_id = 18;
    if (scanf("%d", &n) != 1)
        return EXIT_FAILURE;
    char temp;
    if (scanf("%c", &temp) != 1)
        return EXIT_FAILURE;
    char ids[n][len_id + 1];
    for (int i = 0; i < n; i++)
    {
        if (scanf("%s", ids[i]) != 1)
            return EXIT_FAILURE;
    }

    // 判断是否通过验证并处理输出
    int valid_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (is_valid(ids[i], len_id) == 0)
        {
            printf("%s\n", ids[i]);
            valid_count++;
        }
    }
    if (valid_count == 0)
    {
        printf("All passed");
    }

    return EXIT_SUCCESS;
}
