/* 1027 打印沙漏 （20 分）
解析：
1. 等差数列公式：Sn=n*a1 + n(n-1)*d/2，an=a1 + (n-1)*d，Sn反推回来求n和an。
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    // 处理输入
    int Sn;
    char c;
    if (scanf("%d %c", &Sn, &c) != 2)
        return EXIT_FAILURE;
    // a1=1，d=2，沙漏的公式是Sn=(n*a1 + n(n-1)*d/2)*2 - 1，Sn反推回来求n和an。
    int d = 2;
    int n = sqrt((Sn + 1) / 2);
    int an = 1 + (n - 1) * 2;
    int printed_count = 0;
    // 处理输出
    //   打印沙漏上半截
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < an; k++)
        {
            printf("%c", c);
            printed_count++;
        }
        printf("\n");
        an -= d;
    }
    //   打印沙漏下半截
    an += d;
    an += d;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < an; k++)
        {
            printf("%c", c);
            printed_count++;
        }
        printf("\n");
        an += d;
    }
    printf("%d", Sn - printed_count);
    return EXIT_SUCCESS;
}
