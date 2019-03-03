/* 1005 继续(3n+1)猜想 （25 分）
解析：
1. 使用int数组作为字典，用作状态标记。
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	// 处理输入
	int n;
	int max = 100;
	if(scanf("%d", &n) != 1) {
		return EXIT_FAILURE;
	}
	int in_nums[n];
	for(int i=0; i<n; i++){
		if(scanf("%d", &in_nums[i]) != 1){
			return EXIT_FAILURE;
		}
	}
	// (3n+1)猜想
	int flags[max + 1];
	for(int i=0; i<max+1; i++){
		flags[i] = 0;
	}
	for(int i=0; i<n; i++){
		int temp_num = in_nums[i];
		if(flags[temp_num] == 0){ // 如果标志为0，说明没有被覆盖过，则标志设置为1
			flags[temp_num] = 1; 
		}else{
			continue;
		}
		while(temp_num > 1){
			if(temp_num % 2 == 0){
				temp_num = temp_num/2;
			}else{
				temp_num = (3*temp_num + 1)/2;
			}
			// 设置被覆盖的数字的状态为in_nums[i]，大于101的不会用到，所以不用设置 
			if(temp_num <= max){
				flags[temp_num] = in_nums[i];
			}
		}
    }
    // 获取关键数
	int count = 0;
	for(int i=0; i<n; i++) {
		if(flags[in_nums[i]] == 1){
			count++;
		}
	}
	// 处理输出
	for(int i=max; i>=0; i--) {
		if(flags[i] == 1){
			count--;
			printf("%d%s", i, count==0?"": " ");
		}
	}
	return EXIT_SUCCESS; 
}
