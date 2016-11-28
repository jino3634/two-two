//출처 : http://breadshuttle.tistory.com/entry/C%EC%96%B8%EC%96%B4-%EC%8B%AC%EC%8B%AC%ED%92%80%EC%9D%B4%EA%B2%8C%EC%9E%84%EB%A7%8C%EB%93%A4%EC%96%B4%EB%B3%B4%EA%B8%B02%ED%83%84
#include<stdio.h>
#include<conio.h>
#include<windows.h>

/*******************1번********************/

#define LEFT 75                       //1-1
#define RIGHT 77                     //1-2
#define UP 72                          //1-3
#define DOWN 80                     //1-4

typedef enum {false, true}bool;//c에서도 활용 가능하도록 typedef사용.

void gotoxy(int x, int y);           //1-5
COORD getXY();
COORD Cur;

void setmap();                        //1-6
int move(char ch);                //1-7 게임의 진행도(게임 클리어, 게임 오버, 게임 진행중을 반환 각각 1,2,3)
void enemy1Move();

void changeRode(int map[][25], int x, int y);//2016 - 11- 22 한진오 미완성
void disappear();

void printTitle();
void Title();

char startx = 0;                        //1-8
char starty = 0;                        //1-9
/*
char endx = 0;                         //1-10
char endy = 0;                         //1-11
기존의 미로게임의 종료점 -> 먹이 카운터 정수로 수정*/

char u1x = 0;
char u1y = 0;

char u2x = 0;
char u2y = 0;

char u3x = 0;
char u3y = 0;

char u4x = 0;
char u4y = 0;



int food=1;//스테이지별 등으로 처리 가능(food1, 2, 3등)
									   //1-13

char map[50][50] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
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
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1 },
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
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }

};


char map1[25][25] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },//0은 먹이, 1은 벽,2는 유저,  3은 먹이 먹은 빈길
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,1 },
	{ 1,0,3,3,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,1 },
	{ 1,0,1,3,3,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,1,0,1 },
	{ 1,0,1,1,3,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,1,0,1 },
	{ 1,0,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,0,1 },
	{ 1,0,1,1,1,1,0,0,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,0,1,1,0,0,0,1,1,0,1,1,1,1,1,1,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,1,1,1,1,1,1,0,1,1,0,0,0,1,1,0,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1 },
	{ 1,0,1,1,1,1,0,0,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,0,1 },
	{ 1,0,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,0,1 },
	{ 1,0,1,1,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,1,0,1 },
	{ 1,0,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,1,0,1 },
	{ 1,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,1 },
	{ 1,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,1 },
	{ 1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};
/*
char map[25][25] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,2,1,0,1,1,0,1,0,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,1 },
	{ 1,0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,0,0,0,1,1,0,1,0,1 },
	{ 1,0,1,0,1,1,0,1,0,0,0,1,1,0,1,1,0,1,0,1,0,0,1,0,1 },
	{ 1,0,1,0,0,0,0,1,1,0,1,1,0,0,0,1,1,1,0,1,0,1,1,0,1 },
	{ 1,0,1,1,1,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,1,0,1 },
	{ 1,0,0,0,0,0,0,1,0,1,0,1,0,1,1,0,0,1,0,1,1,1,1,0,1 },
	{ 1,0,1,1,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,1 },
	{ 1,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,1 },
	{ 1,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,0,1,0,0,0,0,1,0,1 },
	{ 1,0,1,0,1,0,1,1,0,1,0,1,0,0,1,1,0,1,1,1,0,0,1,0,1 },
	{ 1,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,1,0,0,1,0,1 },
	{ 1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,0,1,0,1,0,1,1,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,1 },
	{ 1,1,1,1,0,1,1,0,1,0,0,1,0,1,0,0,1,1,1,1,0,1,1,0,1 },
	{ 1,0,0,1,0,0,0,0,1,0,0,1,0,1,1,0,0,1,0,0,1,0,0,0,1 },
	{ 1,0,1,1,0,0,1,0,1,1,1,1,0,1,0,0,1,1,0,1,1,1,0,1,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,0,1,0,1,0,1,1 },
	{ 1,0,1,1,0,1,1,1,1,1,0,1,0,0,1,1,1,0,0,1,0,1,0,1,1 },
	{ 1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1 },
	{ 1,0,1,0,1,1,1,0,1,0,1,1,0,1,1,1,0,0,0,1,0,1,0,1,1 },
	{ 1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,1,1,0,1,0,1,0,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,0,0,1,0,1,1,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};
*/
/*******************************************/

/*****************2번**********************/

void main()
{
	Title();
	
	int state=3;
	int key = 1;//초기화를 안하면 if문에서 에러가 나므로, 아무 값이나 초기화.
	disappear();
	setmap();                              //2-1
	while (true)                             //2-2
	{
		//gotoxy(30, 27);
		//printf(" %d, %d %d", map[u1y][u1x], u1x, u1y);
		enemy1Move();
		//enemy1Move();
		//gotoxy(30, 27);
		//printf(" %d, %d %d", map[u1y][u1x], u1x, u1y);

		if (_kbhit())//키 입력 여부 확인 ->http://showmiso.tistory.com/8
			key = _getch();//키를 입력 받음. 
		
		state = move(key);//움직이며 상태 변수를 반환.
		
		Sleep(100);
		
		
		
		if (state==3)  //2-3 가장 많은 경우이므로 상단에 배치(게임 진행중)
		{
			continue;
		}
		else if (state == 1)
		{
			printf("게임 클리어!!!");//임의 프린트문으로 대체, 맵의 다양해짐에따라 추가 예정
		}
		else if (state == 2)
		{
			break;//게임 오버시 탈출
		}
	}
	printf("게임오버");
	while (getch() != 27)                   //2-4
	{
		gotoxy(0, 26);                            //2-5
		printf("종료는 esc\n");
	}
}

/*******************************************/

/******************3번*********************/

int move(char ch)//캐릭터의 벽터치 및 먹이 먹이는 함수
{
	//Sleep(100);
	gotoxy(startx * 2, starty);//팩맨 위치로 커서 이동
	switch (ch)
	{
	case LEFT:                                  //3-1
			if (map[starty][startx - 1] != 1)//이동 하는 방향이 벽이 아닌경우     
			{
				printf(" ");//좌표를 이동하기 전에 현재의 ◎를 지워줍니다.
				startx--;

				//changeRode(map, starty, startx);
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
			//changeRode(map, starty, startx);
			
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
			//changeRode(map, starty, startx);
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
			//changeRode(map, starty, startx);
			if (map[starty][startx] == 0)//현재 위치에 먹이가 있었던경우, 차차 함수화 ㅠ
			{
				food++;//먹이 먹은갯수 1 추가
				map[starty][startx] = 3;//먹이를 먹어, 빈길로 처리
			}
		}
		break;
	}
	//gotoxy(30, 25);
	//printf("food : %d", food);//푸드 겟수 -> 감소하는 식의 카운터도 가능

	//gotoxy(30, 26);
	//printf("%d %d, %d %d" ,startx,starty,u1x,u1y);//푸드 겟수 -> 감소하는 식의 카운터도 가능
	
	gotoxy(startx * 2, starty);                                    //3-5
	printf("◎");                                                     //3-6
	//gotoxy(startx * 2, starty);                                    //3-7
	
	//움직이는 속도

	if (food == 999)      //3-8 게임 클리어 조건, 먹이를 다 먹을때
	{
		return 1;//게임 클리어//스테이지별로 다름->if문 사용예정
	}
	else if (startx == u1x&&starty == u1y || startx == u2x&&starty == u2y || startx == u3x&&starty == u3y || startx == u4x&&starty == u4y)//유령[1,2,3,4 {(,)는 or}]에 닿을때
	{
		return 2;//게임 오버
	}
	else
		return 3;//게임의 진행중
}


void enemy1Move()//8방으로..
{

	if (startx > u1x && starty > u1y)//유저가 유령의 동남쪽에 있을경우
	{
		//Sleep(100);

		//gotoxy(u1x * 2, u1y);//적 위치로 커서 이동
		//오른쪽으로 이동 하능하면 오른쪽 이동 아니면 아래 이동 가능하면 아래이동 if ifelse문
		if (map[u1y][u1x + 1] != 1)//오른쪽 방향이 벽이 아닌경우     
		{

			if (map[u1y][u1x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(u1x * 2, u1y);
				printf("·");
				u1x++;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;
				//Sleep(200);//게임 전체의 진행속도
			}
			else if (map[u1y][u1x] == 3)
			{
				gotoxy(u1x * 2, u1y);
				printf(" ");
				u1x++;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;

			}
		}
		else if (map[u1y + 1][u1x] != 1)//아래로 이동 가능시
		{
			if (map[u1y][u1x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(u1x * 2, u1y);
				printf("·");
				u1y++;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;

			}
			else if (map[u1y][u1x] == 3)
			{
				gotoxy(u1x * 2, u1y);
				printf(" ");
				u1y++;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");                                                     //3-6

			}

		}

	}

	else if (startx > u1x && starty == u1y)//유저가 유령의 동쪽에 있을경우
	{
		//Sleep(200);

		//gotoxy(u1x * 2, u1y);//적 위치로 커서 이동
		//오른쪽으로 이동 하능하면 오른쪽 이동 아니면 아래 이동 가능하면 아래이동 if ifelse문
		if (map[u1y][u1x + 1] != 1)//오른쪽 방향이 벽이 아닌경우     
		{

			if (map[u1y][u1x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(u1x * 2, u1y);
				printf("·");
				u1x++;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;
				//Sleep(200);//게임 전체의 진행속도
			}
			else if (map[u1y][u1x] == 3)
			{
				gotoxy(u1x * 2, u1y);
				printf(" ");
				u1x++;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;

			}
		}
	}

	else if (startx > u1x && starty < u1y)//유저가 유령의 북동쪽에 있을경우
	{

		if (map[u1y][u1x + 1] != 1)//오른쪽 방향이 벽이 아닌경우     
		{

			if (map[u1y][u1x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(u1x * 2, u1y);
				printf("·");
				u1x++;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;
				//Sleep(200);//게임 전체의 진행속도
			}
			else if (map[u1y][u1x] == 3)
			{
				gotoxy(u1x * 2, u1y);
				printf(" ");
				u1x++;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;

			}
		}
		else if (map[u1y - 1][u1x] != 1)//위로 이동 가능시
		{
			if (map[u1y][u1x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(u1x * 2, u1y);
				printf("·");
				u1y--;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;

			}
			else if (map[u1y][u1x] == 3)
			{
				gotoxy(u1x * 2, u1y);
				printf(" ");
				u1y--;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");                                                     //3-6

			}

		}

	}


	else if (startx == u1x && starty < u1y)//유저가 유령의 남쪽에 있을경우
	{
		if (map[u1y - 1][u1x] != 1)//위쪽 방향이 벽이 아닌경우     
		{

			if (map[u1y][u1x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(u1x * 2, u1y);
				printf("·");
				u1y--;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;
				//Sleep(200);//게임 전체의 진행속도
			}
			else if (map[u1y][u1x] == 3)
			{
				gotoxy(u1x * 2, u1y);
				printf(" ");
				u1y--;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;

			}
		}
	}

	else if (startx < u1x && starty < u1y)//유저가 유령의 북서쪽에 있을경우
	{

		if (map[u1y][u1x - 1] != 1)//왼쪽 방향이 벽이 아닌경우     
		{

			if (map[u1y][u1x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(u1x * 2, u1y);
				printf("·");
				u1x--;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;
				//Sleep(200);//게임 전체의 진행속도
			}
			else if (map[u1y][u1x] == 3)
			{
				gotoxy(u1x * 2, u1y);
				printf(" ");
				u1x--;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;

			}
		}
		else if (map[u1y - 1][u1x] != 1)//위로 이동 가능시
		{
			if (map[u1y][u1x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(u1x * 2, u1y);
				printf("·");
				u1y--;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;

			}
			else if (map[u1y][u1x] == 3)
			{
				gotoxy(u1x * 2, u1y);
				printf(" ");
				u1y--;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");                                                     //3-6

			}

		}
	}
	
	else if (startx < u1x && starty == u1y)//유저가 유령의 서쪽에 있을경우
	{
		if (map[u1y][u1x - 1] != 1)//왼쪽 방향이 벽이 아닌경우     
		{

			if (map[u1y][u1x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(u1x * 2, u1y);
				printf("·");
				u1x--;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;
				//Sleep(200);//게임 전체의 진행속도
			}
			else if (map[u1y][u1x] == 3)
			{
				gotoxy(u1x * 2, u1y);
				printf(" ");
				u1x--;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;

			}
		}
	}

	else if (startx < u1x && starty > u1y)//유저가 유령의 남서쪽에 있을경우
	{

		if (map[u1y][u1x - 1] != 1)//왼쪽 방향이 벽이 아닌경우     
		{

			if (map[u1y][u1x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(u1x * 2, u1y);
				printf("·");
				u1x--;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;
				//Sleep(200);//게임 전체의 진행속도
			}
			else if (map[u1y][u1x] == 3)
			{
				gotoxy(u1x * 2, u1y);
				printf(" ");
				u1x--;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;

			}
		}
		else if (map[u1y + 1][u1x] != 1)//아래로 이동 가능시
		{
			if (map[u1y][u1x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(u1x * 2, u1y);
				printf("·");
				u1y++;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;

			}
			else if (map[u1y][u1x] == 3)
			{
				gotoxy(u1x * 2, u1y);
				printf(" ");
				u1y++;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");                                                     //3-6

			}

		}
	}

	else if (startx == u1x && starty > u1y)//유저가 유령의 남쪽에 있을경우
	{
		if (map[u1y + 1][u1x] != 1)//아래쪽 방향이 벽이 아닌경우     
		{

			if (map[u1y][u1x] == 0)//몬스터에게 먹이 안먹이기..
			{
				gotoxy(u1x * 2, u1y);
				printf("·");
				u1y++;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;
				//Sleep(200);//게임 전체의 진행속도
			}
			else if (map[u1y][u1x] == 3)
			{
				gotoxy(u1x * 2, u1y);
				printf(" ");
				u1y++;
				gotoxy(u1x * 2, u1y);                                    //3-5
				printf("☆");
				return;

			}
		}
	}

}

	
	//else
	//	Sleep(100);



/*******************************************/

/******************4번**********************/

void setmap()
{
	char ch;

	int count=1;

	for (int i = 0; i<sizeof(map) / sizeof(map[0]); i++)                      //4-1
	{
		for (int j = 0; j<sizeof(map[0]) / sizeof(map[0][0]); j++)            //4-2
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
				map[i][j] = 0;//유저의 프린트 및, 좌표 설정이 끝나면, 그 위치를 0(먹이)로 바꿈(유령AI의 이동 용이)
				break;
			case 3:
				printf("  ");
				/*
				endx = i;
				endy = j;
				기존 미로게임의 엔드포인트*/
				break;
			case 4:
				printf("★");
				if (count == 1)
				{
					u1x = j;
					u1y = i;
					map[i][j] = 0;//유령의 프린트 및, 좌표 설정이 끝나면, 그 위치를 0(먹이)로 바꿈
					count++;
				}
				else if (count == 2)
				{
					u2x = j;
					u2y = i;
					map[i][j] = 0;
					count++;
				}
				else if (count == 3)
				{
					u3x = j;
					u3y = i;
					map[i][j] = 0;
					count++;
				}
				else if (count == 4)
				{
					u4x = j;
					u4y = i;
					map[i][j] = 0;
					count++;
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
/*******************************************/

void changeRode(int map[][25], int y, int x)
{
	if ((*(*map + y) + x) == 0)//현재 위치에 먹이가 있었던경우
	{
		food++;//먹이 먹은갯수 1 추가
		map[y][x] = 3;//먹이를 먹어, 빈길로 처리
	}
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

void Title()
{
	system("mode con:cols=130 lines=51");
	system("title 봉재의 햄버거 여행기");
	int key;
	while (1)
	{
		printTitle();
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
/*

1번은 사용하는 상수 / 변수 / 함수들을 정의합니다.

1-1 ~ 1-4 :
#define을 이용해 방향키들의 아스키코드를 상수로 정의해둡니다.

1-5 : gotoxy(int x, int y); 함수는 콘솔화면에서의 좌표이동을 할때 사용하는 함수입니다.

1-6 : setmap()은 미로화면을 만들어주고 콘솔화면의 좌표를 시작지점으로 이동시켜주는 함수입니다.

1-7 : move함수는 방향키에 맞는 방향으로 ◎를 이동시켜줍니다.

1-8 ~ 1-11: 시작점과 종료점을 가지고 있는 함수입니다.

2번은 메인함수를 정의합니다.

2-1 : setmap() 함수를 이용하여 콘솔화면을 초기화 시킵니다.

2-2 : while(true)를 사용하면 조건이 항상 참이기때문에 무한반복에 빠지게 됩니다. 그러므로 while 내부에는 루프를 빠져나오는 문장을
정의해 주어야 합니다.

2-3  : if(move(getch())) move(char ch) 함수는 bool의 값(true or false)을 반환하기때문에 if문의 조건문으로 사용할 수 있습니다.
move(char ch) 함수가 true를 반환하게 되면 2-2번의 while(true) 문장을 빠져나오게 됩니다.

2-4 : while(getch() != 27) 27은 ESC키의 아스키코드값입니다.

2-5 : gotoxy(int x, int y) 함수는 매개변수로 받은 값의 콘솔화면 좌표로 이동하게 됩니다.
콘솔화면의 좌표는 왼쪽상단부분(0,0)을 기준으로 합니다.

3번은 move(char ch)의 구현부분입니다.

3-1 : case 75: 와 동일한 문장입니다. 왼쪽 방향키를 눌렀을때의 정의입니다.

3-2 : if문을 사용해 일단 배열의 왼쪽이 □(1) 인지 확인합니다.
map[starty][startx-1] 여기서 x와 y사 반대인 이유는
gotoxy에서는 앞이 x좌표 뒤가 y좌표 이지만
배열에서는 앞의 y좌표 뒤가 x좌표가 되기 때문입니다.

3-3 : 좌표를 이동하기 전에 현재의 ◎를 지워줍니다.

3-4 : x좌표의 값을 하나 감소시켜줍니다.

3-5 : gotoxy(startx*2,starty); 을 이용해 콘솔의 좌표를 이동시켜줍니다.
startx에 2를 곱해주는 이유는 공백이 '◎'모양의 1/2칸이기 때문입니다.

3-6 : 이동한 좌표에 ◎를 프린트 해줍니다.

3-7 : 좌표를 다시 startx*2,starty로 이동시켜줍니다. printf()를 사용하면 커서값이 다음칸으로 이동되기 때문입니다.

3-8 : 현재의 좌표값과 endx,endy(골인지점)의 값이 같으면 true를 반환합니다.

4번은 미로의 화면을 그려주는 setmap()함수의 구현입니다.

4-1 : sizeof[map]은 배열의 전체크기(25*25)를 가지고 있습니다.
sizeof(map[0])은 map[0]의 줄의 수를 가지고 있다고 생각합시다.

4-2 : sizeof(map[0][0])은 배열 한칸의 크기를 가지고 있겠지요.

4-3 : 1탄의 게임만들기와 비슷하게 0이면 공백을 1이면 벽을 2이면 시작점 3이면 골인지점을 그리도록 했습니다.

4-4 : 다 그리고 난뒤에는 시작점으로 커서를 이동시킵니다.

5번은 gotoxy(int x, int y)함수의 구현부분입니다. 지금은 그냥 이렇게 사용한다는 법만 알아두시면 될 듯 합니다.
핸들같은건 나중에 API를 공부할때 나오게됩니다.
이 함수를 구현하기 위해서는 conio.h 와 windows.h 를 include 해주셔야 합니다.

*/