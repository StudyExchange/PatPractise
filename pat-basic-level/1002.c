/* 1002 写出这个数 （20 分）
解析：
1. 注意打印字符串后面没有空格，使用printf("%s%s", pinyins[sum_num[j]], j==0?"":" ");
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	char big_num[110] = "";
	if (scanf("%s", big_num) != 1)
	{
		return EXIT_FAILURE;
	}
	// 字符转数字并求和
	int sum = 0;
	for (int i = 0; i < strlen(big_num); i++)
	{
		sum += big_num[i] - '0';
	}
	// 和转换成单个的数字（倒序的）
	int sum_num[110] = {0};
	int i = 0;
	do
	{
		sum_num[i] = sum % 10;
		sum = sum / 10;
		i++;
	} while (sum);
	// 倒序打印和的各个数字
	char pinyins[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	for (int j = i - 1; j >= 0; j--)
	{
		printf("%s%s", pinyins[sum_num[j]], j == 0 ? "" : " ");
	}
	return EXIT_SUCCESS;
}
