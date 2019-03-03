/* 1020 月饼 （25 分）
解析：
1. 交换数组的两个元素。
2. argsort。
3. 注意题目说的正数，不是正整数，所以库存量和各种类的总收益都要定义成float。
*/

#include <stdio.h>
#include <stdlib.h>

void swap_int(int *n, int *m)
{
    int temp = *n;
    *n = *m;
    *m = temp;
}

void swap_float(float *n, float *m)
{
    float temp = *n;
    *n = *m;
    *m = temp;
}

void argsort(int index_arr[], float arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                swap_int(&index_arr[i], &index_arr[j]);
                swap_float(&arr[i], &arr[j]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    // 处理输入
    int n_cat, demand_amount;
    if (scanf("%d%d", &n_cat, &demand_amount) != 2)
        return EXIT_FAILURE;

    int count = 0;
    float cat_quantity[1001] = {0};
    float selling_prices[1001] = {0};
    for (int i = 0; i < n_cat; i++)
    {
        if (count >= n_cat)
        {
            break;
        }
        if (scanf("%f", &cat_quantity[i]) != 1)
            return EXIT_FAILURE;
        count++;
    }
    count = 0;
    for (int i = 0; i < n_cat; i++)
    {
        if (count >= n_cat)
        {
            break;
        }
        if (scanf("%f", &selling_prices[i]) != 1)
            return EXIT_FAILURE;
        count++;
    }
    // 计算单价
    float unit_prices[1001] = {0};
    for (int i = 0; i < n_cat; i++)
    {
        unit_prices[i] = selling_prices[i] / cat_quantity[i];
    }
    // 单价排序，排序返回索引数组和值的数组
    int index_arr[1001] = {0};
    for (int i = 0; i < n_cat; i++)
    {
        index_arr[i] = i;
    }
    argsort(index_arr, unit_prices, n_cat);
    // 按照各品种单价的排序，由高到低取值。
    float selled_amount = 0;
    for (int i = 0; i < n_cat; i++)
    {
        if (demand_amount <= 0)
        {
            break;
        }
        if (demand_amount >= cat_quantity[index_arr[i]])
        {
            demand_amount -= cat_quantity[index_arr[i]];
            selled_amount += selling_prices[index_arr[i]];
        }
        else
        {
            selled_amount += demand_amount * unit_prices[i];
            demand_amount = 0;
        }
    }
    // 处理输出
    printf("%.2f", selled_amount);
    return EXIT_SUCCESS;
}
