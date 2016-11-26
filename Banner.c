#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void printTitle()
{
	int color[2] = { 14,15 };//색상  ->http://tmong.tistory.com/entry/C-setcolor-1
	static int i;//후훗,, 고급기능인 스태틱변수
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[i]);
	
	int x = 5, y = 5;
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

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	x += 27;  y = 4;
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

	

}
/*void printTitle() {//***2012244063 한진오***
	int color[7] = { 12, 4, 14, 10, 9, 1, 13 };//색상  ->http://tmong.tistory.com/entry/C-setcolor-1
	static int i;//후훗,, 고급기능인 스태틱변수
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

	int x = 8, y = 5;
	gotoxy(x, y); y += 1;
	printf("│        │  │    ────── │    │");
	gotoxy(x, y); y += 1;
	printf("├────┤  │      │    │ ─┤    │");
	gotoxy(x, y); y += 1;
	printf("│        │─┤     ↙↘  ↙↘  │    │");
	gotoxy(x, y); y += 1;
	printf("│        │  │   ↙    ↙    ↘│    │");
	gotoxy(x, y); y += 1;
	printf("└────┘  │                       │");
	gotoxy(x, y); y += 1;
	printf("              │      ──────┐   │");
	gotoxy(x, y); y += 1;
	printf("   │                             │   │");
	gotoxy(x, y); y += 1;
	printf("   │                             │     ");
	gotoxy(x, y); y += 1;
	printf("   └──────                 │   ●");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	x += 50;  y = 5;
	gotoxy(x, y); y += 1;
	printf("─────┐ │       ───      │   ───┐   │");
	gotoxy(x, y); y += 1;
	printf("          │ │     ↙      ↖    │         │ ─┤");
	gotoxy(x, y); y += 1;
	printf("         ↙  │    │        │ ─┤   ┌──┘   │");
	gotoxy(x, y); y += 1;
	printf("       ↙    │    │        │   │   │       ─┤");
	gotoxy(x, y); y += 1;
	printf("     ↙      │     ↘      ↗    │   └───   │");
	gotoxy(x, y); y += 1;
	printf("   ↙        │       ───      │              │");
	gotoxy(x, y); y += 1;
	printf(" ↙          │         ─────┐      ────┐");
	gotoxy(x, y); y += 1;
	printf("             │                   │              │");
	gotoxy(x, y); y += 1;
	printf("             │                   │              │");

	i = (i % 7) + 1;
}*/

int main(void)
{
	system("mode con:cols=130 lines=50");
	system("title 봉재의 햄버거 여행기");
	while (1)
	{
		printTitle();
		Sleep(100);
	}
	
	return 0;
}