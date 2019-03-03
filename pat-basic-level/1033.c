/* 1033 旧键盘打字 （20 分）
解析：
1. 根据字母的大小写，在分别的if分支处理就行了。 
2. 注意：处理输入的额首行是空行的情况。 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // 处理输入
    char bad_key_str[100001];
    char str_orig[100001];
    char temp = '\0';
    int bad_key_count = 0;
    while (temp != '\n')
    {
        if (scanf("%c", &temp) != 1)
            return EXIT_FAILURE;
        bad_key_str[bad_key_count] = temp;
        bad_key_count++;
    }
    bad_key_str[bad_key_count - 1] = '\0';
    if (scanf("%s", str_orig) != 1)
        return EXIT_FAILURE;
    // 准备bad_key字典
    long int len_bad_keys = strlen(bad_key_str);
    int bad_keys[128] = {0};
    for (long int i = 0; i < len_bad_keys; i++)
    {
        bad_keys[(int)bad_key_str[i]] = 1;
    }
    // 处理输出
    long int len_str_orig = strlen(str_orig);
    char str_real[100001];
    long int real_count = 0;
    for (long int i = 0; i < len_str_orig; i++)
    {
        char char_orig = str_orig[i];
        int val_orig = (int)char_orig;
        // 小写字母
        if (char_orig >= 'a' && char_orig <= 'z')
        {
            int upper_char = char_orig + 'A' - 'a';
            if (bad_keys[upper_char] == 0)
            {
                str_real[real_count] = char_orig;
                real_count++;
            }
        }
        // 大写字母
        else if (char_orig >= 'A' && char_orig <= 'Z')
        {
            if (bad_keys[val_orig] == 0 && bad_keys[(int)('+')] == 0)
            {
                str_real[real_count] = char_orig;
                real_count++;
            }
        }
        // 其他键
        else
        {
            if (bad_keys[val_orig] == 0)
            {
                str_real[real_count] = char_orig;
                real_count++;
            }
        }
    }
    // 处理输出
    str_real[real_count] = '\0';
    if (real_count != 0)
    {
        printf("%s", str_real);
    }
    else
    {
        printf("\n");
    }

    return EXIT_SUCCESS;
}
