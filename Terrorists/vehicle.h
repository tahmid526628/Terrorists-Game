#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#define ROADCOORDINATE_Y 130
#define BLASTWIDTH 150
#define BLASTHEIGHT 90

#define TANKSPEED 1

int imagePlane,imagePlaneBomb;//for image loading
int planeCordinateX = 1100;
int planeCordinateY = 550;

//variable for plane rocket bomb
int planeBombCordinateX = planeCordinateX + 50;
int planeBombCordinateY = 550;
bool showPlaneBomb = true;
bool blastDie = false;

int blast1Image;//blast image variable


//variables for canon
int tankCount = 0;
int enemyTank;
int policeTank;
int tankBullet;
int tankBullet_x = 750;
int tankBullet_y = 240;
int tankBullet_width = 50;
int tankBullet_height = 10;
bool tankBullet_show = false;
bool tankDestroy = false;

struct Tank
{
	int x;
	int y;
	int width;
	int height;
	int show;
}eTank,pTank;

// image load function for vehicle
void loadVehicleImage()
{
	//aeroplane
    imagePlane = iLoadImage("image\\vehicle\\plane.png");
	imagePlaneBomb = iLoadImage("image\\fireObject\\RocketBomb1.png");
	blast1Image = iLoadImage("image\\fireObject\\Blast1.png");

	//canon/tank
	enemyTank = iLoadImage("image\\vehicle\\enemyTank.png");
	policeTank = iLoadImage("image\\vehicle\\tank.png");
	tankBullet = iLoadImage("image\\fireObject\\tankBullet.png");

}

//function for plane moving
void planeChange() {

	planeCordinateX -= rand() % 100 + 7;
	if (planeCordinateX <= 0)
	{
		planeCordinateX = 1290;
	}

	planeBombCordinateY -= 12;
	if (planeBombCordinateY <= ROADCOORDINATE_Y - 5) {

		planeBombCordinateX = planeCordinateX + 50;
		planeBombCordinateY = 550;
	}

}

//function for showing plane and its rocket bomb
void showPlane()
{
	iShowImage(planeCordinateX, planeCordinateY, 200, 200, imagePlane);
	iShowImage(planeBombCordinateX, planeBombCordinateY, 50, 50, imagePlaneBomb);
}

//function for showing blast image i.e. this function is for making collision between road and plane rocket bomb
void collisionGroundAndRocketBomb()
{
	if (planeBombCordinateY <= ROADCOORDINATE_Y)
	{
		iShowImage(planeBombCordinateX - 50, ROADCOORDINATE_Y, BLASTWIDTH, BLASTHEIGHT, blast1Image);
		/*planeBombCordinateX = planeCordinateX + 50;
		planeBombCordinateY = 550;*/
		blastDie = true;
		
	}
}
//collision code between plane rocket and police 1
void planeBlastDiePolice1()
{
	if (blastDie && p1.police_x + p1.police_width >= planeBombCordinateX - 50 && p1.police_x + p1.police_width <= planeBombCordinateX - 50 + BLASTWIDTH)
	{
		PL1.pLife_index = 19;
		blastDie = false;
	}
}

//collision code between plane rocket and police 2
void planeBlastDiePolice2()
{
	if (blastDie && p2.police_x + p2.police_width >= planeBombCordinateX - 50 && p2.police_x + p2.police_width <= planeBombCordinateX - 50 + BLASTWIDTH)
	{
		PL1.pLife_index = 19;
		blastDie = false;
	}
}



/*the following codes are related to tank both for police and terrorists*/

//the following function is for setting value of tank
void setValueOfTank()
{
	//terrorists tank
	eTank.x = 2000;
	eTank.y = 130;
	eTank.width = 350;
	eTank.height = 170;
	eTank.show = false;
	//police tank
	/*pTank.x = 300;
	pTank.y = 130;
	pTank.width = 400;
	pTank.height = 200;
	pTank.show = true;
	*/
}


/*
//moving function of tank
void moveEnemyTank()
{
	if (level == 3)
	{
		if (score >= 1200 && eTank.x >= 750)
		{
			eTank.x = eTank.x - 20;
		}

		if (tankBullet_show)
		{
			tankBullet_x -= 10;
			if (tankBullet_x <= 0)
			{
				tankBullet_x = 750;
			}
			if (tankBullet_x <= p2.police_x + p2.police_width && eTank.x >= p2.police_x  && eTank.y >= p2.police_y + p2.jumpCoordinate && eTank.y <= p2.police_y + p2.police_height + p2.jumpCoordinate)
			{
				PL1.pLife_index = 19;
				tankBullet_x = 750;
			}
			if (tankBullet_x <= p1.police_x + p1.police_width && eTank.x >= p1.police_x  && eTank.y >= p1.police_y + p1.jumpCoordinate && eTank.y <= p1.police_y + p1.police_height + p1.jumpCoordinate)
			{
				PL1.pLife_index = 19;
				tankBullet_x = 750;
			}
		}
	}
}
*/

void tankBulletCollisionPolice2()
{
	if (tankBullet_show)
	{
		tankBullet_x -= 15;
		if (tankBullet_x <= 0)
		{
			tankBullet_x = 750;
		}
		if (tankBullet_x <= p2.police_x + p2.police_width && eTank.x >= p2.police_x  && eTank.y >= p2.police_y + p2.jumpCoordinate && eTank.y <= p2.police_y + p2.police_height + p2.jumpCoordinate)
		{
			PL1.pLife_index = 19;
			tankBullet_x = 750;
		}
	}
}

void tankBulletCollisionPolice1()
{
	if (tankBullet_show)
	{
		tankBullet_x -= 5;
		if (tankBullet_x <= 0)
		{
			tankBullet_x = 750;
			tankCount = 0;
		}
		if (tankBullet_x <= p1.police_x + p1.police_width && eTank.x >= p1.police_x  && eTank.y >= p1.police_y + p1.jumpCoordinate && eTank.y <= p1.police_y + p1.police_height + p1.jumpCoordinate)
		{
			PL1.pLife_index = 19;
			tankBullet_x = 750;
			tankCount = 0;
		}
	}
}

//show function for tank
void showTank()
{
	if (score >= 1200)
	{
		iShowImage(eTank.x, eTank.y, eTank.width, eTank.height, enemyTank);
		//iPauseTimer(7);
		if (/*score >= 1200 &&*/ eTank.x >= 750)
		{
			eTank.x = eTank.x - TANKSPEED;
		}
	}
	/*if (score >= 1200 && level == 3)
	{
		iShowImage(pTank.x, pTank.y, pTank.width, pTank.height, policeTank);
	}*/
	if (eTank.x <= 765)
	{
		tankCount++;
		if (tankCount >= 50)
		{
			iShowImage(tankBullet_x, tankBullet_y, tankBullet_width, tankBullet_height, tankBullet);
			tankBullet_show = true;
		}
	}
}
#endif // VEHICLE_H_INCLUDED
