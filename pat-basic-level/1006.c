/* 1006 换个格式输出整数 （15 分）
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	// 处理输入
	int n;
	if(scanf("%d", &n) != 1) {
		return EXIT_FAILURE;
	}
	// 数字分拆成各位的数字
	int nums[3] = {0};
	for(int i=2; i>=0; i--){
		nums[i] = n%10;
		n = n/10;
	}
	// 处理输出
	for(int i=0; i<nums[0]; i++){
		printf("B");
	}
	for(int i=0; i<nums[1]; i++){
		printf("S");
	}
	for(int i=0; i<nums[2]; i++){
		printf("%d", i+1);
	}

    return EXIT_SUCCESS; 
}
