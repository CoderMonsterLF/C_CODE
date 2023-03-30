#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
void menu() {
	printf("**********************\n");
	printf("*****   1.play   *****\n");
	printf("*****   0.exit   *****\n");
	printf("**********************\n");
}

void game() {
	char board[ROW][COL];
	
	//初始化棋盘-初始化为空格
	InitBoard(board, ROW, COL);
	
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	
	char ret = 0;

	//下棋
	while (1) {
		//玩家下棋
		PlayerBoard(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		

		//判断玩家是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		
		//电脑下棋
		ComputerBoard(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//判断电脑是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}

	}
	if (ret == '*') {
		printf("玩家赢了！\n");
		DisplayBoard(board, ROW, COL);
	}
	else if (ret == '#') {
		printf("电脑赢了！\n");
		DisplayBoard(board, ROW, COL);
	}
	else {
		printf("双方平局！\n");
		DisplayBoard(board, ROW, COL);
	}
}

int main() {
	int input = 0;
//	srand(time(0));
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请选择：");
		scanf ("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择！\n");
			break;
		}
	} while (input);
	return 0;
}
