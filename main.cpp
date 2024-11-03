#pragma comment(lib, "MSIMG32.LIB")
#include<iostream>
#include<vector>
#include<graphics.h>
#include<string>
#include"Animation.h"
#include"Player.h"
#include"Point.h"
#include"Image_Loading.h"
#include"Enermy.h"
#include"H.h"
   //一个动画帧中的图片数目
using namespace std;
 IMAGE Player_left[Player_Anim_Num];
 IMAGE Player_right[Player_Anim_Num];
 int current_image = 0;      
                            //动画帧索引，游戏帧与循环的频率一致，动画帧没必要这么快

int main()
{
	initgraph(X, Y);
	IMAGE m;
	ExMessage  msg;

	Player PM;
	bool up = 0;
	bool down = 0;
	bool left = 0;
	bool right = 0;

	loadimage(&m, _T("img/background.png"));
	LoadAnimation();
	BeginBatchDraw();
	srand(time(0));
	bool running = 1;


	while (running)
	{
		DWORD time1 = GetTickCount();

		static int counter = 0;                     //游戏帧索引
		if (++counter % 5==0)
			current_image = (current_image + 1) % Player_Anim_Num;
		
		while (peekmessage(&msg))
		{
			/*Player_pos.x = msg.x;
			Player_pos.y = msg.y;*/
			if (msg.message == WM_KEYDOWN)
			{
				switch (msg.vkcode)
				{
				case 0x57:  //W键
				{
					//PM.pos.y-=PM.speed;
					up = 1;
					break;
				}
				case 0x53:  //S键
				{
					//PM.pos.y+=PM.speed;
					down = 1;
					break;
				}
				case 0x41:  //A键
				{
					//PM.pos.x-=PM.speed;
					left = 1;
					break;
				}
				case 0x44:  //D键
				{
					//PM.pos.x+=PM.speed;
					right = 1;
					break;
				}
				default:
				{
					break;
				}
				}
			}

			if (msg.message == WM_KEYUP)
			{
				switch (msg.vkcode)
				{
				case 0x57:  //W键
				{
					//PM.pos.y-=PM.speed;
					up = 0;
					break;
				}
				case 0x53:  //S键
				{
					//PM.pos.y+=PM.speed;
					down = 0;
					break;
				}
				case 0x41:  //A键
				{
					//PM.pos.x-=PM.speed;
					left = 0;
					break;
				}
				case 0x44:  //D键
				{
					//PM.pos.x+=PM.speed;
					right = 0;
					break;
				}
				default:
				{
					break;
				}
				}
			}
		}

		PM.Move(up, down, left, right);
		


		cleardevice();
		putimage(0, 0, &m);
		if (PM.face==0)
			putimage_alpha(PM.pos.x, PM.pos.y, &Player_left[current_image]);
		else 
			putimage_alpha(PM.pos.x, PM.pos.y, &Player_right[current_image]);


		FlushBatchDraw();
		DWORD time2 = GetTickCount();         
		DWORD t = time2 - time1;
		if (t < 1000 / 60)
		{
			Sleep(1000 / 60 - t);
		}
	}
	EndBatchDraw();
	return 0;
}
