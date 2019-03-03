/* 1047 编程团体赛 （20 分）
解析：
1. int数组作为字典
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int team_id;
    int member_id;
    int grade;
} Competitor;

int main(int argc, char *argv[])
{
    // 处理输入
    char temp;
    int n;
    if (scanf("%d", &n) != 1)
        return EXIT_FAILURE;
    if (scanf("%c", &temp) != 1)
        return EXIT_FAILURE;
    Competitor competitors[n];
    int sums[1001] = {0};
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d-%d %d", &competitors[i].team_id, &competitors[i].member_id, &competitors[i].grade) != 3)
            return EXIT_FAILURE;
        if (scanf("%c", &temp) != 1)
            return EXIT_FAILURE;
        sums[competitors[i].team_id] += competitors[i].grade;
    }
    // 找到最大的队伍
    int max_team_id = 0;
    int max_sum = sums[0];
    for (int i = 1; i < 1001; i++)
    {
        if (sums[i] > max_sum)
        {
            max_sum = sums[i];
            max_team_id = i;
        }
    }
    // 处理输出
    printf("%d %d", max_team_id, max_sum);

    return EXIT_SUCCESS;
}
