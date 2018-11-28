
#include<stdio.h>
#include<windows.h>
#include<time.h>
#define BLACK_GREEN 0x0a															//黑底绿字
#define BLACK_YELLOW 0x0e															//黑底黄字
#define BLACK_RED 0x0c																//黑底红字
int snake[10][2] = { { 11,11 } ,{ 11, 12 }, { 11, 13 }, { 11, 14} ,{ 11,15 } ,{ 11, 16}, { 11, 17 }, { -1, -1 }, { -1, -1 }, { -1, -1 } };
int apple_x, apple_y, len=3, flag = 1, j, score = 0,dir='w';
/*初始化参数
snake储存蛇的x,y坐标,apple储存苹果的x,y坐标,len蛇长(最大为9)
(列0储存x,列1储存y),dir保存方向*/
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
//			Sleep(7);															//让菜单背景的输出产生动画效果
		}
		printf("\n");

	}
	gotoxy(0, 7);
	printf("Python's Not Shanke(PNS) Entertsinment System by S.Wong\n");		//菜单选项
//	Sleep(500);
	printf("PRESS S TO START\n");

//	Sleep(500);
	printf("I TO INFORMATION\n");
//	Sleep(500);
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
	while (!(kbhit()));														//等待键入
}

/*显示动态信息*/
void showstate()
{	
	color(BLACK_YELLOW);
	gotoxy(24, 8);
	printf("SCORE:%d", score);
}

/*显示苹果*/
void prt_apple()
{
	int i, flag = 0;
	do
	{
		flag = 0;
		apple_x = (int)(20.0*rand() / RAND_MAX + 1.0);									//通过随机数为苹果坐标赋值(0<=rand()/RAND_MAX<=1)
		apple_y = (int)(20.0*rand() / RAND_MAX + 1.0);
		for (i = 0; i < 10; i++)														//检查生产苹果是否与蛇重合
		{
			if (snake[i][0] == apple_x && snake[i][1] == apple_y)
			{
				flag = 1;
			}
		}

	} while (flag);
	gotoxy(apple_x, apple_y);														//显示苹果
	color(BLACK_RED);
	printf("●");
}
/*初始化参数*/
void init()
{
	int i;
	len = 3;
	srand((int)time(0));														 //通过系统时间获取随机数种子
	color(0X00);																 //颜色设定为黑底黑字
	system("cls");																 //清屏															
	gotoxy(0, 0);																 //重置坐标
	for (i = 0; i < 22; i++)													 //输出地图
	{
		if (0 < i && i < 21)
		{	
			color(BLACK_GREEN);
			printf("□");
			color(BLACK_YELLOW);
			printf("■■■■■■■■■■■■■■■■■■■■■■");
			color(BLACK_GREEN);
			printf("□\n");
		}
		else
		{
			color(BLACK_GREEN);
			printf("□□□□□□□□□□□□□□□□□□□□□□□□\n");
		}
	}
	color(BLACK_YELLOW);															//输出信息
	gotoxy(24, 0);
	printf("GROUP NUMBER:     ");
	gotoxy(24,1);
	printf("ID:     NAME:S.W.");
	gotoxy(24, 2);
	printf("TERRITORY:WHOLE");
	showstate();																	//输出动态信息
	prt_apple();
}

/*控制蛇*/
void ctrl_snake()
{
	int i, temp_x = snake[0][0], temp_y = snake[0][1];
	color(BLACK_YELLOW);
	gotoxy(snake[0][0], snake[0][1]);													 //输出蛇头
	printf("¤");
	for (i = 1; i <= len; i++)															 //输出蛇身
	{
		color(BLACK_YELLOW);
		gotoxy(snake[i][0], snake[i][1]);
		printf("★");
	}
		color(BLACK_YELLOW);
		gotoxy(snake[len+1][0], snake[len+1][1]);										 //蛇尾储输出空位
		printf("■");
		Sleep(2000-0.5*score);
		if (kbhit())																	 //按键激活
		{
			dir = _kbhit();
		}
			switch (dir)												    			 //获得按键
			{
			case 'w':
			case 'W':
				snake[0][1]--;
			break;
			case 's':
			case 'S':
				snake[0][1]++;
			break;
			case 'a':
			case 'A':
				snake[0][0]--;
			break;
			case 'd':
			case 'D':
				snake[0][0]++;
			break;
			default:																	  //保存按键方向									
				switch (dir)
				{
				case 0:
					snake[0][1]--;
				break;
				case 1:
					snake[0][1]++;
				break;
				case 2:
					snake[0][0]--;
				break;
				case 3:
					snake[0][0]++;
				break;
			break;
				}
		}
			snake[1][0] = temp_x;
			snake[1][1] = temp_y;
		for (i = 2; i <= 10; i++)														//蛇身移动(讲上一个蛇身的坐标移至下一个蛇身)
		{
			snake[i][0] = snake[i + 1][0];
			snake[i][1] = snake[i + 1][1];
		}
}

/*蛇吃到苹果*/
void eat_apple()
{
	prt_apple();
	score++;
	showstate();
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
		init();	
		//初始化参数
		while (1)											//地图关卡循环(屏幕刷新循环)
		{
			ctrl_snake();									//控制蛇
			if (snake[0][0] == 0 || snake[0][0] == 22 || snake[0][1] == 0 || snake[0][1] == 22)		//判断是否撞墙(蛇头坐标是否与墙重合)
			{
				wall();										//显示撞墙后效果
				return 0;										//退出屏幕刷新循环
			}
			if (snake[0][0] == apple_x && snake[0][1] == apple_y)
			{
				eat_apple();
			}
			if (len == 10)									//判断是否达到胜利条件(蛇长达到10)
			{
				win();										//显示胜利效果
				return 0;										//退出屏幕刷新循环
			}
		}
		if (continue_yn())
		{
			return 0;											//退出游戏循环
		}
	}
	return 0;
}