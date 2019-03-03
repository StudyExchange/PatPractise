/* 1044 火星数字 （20 分）
解析：
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str2num(char str[], int str_len){
	int sum=0;
	for(int i=0;i<str_len;i++){
		sum+=(int)str[i]*pow(10, str_len-1);
	}
	return sum;
}

void num2mar(int num, char mar[]){
	int ten = num/13;
	int reminder = num%13;
	char one_arr[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
	char ten_arr[13][5] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
	if(ten==0){
		strcpy(mar, one_arr[reminder]);
	}else{
		strcpy(mar, ten_arr[ten]);
		strcat(mar, " ");
		strcat(mar, one_arr[reminder]);
	}
}

int mar2num(char mar[], int n){
	char num[2][5];
	int count=0;
	int idx=0;
	// 分割字符串 
	for(int i=0;i<n;i++){
		if(mar[i]==' '){
			num[count][idx]='\0';
			count++;
			idx=0;
		}else if(mar[i]=='\0'){
			num[count][idx]='\0';
			break;
		}else{
			num[count][idx]=mar[i];
			idx++;
		}
	}
	// 字符串转数字
	char mar_num_arr[2][13][5] = {
		{"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"}, 
		{"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}
	};
	int sum=0;
	for(int i=0;i<count;i++){
		int num=0;
		int num_idx=count-i;
		for(int j=0;j<13;j++){
			char dest[5];
			char src[5];
			strcpy(dest, num[num_idx]);
			strcpy(src, mar_num_arr[num_idx][j]);
			if(strcmp(dest, src)==0){
				num=j;
			}
		}
		sum+=num*pow(13, num_idx);
	}
	return sum;
}

int main(int argc, char *argv[]){
	// 处理输入
	char temp;
	int n;
	if(scanf("%d", &n)!=1) return EXIT_FAILURE;
	if(scanf("%c", &temp)!=1) return EXIT_FAILURE;
	char num_str[n][4];
	for(int i=0;i<n;i++){
		if(scanf("%s", num_str[i])!=3) return EXIT_FAILURE;
		if(scanf("%c", &temp)!=1) return EXIT_FAILURE;
	}
	// 处理输出
	for(int i=0;i<n;i++){
		if(num_str[i][0] >= '0' && num_str[i][0]){
			char result[10]="";
			int num = str2num(num_str[i], strlen(num_str[i]));
			num2mar(num, result);
			printf("%s", result);
		}else{
			int result = mar2num(num_str[i], strlen(num_str[i]));
			printf("%s", result);
		}
	}
	
	return EXIT_SUCCESS; 
}
