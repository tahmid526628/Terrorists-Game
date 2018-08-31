#include "police.h"
#include "enemy.h"
#include "life.h"
#include "vehicle.h"

#define BULLETHEIGHT 10
#define BULLETWIDTH 7
#define BULLETSPEED 10

#define BULLETNUMBER 12
int k = 0;//a simple variable to control loop globally


int bullet;
int enemyBullet;
int rocket;
int rocketBlast;
int blastCount = 0;


//bool bulletOnEnemy = false;

//bullet load function
void loadBullet()
{
	bullet = iLoadImage("image\\bullet1.png");
	rocket = iLoadImage("image\\policeRocket.png");
	rocketBlast = iLoadImage("image\\fireObject\\Blast2.png");
}

struct bullet {
	int x;
	int y;
	bool show;
} bullets[BULLETNUMBER];

void setPolice1BulletValue() {
	for (int i = k; i < BULLETNUMBER; i++) {
		bullets[i].x = p1.police_x + p1.police_width;
		bullets[i].y = p1.police_y + p1.police_height + p1.jumpCoordinate - 55;
		bullets[i].show = false;
	}
}

void setPolice2BulletValue()
{
	for (int i = k; i < BULLETNUMBER; i++) {
		bullets[i].x = p2.police_x + p2.police_width;
		bullets[i].y = p2.police_y + p2.police_height + p2.jumpCoordinate - 55;
		bullets[i].show = false;
	}
}

void showAndMovePoliceBullet()
{
	for (int i = 0; i < BULLETNUMBER; i++)
	{
		if (bullets[i].show) {
			if (police1_rocket || police2_rokcet)
			{
				iShowImage(bullets[i].x, bullets[i].y, 10, 7, rocket);
				if (bullets[i].x >= eTank.x + 50)
				{
					iShowImage(bullets[i].x, bullets[i].y, 30, 30, rocketBlast);
					blastCount++;
					if (blastCount >= 10)
					{
						score += 500;
						tankDestroy = true;
					}
				}
			}
			else {
				iShowImage(bullets[i].x, bullets[i].y, 10, 7, bullet);
				bullets[i].x += 16;
				//the following codes for the collision between police's bullets and enemies 1
				for (int j = 0; j < FIRSTSTAGEENEMY; j++)
				{
					if (bullets[i].x >= e1[j].enemy_x && bullets[i].x <= e1[j].enemy_x + e1[j].enemy_width && e1[j].enemyShow)
					{
						e1[j].enemy_x = SCREENWIDTH + rand() % 1000;
						e1[j].enemyIdleShow = false;
						e1[j].enemyShow = false;
						bullets[i].show = false;
						score = score + 5;

					}
				}
				//the following codes for the collision between police's bullets and enemies 2
				for (int j = 0; j < SECONDSTAGEENEMY; j++)
				{
					if (bullets[i].x >= e2[j].enemy_x && bullets[i].x <= e2[j].enemy_x + e2[j].enemy_width && e2[j].enemyShow)
					{
						enemy2KillCountDown++;
						bullets[i].show = false;
						if (enemy2KillCountDown >= 3)
						{
							e2[j].enemy_x = SCREENWIDTH + rand() % 1100;
							e2[j].enemyIdleShow = false;
							e2[j].enemyShow = false;
							bullets[i].show = false;
							score = score + 20;
							enemy2ComingCountDown = 0;
							enemy2KillCountDown = 0;
						}
					}
				}
			}
			
		}

		if (bullets[i].x == 1600)
			bullets[i].show = false;
	}
}


struct enemyBullet
{
	int x;
	int y;
}eB1[FIRSTSTAGEENEMY];


//set function of enemies bullet
void setEnemyBulletValue()
{
	for (int i = 0; i < FIRSTSTAGEENEMY; i++)
	{
		eB1[i].x = e1[i].enemy_x;//950;
		eB1[i].y = 250 - 67;//e1[i].enemy_y + e1[i].enemy_height - 67;//250-67;//e1[i].enemy_y + e1[i].enemy_height - 67;
	}
}

//changing coordinate of enemies bullet(rendering of enemies bullet)
void enemyBulletChangeForPolice1()
{
	for (int i = 0; i < FIRSTSTAGEENEMY; i++)
	{
		if (e1[i].enemyShow && firstCharacter)
		{
			eB1[i].x -= BULLETSPEED;
			if (eB1[i].x <= 0)
			{
				eB1[i].x = e1[i].enemy_x;
			}
			if (eB1[i].x <= p1.police_x + p1.police_width && eB1[i].x >= p1.police_x && eB1[i].y >= p1.police_y + p1.jumpCoordinate && eB1[i].y <= p1.police_y + p1.police_height + p1.jumpCoordinate)
			{
				PL1.pLife_index++;
				if (PL1.pLife_index > 19) {
					policeDie = true;
				}
				eB1[i].x = e1[i].enemy_x;  // here should be changed
			}
		}
	}

}

//change today
void enemyBulletChangeForPolice2()
{
	for (int i = 0; i < FIRSTSTAGEENEMY; i++)
	{
		if (/*e1[i].enemyIdleShow*/e1[i].enemyShow && secondCharacter)
		{
			eB1[i].x -= BULLETSPEED;
			if (eB1[i].x <= 0)
			{
				eB1[i].x = e1[i].enemy_x;//950;
			}
			if (eB1[i].x <= p2.police_x + p2.police_width && eB1[i].x >= p2.police_x  && eB1[i].y >= p2.police_y + p2.jumpCoordinate && eB1[i].y <= p2.police_y + p2.police_height + p2.jumpCoordinate)
			{
				PL1.pLife_index++;
				if (PL1.pLife_index > 19) {
					policeDie = true;
				}
				eB1[i].x = e1[i].enemy_x;// 950;  // here should be changed
			}
		}
	}

}

//Enemy bullet showing function
void enemyBulletShow()
{
	for (int i = 0; i < FIRSTSTAGEENEMY; i++)
	{
		if (e1[i].enemyShow)//e1[i].enemyIdleShow)
		{
			iShowImage(eB1[i].x, eB1[i].y, BULLETWIDTH, BULLETHEIGHT, bullet);
		}
	}
}


//collision between police bullet and enemy
void collisionBetweenPoliceBulletAndEnemy()
{
	
}

//level change 
void levelchange()
{
	if (score >= 300)
	{
		level = 2;
	}
	if (score >= 550 )
	{
		level = 3;
	}
}