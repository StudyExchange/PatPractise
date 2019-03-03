/* 1036 跟奥巴马一起编程 （15 分）
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
	// 处理输入
	int n;
	char c;
	if(scanf("%d %c", &n, &c)!=2) return EXIT_FAILURE;
	// 计算长和宽
	int len=n;
	int width=(int)(n/2.0+0.5); // 四舍五入 
	// 处理输出
	//   输出第一行 
	for(int i=0;i<len; i++){
		printf("%c", c);
	}
	printf("\n");
	//   输出中间的行
	for(int i=1; i<width-1; i++){
		printf("%c", c);
		for(int j=1;j<len-1; j++){
			printf(" ");
		}
		printf("%c\n", c);
	}
	//   输出最后一行
	for(int i=0;i<len; i++){
		printf("%c", c);
	}
	printf("\n");
	
	return EXIT_SUCCESS; 
}
