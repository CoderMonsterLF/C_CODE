
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<windows.h>	
#include<stdlib.h>
#include<time.h>
#include<math.h>


/*【题目名称】

函数判断素数

【题目内容】

实现一个函数，判断一个数是不是素数。

利用上面实现的函数打印100到200之间的素数。*/

int prime(int n) {
	int x = 0;
	for (x = 2; x < sqrt(n); x++) {
		if (n % x == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int i = 0;
	for (i = 100; i <= 200; i++) {
		//判断i是否是素数
		if (prime(i) == 1) {
			printf("%d\t", i);
		}
	}
	return 0;
}