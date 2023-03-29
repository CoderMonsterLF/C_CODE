/*
【题目名称】
递归实现n的k次方

【题目内容】
编写一个函数实现n的k次方，使用递归实现。
*/
int k_pow(int n,int k) {
	if (k > 0) {
		return n * k_pow(n, k - 1);
	}
	else {
		return 1;
	}
}
int main() {
	int n = 0;
	int k = 0;
	printf("输入一个整数n以及次方k：");
	scanf("%d %d", &n, &k);

	int ret = k_pow(n, k);
	printf("%d的%d次方为：%d",n, k, ret);
	return 0;
}