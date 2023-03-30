//递归调用一
void print(int n)
{
	if (n > 9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}
int main()
{
	int num = 1234;
	print(num);
	return 0;
}

//递归调用 - mystrlen
int Strlen(const char*str)
{
	if(*str == '\0')
	return 0;
	else
	return 1+Strlen(str+1);
}
int main()
{
	char *p = "abcdef";
	int len = Strlen(p);
	printf("%d\n", len);
	return 0;
}

//递归调用三 - 斐波那契数列
//递归调用的缺点：容易重复调用导致栈溢出，从而程序崩溃，效率特别低
int count = 0;//全局变量
int fib(int n)
{
	if (n == 3)
		count++;
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

int main() {
	int n = 0;
	scanf("%d", n);
	int ret = fib(n);
	printf("%d\n", ret);
	printf("count = %d", count);
	return 0;
}



//递归调用改迭代-效率直接飞速提升（斐波那契数列）
int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n>2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Fib(n);

	printf("%d\n", ret);

	return 0;
}