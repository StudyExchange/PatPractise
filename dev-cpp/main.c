/* 1023 组个最小数 （20 分）
解析：
1. 注意处理指数为-0和+0的情况。 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]){
	// 处理输入
	char str[10000];
	if(scanf("%s", str) !=1) return EXIT_FAILURE;
	int str_len = strlen(str);
	// 统计数字的参数
	//   判断正负 
	int is_positive=1;
	if(str[0]=='-'){
		is_positive = 0;
	}
	//    收集有效数字
	int valid_num_count=0;
	int pos = 0;
	char valid_num_arr[str_len];
	for(int i=0; i<str_len; i++){
		pos++;
		if(str[i] == 'E'){
			break;
		}
		if((str[i] - '0') < 0 || (str[i] - '0') > 9){
			continue;
		}
		valid_num_arr[valid_num_count]=str[i];
		valid_num_count++;
	}
	//    判断指数的正负
	int is_e_positive=1;
	if(str[pos]=='-'){
		is_e_positive = 0;
	}
	//    收集指数
	int e_count=0;
	char e_num_arr[str_len];
	for(int i=pos+1; i<str_len; i++){
		e_num_arr[e_count] = str[i];
		e_count++;
	}
	//    指数字符串转int
	int e_val=0;
	for(int i=0; i<e_count; i++){
		e_val += (e_num_arr[i] - '0') * (int)pow(10, e_count-i-1);
	}
	
	// 处理输出
	if(is_positive==0){
		printf("-");
	}
	if(is_e_positive > 0){
		int i = 0;
		while(i < valid_num_count || i <= e_val){
			if(i < valid_num_count){
				printf("%c", valid_num_arr[i]);
			}else{
				printf("0");
			}
			if(i < valid_num_count-1 && i==e_val){
				printf(".");
			}
			i++;
		}
	}else{
		int i=0;
		if(e_val>0){
			printf("0.");
			while(i<e_val-1){
				printf("0");
				i++;
			}
			int j=0;
			while(j < valid_num_count){
				printf("%c", valid_num_arr[j]);
				i++;
				j++;
			}
		}else{
			printf("%c.", valid_num_arr[0]);
			for(int i=1; i<valid_num_count; i++){
				printf("%c", valid_num_arr[i]);
			}
		}
		
	}
	return EXIT_SUCCESS; 
}

