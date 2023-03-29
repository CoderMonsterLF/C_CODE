/*
【题目名称】
乘法口诀表

【题目内容】
实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
如：输入9，输出9*9口诀表，输入12，输出12*12的乘法口诀表。
*/
void multiplication_table(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d * %d = %d\t", j, i, i * j);
		}
		printf("\n");
	}
}
int main() {
	int n = 0;
	printf("请输入打印行列数：\n");
	scanf("%d", &n);
	multiplication_table(n);
	return 0;
}