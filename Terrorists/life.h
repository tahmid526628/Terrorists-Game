#ifndef LIFE_H_INCLUDED
#define LIFE_H_INCLUDED

#include "menupage.h"

//Police Life
int policeLife1[20];
char pLife1[20][50] = {"image\\policelife\\Asset 1.png","image\\policelife\\Asset 2.png","image\\policelife\\Asset 3.png","image\\policelife\\Asset 4.png" ,"image\\policelife\\Asset 5.png" ,"image\\policelife\\Asset 6.png" ,"image\\policelife\\Asset 7.png" ,"image\\policelife\\Asset 8.png" ,"image\\policelife\\Asset 9.png" ,"image\\policelife\\Asset 10.png" ,"image\\policelife\\Asset 11.png" ,"image\\policelife\\Asset 12.png" ,"image\\policelife\\Asset 13.png" ,"image\\policelife\\Asset 14.png" ,"image\\policelife\\Asset 15.png" ,"image\\policelife\\Asset 16.png" ,"image\\policelife\\Asset 17.png" ,"image\\policelife\\Asset 18.png","image\\policelife\\Asset 19.png" ,"image\\policelife\\Asset 20.png"};


//life gain
int lifeGain;
int lifeGainCountDown = 0;

struct LifeGain
{
	int x;
	int y;
	int width;
	int height;
	bool show;
};
LifeGain chicken;

struct PoliceLife
{
	int pLife_x;
	int pLife_y;
	int pLife_width;
	int pLife_height;
	int pLife_index;
	bool lifeShow = false;
};
PoliceLife PL1;

//image load for life
void policeLifeSet()
{
	for (int i = 0; i < 20; i++)
	{
		policeLife1[i] = iLoadImage(pLife1[i]);
	}

	//image loading for life gaining chicken
	lifeGain = iLoadImage("image\\LifeGain.png");
}

//setting or assigning values in variables
void policeLifeSetValue()
{
	PL1.pLife_x = 50;
	PL1.pLife_y = 630;
	PL1.pLife_width = 250;
	PL1.pLife_height = 50;
	PL1.pLife_index = 0;
	PL1.lifeShow = true;
}


//the following function is for setting value of life gain element
void lifeGainSetValue()
{
	chicken.x = 4000 + rand() % 300;
	chicken.y = 300;
	chicken.width = 50;
	chicken.height = 40;
	chicken.show = false;
}

void changeLifeGain()
{
	//if ()
	//{
		chicken.x -= 3;
		if (chicken.x <= 0)
		{
			chicken.x = 1000 + rand() % 300;
			chicken.y = 300 + rand() % 500;
			if (chicken.y >= 400)
			{
				chicken.y = 250;
			}
		}
		/*if (chicken.x <= 500 + rand() % 100)
		{
			chicken.show = true;
		}*/
	//}
}

//flollowing function is for showing life gain
void showLifeGain()
{
	//if (chicken.show)
	//{
	iShowImage(chicken.x, chicken.y, chicken.width, chicken.height, lifeGain);
		/*lifeGainCountDown++;
		if (lifeGainCountDown >= 300)
		{
			chicken.show = false;
			lifeGainCountDown = 0;
		}
	}*/
}


#endif // LIFE_H_INCLUDED
