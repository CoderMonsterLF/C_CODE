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

//声明函数
void InitBoard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col);

void PlayerBoard(char board[ROW][COL], int row, int col);

void ComputerBoard(char board[ROW][COL], int row, int col);

//1.玩家赢了返回 * 
//2.电脑赢了返回 #
//3.平局返回 D（draw）
//4.游戏继续 C （continue）

char IsWin(char board[ROW][COL], int row, int col);
