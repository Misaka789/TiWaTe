#pragma once
#include"Point.h"
#include"Animation.h"
#include"H.h"
class Player
{
public:
	Point pos;
	int speed = 5;
	int face = 0;  //³¯Ïò
	int width;
	int height;
	Player() :width(Player_Width), height(Player_Height) {};
	//Player() :width(80), height(80) {};
	void Move(bool up, bool down, bool left, bool right);  //ÒÆ¶¯º¯Êý
	void Show();
	Animation animation();
	
};
