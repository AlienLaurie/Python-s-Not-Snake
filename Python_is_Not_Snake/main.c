#include<stdio.h>
#include<windows.h>
#define BLACK_GREEN 0x0a															//黑底绿字
#define BLACK_YELLOW 0x0e															//黑底黄字
#define BLACK_RED																	//黑底红字
int snake[10][2], apple[1][2],len,flag=1,j,score=0;
/*初始化参数
snake储存蛇的x,y坐标,apple储存苹果的x,y坐标,len蛇长
(列0储存x,列1储存y)*/
/*光标移动到x,y*/
void gotoxy

(int x, int y)
{
	COORD pos;
	pos.X = 2 * x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);				//获得控制台光标位置
}
/*改变控制台输出颜色*/
void color(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

/*输出主菜单*/
int prt_menu()
{
	char input=0;
	int i,j;
	gotoxy(0, 0);
	for (i = 0;i < 20; i++)														//输出菜单背景
	{
		color(i * 0x0f);														//让背景输出产生变色效果
		for (j = 0; j < 20; j++)
		{
			printf("< >");
			Sleep(7);															//让菜单背景的输出产生动画效果
		}
		printf("\n");

	}
	gotoxy(0, 7);
	printf("Python's Not Shanke(PNS) Entertsinment System by S.Wong\n");		//菜单选项
	Sleep(500);
	printf("PRESS S TO START\n");

	Sleep(500);
	printf("I TO INFORMATION\n");
	Sleep(500);
	printf("OTHERS TO EXIT\n");
	gotoxy(0, 11);
	scanf("%c", &input);
	return input;
}

/*显示信息页*/
void inf_page()
{	
	color(0x00);																//将屏幕背景颜色设定为黑色
	system("cls");																//清屏(黑色)
	gotoxy(0, 0);																//重置光标
	color(BLACK_GREEN);																
	printf("Python's Not Snake(PNS) Entertainment System By S.Wong\nGrapics by S.W.\nProgram by S.W.\nTHANKS FOR PLAYING.\nPRESS ANY KEY TO CONTINUE\n");
	while (!(_kbhit()));														//等待键入
}

/*显示动态信息*/
void showstate()
{	
	color(BLACK_YELLOW);
	gotoxy(24, 8);
	printf("SCORE:%d", score);
}
/*初始化参数*/
void init()
{
	int i;
	system("cls");
	gotoxy(0, 0);
	for (i = 0; i < 22; i++)
	{
		if (0 < i || i < 22)
		{	
			color(BLACK_GREEN);
			printf("■");
			color(BLACK_YELLOW);
			printf("■■■■■■■■■■■■■■■■■■■■■■");
			color(BLACK_GREEN);
			printf("■\n");
		}
		else
		{
			color(BLACK_YELLOW);
			printf("■■■■■■■■■■■■■■■■■■■■■■■■\n");
		}
	}
	gotoxy(0, 0);
	color(BLACK_GREEN);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■\n");
	gotoxy(0, 22);
	color(BLACK_GREEN);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■\n");
	color(BLACK_YELLOW);
	gotoxy(24, 0);
	printf("GROUP NUMBER:     ");
	gotoxy(24,1);
	printf("ID:     NAME:S.W.");
	gotoxy(24, 2);
	printf("TERRITORY:WHOLE");
	showstate();
}

/*显示地图*/
void prt_map()
{

}

/*显示苹果*/
void prt_apple()
{

}
/*控制蛇*/
void ctrl_snake()
{

}
/*蛇吃到苹果*/
void eat_apple()
{

}

/*蛇撞墙*/
void wall()
{

}

/*达到最大蛇长胜利*/
void win()
{

}

/*询问是否继续*/
int continue_yn()
{

	return 1;												//返回是否继续
}

int main()
{
	while (1)												//游戏整体循环
	{	
			switch (flag=prt_menu())						//显示主菜单
			{
			case 'S':
			case 's':
				break;
			case 'I':
			case 'i':
				inf_page();
				break;
			default:
				return 0;
			}
		init();												//初始化参数
		prt_map();											//显示地图
		while (1)											//地图关卡循环(屏幕刷新循环)
		{
			ctrl_snake();									//控制蛇
			prt_apple();									//显示苹果
			if (snake[0][0] == 0 || snake[0][0] == 22 || snake[0][1] == 0 || snake[0][1] == 22)		//判断是否撞墙(蛇头坐标是否与墙重合)
			{
				wall();										//显示撞墙后效果
				break;										//退出屏幕刷新循环
			}
			if (snake[0][0] == apple[0] && snake[0][1] == apple[1])
			{
				eat_apple();
			}
			if (len == 10)									//判断是否达到胜利条件(蛇长达到10)
			{
				win();										//显示胜利效果
				break;										//退出屏幕刷新循环
			}
		}
		if (continue_yn())
		{
			break;											//退出游戏循环
		}
	}
	return 0;
}