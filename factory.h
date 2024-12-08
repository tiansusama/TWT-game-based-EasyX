#pragma once

#include <graphics.h>
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"

void TryGenerateEnemy(std::vector<Enemy*>& enemy_list)
{
	const int INTERVAL = 100;
	static int counter = 0;
	if ((++counter) % INTERVAL == 0)
		enemy_list.push_back(new Enemy());
}

void UpdateBullets(std::vector<Bullet>& buller_list, const Player& player)
{
	const double RADIAL_SPEED = 0.0045;	//径向波动速度
	const double TANGENT_SPEED = 0.0055;//切向波动速度
	double radian_interval = 2 * 3.14159 / buller_list.size();	//子弹之间的弧度间隔
	POINT player_position = player.GetPosition();
	double radius = 100 + 25 * sin(GetTickCount() * RADIAL_SPEED);
	for (size_t i = 0; i < buller_list.size(); i++)
	{
		double radian = GetTickCount() * TANGENT_SPEED + radian_interval * i;	//当前子弹所在弧度值
		buller_list[i].position.x = player_position.x + player.GetPlayerWidth() / 2 + (int)(radius * sin(radian));
		buller_list[i].position.y = player_position.y + player.GetPlayerHeight() / 2 + (int)(radius * cos(radian));
	}
}

//绘制玩家得分
void DrawPlayerScore(int score)
{
	static TCHAR text[64];
	_stprintf_s(text, _T("当前玩家得分：%d"), score);

	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 85, 185));
	outtextxy(10, 10, text);
}