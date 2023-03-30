/*
【题目名称】
计算一个数的每位之和（递归实现）

【题目内容】
写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和

例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19
输入：1729，输出：19
*/

//函数迭代
int DigitSum(n) {
	int sum = 0;
	int i = 0;
	while (n > 0) {		
		i =	n % 10;
		sum += i;
		n /= 10;
	}
	return sum;
}
int main() {
	int n = 0;
	printf("输入一个非负整数：");
	scanf("%d", &n);
	int ret = DigitSum(n);
	printf("数字之和为：%d", ret);
	return 0;
}

//函数递归
int DigitSum(n) {
	if (n > 9) {
		return DigitSum(n / 10) + (n % 10);
	}
	else {
		return n;
	}
}
int main() {
	int n = 0;
	printf("输入一个非负整数：");
	scanf("%d", &n);
	int ret = DigitSum(n);
	printf("数字之和为：%d", ret);
	return 0;
}
