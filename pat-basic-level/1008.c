/* 1008 数组元素循环右移问题 （20 分）
解析：
1. 右移的实现技巧。使用三个reverse。
*/

#include <stdio.h>
#include <stdlib.h>

void reverse(int nums[], int start, int end);

int main(int argc, char *argv[]){
	// 处理输入
	int n, m;
	if(scanf("%d%d", &n, &m) != 2) return EXIT_FAILURE;
	int nums[n];
	for(int i=0; i<n; i++){
		if(scanf("%d", &nums[i]) != 1) return EXIT_FAILURE;
	}
	// 除余，避免越界 
	m = m%n;
	// 右移
	reverse(nums, 0, n);
	reverse(nums, 0, m);
	reverse(nums, m, n);
	// 处理输出
	for(int i=0; i<n; i++){
		printf("%d%s", nums[i], i==n-1?"":" ");
	}
	return EXIT_SUCCESS; 
}

void reverse(int nums[], int start, int end){
	for(int i=0; i<(end-start)/2; i++){
		int t = nums[start + i];
		nums[start + i] = nums[end - i - 1];
		nums[end - i - 1] = t;
	}
}
