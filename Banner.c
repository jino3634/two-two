#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y);
void printTitle();



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