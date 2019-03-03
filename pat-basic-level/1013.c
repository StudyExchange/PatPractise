/* 1013 数素数 （20 分）
解析：
1. 求素数。注意，2是素数。 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int is_prime(long n);

int main(int argc, char *argv[])
{
    // 处理输入
    int m, n;
    if (scanf("%d%d", &m, &n) != 2)
        return EXIT_FAILURE;
    // 统计
    int count = 0, pos = 0;
    for (long i = 2; i <= LONG_MAX; i++)
    {
        if (is_prime(i))
        {
            count++;
            if (count >= m && count <= n)
            {
                pos = pos % 10;
                switch (pos)
                {
                case 0:
                    printf("%ld", i);
                    break;
                case 9:
                    printf(" %ld\n", i);
                    break;
                default:
                    printf(" %ld", i);
                    break;
                }
                pos++;
            }
            if (count > n)
                break;
        }
    }
    return EXIT_SUCCESS;
}

int is_prime(long n)
{
    long k = (long)sqrt(n);
    for (long i = 2; i <= k; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
