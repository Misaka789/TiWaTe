#include<cmath>
#include"Player.h"
#include"Image_Loading.h"
#include"H.h"

//Player::Player()
//{
//	width = Player_Width;
//	height = Player_Height;
//}


void Player::Move(bool up, bool down, bool left, bool right)  //�޸��ƶ��߼�
{
	int delt_x = right - left;             //�ֱ�ȡ���Һ�����Ϊ������
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

	//Խ���ж�
	if (pos.x < 0)pos.x = 0;
	if (pos.x + width >= X)pos.x =X - width;
	if (pos.y < 0)pos.y = 0;
	if (pos.y + height >= Y)pos.y =Y - height;


	if (delt_x > 0)face = 1;  //�����������
	if (delt_x < 0)face = 0;
}

void Player::Show()     //���Ŷ���
{

}