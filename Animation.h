#pragma once
#include<vector>
#include<graphics.h>
#include"Image_Loading.h"
using namespace std;
class Animation
{
public:
	Animation(LPCTSTR path, int num, int interval);   //����Ҫ���ƵĶ����ĵ�ַ��ͼƬ�������Լ�֡���
	~Animation();

	void Play(int x, int y, int delta);   //���Ŷ����������Լ�ʱ����
	



private:
	int timer = 0;
	int idx_frame = 0;
	vector <IMAGE*> frame_list;
	int interval_ms = 0;    //֡���
};