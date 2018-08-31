#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
//#include "bullet.h"
//#include "police.h"

#define FIRSTSTAGEENEMY 4
#define SECONDSTAGEENEMY 2
#define ENEMYSPEED 3
//Enemy 1
//idle
int enemy_1_idle;

//walk
int enemy_1_walk[8];
char e1_walk[8][100] = { "image\\terrorist1\\Asset1.png","image\\terrorist1\\Asset2.png","image\\terrorist1\\Asset3.png","image\\terrorist1\\Asset4.png","image\\terrorist1\\Asset5.png","image\\terrorist1\\Asset6.png","image\\terrorist1\\Asset7.png","image\\terrorist1\\Asset8.png" };

//reverse
int enemy_1_idleRev;
int enemy_1_walkReverse[8];
char e1_walkReverse[8][100] = {  "image\\Enemy\\walk\\Reverse\\1_terrorist_1_Walk_reverse_000.png","image\\Enemy\\walk\\Reverse\\1_terrorist_1_Walk_reverse_001.png","image\\Enemy\\walk\\Reverse\\1_terrorist_1_Walk_reverse_002.png" ,"image\\Enemy\\walk\\Reverse\\1_terrorist_1_Walk_reverse_003.png" ,"image\\Enemy\\walk\\Reverse\\1_terrorist_1_Walk_reverse_004.png","image\\Enemy\\walk\\Reverse\\1_terrorist_1_Walk_reverse_005.png","image\\Enemy\\walk\\Reverse\\1_terrorist_1_Walk_reverse_006.png","image\\Enemy\\walk\\Reverse\\1_terrorist_1_Walk_reverse_007.png" };

//bool enemyKill = false;

//enemy 2
//idle
int enemy_2_idle;
//walk
int enemy_2_walk[8];
char e2_walk[8][200] = { "image\\terrorist2\\Rev\\Asset1.png","image\\terrorist2\\Rev\\Asset2.png" ,"image\\terrorist2\\Rev\\Asset3.png" ,"image\\terrorist2\\Rev\\Asset4.png" ,"image\\terrorist2\\Rev\\Asset5.png" ,"image\\terrorist2\\Rev\\Asset6.png" ,"image\\terrorist2\\Rev\\Asset7.png" ,"image\\terrorist2\\Rev\\Asset8.png" };
int enemy2ComingCountDown = 0;
int enemy2KillCountDown = 0;

int enemyIndex = 0;
struct Enemy
{
	int enemy_x;
	int enemy_y;
	int enemy_width;
	int enemy_height;

	//int enemy_index;
	int enemyWalk_index;
	bool enemyIdleShow;
	int enemyIndex = 0;
	bool enemyShow;
	//bool enemyWalkShow;
};
Enemy e1[FIRSTSTAGEENEMY],e2[SECONDSTAGEENEMY];

void enemy1SetValue()
{
	for (int i = 0; i < FIRSTSTAGEENEMY; i++)
	{
		e1[i].enemy_x = 1280 + rand() % 900;
		e1[i].enemy_y = 130;
		e1[i].enemy_width = 70;
		e1[i].enemy_height = 120;
		e1[i].enemyShow = false;
		//e1.enemy_index = 0;
		e1[i].enemyIdleShow = false;
		e1[i].enemyWalk_index = 0;
		//e1.enemyWalkShow = false;
	}
}

void enemy2SetValue()
{
	for (int i = 0; i < SECONDSTAGEENEMY; i++)
	{
		e2[i].enemy_x = 1280 + rand() % 1000;
		e2[i].enemy_y = 130;
		e2[i].enemy_width = 70;
		e2[i].enemy_height = 120;
		e2[i].enemyShow = false;
		//e1.enemy_index = 0;
		e2[i].enemyIdleShow = false;
		e2[i].enemyWalk_index = 0;
	}
}


//image loading function
void enemyMoveSet()
{
	//first stage enemy
	enemy_1_idle = iLoadImage("image\\terrorist1\\Idle.png");
	for (int i = 0; i < 8; i++)
	{
		enemy_1_walk[i] = iLoadImage(e1_walk[i]);
	}

	//second stage enemy
	enemy_2_idle = iLoadImage("image\\terrorist2\\Rev\\Idle.png");
	for (int i = 0; i < 8; i++)
	{
		enemy_2_walk[i] = iLoadImage(e2_walk[i]);
	}

}


//moving function for enemy 1
void enemyMoveLeft()
{
	//function for moving enemy left
	for (int i = enemyIndex; i < FIRSTSTAGEENEMY; i++)
	{
		if (!e1[i].enemyIdleShow)
		{
			//enemyKill = fa2lse;
			e1[i].enemy_x -= ENEMYSPEED;
			e1[i].enemyWalk_index++;
			
			//enemyKill();
			if (e1[i].enemyWalk_index >= 8)
			{
				e1[i].enemyWalk_index = 0;
			}
			e1[i].enemyIdleShow = false;
		}
		if (e1[i].enemy_x <= 1100)
		{
			e1[i].enemyShow = true;
		}
	}
}

//enemy 2 movement
void enemy2MoveLeft()
{
	for (int i = 0; i < SECONDSTAGEENEMY; i++)
	{
		if (!e2[i].enemyIdleShow && enemy2ComingCountDown >= 200)
		{
			//enemyKill = fa2lse;
			e2[i].enemy_x -= ENEMYSPEED;
			e2[i].enemyWalk_index++;

			//enemyKill();
			if (e2[i].enemyWalk_index >= 8)
			{
				e2[i].enemyWalk_index = 0;
			}
			e2[i].enemyIdleShow = false;
		}
		if (e2[i].enemy_x <= 1050)
		{
			e2[i].enemyShow = true;
		}
	}
}

//showing the images of enemy
void enemyShow()
{
	for (int i = enemyIndex; i < FIRSTSTAGEENEMY; i++)
	{
		if (!e1[i].enemyIdleShow)
			iShowImage(e1[i].enemy_x, e1[i].enemy_y, e1[i].enemy_width, e1[i].enemy_height, enemy_1_walk[e1[i].enemyWalk_index]);
		if (e1[i].enemy_x <= 850)
		{
			e1[i].enemyIdleShow = true;
			iShowImage(e1[i].enemy_x, e1[i].enemy_y, e1[i].enemy_width, e1[i].enemy_height, enemy_1_idle);
		}
	}
}


//the following function is for showing images of enemy 2
void enemy2Show()
{
	enemy2ComingCountDown++;
	if (enemy2ComingCountDown >= 200)
	{
		for (int i = 0; i < SECONDSTAGEENEMY; i++)
		{
			if (!e2[i].enemyIdleShow)
				iShowImage(e2[i].enemy_x, e2[i].enemy_y, e2[i].enemy_width, e2[i].enemy_height, enemy_2_walk[e2[i].enemyWalk_index]);
			if (e2[i].enemy_x <= 950)
			{
				e2[i].enemyIdleShow = true;
				iShowImage(e2[i].enemy_x, e2[i].enemy_y, e2[i].enemy_width, e2[i].enemy_height, enemy_2_idle);
			}
		}
		
	}
}

#endif // ENEMY_H_INCLUDED