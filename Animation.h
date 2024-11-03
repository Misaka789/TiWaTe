#pragma once
#include<vector>
#include<graphics.h>
#include"Image_Loading.h"
using namespace std;
class Animation
{
public:
	Animation(LPCTSTR path, int num, int interval);   //传递要绘制的动画的地址、图片数量、以及帧间隔
	~Animation();

	void Play(int x, int y, int delta);   //播放动画的坐标以及时间间隔
	



private:
	int timer = 0;
	int idx_frame = 0;
	vector <IMAGE*> frame_list;
	int interval_ms = 0;    //帧间隔
};