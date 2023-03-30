#include"game.h"

//实现函数
//初始化棋盘的函数
void InitBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
// 
// 只能打印3*3棋盘
//void DisplayBoard(char board[ROW][COL], int row, int col) {
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++) {
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2] );
//		if (i < row - 1) {
//			printf("---|---|---\n");
//		}
//	}
//}


//打印n*n棋盘
void DisplayBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) {
			//printf("---|---|---\n");
			for (j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1) {
					printf("|");
				}
				
			}
			printf("\n");
		}
	}
}

//玩家下棋
void PlayerBoard(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("玩家走-->\n");
	
	while (1) {		
		printf("请输入下棋的坐标：\n");
		scanf("%d %d", &x, &y);
		
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			//判断坐标是否被占用
			if (board[x - 1][y - 1] == ' ') {//如果坐标为空，才能输入‘*’
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("坐标被占用，请重新输入!\n");
			}
		}
		else {
			printf("坐标非法，请重新输入!\n");
		}
	}
}


//电脑下棋
void ComputerBoard(char board[ROW][COL], int row, int col) {
	printf("电脑走-->\n");

	while (1) {
		int x = rand() % row;
		int y = rand() % col;
		
		//判断占用
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}
}


//判断棋盘是否满棋
int IsFull(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;//棋盘未满
			}
		}
	}
	return 1;
}

//判断棋局输赢
char IsWin(char board[ROW][COL], int row, int col) {
	int i = 0;

	//判断三行	
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
			return board[i][1];
		}
	}

	//判断三列	
	for (i = 0; i < col; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ') {
			return board[1][i];
		}
	}

	//判断正对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
		return board[1][1];
	}

	//判断副对角线
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ') {
		return board[1][1];
	}

	//判断平局
	int ret = IsFull(board, row, col);
	if (ret == 1) {
		return 'D';
	}

	return 'C';
}