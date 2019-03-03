/* 1023 �����С�� ��20 �֣�
������
1. ע�⴦��ָ��Ϊ-0��+0������� 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]){
	// ��������
	char str[10000];
	if(scanf("%s", str) !=1) return EXIT_FAILURE;
	int str_len = strlen(str);
	// ͳ�����ֵĲ���
	//   �ж����� 
	int is_positive=1;
	if(str[0]=='-'){
		is_positive = 0;
	}
	//    �ռ���Ч����
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
	//    �ж�ָ��������
	int is_e_positive=1;
	if(str[pos]=='-'){
		is_e_positive = 0;
	}
	//    �ռ�ָ��
	int e_count=0;
	char e_num_arr[str_len];
	for(int i=pos+1; i<str_len; i++){
		e_num_arr[e_count] = str[i];
		e_count++;
	}
	//    ָ���ַ���תint
	int e_val=0;
	for(int i=0; i<e_count; i++){
		e_val += (e_num_arr[i] - '0') * (int)pow(10, e_count-i-1);
	}
	
	// �������
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

