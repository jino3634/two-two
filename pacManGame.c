//출처 : http://breadshuttle.tistory.com/entry/C%EC%96%B8%EC%96%B4-%EC%8B%AC%EC%8B%AC%ED%92%80%EC%9D%B4%EA%B2%8C%EC%9E%84%EB%A7%8C%EB%93%A4%EC%96%B4%EB%B3%B4%EA%B8%B02%ED%83%84
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib") // playsound함수를 사용하기 위해 #pragma매크로 사용 -> lib파일 읽어들이는데 사용.

#define LEFT 75                     
#define RIGHT 77                     
#define UP 72                          
#define DOWN 80                    


void gotoxy(int x, int y);          
COORD getXY();
COORD Cur;

void setmap();                      
int move(char ch);               
void enemyMove(char *x, char *y);

void disappear();

void save(int stage);

void printTitle();
void gameMenu();
void selectGameMenu();
void Title();

char(*map)[50];
int enemyCount = 0;
int stage = 1;

char startx = 0;                       
char starty = 0;                      
										

char u1x = 0;
char u1y = 0;

char u2x = 0;
char u2y = 0;

char u3x = 0;
char u3y = 0;

char u4x = 0;
char u4y = 0;

void initialization();

int food = 1;//자신의 위치를 포함(1부터 시작)
			

char map_1[50][50] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,1 },
	{ 1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1 },
	{ 1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1 },
	{ 1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,1 },
	{ 1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }

};

char map_2[50][50] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1 },
	{ 1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1 },
	{ 1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,1 },
	{ 1,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,1 },
	{ 1,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1,1,0,1,1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,0,1,0,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1,1,0,1,1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,1 },
	{ 1,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,1 },
	{ 1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,1 },
	{ 1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1 },
	{ 1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }

};

char map_3[50][50] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,1 },
	{ 1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1 },
	{ 1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1 },
	{ 1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1 },
	{ 1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1 },
	{ 1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1 },
	{ 1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1 },
	{ 1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,2,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1 },
	{ 1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1 },
	{ 1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1 },
	{ 1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1 },
	{ 1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1 },
	{ 1,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};


void main()
{

	disappear();// 처음부터 커서를 제거함. 11.28 수정
	Title();

	system("mode con:cols=130 lines=53");

	int state = 3;
	int key = 1;//초기화를 안하면 if문에서 에러가 나므로, 아무 값이나 초기화.

	map = &map_1;




	setmap();  //2-1

	while (1)                             //2-2
	{

		enemyMove(&u1x, &u1y);


		if (enemyCount >= 2)//유령의 갯수를 파악하여 움직임..
		{
			enemyMove(&u2x, &u2y);
			if (enemyCount >= 3)
			{
				enemyMove(&u3x, &u3y);
				if (enemyCount >= 4)
				{
					enemyMove(&u4x, &u4y);
				}
			}
		}
		//--------------------------------------------------------------------------------------------------유령의 움직임을 2번으로 설정함 //(스테이지별로 if문 걸어서 난이도 설정 가능..)
		enemyMove(&u1x, &u1y);

		//printf(" %d %d", u1x, u1y);

		if (enemyCount >= 2)//유령의 갯수를 파악하여 움직임..
		{
			enemyMove(&u2x, &u2y);
			if (enemyCount >= 3)
			{
				enemyMove(&u3x, &u3y);
				if (enemyCount >= 4)
				{
					enemyMove(&u4x, &u4y);
				}
			}
		}


		if (_kbhit())//키 입력 여부 확인 ->http://showmiso.tistory.com/8
			key = _getch();//키를 입력 받음. 

		state = move(key);//움직이며 상태 변수를 반환.
		Sleep(100);
		
		if (state == 1)
		{
			printf("게임 클리어!!!");//임의 프린트문으로 대체, 맵의 다양해짐에따라 추가 예정
			Sleep(3000);

			initialization();//이하 맵 셋팅;
			stage++;
			if (stage == 2)
			{
				map = &map_2;
				setmap();
			}
			else if (stage == 3)
			{
				map = &map_3;
				setmap();
			}

			else if (stage == 4)
			{
				printf("축하드립니다 올클리어!");//차차 추가 할 예정 ㅠㅠ
				break;//탈출
			}

		}
		else if (state == 2)
		{
			printf("게임오버");
			break;// 탈출
		}

		
		//--------------------------------------------------------------------------------------------------유저의 움직임을 3번으로 설정함 ㅠㅠ//(스테이지별로 if문 걸어서 난이도 설정 가능..)
		if (_kbhit())//키 입력 여부 확인 ->http://showmiso.tistory.com/8
			key = _getch();//키를 입력 받음. 
		state = move(key);//움직이며 상태 변수를 반환.

		Sleep(100);

		if (state == 1)
		{
			printf("게임 클리어!!!");//임의 프린트문으로 대체, 맵의 다양해짐에따라 추가 예정
			Sleep(3000);

			initialization();//이하 맵 셋팅;
			stage++;
			if (stage == 2)
			{
				map = &map_2;
				setmap();
			}
			else if (stage == 3)
			{
				map = &map_3;
				setmap();
			}

			else if (stage == 4)
			{
				printf("축하드립니다 올클리어!");//차차 추가 할 예정 ㅠㅠ
				break;//탈출
			}

		}
		else if (state == 2)
		{
			printf("게임오버");
			break;// 탈출
		}
		//--------------------------------------------------------------------------------------------------유저의 움직임을 3번으로 설정함 ㅠㅠ//(스테이지별로 if문 걸어서 난이도 설정 가능..)
		if (_kbhit())//키 입력 여부 확인 ->http://showmiso.tistory.com/8
			key = _getch();//키를 입력 받음. 
		state = move(key);//움직이며 상태 변수를 반환.

		Sleep(100);

		if (state == 1)
		{
			printf("게임 클리어!!!");//임의 프린트문으로 대체, 맵의 다양해짐에따라 추가 예정
			Sleep(3000);

			initialization();//이하 맵 셋팅;
			stage++;
			if (stage == 2)
			{
				map = &map_2;
				setmap();
			}
			else if (stage == 3)
			{
				map = &map_3;
				setmap();
			}

			else if (stage == 4)
			{
				printf("축하드립니다 올클리어!");//차차 추가 할 예정 ㅠㅠ
				break;//탈출
			}

		}
		else if (state == 2)
		{
			printf("게임오버");
			break;// 탈출
		}

		

	}

	while (_getch() != 27)                   //2-4
	{
		gotoxy(110, 26);                            //2-5
		printf("종료는 esc\n");
	}
}

/*******************************************/

/******************3번*********************/

int move(char ch)//캐릭터의 벽터치 및 먹이 먹이는 함수
{
	int gameClear=0;
	gotoxy(startx * 2, starty);//팩맨 위치로 커서 이동
	switch (ch)
	{
	case LEFT:                                  //3-1
		if (map[starty][startx - 1] != 1)//이동 하는 방향이 벽이 아닌경우     
		{
			printf(" ");//좌표를 이동하기 전에 현재의 ◎를 지워줍니다.
			startx--;

		
			if (map[starty][startx] == 0)//현재 위치에 먹이가 있었던경우, 차차 함수화 ㅠ
			{
				food++;//먹이 먹은갯수 1 추가
				map[starty][startx] = 3;//먹이를 먹어, 빈길로 처리
			}
		}
		break;
	case RIGHT:
		if (map[starty][startx + 1] != 1)
		{
			printf(" ");
			startx++;
		

			if (map[starty][startx] == 0)//현재 위치에 먹이가 있었던경우, 차차 함수화 ㅠ
			{
				food++;//먹이 먹은갯수 1 추가
				map[starty][startx] = 3;//먹이를 먹어, 빈길로 처리
			}
		}
		break;
	case UP:
		if (map[starty - 1][startx] != 1)
		{
			printf(" ");
			starty--;
		
			if (map[starty][startx] == 0)//현재 위치에 먹이가 있었던경우, 차차 함수화 ㅠ
			{
				food++;//먹이 먹은갯수 1 추가
				map[starty][startx] = 3;//먹이를 먹어, 빈길로 처리
			}
		}
		break;
	case DOWN:
		if (map[starty + 1][startx] != 1)
		{
			printf(" ");
			starty++;
			
			if (map[starty][startx] == 0)//현재 위치에 먹이가 있었던경우, 차차 함수화 ㅠ
			{
				food++;//먹이 먹은갯수 1 추가
				map[starty][startx] = 3;//먹이를 먹어, 빈길로 처리
			}
		}
		break;
	}
	gotoxy(110, 3);
	printf("food : %d", food);//푸드 겟수 -> 감소하는 식의 카운터도 가능

	

	gotoxy(startx * 2, starty);                                    
	printf("◎");                                                 



	switch (stage)
	{
	case 1:
		if (food == 609)
			return 1;
		break;
	case 2:
		if (food == 493)
			return 1;
		break;
	case 3://현재까지 3스테이지 먹이수 체크
		if (food == 632)
			return 1;
		break;
	case 4:
		//if (food == 609)
		//	return 1;
		break;

	}
	if (startx == u1x&&starty == u1y || startx == u2x&&starty == u2y || startx == u3x&&starty == u3y || startx == u4x&&starty == u4y)//유령[1,2,3,4 {(,)는 or}]에 닿을때
	{
		return 2;//게임 오버
	}
	else
		return 3;//게임의 진행중
}


void enemyMove(char *x, char *y)//8방으로..
{



	if (startx > *x && starty > *y)//유저가 유령의 동남쪽에 있을경우
	{
	
		if (map[*y][*x + 1] != 1)//오른쪽 방향이 벽이 아닌경우     
		{

			if (map[*y][*x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(*x * 2, *y);
				printf("·");
				(*x)++;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;
				//Sleep(200);//게임 전체의 진행속도
			}
			else if (map[*y][*x] == 3)
			{
				gotoxy(*x * 2, *y);
				printf(" ");
				(*x)++;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;

			}
		}
		else if (map[*y + 1][*x] != 1)//아래로 이동 가능시
		{
			if (map[*y][*x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(*x * 2, *y);
				printf("·");
				(*y)++;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;

			}
			else if (map[*y][*x] == 3)
			{
				gotoxy(*x * 2, *y);
				printf(" ");
				(*y)++;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");                                                     //3-6

			}

		}

	}

	else if (startx > *x && starty == *y)//유저가 유령의 동쪽에 있을경우
	{
		
		if (map[*y][*x + 1] != 1)//오른쪽 방향이 벽이 아닌경우     
		{

			if (map[*y][*x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(*x * 2, *y);
				printf("·");
				(*x)++;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;
				//Sleep(200);//게임 전체의 진행속도
			}
			else if (map[*y][*x] == 3)
			{
				gotoxy(*x * 2, *y);
				printf(" ");
				(*x)++;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;

			}
		}
	}

	else if (startx > *x && starty < *y)//유저가 유령의 북동쪽에 있을경우
	{

		if (map[*y][*x + 1] != 1)//오른쪽 방향이 벽이 아닌경우     
		{

			if (map[*y][*x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(*x * 2, *y);
				printf("·");
				(*x)++;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;
				
			}
			else if (map[*y][*x] == 3)
			{
				gotoxy(*x * 2, *y);
				printf(" ");
				(*x)++;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;

			}
		}
		else if (map[*y - 1][*x] != 1)//위로 이동 가능시
		{
			if (map[*y][*x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(*x * 2, *y);
				printf("·");
				(*y)--;;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;

			}
			else if (map[*y][*x] == 3)
			{
				gotoxy(*x * 2, *y);
				printf(" ");
				(*y)--;;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");                                                     //3-6

			}

		}

	}


	else if (startx == *x && starty < *y)//유저가 유령의 북쪽에 있을경우
	{
		if (map[*y - 1][*x] != 1)//위쪽 방향이 벽이 아닌경우     
		{

			if (map[*y][*x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(*x * 2, *y);
				printf("·");
				(*y)--;;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;
				//Sleep(200);//게임 전체의 진행속도
			}
			else if (map[*y][*x] == 3)
			{
				gotoxy(*x * 2, *y);
				printf(" ");
				(*y)--;;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;

			}
		}
	}

	else if (startx < *x && starty < *y)//유저가 유령의 북서쪽에 있을경우
	{

		if (map[*y][*x - 1] != 1)//왼쪽 방향이 벽이 아닌경우     
		{

			if (map[*y][*x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(*x * 2, *y);
				printf("·");
				(*x)--;;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;
				//Sleep(200);//게임 전체의 진행속도
			}
			else if (map[*y][*x] == 3)
			{
				gotoxy(*x * 2, *y);
				printf(" ");
				(*x)--;;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;

			}
		}
		else if (map[*y - 1][*x] != 1)//위로 이동 가능시
		{
			if (map[*y][*x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(*x * 2, *y);
				printf("·");
				(*y)--;;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;

			}
			else if (map[*y][*x] == 3)
			{
				gotoxy(*x * 2, *y);
				printf(" ");
				(*y)--;;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");                                                     //3-6

			}

		}
	}

	else if (startx < *x && starty == *y)//유저가 유령의 서쪽에 있을경우
	{
		if (map[*y][*x - 1] != 1)//왼쪽 방향이 벽이 아닌경우     
		{

			if (map[*y][*x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(*x * 2, *y);
				printf("·");
				(*x)--;;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;
			
			}
			else if (map[*y][*x] == 3)
			{
				gotoxy(*x * 2, *y);
				printf(" ");
				(*x)--;;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;

			}
		}
	}

	else if (startx < *x && starty > *y)//유저가 유령의 남서쪽에 있을경우
	{

		if (map[*y][*x - 1] != 1)//왼쪽 방향이 벽이 아닌경우     
		{

			if (map[*y][*x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(*x * 2, *y);
				printf("·");
				(*x)--;;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;
				//Sleep(200);//게임 전체의 진행속도
			}
			else if (map[*y][*x] == 3)
			{
				gotoxy(*x * 2, *y);
				printf(" ");
				(*x)--;;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;

			}
		}
		else if (map[*y + 1][*x] != 1)//아래로 이동 가능시
		{
			if (map[*y][*x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(*x * 2, *y);
				printf("·");
				(*y)++;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;

			}
			else if (map[*y][*x] == 3)
			{
				gotoxy(*x * 2, *y);
				printf(" ");
				(*y)++;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");                                                     //3-6

			}

		}
	}

	else if (startx == *x && starty > *y)//유저가 유령의 남쪽에 있을경우
	{
		if (map[*y + 1][*x] != 1)//아래쪽 방향이 벽이 아닌경우     
		{

			if (map[*y][*x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(*x * 2, *y);
				printf("·");
				(*y)++;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;
				//Sleep(200);//게임 전체의 진행속도
			}
			else if (map[*y][*x] == 3)
			{
				gotoxy(*x * 2, *y);
				printf(" ");
				(*y)++;
				gotoxy(*x * 2, *y);                                    //3-5
				printf("☆");
				return;

			}
		}
	}

}





/*******************************************/

/******************4번**********************/

void initialization()
{
	system("cls");
	enemyCount = 0;

	startx = 0;                        //1-8
	starty = 0;                        //1-9

	u1x = 0;
	u1y = 0;

	u2x = 0;
	u2y = 0;

	u3x = 0;
	u3y = 0;

	u4x = 0;
	u4y = 0;
}

void setmap()
{
	char ch;



	for (int i = 0; i<2500 / 50; i++)    //2500은 char[50][50]의 배열 크기, 50은 한 라인의 크기                  //4-1
	{
		for (int j = 0; j<50 / 1; j++)     //1은 char의 바이트 크기       //4-2
		{
			ch = map[i][j];
			switch (ch)                                                                        //4-3
			{
			case 0:
				printf("·");
				break;
			case 1:
				printf("■");
				break;
			case 2:
				printf("◎");
				startx = j;
				starty = i;
				map[i][j] = 3;//유저의 프린트 및, 좌표 설정이 끝나면, 그 위치를 3으로 바꿈(유령AI의 이동 용이)
				break;
			case 3:
				printf("  ");
				break;
			case 4:
				printf("★");
				if (enemyCount == 0)
				{
					u1x = j;
					u1y = i;
					map[i][j] = 0;//유령의 프린트 및, 좌표 설정이 끝나면, 그 위치를 0(먹이)로 바꿈
					enemyCount++;
				}
				else if (enemyCount == 1)
				{
					u2x = j;
					u2y = i;
					map[i][j] = 0;
					enemyCount++;
				}
				else if (enemyCount == 2)
				{
					u3x = j;
					u3y = i;
					map[i][j] = 0;
					enemyCount++;
				}
				else if (enemyCount == 3)
				{
					u4x = j;
					u4y = i;
					map[i][j] = 0;
					enemyCount++;
				}
				else
					printf("맵 배열상에 표기된 4(유령)의 수가 많습니다.(4 초과)");
				break;
			}
		}

		printf("\n");
	}
	gotoxy(startx * 2, starty);                                                            //4-4
}
/*******************************************/

/******************5번*********************/

void gotoxy(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}



void disappear() { // goto사용시 깜박이는 콘솔의 커서 제거, 참고문헌 http://tip.daum.net/question/39372106
	HANDLE hConsole; // 콘솔 핸들
	CONSOLE_CURSOR_INFO ConsoleCursor; // 콘솔커서 정보 구조체

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 핸들을 구하고

	ConsoleCursor.bVisible = 0; // 1 보임 , 0 안보임
	ConsoleCursor.dwSize = 1; // 커서 사이즈

	SetConsoleCursorInfo(hConsole, &ConsoleCursor); // 설정
}

void printTitle()
{
	int color[2] = { 14,15 };//색상  ->http://tmong.tistory.com/entry/C-setcolor-1
	static int i;//후훗,, 고급기능인 스태틱변수
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[i]);

	int x = 5, y = 5; // 팩맨 캐릭터 텍스쳐
	gotoxy(x, y); y += 1;
	printf("       ■■■■■■");
	gotoxy(x, y); y += 1;
	printf("    ■■■■■■■■■");
	gotoxy(x, y); y += 1;
	printf("  ■■■■■■■■■■■");
	gotoxy(x, y); y += 1;
	printf(" ■■■■■■■■■");
	gotoxy(x, y); y += 1;
	printf("■■■■■■■■");
	gotoxy(x, y); y += 1;
	printf("■■■■■■■■");
	gotoxy(x, y); y += 1;
	printf(" ■■■■■■■■■");
	gotoxy(x, y); y += 1;
	printf("  ■■■■■■■■■■■");
	gotoxy(x, y); y += 1;
	printf("    ■■■■■■■■■");
	gotoxy(x, y); y += 1;
	printf("       ■■■■■■");
	i = (i + 1) % 2;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 햄버거 텍스쳐
	x = 32;  y = 4;
	gotoxy(x, y); y += 1;
	printf("           ■■■■■■");
	gotoxy(x, y); y += 1;
	printf("       ■■■■■■■■■■");
	gotoxy(x, y); y += 1;
	printf("     ■■■■■■■■■■■■");
	gotoxy(x, y); y += 1;
	printf("   ■■■■■■■■■■■■■■");
	gotoxy(x, y); y += 1;
	printf(" ■■■■■■■■■■■■■■■■");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	gotoxy(x, y); y += 1;
	printf("  ■■■■■■■■■■■■■■■");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	gotoxy(x, y); y += 1;
	printf("■■■■■■■■■■■■■■■■■");
	gotoxy(x, y); y += 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("  ■■■■■■■■■■■■■■■");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(x, y); y += 1;
	printf("■■■■■■■■■■■■■■■■■");
	gotoxy(x, y); y += 1;
	printf(" ■■■■■■■■■■■■■■■■");
	gotoxy(x, y); y += 1;
	printf("  ■■■■■■■■■■■■■■■");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // 봉
	x = 72;  y = 5;
	gotoxy(x, y); y += 1;
	printf(" BO     NG");
	gotoxy(x, y); y += 1;
	printf(" BONGBONGB");
	gotoxy(x, y); y += 1;
	printf(" ON     GB");
	gotoxy(x, y); y += 1;
	printf(" ONGBONGBO");
	gotoxy(x, y); y += 1;
	printf("    NGB");
	gotoxy(x, y); y += 1;
	printf("ONGBONGBONG");
	gotoxy(x, y); y += 1;
	printf("  BONGBON");
	gotoxy(x, y); y += 1;
	printf(" GBO   NGB");
	gotoxy(x, y); y += 1;
	printf(" ONG   BON");
	gotoxy(x, y); y += 1;
	printf("  GBONGBO");

	x = 90;  y = 5; // 재
	gotoxy(x, y); y += 1;
	printf("       JA EJ");
	gotoxy(x, y); y += 1;
	printf("AEJAE  JA EJ");
	gotoxy(x, y); y += 1;
	printf("AEJAE  JA EJ");
	gotoxy(x, y); y += 1;
	printf("   AE  JA EJ");
	gotoxy(x, y); y += 1;
	printf("  AEJ  AEJAE");
	gotoxy(x, y); y += 1;
	printf("  JAE  JA EJ");
	gotoxy(x, y); y += 1;
	printf("AEJ AE JA EJ");
	gotoxy(x, y); y += 1;
	printf("AE   JAEJ AE");
	gotoxy(x, y); y += 1;
	printf("       JA EJ");
	gotoxy(x, y); y += 1;
	printf("       AE JA");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 의
	x = 108, y = 6;
	gotoxy(x, y); y += 1;
	printf("  =8E+   M#");
	gotoxy(x, y); y += 1;
	printf(" MM:~#M` ME");
	gotoxy(x, y); y += 1;
	printf(".M=  `Mi ME");
	gotoxy(x, y); y += 1;
	printf(" MM.`8M. ME");
	gotoxy(x, y); y += 1;
	printf("  +MMO`  ME");
	gotoxy(x, y); y += 1;
	printf("~.```~:I~ME");
	gotoxy(x, y); y += 1;
	printf("MMMMM#E8;ME");
	gotoxy(x, y); y += 1;
	printf("         ME");
	gotoxy(x, y); y += 1;
	printf("         8+");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // 햄
	x = 72;  y = 17;
	gotoxy(x, y); y += 1;
	printf("  HA   MH AM");
	gotoxy(x, y); y += 1;
	printf("HAMHAM HA MH");
	gotoxy(x, y); y += 1;
	printf(" AMHA  MH AM");
	gotoxy(x, y); y += 1;
	printf("HA  MH AMHAM");
	gotoxy(x, y); y += 1;
	printf(" HAMH  AM HA");
	gotoxy(x, y); y += 1;
	printf("\n");
	gotoxy(x, y); y += 1;
	printf("    MHAMHAMH");
	gotoxy(x, y); y += 1;
	printf("    AM    HA");
	gotoxy(x, y); y += 1;
	printf("    MH    AM");
	gotoxy(x, y); y += 1;
	printf("    HAMHAMHA");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // 버
	x = 90;  y = 17;
	gotoxy(x, y); y += 1;
	printf("         BU");
	gotoxy(x, y); y += 1;
	printf(" RB  UR  BU");
	gotoxy(x, y); y += 1;
	printf(" RB  UR  BU");
	gotoxy(x, y); y += 1;
	printf(" RBURBU  RB");
	gotoxy(x, y); y += 1;
	printf(" URBURBURBU");
	gotoxy(x, y); y += 1;
	printf(" RB  UR  BU");
	gotoxy(x, y); y += 1;
	printf(" RBURBU  RB");
	gotoxy(x, y); y += 1;
	printf(" URBURB  UR");
	gotoxy(x, y); y += 1;
	printf("         BU");
	gotoxy(x, y); y += 1;
	printf("         RB");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // 거
	x = 108;  y = 17;
	gotoxy(x, y); y += 1;
	printf("         GE");
	gotoxy(x, y); y += 1;
	printf("RGERGER  GE");
	gotoxy(x, y); y += 1;
	printf("RGERGER  GE");
	gotoxy(x, y); y += 1;
	printf("    RGERGER");
	gotoxy(x, y); y += 1;
	printf("    GERGERG");
	gotoxy(x, y); y += 1;
	printf("  ERG    ER");
	gotoxy(x, y); y += 1;
	printf(" GER     GE");
	gotoxy(x, y); y += 1;
	printf("RGE      RG");
	gotoxy(x, y); y += 1;
	printf("         ER");
	gotoxy(x, y); y += 1;
	printf("         GE");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 여
	x = 72;  y = 29;
	gotoxy(x, y); y += 1;
	printf(" ;EMO   iM`");
	gotoxy(x, y); y += 1;
	printf("iMi~MM+oEM`");
	gotoxy(x, y); y += 1;
	printf("ME  `M8;OM`");
	gotoxy(x, y); y += 1;
	printf("Mo   M+ IM`");
	gotoxy(x, y); y += 1;
	printf("ME  .MM8#M`");
	gotoxy(x, y); y += 1;
	printf("=M+:MM~~oM`");
	gotoxy(x, y); y += 1;
	printf(" :8#+   iM`");
	gotoxy(x, y); y += 1;
	printf("        iM`");
	gotoxy(x, y); y += 1;
	printf("        ;E`");

	x = 85;  y = 28; // 행
	gotoxy(x, y); y += 1;
	printf("  :::` .` :");
	gotoxy(x, y); y += 1;
	printf(" `8O8: MO:M.");
	gotoxy(x, y); y += 1;
	printf("oMEEEMiMo~M`");
	gotoxy(x, y); y += 1;
	printf(" .E##I MMMM`");
	gotoxy(x, y); y += 1;
	printf(" Mi .M Mo:M`");
	gotoxy(x, y); y += 1;
	printf(" IMMM+ Mo~M`");
	gotoxy(x, y); y += 1;
	printf("    ;+8oi=;");
	gotoxy(x, y); y += 1;
	printf("  ;M8I:;=MM");
	gotoxy(x, y); y += 1;
	printf("  ;M+~..:#M");
	gotoxy(x, y); y += 1;
	printf("    iOEEoI");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // 비행기 그림 텍스쳐
	x = 99;  y = 29;
	gotoxy(x, y); y += 1;
	printf("                        ;MMM");
	gotoxy(x, y); y += 1;
	printf("  =#M#EO+=;:.        ;8MMMMM");
	gotoxy(x, y); y += 1;
	printf("  MMMMMMMMMMMMMMMEOoMMMMMMMM");
	gotoxy(x, y); y += 1;
	printf("   `Io#MMMMMMMMMMMMMMMMMMMo.");
	gotoxy(x, y); y += 1;
	printf("        .IoEMMMMMMMMMMMME");
	gotoxy(x, y); y += 1;
	printf("          `iMMMMMMMMMMMMM.");
	gotoxy(x, y); y += 1;
	printf("  `     =MMMMMMMMMMMMMMMMM");
	gotoxy(x, y); y += 1;
	printf("MMMMM#EMMMMMMMM8: oMMMMMMM=");
	gotoxy(x, y); y += 1;
	printf("=8MMMMMMMMMMM=     ~MMMMMMM");
	gotoxy(x, y); y += 1;
	printf("   ~+MMMMMMM         OMMMMME");
	gotoxy(x, y); y += 1;
	printf("      =MMMMMO         :MMMME");
	gotoxy(x, y); y += 1;
	printf("        I##=`           I.");
}

void gameMenu() // 게임 메뉴
{
	int x = 18, y = 20;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(x, y);
	printf("■□□□■■■□□■■□□■■");
	gotoxy(x, y + 1);
	printf("■■■□★■□□  ♪■■□□■");
	gotoxy(x, y + 2);
	printf("□□□■Bongjae Travel□■☆■");
	gotoxy(x, y + 3);
	printf("■■□■■햄□버■거□□■□□");
	gotoxy(x, y + 4);
	printf("■■★■□□□■■■□■■□□");

	gotoxy(x + 7, y + 8);
	printf("1. 여행 START");
	gotoxy(x + 7, y + 10);
	printf("2. 여행이어하기");
	gotoxy(x + 7, y + 12);
	printf("3. 여행점수확인");
	gotoxy(x + 7, y + 14);
	printf("4. The End");
}

void selectGameMenu() // 메뉴 선택 함수
{

}

void Title()
{

	system("mode con:cols=130 lines=43"); // 타이틀화면에서만 130x43 크기로 지정. (깔끔해보이도록 조정)

	system("title 봉재의 햄버거 여행기");
	PlaySound(TEXT("payday.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	//사운드 파일 위치, SND_ASYNC, SND_LOOP 세가지가 제일 중요
	//SND_ASYNC : 재생하면서 다음코드 실행
	//SND_LOOP : 반복재생
	int key;
	while (1)
	{
		printTitle();
		gameMenu();
		Sleep(100);
		if (_kbhit())//키 입력 여부 확인 ->http://showmiso.tistory.com/8
		{
			key = _getch();//키를 입력 받음 key에 저장하는 이유는 타이틀 탈출시의 엔터 중복입력 방지 
			system("cls");//타이틀 지움
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//색을 흰색을 복구
			break;
		}

	}
}


COORD getXY() {
	COORD Cur;
	CONSOLE_SCREEN_BUFFER_INFO a;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &a);
	Cur.X = a.dwCursorPosition.X;
	Cur.Y = a.dwCursorPosition.Y;
	return Cur;
}

void save(int stage) {
	
	FILE *fpin;

	fpin = fopen("save.txt", "r");

	while (!feof(fpin)) {
		fprintf(fpin, "%d", stage);
	}

	fclose(fpin);
}
