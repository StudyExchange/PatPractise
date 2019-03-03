/* 1030 完美数列 （25 分）
解析：
1. 技巧：第二层的for循环里面不用从i开始，而是从i+max开始，这样可以解决运行超时问题。
*/

#include <stdio.h>
#include <stdlib.h>

int comfunc(const void *a, const void *b){
	return *(double *)a - *(double *)b;
}

int main(int argc, char *argv[]){
	// 处理输入
	long int n, p;
	if(scanf("%ld %ld", &n, &p) != 2) return EXIT_FAILURE;
	char temp;
	if(scanf("%c", &temp) != 1) return EXIT_FAILURE;
	double nums[n];
	for(long int i=0; i<n; i++) {
		if(scanf("%lf", &nums[i])!=1) return EXIT_FAILURE;
	}
	// 排序 
	qsort(nums, n, sizeof(double), comfunc);
	long int max=0;
	for(long int i=0; i<n; i++) {
		long int count=max;
		double temp = nums[i]*p;
		for(long int j=i+max; j<n; j++){
			if(nums[j] > temp){
				break;
			}
			count++;
		}
		if(count > max){
			max=count;
		}
	}
	// 处理输出
	printf("%ld", max) ;
	return EXIT_SUCCESS; 
}
