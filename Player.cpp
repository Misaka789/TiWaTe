#include<cmath>
#include"Player.h"
#include"Image_Loading.h"
#include"H.h"

//Player::Player()
//{
//	width = Player_Width;
//	height = Player_Height;
//}


void Player::Move(bool up, bool down, bool left, bool right)  //修改移动逻辑
{
	int delt_x = right - left;             //分别取向右和向下为正方向
	int delt_y = down - up;


	double len = sqrt(delt_x * delt_x + delt_y * delt_y);
	if (len != 0) {

		/*double normalized_x = delt_x / len;
		double normalized_y = delt_y / len;
		pos.x += (int)(speed * normalized_x);
		pos.y += (int)(speed * normalized_y);

		int _x = (delt_x / len) * speed;
		int _y = (delt_y / len) * speed;*/
		pos.x += int(delt_x / len * speed);
		pos.y += int(delt_y / len * speed);
	}

	//越界判断
	if (pos.x < 0)pos.x = 0;
	if (pos.x + width >= X)pos.x =X - width;
	if (pos.y < 0)pos.y = 0;
	if (pos.y + height >= Y)pos.y =Y - height;


	if (delt_x > 0)face = 1;  //解决朝向问题
	if (delt_x < 0)face = 0;
}

void Player::Show()     //播放动画
{

}