#pragma once
#include<stdio.h>
#include <stdlib.h>

#define ROW 9
#define COW 9
//��ӡ��ս��
#define ROWS (ROW+2)
#define COWS (COW+2)
//���׵�ս��

#define EASY_COUNT 10

//��ʼ��
void InitBoard(char board[ROWS][COWS], int row, int cow,char some);

void DisPlay(char board[ROWS][COWS], int row, int cow);

void GetMind(char board[ROWS][COWS], int row, int cow);

int Count(char mind[ROWS][COWS],int x, int y);

void FindMind(char mind[ROWS][COWS], char show[ROWS][COWS], int row, int cow);