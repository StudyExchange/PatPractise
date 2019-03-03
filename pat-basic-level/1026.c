/* 1026 程序运行时间 （15 分）
解析：
1. C语言实现四舍五入。
*/

#include <stdio.h>
#include <stdlib.h>

#define CLK_TCK 100

int main(int argc, char *argv[])
{
    // 处理输入
    long int c1, c2;
    if (scanf("%ld %ld", &c1, &c2) != 2)
        return EXIT_FAILURE;
    // 计算秒数
    long int c_diff = (int)((c2 - c1) / (float)CLK_TCK + 0.5);
    // 处理输出
    printf("%02ld:%02ld:%02ld", c_diff / 60 / 60, c_diff / 60 % 60, c_diff % 60 % 60);
    return EXIT_SUCCESS;
}
