#include<stdio.h>
#include<windows.h>
int snake[10][2], apple[1][2],len;			
/*��ʼ������
snake�����ߵ�x,y����,apple����ƻ����x,y����,len�߳�
(��0����x,��1����y)*/
/*����ƶ���x,y*/
void gotoxy(int x, int y)
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
	int input;
	int i;
	for (i = 0;i < 23; i++)
	{
		color(i * 0x0f);
		printf("* * * * * * * * * * * * * * * * * * * * * * * \n");
		Sleep(100);
	}
	gotoxy(0, 10);
	printf("Python's Not Shanke(PNS) by S.wong(201800800101)\n");
	printf("INTER Y FOR CONTINUE,OTHERS FOR EXIT\n");
	scanf("%d", &input);
	input -= 89;
	return input;
}

/*��ʼ������*/
void init()
{

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
		if (prt_menu())										//��ʾ���˵� ���������ֵ���˳���Ϸ����ѭ��
		{
			break;
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