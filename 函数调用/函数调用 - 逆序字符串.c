/*
【题目名称】

字符串逆序（递归实现）

【题目内容】

编写一个函数 reverse_string(char * string)（递归实现）

实现：将参数字符串中的字符反向排列，不是逆序打印。

要求：不能使用C函数库中的字符串操作函数。

比如:
char arr[] = "abcdef";
逆序之后数组的内容变成：fedcba
*/

//递归打印
void reverse_string(char* str) {
	if (*str != '\0') {
		reverse_string(1 + str );
		printf("%c", *str);
	}
}
int main() {
	char arr[20] = { 0 };
	printf("输入字符串：\n");
	scanf("%s", arr);

	reverse_string(arr);
	return 0;
}

//递归交换
void reverse_string(char* arr)
{
	int len = strlen(arr);
	
	//假设字符串‘a b c d e f \0’
	//第一步：先把首位字符 ‘a’ 复制一份到一边  ‘a b c d e f \0’ ，即 tmp=a
	char tmp = *arr;
	//第二步：字符串最后一位 ‘f’ 赋值到第一位 ‘a’ ，即‘f b c d e f \0’
	*arr = *(arr + len - 1);
	//第三步：将字符串最后一位 ‘f’ 赋值'\0'，即‘f b c d e \0 \0’
	*(arr + len - 1) = '\0';
	//第四步：将第二位‘b’设置为首位，然后递归调用，重复运行
	if (strlen(arr + 1) >= 2) {
		reverse_string(arr + 1);
	}
	//第五步：把 tmp 中的 ‘c’、‘b’、‘a’ 放到相应的 ‘\0’ 中
	*(arr + len - 1) = tmp;
}
int main() {
	char arr[20] = { 0 };
	printf("输入字符串：\n");
	scanf("%s", arr);

	reverse_string(arr);
	printf("逆序字符串为：%s\n", arr);
	return 0;
}