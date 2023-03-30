/*
【题目名称】
strlen的模拟（递归实现）

【题目内容】
递归和非递归分别实现strlen
*/

//递归strlen
int my_strlen(char *str) {
	if (*str == '\0')
		return 0;
	else
		return 1 + my_strlen(str + 1);
}
int main() {
	char arr[20] = { 0 };
	printf("输入字符串：\n");
	scanf("%s", arr);

	int len = my_strlen(arr);
	printf("字符串长度为：%d\n", len);
	return 0;
}

//迭代strlen
int my_strlen(char* str) {
	int cnt = 0;
	while (*str != '\0') {
		cnt++;
		str++;
	}
	return cnt;
}
int main() {
	char arr[20] = { 0 };
	printf("输入字符串：\n");
	scanf("%s", arr);

	int len = my_strlen(arr);
	printf("字符串长度为：%d\n", len);
	return 0;
}