#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


//初始化棋盘 - 遍历数组
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) {
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			board[i][j] = set;
		}
	}
}


//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	int j = 0;
	printf("---------扫雷游戏-----------\n");
	//打印列号
	for (i = 0; i <= col; i++) {
		printf("%d ", i);
	}
	printf("\n");


	//打印棋盘
	for (i = 1; i <= row; i++) {
		printf("%d ", i);//打印行号
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("---------扫雷游戏-----------\n");
}

//布置雷
void SetMine(char mine[ROWS][COLS], int row, int col) {
	int count = EASY_COUNT;
	while (count) {
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		//判断是否盘上有雷
		if (mine[x][y] == '0') {
			mine[x][y] = '1';
			count--;
		}
	}
}

//static
//1. 修饰局部变量
//2. 修饰全局变量
//3. 修饰函数

static int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	//粗暴实现法
	//return mine[x - 1][y] +
	//	mine[x - 1][y - 1] +
	//	mine[x][y - 1] +
	//	mine[x + 1][y - 1] +
	//	mine[x + 1][y] +
	//	mine[x + 1][y + 1] +
	//	mine[x][y + 1] +
	//	mine[x - 1][y + 1] - 8 * '0';


	int cnt = 0;
	//由于是中间肯定为‘0’，所以可以直接遍历x-1到x+1，以及y-1到y+1
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (mine[i][j] == '1') {
				cnt++;
			}
		}
	}
	return cnt;
}

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//1. 输入排查的坐标
	//2. 检查坐标处是不是雷
	   // (1) 是雷   - 很遗憾炸死了 - 游戏结束
	   // (2) 不是雷  - 统计坐标周围有几个雷 - 存储排查雷的信息到show数组，游戏继续

	int x = 0;
	int y = 0;
	int win = 0;

	while (win < row * col - EASY_COUNT)
	{
		printf("请输入要排查的坐标:>");
		scanf("%d %d", &x, &y);//x--(1,9)  y--(1,9)

		//判断坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//不是雷情况下，统计x,y坐标周围有几个雷
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				//显示排查出的信息
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标不合法，请重新输入\n");
		}
	}

	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, row, col);
	}
}



