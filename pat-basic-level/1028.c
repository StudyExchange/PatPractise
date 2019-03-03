/* 1028 人口普查 （20 分）
解析：
1. 多字段排序。
2. 注意。测试点：没有一个生日是合理的情况。 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char name[6];
    int year;
    int month;
    int day;
    int is_valid;
} Person;

int date_a_gt_b(int a_year, int a_month, int a_day, int b_year, int b_month, int b_day)
{
    if (a_year < b_year)
    {
        return 0;
    }
    else if (a_year == b_year)
    {
        if (a_month < b_month)
        {
            return 0;
        }
        else if (a_month == b_month)
        {
            if (a_day < b_day)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}

int comfunc(const void *a, const void *b)
{
    Person aa = *(Person *)a;
    Person bb = *(Person *)b;
    return date_a_gt_b(aa.year, aa.month, aa.day, bb.year, bb.month, bb.day);
}

int main(int argc, char *argv[])
{
    // 处理输入
    int n;
    if (scanf("%d", &n) != 1)
        return EXIT_FAILURE;
    char temp;
    if (scanf("%c", &temp) != 1)
        return EXIT_FAILURE;
    Person persons[n];
    for (int i = 0; i < n; i++)
    {
        if (scanf("%s %d/%d/%d", persons[i].name, &persons[i].year, &persons[i].month, &persons[i].day) != 4)
            return EXIT_FAILURE;
    }
    // 判断有效性
    int valid_count = 0;
    int now_year = 2014, now_month = 9, now_day = 6;
    for (int i = 0; i < n; i++)
    {
        if (date_a_gt_b(persons[i].year, persons[i].month, persons[i].day, now_year - 200, now_month, now_day) && date_a_gt_b(now_year, now_month, now_day, persons[i].year, persons[i].month, persons[i].day))
        {
            persons[i].is_valid = 1;
            valid_count++;
        }
        else
        {
            persons[i].is_valid = 0;
        }
    }
    // 排序
    qsort(persons, n, sizeof(Person), comfunc);
    // 找最年长和最年轻的人的名字
    char oldest_name[6], youngest[6];
    for (int i = 0; i < n; i++)
    {
        if (persons[i].is_valid)
        {
            memcpy(oldest_name, persons[i].name, 6);
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (persons[i].is_valid)
        {
            memcpy(youngest, persons[i].name, 6);
            break;
        }
    }
    // 处理输出
    if (valid_count >= 1)
    {
        printf("%d %s %s", valid_count, oldest_name, youngest);
    }
    else
    {
        printf("0");
    }

    return EXIT_SUCCESS;
}
