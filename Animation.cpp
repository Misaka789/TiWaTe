#include"Animation.h"
#include"Image_Loading.h"
Animation::Animation(LPCTSTR path, int num, int interval)   //����Ҫ���ƵĶ����ĵ�ַ��ͼƬ�������Լ�֡���
{
	interval_ms = interval;

	TCHAR path_file[256];
	for (int i = 0; i < num; i++)
	{
		_stprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file);
		frame_list.push_back(frame);
	}
}

Animation::~Animation()
{
	for (int i = 0; i < frame_list.size(); i++)
	{
		delete frame_list[i];
	}
}


void Animation::Play(int x, int y, int delta)   //���Ŷ����������Լ�ʱ����
{
	timer += delta;
	if (timer > interval_ms)
	{
		idx_frame = (idx_frame + 1) % frame_list.size();
		timer = 0;
	}
	putimage_alpha(x, y, frame_list[idx_frame]);
}

/*void DrawPlayer(int delta, int dir_x)
	{
		static bool facing_left = false;
		if (dir_x < 0)
			facing_left = true;
		else if (dir_x > 0)
			facing_left = false;
		if (facing_left)
			anim_left_player.Play(player_pos.x, player_pos.y, delta);
		else
			anim_right_player.Play(player_pos.x, player_pos.y, delta);
	}*/