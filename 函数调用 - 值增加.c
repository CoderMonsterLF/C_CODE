//4. 写一个函数，每调用一次这个函数，就会将num 的值增加1。
//函数中实现值增加，只能传入地址，通过指针的方式改变值
void Add(int *p) {
	(*p)++;
}

int main() {
	int num = 0;
	Add(&num);
	printf("%d\n", num);
	return 0;
}