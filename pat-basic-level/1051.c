/* 11051 复数乘法 （15 分）
解析：
1. 复数乘法。
2. 当A或者B小于0但是大于-0.005(比如-0.00001)时候，如果按照A>=0的判断，会输出“-0.00”这样的结果,事实上应该输出“0.00”。
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 0.01

typedef struct
{
    double real;
    double imaginary;
} Complex;

int main(int argc, char *argv[])
{
    // 处理输入
    Complex a, b;
    if (scanf("%lf %lf %lf %lf", &a.real, &a.imaginary, &b.real, &b.imaginary) != 4)
        return EXIT_FAILURE;
    // 计算乘积
    Complex product;
    product.real = a.real * b.real * cos(a.imaginary + b.imaginary);
    product.imaginary = a.real * b.real * sin(a.imaginary + b.imaginary);
    if (fabs(product.real) < EPSILON)
    {
        product.real = 0;
    }
    if (fabs(product.imaginary) < EPSILON)
    {
        product.imaginary = 0;
    }
    // 处理输出
    if (product.imaginary >= 0)
    {
        printf("%.2f+%.2fi", product.real, product.imaginary);
    }
    else
    {
        printf("%.2f-%.2fi", product.real, -product.imaginary);
    }

    return EXIT_SUCCESS;
}
