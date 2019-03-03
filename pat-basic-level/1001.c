/* 1001 害死人不偿命的(3n+1)猜想 （15 分）
解析：
1. 注意PAT中使用scanf需要加判断，免得提交报警告
if (scanf("%d", &n) != 1) {
	return EXIT_FAILURE;
};
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int n;
	int count = 0;
	if (scanf("%d", &n) != 1)
	{
		return EXIT_FAILURE;
	};
	// n为正整数，否则返回错误
	if (n < 1)
	{
		return EXIT_FAILURE;
	}
	while (n > 1)
	{
		if (n % 2)
		{
			n = (3 * n + 1) / 2;
		}
		else
		{
			n /= 2;
		}
		count++;
	}
	if (n != 1)
	{
		return EXIT_FAILURE;
	}
	printf("%d", count);
	return EXIT_SUCCESS;
}
