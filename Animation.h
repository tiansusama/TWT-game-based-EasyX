#pragma once

#include <graphics.h>
#include "Atlas.h"
#include "graphics_utils.h"

class Animation
{
public:
	Animation(Atlas* atlas, int interval)
	{
		anim_atlas = atlas;
		interval_ms = interval;
	}

	~Animation() = default;

	void Play(int x, int y, int delta)
	{
		timer += delta;
		if (timer >= interval_ms)
		{
			idx_frame = (idx_frame + 1) % anim_atlas->frame_list.size();
			timer = 0;
		}

		putimage_alpha(x, y, anim_atlas->frame_list[idx_frame]);
	}

private:
	int timer = 0;	//������ʱ��
	int idx_frame = 0;	//����֡����
	int interval_ms = 0; //֡���

private:
	Atlas* anim_atlas;
};
