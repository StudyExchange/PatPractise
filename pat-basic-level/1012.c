/* 1012 数字分类 （20 分）
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    int count;
} A;

int main(int argc, char *argv[])
{
    // 处理输入
    int n;
    if (scanf("%d", &n) != 1)
        return EXIT_FAILURE;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &nums[i]) != 1)
            return EXIT_FAILURE;
    }
    // 统计
    A a1 = {0, 0}, a2 = {0, 0}, a3 = {0, 0}, a4 = {0, 0}, a5 = {0, 0};
    for (int i = 0; i < n; i++)
    {
        int reminder = nums[i] % 5;
        switch (reminder)
        {
        case 0:
            if (nums[i] % 2 == 0)
            {
                a1.data += nums[i];
                a1.count++;
            }
            break;
        case 1:
            if (a2.count % 2 == 0)
            {
                a2.data += nums[i];
            }
            else
            {
                a2.data -= nums[i];
            }
            a2.count++;
            break;
        case 2:
            a3.count++;
            break;
        case 3:
            a4.data += nums[i];
            a4.count++;
            break;
        case 4:
            if (a5.count == 0)
            {
                a5.data = nums[i];
            }
            else
            {
                a5.data = a5.data > nums[i] ? a5.data : nums[i];
            }
            a5.count++;
            break;
        default:
            return EXIT_FAILURE;
        }
    }
    // 处理输出
    if (a1.count > 0)
    {
        printf("%d ", a1.data);
    }
    else
    {
        printf("N ");
    }
    if (a2.count > 0)
    {
        printf("%d ", a2.data);
    }
    else
    {
        printf("N ");
    }
    if (a3.count > 0)
    {
        printf("%d ", a3.count);
    }
    else
    {
        printf("N ");
    }
    if (a4.count > 0)
    {
        printf("%.1f ", (float)a4.data / a4.count);
    }
    else
    {
        printf("N ");
    }
    if (a5.count > 0)
    {
        printf("%d", a5.data);
    }
    else
    {
        printf("N");
    }

    return EXIT_SUCCESS;
}
