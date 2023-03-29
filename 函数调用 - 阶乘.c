/*
【题目名称】
求阶乘

【题目内容】
递归和非递归分别实现求n的阶乘（不考虑溢出的问题）
*/
//阶乘递归
int factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}
int main() {
	int n = 0;
	printf("输入所求阶乘n的值：\n");
	scanf("%d", &n);

	int ret = factorial(n); 
	printf("%d的阶乘为：%d",n,ret);
	return 0;
}


// 阶乘迭代while
int factorial(int n) {
	int ret = 1;
	while (n>=1) {
		ret = n * ret;
		n--;
	}
	return ret;
}
int main() {
	int n = 0;
	printf("输入所求阶乘n的值：\n");
	scanf("%d", &n);

	int ret = factorial(n);
	printf("%d的阶乘为：%d", n, ret);
	return 0;
}

// 阶乘迭代for
int factorial(int N)
{
	int ret = 1;
	for (int i = 2; i <= N; ++i)
	{
		ret *= i;
	}

	return ret;
}
int main() {
	int n = 0;
	printf("输入所求阶乘n的值：\n");
	scanf("%d", &n);

	int ret = factorial(n);
	printf("%d的阶乘为：%d", n, ret);
	return 0;
}