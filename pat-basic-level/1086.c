/* 1086 就不告诉你 （15 分）
解析：
1. 注意：数字颠倒之后，它开始的零不能输出。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // 处理输入
    int m, n;
    if (scanf("%d %d", &m, &n) != 2)
        return EXIT_FAILURE;
    // 计算乘积
    int product = m * n;
    // 处理输出
    int is_start_num = 0;
    if (product == 0)
    {
        printf("0");
    }
    else
    {
        while (product > 0)
        {
            int reminder = product % 10;
            if (reminder > 0)
            {
                is_start_num = 1;
            }
            if (is_start_num == 1)
            {
                printf("%d", reminder);
            }
            product /= 10;
        }
    }

    return EXIT_SUCCESS;
}
