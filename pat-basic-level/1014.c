/* 1015 德才论 （25 分）
解析：
1. 结构体多属性排序。
*/

#include <stdio.h>
#include <stdlib.h>

enum Level
{
    Failed = 0,
    BothGood = 4,
    Hight_M_Than_A = 3,
    Low_M_Than_A = 2,
    Other_Enrolled = 1
};

typedef struct
{
    long id;
    int morality;
    int ability;
    int sum;
    enum Level level;
} Student;

int comfunc(const void *a, const void *b)
{
    Student aa = *(Student *)a, bb = *(Student *)b;
    if (aa.level > bb.level)
    {
        return -1;
    }
    else if (aa.level < bb.level)
    {
        return 1;
    }
    else
    {
        if (aa.sum > bb.sum)
        {
            return -1;
        }
        else if (aa.sum < bb.sum)
        {
            return 1;
        }
        else
        {
            if (aa.morality > bb.morality)
            {
                return -1;
            }
            else if (aa.morality < bb.morality)
            {
                return 1;
            }
            else
            {
                if (aa.id > bb.id)
                {
                    return 1;
                }
                else
                {
                    return -1;
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    // 处理输入
    int n, low, high;
    if (scanf("%d%d%d", &n, &low, &high) != 3)
        return EXIT_FAILURE;
    Student students[n];
    for (int i = 0; i < n; i++)
    {
        if (scanf("%ld %d %d", &students[i].id, &students[i].morality, &students[i].ability) != 3)
            return EXIT_FAILURE;
    }
    // 处理数据
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        students[i].sum = students[i].morality + students[i].ability;
        if (students[i].morality >= low && students[i].ability >= low)
        {
            m++;
            if (students[i].morality >= high && students[i].ability >= high)
            {
                students[i].level = BothGood;
            }
            else if (students[i].morality >= high && students[i].ability < high)
            {
                students[i].level = Hight_M_Than_A;
            }
            else if (students[i].morality < high && students[i].ability < high && students[i].morality >= students[i].ability)
            {
                students[i].level = Low_M_Than_A;
            }
            else
            {
                students[i].level = Other_Enrolled;
            }
        }
        else
        {
            students[i].level = Failed;
        }
    }
    // 排序
    qsort(students, n, sizeof(Student), comfunc);
    // 处理输出
    printf("%d\n", m);
    for (int i = 0; i < n; i++)
    {
        if (students[i].level != Failed)
            printf("%ld %d %d\n", students[i].id, students[i].morality, students[i].ability);
    }

    return EXIT_SUCCESS;
}
