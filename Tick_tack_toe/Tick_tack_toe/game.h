#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<windows.h>	
#include<stdlib.h>
#include<time.h>
#include<math.h>


#define ROW 3
#define COL 3

//��������
void InitBoard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col);

void PlayerBoard(char board[ROW][COL], int row, int col);

void ComputerBoard(char board[ROW][COL], int row, int col);

//1.���Ӯ�˷��� * 
//2.����Ӯ�˷��� #
//3.ƽ�ַ��� D��draw��
//4.��Ϸ���� C ��continue��

char IsWin(char board[ROW][COL], int row, int col);
