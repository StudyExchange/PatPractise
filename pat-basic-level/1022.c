/* 1022 D进制的A+B （20 分）
解析：
1. 注意处理sum为零的情况。
2. 结果数组sum_d的长度应该至少等于31。如果是30的话，会报错。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // 处理输入
    long a, b;
    int d;
    if (scanf("%ld%ld%d", &a, &b, &d) != 3)
        return EXIT_FAILURE;
    // 计算
    long sum = a + b;
    int sum_d[31] = {0};
    int count = 0;
    if (sum == 0)
    {
        count++;
    }
    else
    {
        while (sum)
        {
            sum_d[count] = sum % d;
            sum /= d;
            count++;
        }
    }
    // 处理输出
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%d", sum_d[i]);
    }
    return EXIT_SUCCESS;
}
