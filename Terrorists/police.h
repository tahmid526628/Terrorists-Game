#ifndef POLICE_H_INCLUDED
#define POLICE_H_INCLUDED


#define POLICEJUMPLIMIT 300

//#include "bullet.h"
#include "life.h"

//police 1
//idle
int police_1_idle;
//walk
int police_1_walk[8];
char p1_walk[8][100] = { "image\\police1\\walk\\Asset 1.png", "image\\police1\\walk\\Asset 2.png", "image\\police1\\walk\\Asset 3.png","image\\police1\\walk\\Asset 4.png","image\\police1\\walk\\Asset 5.png","image\\police1\\walk\\Asset 6.png","image\\police1\\walk\\Asset 7.png","image\\police1\\walk\\Asset 8.png"};
//reverse
int police_1_idleRev;
int police_1_walkReverse[8];
char p1_walkReverse[8][100] = { "image\\police1\\walk\\reverse\\Asset8.png", "image\\police1\\walk\\reverse\\Asset7.png", "image\\police1\\walk\\reverse\\Asset6.png","image\\police1\\walk\\reverse\\Asset5.png","image\\police1\\walk\\reverse\\Asset4.png","image\\police1\\walk\\reverse\\Asset3.png","image\\police1\\walk\\reverse\\Asset2.png","image\\police1\\walk\\reverse\\Asset1.png" };
//shoot
int police_1_attack1[6];
char p1_attack1[6][100] = { "image\\police1\\attack_1\\1_police_attack_Attack_000_000.png","image\\police1\\attack_1\\1_police_attack_Attack_000_001.png","image\\police1\\attack_1\\1_police_attack_Attack_000_002.png","image\\police1\\attack_1\\1_police_attack_Attack_000_003.png","image\\police1\\attack_1\\1_police_attack_Attack_000_004.png","image\\police1\\attack_1\\1_police_attack_Attack_000_005.png" };
//police 2
//idle
int police_2_idle;
//walk
int police_2_walk[8];
char p2_walk[8][100] = { "image\\police2\\walk\\Asset1.png","image\\police2\\walk\\Asset2.png" ,"image\\police2\\walk\\Asset3.png" ,"image\\police2\\walk\\Asset4.png" ,"image\\police2\\walk\\Asset5.png" ,"image\\police2\\walk\\Asset6.png" ,"image\\police2\\walk\\Asset7.png" ,"image\\police2\\walk\\Asset8.png" };
//reverse
int police_2_idleRev;
int police_2_walkReverse[8];
char p2_walkReverse[8][100] = { "image\\police2\\reverse\\Asset8.png","image\\police2\\reverse\\Asset7.png" ,"image\\police2\\reverse\\Asset6.png" ,"image\\police2\\reverse\\Asset5.png" ,"image\\police2\\reverse\\Asset4.png" ,"image\\police2\\reverse\\Asset3.png" ,"image\\police2\\reverse\\Asset2.png" ,"image\\police2\\reverse\\Asset1.png" };


int standcount = 0;//after that count automatically idle will true
int standcount2 = 0;//for police character 2

/*the following variables are declared for police 1 character*/
bool stateLeft = false;//reverse image variable
bool stateRight = true;//right image variable
bool mouseState = false;//mouse button variable

/*the following variables are declared for police 2*/
bool stateLeft1 = false;//reverse image variable
bool stateRight1 = true;//forward image varibale


//here the changes of 6 august

int police1JumpUp;
int police1JumpDown;
int police2JumpUp;
int police2JumpDown;

bool jump1 = false;
bool jump2 = false;
bool jump1Rev = false;
bool jump2Rev = false;
bool jump1Up = false;
bool jump2Up = false;

//end of 6 august's changes

bool policeDie = false;

//rocket launcher related
int police1_rocketImg;
int police2_rocketImg;
bool police1_rocket = false;
bool police2_rokcet = false;

//variable for score
int score = 0;
char scoreStr[50];

//edited today
int newScore = 0;
//int currentScore = 5;
int highScore = 0;
char highScoreStr[50];

struct Police
{
	int police_x;
	int police_y;
	int police_width;
	int police_height;
	int police_attack_index;
	int policeWalk_index = 0;
	bool policeIdleShow;
	int jumpCoordinate = 0;
	//bool policeWalkShow;
};
Police p1,p2;

//function for assigning values in variables
void police1SetValue()
{
	p1.police_x = 50;
	p1.police_y = 130;
	p1.police_width = 70;
	p1.police_height = 120;
	//p1.police_index = 0;
	p1.policeIdleShow = true;
	//p1.policeWalkShow = false;
}

//function for setting value of police 2 character
void police2SetValue()
{
	p2.police_x = 50;
	p2.police_y = 130;
	p2.police_width = 70;
	p2.police_height = 120;
	p2.policeIdleShow = true;
	p2.policeWalk_index = 0;
}

//image load for police character
void policeMoveSet()
{
	//police 1 image loading
	//walking image load
	police_1_idle = iLoadImage("image\\police1\\walk\\Idle.png");
	for (int i = 0; i < 8; i++)
	{
		police_1_walk[i] = iLoadImage(p1_walk[i]);
	}

	//reverse image loading
	police_1_idleRev = iLoadImage("image\\police1\\walk\\reverse\\IdleRev.png");
	for (int i = 0; i < 8; i++)
	{
		police_1_walkReverse[i] = iLoadImage(p1_walkReverse[i]);
	}

	//image loading for shooting
	for (int i = 0; i < 6; i++)
	{
		police_1_attack1[i] = iLoadImage(p1_attack1[i]);
	}

	//police 2 image loading
	//idle image load
	police_2_idle = iLoadImage("image\\police2\\Idle.png");
	//walking image load
	for (int i = 0; i < 8; i++)
	{
		police_2_walk[i] = iLoadImage(p2_walk[i]);
	}
	//reverse image load
	//reverse idle
	police_2_idleRev = iLoadImage("image\\police2\\reverse\\IdleRev.png");
	for (int i = 0; i < 8; i++)
	{
		police_2_walkReverse[i] = iLoadImage(p2_walkReverse[i]);
	}

	//image for jump
	//*****police 1*****
	police1JumpUp = iLoadImage("image\\police1\\jump\\Asset1.png");
	police1JumpDown = iLoadImage("image\\police1\\jump\\Asset2.png");
	//*****police 2*****
	police2JumpUp = iLoadImage("image\\police2\\jump\\Asset1.png");
	police2JumpDown = iLoadImage("image\\police2\\jump\\Asset2.png");

	//image for rocket launcher
	police1_rocketImg = iLoadImage("image\\police1\\Asset1.png");
	police2_rocketImg = iLoadImage("image\\police2\\Asset2.png");
}

//function for rendering police character in right direction
void policeMoveRight()
{
	p1.police_x += 5;
	p1.policeWalk_index++;
	if (p1.policeWalk_index >= 8)
	{
		p1.policeWalk_index = 0;
	}
	p1.policeIdleShow = false;
}

//function for rendering police character in left direction
void policeMoveLeft()
{
	p1.police_x -= 5;
	p1.policeWalk_index++;
	if (p1.policeWalk_index >= 8)
	{
		p1.policeWalk_index = 0;
	}
	p1.policeIdleShow = false;
}

/*the following two function is for rendering or moving the police 2 character*/
//function for rendering police character in right direction
void police2MoveRight()
{
	p2.police_x += 5;
	p2.policeWalk_index++;
	if (p2.policeWalk_index >= 8)
	{
		p2.policeWalk_index = 0;
	}
	p2.policeIdleShow = false;
}
//function for rendering police character in left direction
void police2MoveLeft()
{
	p2.police_x -= 5;
	p2.policeWalk_index++;
	if (p2.policeWalk_index >= 8)
	{
		p2.policeWalk_index = 0;
	}
	p2.policeIdleShow = false;
}

//function for shooting
void policeShootChange()
{
	p1.police_attack_index++;
	if (p1.police_attack_index >= 6)
	{
		p1.police_attack_index = 0;
	}
	p1.policeIdleShow = false;
}

/*Police 1 showing. There are two function for the character to show. One is for forward image showing and
another is for reverse image showing.*/
//this function is for showing police character 1 in right direction
void police1RightShow()
{
	if (jump1)
	{
		if (jump1Up)
			iShowImage(p1.police_x, p1.police_y + p1.jumpCoordinate, p1.police_width, p1.police_height, police1JumpUp);
		else
			iShowImage(p1.police_x, p1.police_y + p1.jumpCoordinate, p1.police_width, p1.police_height, police1JumpDown);
		police1_rocket = false;
	}
	else if (police1_rocket)
	{
		iShowImage(p1.police_x, p1.police_y, p1.police_width, p1.police_height, police1_rocketImg);
	}
	else
	{
		if (!p1.policeIdleShow)
		{
			iShowImage(p1.police_x, p1.police_y, p1.police_width, p1.police_height, police_1_walk[p1.policeWalk_index]);
			standcount++;
			if (standcount >= 20)
			{
				standcount = 0;
				p1.policeIdleShow = true;
			}
		}
		//when the button not pressing then it shows the idle image
		else
		{
			iShowImage(p1.police_x, p1.police_y, p1.police_width, p1.police_height, police_1_idle);
		}
		police1_rocket = false;
	}
}

//this function is for showing police character 1 in reverse direction
void police1LeftShow()
{
	if (!p1.policeIdleShow)
	{
		iShowImage(p1.police_x, p1.police_y, p1.police_width, p1.police_height, police_1_walkReverse[p1.policeWalk_index]);
		standcount++;
		if (standcount >= 20)
		{
			standcount = 0;
			p1.policeIdleShow = true;
		}
	}
	//when the button not pressing then it shows the idle image
	else
		iShowImage(p1.police_x, p1.police_y, p1.police_width, p1.police_height, police_1_idleRev);
}

/*Police 2 showing. There are two function for the character to show. One is for forward image showing and
another is for reverse image showing.*/
//this function is for showing police character 2 in right direction
void police2RightShow()
{
	if (jump2)
	{
		if (jump2Up)
		{
			iShowImage(p2.police_x, p2.police_y + p2.jumpCoordinate, p2.police_width, p2.police_height, police2JumpUp);
		}
		else
			iShowImage(p2.police_x, p2.police_y + p2.jumpCoordinate, p2.police_width, p2.police_height, police2JumpDown);
		police2_rokcet = false;
	}
	else if (police2_rokcet)
	{
		iShowImage(p2.police_x, p2.police_y, p2.police_width, p2.police_height, police2_rocketImg);
	}
	else
	{
		if (!p2.policeIdleShow)
		{
			iShowImage(p2.police_x, p2.police_y, p2.police_width, p2.police_height, police_2_walk[p2.policeWalk_index]);
			standcount2++;
			if (standcount2 >= 20)
			{
				standcount2 = 0;
				p2.policeIdleShow = true;
			}
		}
		//when the button not pressing then it shows the idle image
		else
		{
			iShowImage(p2.police_x, p2.police_y, p2.police_width, p2.police_height, police_2_idle);
		}
		police2_rokcet = false;
	}
}

//this function is for showing police character 2 in reverse direction
void police2LeftShow()
{
	if (!p2.policeIdleShow)
	{
		iShowImage(p2.police_x, p2.police_y, p2.police_width, p2.police_height, police_2_walkReverse[p2.policeWalk_index]);
		standcount2++;
		if (standcount2 >= 20)
		{
			standcount2 = 0;
			p2.policeIdleShow = true;
		}
	}
	//when the button not pressing then it shows the idle image
	else
		iShowImage(p2.police_x, p2.police_y, p2.police_width, p2.police_height, police_2_idleRev);
}


//jump change code
//*****police 1 jump*****
void police1JumpChange()
{
	if (jump1)
	{
		if (jump1Up)
		{
			p1.jumpCoordinate += 5;
			if (p1.jumpCoordinate >= POLICEJUMPLIMIT)
			{
				jump1Up = false;
			}
		}
		else
		{
			p1.jumpCoordinate -= 5;
			if (p1.jumpCoordinate <= 0)
			{
				jump1 = false;
				p1.jumpCoordinate = 0;
			}
		}
	}
}

//*****police 2 jump*****
void police2JumpChange()
{
	if (jump2)
	{
		if (jump2Up)
		{
			p2.jumpCoordinate += 5;
			if (p2.jumpCoordinate >= POLICEJUMPLIMIT)
			{
				jump2Up = false;
			}
		}
		else
		{
			p2.jumpCoordinate -= 5;
			if (p2.jumpCoordinate <= 0)
			{
				jump2 = false;
				p2.jumpCoordinate = 0;
			}
		}
	}

}


//the following function is for the collision between police 1 and life gain element.
void collisionBetweenPolice1AndLifeGain()
{
	/***************************there should be changed****the life related problem.**********************/
	if (p1.police_x >= chicken.x && p1.police_x <= chicken.x + chicken.width /*&& p1.police_x + p1.police_width >= chicken.x && p1.police_x + p1.police_width <= chicken.x + chicken.width */&& p1.police_y + p1.jumpCoordinate >= chicken.y && p1.police_y + p1.jumpCoordinate <= chicken.y + chicken.height )//&& p1.police_y + p1.police_height + p1.jumpCoordinate >= chicken.y && p1.police_y + p1.police_height + p1.jumpCoordinate <= chicken.y + chicken.height)
	{
		PL1.pLife_index = 0;
		chicken.show = false;
		chicken.x = 2000 + rand() % 300;
		lifeGainCountDown = 0;
	}
}

//the following function is for the collision between police 2 and life gain element.
void collisionBetweenPolice2AndLifeGain()
{
	/***************************there should be changed****the life related problem.**********************/
	if (p2.police_x >= chicken.x && p2.police_x <= chicken.x + chicken.width /*&& p1.police_x + p1.police_width >= chicken.x && p1.police_x + p1.police_width <= chicken.x + chicken.width */&& p2.police_y + p2.jumpCoordinate >= chicken.y && p2.police_y + p2.jumpCoordinate <= chicken.y + chicken.height)//&& p1.police_y + p1.police_height + p1.jumpCoordinate >= chicken.y && p1.police_y + p1.police_height + p1.jumpCoordinate <= chicken.y + chicken.height)
	{
		PL1.pLife_index = 0;
		chicken.show = false;
		chicken.x = 2000 + rand() % 300;
		lifeGainCountDown = 0;
	}
}

#endif // POLICE_H_INCLUDED
