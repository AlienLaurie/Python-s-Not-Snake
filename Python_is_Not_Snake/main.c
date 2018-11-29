
#include<stdio.h>
#include<windows.h>
#include<time.h>
#define BLACK_GREEN 0x0a															//�ڵ�����
#define BLACK_YELLOW 0x0e															//�ڵ׻���
#define BLACK_RED 0x0c																//�ڵ׺���
#define RED_RED 0xc4																//��׺���
int Snake[10][2] = { { 11,11 } ,{ 11, 12 }, { 11, 13 }, { 11, 14} ,{ 11,15 } ,{ 11, 16}, { 11, 17 }, { -1, -1 }, { -1, -1 }, { -1, -1 } };
int Apple_x, Apple_y, Len=3, Flag = 1, Score = 0;
/*��ʼ������
snake�����ߵ�x,y����,apple����ƻ����x,y����,Len�߳�(���Ϊ9)
(��0����x,��1����y),dir���淽��*/
/*����ƶ���x,y*/
void gotoxy

(int x, int y)
{
	COORD pos;
	pos.X = 2 * x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);				//��ÿ���̨���λ��
}
/*�ı����̨�����ɫ*/
void color(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

/*������˵�*/
int prt_menu()
{
	char input=0;
	int i,j;
	gotoxy(0, 0);
	for (i = 0;i < 20; i++)														//����˵�����
	{
		color(i * 0x0f);														//�ñ������������ɫЧ��
		for (j = 0; j < 20; j++)
		{
			printf("< >");
//			Sleep(7);															//�ò˵������������������Ч��
		}
		printf("\n");

	}
	gotoxy(0, 7);
	printf("Python's Not Shanke(PNS) Entertsinment System by S.Wong\n");		//�˵�ѡ��
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

/*��ʾ��Ϣҳ*/
void inf_page()
{	
	color(0x00);																//����Ļ������ɫ�趨Ϊ��ɫ
	system("cls");																//����(��ɫ)
	gotoxy(0, 0);																//���ù��
	color(BLACK_GREEN);																
	printf("Python's Not Snake(PNS) Entertainment System By S.Wong\nGrapics by S.W.\nProgram by S.W.\nTHANKS FOR PLAYING.\nPRESS ANY KEY TO CONTINUE\n");
	while (!(kbhit()));														//�ȴ�����
}

/*��ʾ��̬��Ϣ*/
void showstate()
{	
	color(BLACK_YELLOW);
	gotoxy(24, 8);
	printf("SCORE:%d", Score);
}

/*��ʾƻ��*/
void prt_apple()
{
	int i, flag = 0;
	do
	{
		flag = 0;
		Apple_x = (int)(20.0*rand() / RAND_MAX + 1.0);									//ͨ�������Ϊƻ�����긳ֵ(0<=rand()/RAND_MAX<=1)
		Apple_y = (int)(20.0*rand() / RAND_MAX + 1.0);
		for (i = 0; i <=Len; i++)														//�������ƻ���Ƿ������غ�
		{
			if (Snake[i][0] == Apple_x && Snake[i][1] == Apple_y)
			{
				flag = 1;
			}
		}

	} while (flag);
	gotoxy(Apple_x, Apple_y);														//��ʾƻ��
	color(BLACK_RED);
	printf("��");
}
/*��ʼ������*/
void init()
{
	int i;
	Len = 3;
	srand((int)time(0));														 //ͨ��ϵͳʱ���ȡ���������
	color(0X00);																 //��ɫ�趨Ϊ�ڵ׺���
	system("cls");																 //����															
	gotoxy(0, 0);																 //��������
	for (i = 0; i < 22; i++)													 //�����ͼ
	{
		if (0 < i && i < 21)
		{	
			color(BLACK_GREEN);
			printf("��");
			color(BLACK_YELLOW);
			printf("��������������������������������������������");
			color(BLACK_GREEN);
			printf("��\n");
		}
		else
		{
			color(BLACK_GREEN);
			printf("������������������������������������������������\n");
		}
	}
	color(BLACK_YELLOW);															//�����Ϣ
	gotoxy(24, 0);
	printf("GROUP NUMBER:     ");
	gotoxy(24,1);
	printf("ID:     NAME:S.W.");
	gotoxy(24, 2);
	printf("TERRITORY:WHOLE");
	showstate();																	//�����̬��Ϣ
	prt_apple();
}

/*������*/
void ctrl_snake()
{
	static dir = 'w';
	int i;
	color(BLACK_YELLOW);
	gotoxy(Snake[0][0], Snake[0][1]);													 //�����ͷ
	printf("��");
	for (i = 1; i < Len; i++)															 //�������
	{
		color(BLACK_YELLOW);
		gotoxy(Snake[i][0], Snake[i][1]);
		printf("��");
	}
		color(BLACK_YELLOW);
		gotoxy(Snake[Len+1][0], Snake[Len+1][1]);										 //��β�������λ
		printf("��");
		Sleep(200-5*Score);																 //�����ߵ��ƶ��ٶ�
		for (i = Len; i >= 0; i--)														 //�����ƶ�(����һ�����������������һ������)
		{
			Snake[i + 1][0] = Snake[i][0];
			Snake[i + 1][1] = Snake[i][1];
		}
		if (_kbhit())																	 //��������
		{
			dir = getch();
		}
			switch (dir)												    			 //��ð���
			{
			case 'w':
			case 'W':
				Snake[0][1]--;
			break;
			case 's':
			case 'S':
				Snake[0][1]++;
			break;
			case 'a':
			case 'A':
				Snake[0][0]--;
			break;
			case 'd':
			case 'D':
				Snake[0][0]++;
			break;
			default:																	  //���水������									
				switch (dir)
				{
				case 'w':
				case 'W':
					Snake[0][1]--;
					break;
				case 's':
				case 'S':
					Snake[0][1]++;
					break;
				case 'a':
				case 'A':
					Snake[0][0]--;
					break;
				case 'd':
				case 'D':
					Snake[0][0]++;
					break;
			break;
				}
		}
}

/*�߳Ե�ƻ��*/
void eat_apple()
{
	prt_apple();
	Score++;
	Len++;
	showstate();
}

/*��ײǽ*/
void wall()
{
	color(RED_RED);
	system("clr");
	gotoxy(11, 11);
	printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOPS!SORRY,BUT,GAME OVER.\nPRESS ANY KEY TO CONTINUE.");
	while (kbhit());
}

/*�ﵽ����߳�ʤ��*/
void win()
{
	color(RED_RED);
	system("clr");
	gotoxy(11, 11);
	printf("WOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOW!YOU WIN!\nPRESS ANY KEY TO CONTINUE.");
	while (kbhit());
}

/*ѯ���Ƿ����*/
int continue_yn()
{
	char input;
	color(BLACK_GREEN);
	system("clr");
	gotoxy(0, 0);
	do
	{
		input = 0;
		printf("WOULD YOU LIKE TO PLAY AGAIN? Y/N\n");
		input = getchar();
	} while (input == 'Y' || input == 'y' || input == 'N' || input == 'n');
	return input;												//�����Ƿ����
}

int main()
{
	while (1)												//��Ϸ����ѭ��
	{	
			switch (Flag=prt_menu())						//��ʾ���˵�
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
		init();												//��ʼ������
		while (1)											//��ͼ�ؿ�ѭ��(��Ļˢ��ѭ��)
		{
			ctrl_snake();									//������
			if (Snake[0][0] == 0 || Snake[0][0] == 21 || Snake[0][1] == 0 || Snake[0][1] == 21)		//�ж��Ƿ�ײǽ(��ͷ�����Ƿ���ǽ�غ�)
			{
				wall();										//��ʾײǽ��Ч��
				break;										//�˳���Ļˢ��ѭ��
			}
			if (Snake[0][0] == Apple_x && Snake[0][1] == Apple_y)
			{
				eat_apple();
			}
			if (Len == 9)									//�ж��Ƿ�ﵽʤ������(�߳��ﵽ10)
			{
				win();										//��ʾʤ��Ч��
				break;										//�˳���Ļˢ��ѭ��
			}
		}
		if (continue_yn()=='Y'||continue_yn=='y')
		{
			return 0;											//�˳���Ϸѭ��
		}
	}
	return 0;
}