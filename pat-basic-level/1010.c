/* 1010 一元多项式求导 （25 分）
解析：
1. 处理一行中未知个数的连续输入。
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 处理输入
    int nums[2000] = {0};
    int i = 0;
    while (1)
    {
        int t = scanf("%d", &nums[i++]);
        char temp;
        scanf("%c", &temp);
        if (t != 1 || temp == '\n')
        {
            break;
        }
    }
    if (i % 2 != 0)
    {
        return EXIT_FAILURE;
    }
    // 计算导数
    for (int j = 0; j <= i; j += 2)
    {
        nums[j] *= nums[j + 1];
        if (nums[j + 1])
        {
            nums[j + 1] -= 1;
        }
        else
        {
            nums[j + 1] = 0;
        }
    }
    // 处理输出
    if (i == 2 && nums[0] == 0)
    {
        printf("0 0");
        return EXIT_SUCCESS;
    }
    for (int j = 0; j < i; j += 2)
    {
        printf("%d %d", nums[j], nums[j + 1]);
        if (nums[j + 2] != 0 && j != i - 2)
        {
            printf(" ");
        }
        else
        {
            printf("");
            break;
        }
    }

    return EXIT_SUCCESS;
}
