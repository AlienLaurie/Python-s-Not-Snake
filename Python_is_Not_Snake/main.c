#include<stdio.h>
#include<windows.h>
#define BLACK_GREEN 0x0a															//�ڵ�����
#define BLACK_YELLOW 0x0e															//�ڵ׻���
#define BLACK_RED																	//�ڵ׺���
int snake[10][2], apple[1][2],len,flag=1,j,score=0;
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
/*��ʼ������*/
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
			printf("��");
			color(BLACK_YELLOW);
			printf("��������������������������������������������");
			color(BLACK_GREEN);
			printf("��\n");
		}
		else
		{
			color(BLACK_YELLOW);
			printf("������������������������������������������������\n");
		}
	}
	gotoxy(0, 0);
	color(BLACK_GREEN);
	printf("������������������������������������������������\n");
	gotoxy(0, 22);
	color(BLACK_GREEN);
	printf("������������������������������������������������\n");
	color(BLACK_YELLOW);
	gotoxy(24, 0);
	printf("GROUP NUMBER:     ");
	gotoxy(24,1);
	printf("ID:     NAME:S.W.");
	gotoxy(24, 2);
	printf("TERRITORY:WHOLE");
	showstate();
}

/*��ʾ��ͼ*/
void prt_map()
{

}

/*��ʾƻ��*/
void prt_apple()
{

}
/*������*/
void ctrl_snake()
{

}
/*�߳Ե�ƻ��*/
void eat_apple()
{

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
		init();												//��ʼ������
		prt_map();											//��ʾ��ͼ
		while (1)											//��ͼ�ؿ�ѭ��(��Ļˢ��ѭ��)
		{
			ctrl_snake();									//������
			prt_apple();									//��ʾƻ��
			if (snake[0][0] == 0 || snake[0][0] == 22 || snake[0][1] == 0 || snake[0][1] == 22)		//�ж��Ƿ�ײǽ(��ͷ�����Ƿ���ǽ�غ�)
			{
				wall();										//��ʾײǽ��Ч��
				break;										//�˳���Ļˢ��ѭ��
			}
			if (snake[0][0] == apple[0] && snake[0][1] == apple[1])
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
			break;											//�˳���Ϸѭ��
		}
	}
	return 0;
}