#include<stdio.h>
#include<windows.h>
int snake[10][2], apple[1][2],len;			
/*初始化参数
snake储存蛇的x,y坐标,apple储存苹果的x,y坐标,len蛇长
(列0储存x,列1储存y)*/

/*输出主菜单*/
void prt_menu()
{

}

/*初始化参数*/
void init()
{

}

/*显示地图*/
void prt_map()
{

}

/*显示苹果*/
void prt_apple()
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
		prt_menu();											//显示主菜单
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