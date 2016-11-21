#include<stdio.h>
#include<conio.h>
#include<windows.h>

/*******************1번********************/

#define LEFT 75                       //1-1
#define RIGHT 77                     //1-2
#define UP 72                          //1-3
#define DOWN 80                     //1-4

void gotoxy(int x, int y);           //1-5
void setmap();                        //1-6
bool move(char ch);                //1-7

char startx = 0;                        //1-8
char starty = 0;                        //1-9
char endx = 0;                         //1-10
char endy = 0;                         //1-11

									   //1-13

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
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};

/*******************************************/

/*****************2번**********************/

void main()
{
	setmap();                              //2-1
	while (true)                             //2-2
	{
		if (move(getch()))                  //2-3
		{
			break;
		}
	}
	while (getch() != 27)                   //2-4
	{
		gotoxy(0, 26);                            //2-5
		printf("clear\n종료는 esc\n");
	}
}

/*******************************************/

/******************3번*********************/

bool move(char ch)
{
	switch (ch)
	{
	case LEFT:                                  //3-1
		if (map[starty][startx - 1] != 1)         //3-2
		{
			printf(" ");                                    //3-3
			startx--;                //3-4
		}
		break;
	case RIGHT:
		if (map[starty][startx + 1] != 1)
		{
			printf(" ");
			startx++;
		}
		break;
	case UP:
		if (map[starty - 1][startx] != 1)
		{
			printf(" ");
			starty--;
		}
		break;
	case DOWN:
		if (map[starty + 1][startx] != 1)
		{
			printf(" ");
			starty++;
		}
		break;
	}
	gotoxy(startx *2, starty);                                    //3-5
	printf("◎");                                                     //3-6
	gotoxy(startx *2, starty);                                    //3-7
	if (map[startx][starty] == map[endx][endy])      //3-8
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*******************************************/

/******************4번**********************/

void setmap()
{
	char ch;

	for (int i = 0; i<sizeof(map) / sizeof(map[0]); i++)                      //4-1
	{
		for (int j = 0; j<sizeof(map[0]) / sizeof(map[0][0]); j++)            //4-2
		{
			ch = map[i][j];
			switch (ch)                                                                        //4-3
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("■");
				break;
			case 2:
				printf("◎");
				startx = i;
				starty = j;
				break;
			case 3:
				printf("★");
				endx = i;
				endy = j;
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