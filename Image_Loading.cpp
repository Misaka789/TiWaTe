
#include<string>
#include"Image_Loading.h"
#include"H.h"
using namespace std;
void LoadAnimation()
{
	//extern int Player_Anim_Num;
	extern IMAGE Player_left[Player_Anim_Num];
	extern IMAGE Player_right[Player_Anim_Num];
	extern int current_image ;
	for (int i = 0; i < Player_Anim_Num; i++)
	{
		wstring path = L"img/player_left_" + to_wstring(i) + L".png";
		loadimage(&Player_left[i], path.c_str());
	}

	for (int i = 0; i < Player_Anim_Num; i++)
	{
		wstring path = L"img/player_right_" + to_wstring(i) + L".png";
		loadimage(&Player_right[i], path.c_str());
	}
}



void putimage_alpha(int x, int y, IMAGE* m)             //这部分过于高深， 暂时无法理解
{
	int w = m->getwidth();
	int h = m->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(m), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}