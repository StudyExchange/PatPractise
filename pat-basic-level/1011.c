/* 1011 A+B 和 C （15 分）
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 处理输入
    int n;
    if (scanf("%d", &n) != 1)
        return EXIT_FAILURE;
    long nums[n][3];
    for (int i = 0; i < n; i++)
    {
        if (scanf("%ld%ld%ld", &nums[i][0], &nums[i][1], &nums[i][2]) != 3)
            return EXIT_FAILURE;
    }
    // 处理输出
    for (int i = 0; i < n; i++)
    {
        if (nums[i][0] + nums[i][1] > nums[i][2])
        {
            printf("Case #%d: true%s", i + 1, i == (n - 1) ? "" : "\n");
        }
        else
        {
            printf("Case #%d: false%s", i + 1, i == (n - 1) ? "" : "\n");
        }
    }

    return EXIT_SUCCESS;
}
