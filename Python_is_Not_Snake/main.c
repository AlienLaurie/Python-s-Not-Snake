
#include<stdio.h>
#include<windows.h>
#include<time.h>
#define BLACK_GREEN 0x0a															//�ڵ�����
#define BLACK_YELLOW 0x0e															//�ڵ׻���
#define BLACK_RED 0x0c																//�ڵ׺���
int snake[10][2] = { { 11,11 } ,{ 11, 10 }, { 11, 9 }, { -1, -1} ,{ -1, -1} ,{ -1, -1}, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } };
int apple_x, apple_y, len, flag = 1, j, score = 0,dir;
/*��ʼ������
snake�����ߵ�x,y����,apple����ƻ����x,y����,len�߳�
(��0����x,��1����y)*/
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
			Sleep(7);															//�ò˵������������������Ч��
		}
		printf("\n");

	}
	gotoxy(0, 7);
	printf("Python's Not Shanke(PNS) Entertsinment System by S.Wong\n");		//�˵�ѡ��
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

/*��ʾ��Ϣҳ*/
void inf_page()
{	
	color(0x00);																//����Ļ������ɫ�趨Ϊ��ɫ
	system("cls");																//����(��ɫ)
	gotoxy(0, 0);																//���ù��
	color(BLACK_GREEN);																
	printf("Python's Not Snake(PNS) Entertainment System By S.Wong\nGrapics by S.W.\nProgram by S.W.\nTHANKS FOR PLAYING.\nPRESS ANY KEY TO CONTINUE\n");
	while (!(_kbhit()));														//�ȴ�����
}

/*��ʾ��̬��Ϣ*/
void showstate()
{	
	color(BLACK_YELLOW);
	gotoxy(24, 8);
	printf("SCORE:%d", score);
}

/*��ʾƻ��*/
void prt_apple()
{
	int i, flag = 0;
	do
	{
		flag = 0;
		apple_x = (int)(20.0*rand() / RAND_MAX + 1.0);									//ͨ�������Ϊƻ�����긳ֵ(0<=rand()/RAND_MAX<=1)
		apple_y = (int)(20.0*rand() / RAND_MAX + 1.0);
		for (i = 0; i < 10; i++)														//�������ƻ���Ƿ������غ�
		{
			if (snake[i][0] == apple_x && snake[i][1] == apple_y)
			{
				flag = 1;
			}
		}

	} while (flag);
	gotoxy(apple_x, apple_y);														//��ʾƻ��
	color(BLACK_RED);
	printf("��");
}
/*��ʼ������*/
void init()
{
	int i;
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
	int i;
	gotoxy(snake[0][0], snake[0][1]);													 //�����ͷ
	printf("��");
	for (i = 1; i < 10; i++)															 //�������
	{
		if (snake[i][0] > 0)
		{
			gotoxy(snake[i][0], snake[i][1]);
			printf("��");
		}
		else																			 //���ͼ	��λ
		{
			color(BLACK_YELLOW);
			gotoxy(snake[i][0], snake[i][1]);
			printf("��");
		}
		Sleep(350);
		if (_kbhit())																	 //��������
		{
			switch (getchar())															 //��ð���
			{
			case 'w':
			case 'W':
				snake[0][1]++;
				dir = 0;
				break;
			case 's':
			case 'S':
				snake[0][1]--;
				dir = 1;
				break;
			case 'a':
			case 'A':
				snake[0][0]--;
				dir = 2;
				break;
			case 'd':
			case 'D':
				snake[0][0]++;
				dir = 3;
				break;
			default:																	  //���水������									
				switch (dir)
				{
				case 0:
					snake[0][1]--;														  //Ϊʲô��������?��������������,Ϊʲôy�᷽����෴��?

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
		}
		for (i = 1; i < 10; i++)														//�����ƶ�(����һ�����������������һ������)
		{
			snake[i][0] = snake[i + 1][0];
			snake[i][1] = snake[i + 1][1];
		}
	}
}
/*�߳Ե�ƻ��*/
void eat_apple()
{
	prt_apple();
	score++;
	showstate();
}

/*��ײǽ*/
void wall()
{

}

/*�ﵽ����߳�ʤ��*/
void win()
{

}

/*ѯ���Ƿ����*/
int continue_yn()
{

	return 1;												//�����Ƿ����
}

int main()
{
	while (1)												//��Ϸ����ѭ��
	{	
			switch (flag=prt_menu())						//��ʾ���˵�
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
		//��ʼ������
		while (1)											//��ͼ�ؿ�ѭ��(��Ļˢ��ѭ��)
		{
			ctrl_snake();									//������
			if (snake[0][0] == 0 || snake[0][0] == 22 || snake[0][1] == 0 || snake[0][1] == 22)		//�ж��Ƿ�ײǽ(��ͷ�����Ƿ���ǽ�غ�)
			{
				wall();										//��ʾײǽ��Ч��
				break;										//�˳���Ļˢ��ѭ��
			}
			if (snake[0][0] == apple_x && snake[0][1] == apple_y)
			{
				eat_apple();
			}
			if (len == 10)									//�ж��Ƿ�ﵽʤ������(�߳��ﵽ10)
			{
				win();										//��ʾʤ��Ч��
				break;										//�˳���Ļˢ��ѭ��
			}
		}
		if (continue_yn())
		{
			return 0;											//�˳���Ϸѭ��
		}
	}
	return 0;
}