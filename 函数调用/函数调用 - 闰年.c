
//2. 写一个函数判断一年是不是闰年。

int leap_year(int n) {
	//能被400整除，或者能被4整除但不能被100整除的都是闰年

	//if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0)
	//这种在（1000年-2000年）就能正确打印，
	//但是当打印（400年-1000年）时，也会出现401%400==1，然后将n==1传给y，然后打印出“401年是闰年”
	//即根源在于 “if (leap_year(y) == 1)” 这条语句是有问题的，
	//一旦leap_year函数中n%400==1了，即使if语句为假，它也会将n==1传给y


	//优先级 % 大于 == 等于 != 大于 && 大于 ||

	//进一步测试是不是 或 后面的n%400使得n==1了，那么将400改为401
	//if (n % 4 == 0 && n % 100 != 0 || n % 401 == 0) 
	//会出现402年是闰年，判断为 或 后面那条 n%401让n==1

	//将闰年条件互换回来，并且适当调整数据以便观测
	//if (n % 402 == 0 || n % 401 != 0 && n % 4 == 0)
	//打印101年是闰年，判断为 与 后面那条语句 n%4（即101%4） 使得 n==1
	//没有402年是闰年，排除 n % 401 != 0 这条语句
	//没有403年是闰年，排除 n % 402 == 0 这条语句

	//将&&前后调换测试
	//if (n % 402 == 0 || n % 4 == 0 && n % 401 != 0)
	//打印101年是闰年，判断为 与 前面那条n%4让n == 1，

	//没有402年是闰年，排除 n % 401 == 1；
	//没有403年是闰年，排除 n % 402 == 0 这条语句

	//现在单独测试 == 和 != 语句
	//if (n % 401 != 0)
	//什么都不会打印，说明 != 语句不会出现 402%401==1 的情况，即n不会发生改变

	//if (n % 401 == 0)
	//打印了 “402是闰年”，说明 == 语句会使得n为402时出现 402%401==1 的情况，即n会变为1，然后返回给y

	//进一步测试 && 和 ||
	//if (n % 403 == 0 && n % 401 == 0)
	//打印了404是闰年，说明 n % 403==1 返回给y了，没有计算 n % 401
	//初步判断结果为&&只会做前面的运算，而不会做后面的运算，&&结合性为从左至右，有点不合理
	//然后把if (leap_year(y) == 1)改为if (leap_year(y) == 2)
	//会发现会打印403和405是闰年，又会出现 403%401==2 ，然后传值给y
	//试一试3,4,5...等数字
	//之后所有的数字都只会 n % 403 ，即&&前面的，不会出现&&后面的n % 401		
		
	//if (n % 403 == 0 || n % 401 == 0)
	//打印了402是闰年，说明 n % 401==1 返回给y了，没有计算 n % 403		
	// ||会做后面的运算，而不会做前面的运算，猜测可能是||结合性为从左至右
	//然后把if (leap_year(y) == 1)改为if (leap_year(y) == 2)
	//会发现什么都不会打印
	//试一试3,4,6...等数字
	//之后所有的数字都只会 n % 401 ，即 || 后面的，不会出现 || 前面的n % 403


	//经过以上测试，总结几条
	//第一：n % 400 == 0,n % 400会计算结果使得n与y匹配，一旦匹配成功，就会打印
	//		而n % 400 != 0,并不会计算n % 400
	//第二：if (n % 403 == 0 && n % 401 == 0) 中&&大概率会计算前面的（2除外），而不会计算后面的
	//		if (n % 403 == 0 || n % 401 == 0)中 || 大概率会计算后面的（2除外），而不会计算前面的

	//{
	//return 5;
	//	//当返回5也能正常打印时，说明根本没有执行 “return 5;” 这条语句，
	//	//并不是因为 && 比 || 优先级高，先执行 “n % 100 != 0 && n % 4 == 0”这条语句，
	//	//基于101%4==1,以及105%4==1这类情况，所以当后执行 || 语句时，‘或’中有真则真，返回了1。
	//	//测试方法可以使用 if (leap_year(y) == 2) ，那么会打印 “102年是闰年”等情况。 
	//	//还是因为n%4等于了if (leap_year(y) == 这个值)
	//}
	
	//下面写写正确编码
	//第一招：老老实实写else return 0;
	//交换闰年条件位置
	//if (n % 100 != 0 && n % 4 == 0 || n % 400 == 0 )
	//	return 1;
	//else 
	//	return 0;//有了否则就返回0；n%400中的（401%400==1）就不会直接传值给y了

	//第二招：直接返回真或假
	return ((n % 100 != 0 && n % 4 == 0) || (n % 400 == 0));
}

int main() {
	int y = 0;
	for (y = 100; y <= 500; y++) {
		if (leap_year(y) == 1) {//返回值最好不要是正整数
			printf("%d是闰年\n", y);
		}
	}
	return 0;
}
