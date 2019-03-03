/* 1007 素数对猜想 （20 分）
解析：
1. 判断素数。
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(long int n);

int main(int argc, char *argv[]){
	// 处理输入
	long int n, max=100000;
	if(scanf("%ld", &n) != 1) {
		return EXIT_FAILURE;
	}
	// 打印素数，核查数据是否正确 
//	for(long int i=2; i<n; i++) {
//		if(is_prime(i)){
//			printf("%d ", i);
//		}
//	}
	// 判断素数对并计数
	int count=0;
	for(long int i=2; i<=n-2 && i<max-2; i++){
		if(is_prime(i) && is_prime(i+2)){
//			printf("\n%d %d", i, i+2);
			count++;
		}
	}
	
	// 处理输出
	printf("%d", count);
	
	return EXIT_SUCCESS; 
}

int is_prime(long int n){
	long int max_divisor = (long int)sqrt(n);
	for(long int i=2; i<= max_divisor; i++){
		if(n%i == 0){
			return 0;
		}
	}
	return 1;
}
