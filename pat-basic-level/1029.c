/* 1029 旧键盘 （20 分）
解析：
1. 技巧：应该输入的文字是全长，而实际输出的文字一定比前者短，那么程序就好实现了。 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // 处理输入
    char str_orig[81];
    char str_real[81];
    if (scanf("%s", str_orig) != 1)
        return EXIT_FAILURE;
    if (scanf("%s", str_real) != 1)
        return EXIT_FAILURE;
    // 比对数据
    int len_orig = strlen(str_orig);
    int ansic[256] = {};
    int i = 0, j = 0;
    while (i < len_orig)
    {
        if (str_orig[i] == str_real[j])
        {
            i++;
            j++;
        }
        else
        {
            int temp = str_orig[i];
            // 小写字母全部转大写字母
            if (temp >= 'a' && temp <= 'z')
            {
                temp = temp + 'A' - 'a';
            }
            if (ansic[temp] == 0)
            {
                printf("%c", temp);
            }
            ansic[temp] = 1;
            i++;
        }
    }
    return EXIT_SUCCESS;
}
