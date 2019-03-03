/* 1023 组个最小数 （20 分）
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // 处理输入
    int n = 10;
    int quantities[n];
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &quantities[i]) != 1)
            return EXIT_FAILURE;
    }
    // 组装数字
    int nums[50] = {0};
    int count = 0;
    //   找到开头的数字
    for (int i = 1; i < n; i++)
    {
        if (quantities[i] > 0)
        {
            nums[count] = i;
            count++;
            quantities[i]--;
            break;
        }
    }
    //   组装剩余的数字
    for (int i = 0; i < n; i++)
    {
        while (quantities[i] > 0)
        {
            nums[count] = i;
            count++;
            quantities[i]--;
        }
    }
    // 处理输出
    for (int i = 0; i < count; i++)
    {
        printf("%d", nums[i]);
    }
    return EXIT_SUCCESS;
}
