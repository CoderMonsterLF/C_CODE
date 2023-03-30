/*
【题目名称】

交换两个整数

【题目内容】

实现一个函数来交换两个整数的内容。*/

int swap(int* pa, int* pb) {
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}
int main() {
	int i = 0;
	int j = 0;
	printf("请输入需要交换的两个值i和j:\n");
	scanf("%d %d", &i, &j);
	swap(&i, &j);
	printf("i = %d j = %d", i, j);
	return 0;
}