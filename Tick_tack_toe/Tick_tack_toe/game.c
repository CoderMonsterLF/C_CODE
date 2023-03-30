#include"game.h"

//ʵ�ֺ���
//��ʼ�����̵ĺ���
void InitBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}

//��ӡ����
// 
// ֻ�ܴ�ӡ3*3����
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


//��ӡn*n����
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

//�������
void PlayerBoard(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("�����-->\n");
	
	while (1) {		
		printf("��������������꣺\n");
		scanf("%d %d", &x, &y);
		
		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			//�ж������Ƿ�ռ��
			if (board[x - 1][y - 1] == ' ') {//�������Ϊ�գ��������롮*��
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("���걻ռ�ã�����������!\n");
			}
		}
		else {
			printf("����Ƿ�������������!\n");
		}
	}
}


//��������
void ComputerBoard(char board[ROW][COL], int row, int col) {
	printf("������-->\n");

	while (1) {
		int x = rand() % row;
		int y = rand() % col;
		
		//�ж�ռ��
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}
}


//�ж������Ƿ�����
int IsFull(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;//����δ��
			}
		}
	}
	return 1;
}

//�ж������Ӯ
char IsWin(char board[ROW][COL], int row, int col) {
	int i = 0;

	//�ж�����	
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
			return board[i][1];
		}
	}

	//�ж�����	
	for (i = 0; i < col; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ') {
			return board[1][i];
		}
	}

	//�ж����Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
		return board[1][1];
	}

	//�жϸ��Խ���
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ') {
		return board[1][1];
	}

	//�ж�ƽ��
	int ret = IsFull(board, row, col);
	if (ret == 1) {
		return 'D';
	}

	return 'C';
}