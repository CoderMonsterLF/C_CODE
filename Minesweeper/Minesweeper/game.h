#pragma once


#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<windows.h>	
#include<stdlib.h>
#include<time.h>
#include<math.h>


#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

void DisplayBoard(char board[ROWS][COLS], int row, int col);

//布置雷声明
void SetMine(char mine[ROWS][COLS], int row, int col);


//排查雷声明
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);