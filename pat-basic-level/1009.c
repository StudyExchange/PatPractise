/* 1009 说反话 （20 分）
解析：
1. scanf处理输入的空格。1. 分割字符串的技巧。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	// 处理输入
	char string[80];
	if(scanf("%[^\n]", string) != 1) return EXIT_FAILURE;
	// 分割单词
	int len = strlen(string);
	char words[80][80];
	int i = 0, j = 0;
	for(int k=0; k<=len; k++){
		if(string[k] != ' ' && string[k] !='\0'){
			words[i][j] = string[k];
			j++;
		}else{
			words[i][j] = '\0';
			i++;
			j = 0;
		}
	}
	// 处理输出
	while(--i >= 0){
		printf("%s%s", words[i], i==0?"":" ");
	}
	
	return EXIT_SUCCESS; 
}
