#include<stdio.h>
#include<windows.h>
int snake[10][2], apple[1][2],len;			
/*��ʼ������
snake�����ߵ�x,y����,apple����ƻ����x,y����,len�߳�
(��0����x,��1����y)*/

/*������˵�*/
void prt_menu()
{

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
		prt_menu();											//��ʾ���˵�
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