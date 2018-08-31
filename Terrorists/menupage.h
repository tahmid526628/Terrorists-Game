#pragma once

#include "life.h"
#include "file.h"


#define SCREENWIDTH 1280
#define SCREENHEIGHT 720

bool nextPage[] = { true,false,false };
int nextCount = 1;
bool nextPage1 = false,nextPage2 = false,nextPage3 = false;
int introductionNextButton, introductionBackButton;

int highScorePage;
int defaultPage;
int optionPage;
int creditPage;
int instructionPage,Intro[3],introIndex=0;
int pausedImage;
int gameOverPage;


struct DefaultPage
{
	int x;
	int y;
	int height;
	int width;
}dp;

void setDefaultPageValue()
{
	dp.x = 0;
	dp.y = 0;
	dp.height = SCREENHEIGHT;
	dp.width = SCREENWIDTH;
}

//loading image for default page and other pages
void loadDefaultPage()
{
	defaultPage = iLoadImage("image\\defaultMenu\\menudefault.png");
}
void loadHighScorePage()
{
	highScorePage = iLoadImage("image\\defaultMenu\\HighScore.png");
}
void loadOptionPage()
{
	optionPage = iLoadImage("image\\defaultMenu\\Option.png");
}
void loadCreditPage()
{
	creditPage = iLoadImage("image\\defaultMenu\\Credit.png");
}
void loadInstructionPage()
{
	instructionPage = iLoadImage("image\\defaultMenu\\Instruction.png");
	Intro[0] = iLoadImage("image\\defaultMenu\\ins1.png");
	Intro[1] = iLoadImage("image\\defaultMenu\\ins2.png");
	Intro[2] = iLoadImage("image\\defaultMenu\\ins3.png");
	introductionNextButton = iLoadImage("image\\defaultMenu\\next.png");

	//page for game instraction.
}
void loadPausedImage()
{
	pausedImage = iLoadImage("image\\defaultMenu\\Paused.png");
}
void loadGameOverPage()
{
	gameOverPage = iLoadImage("image\\defaultMenu\\GameOver.png");
}


//showing all menu pages
//default page
void showDefaultPage()
{
	iShowImage(dp.x, dp.y, dp.width, dp.height, defaultPage);
}
//high score page
void showHighScorePage()
{
	showDefaultPage();
	iShowImage(500, 600, 200, 80, highScorePage);
	//iText(400, 300, "Game is under construction", GLUT_BITMAP_TIMES_ROMAN_24);
	scoreShow();
}
//option page
void showOptionPage()
{
	showDefaultPage();
	iShowImage(500, 600, 200, 80, optionPage);
	iText(400, 300, "Game is under construction", GLUT_BITMAP_TIMES_ROMAN_24);
}
//credit page
void showCreditPage()
{
	showDefaultPage();
	iShowImage(500, 600, 200, 80, creditPage);
	iText(400, 400, "TAHMID", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(400, 300, "PRANTICK", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(400, 200, "SHILA", GLUT_BITMAP_TIMES_ROMAN_24);
}
//instruction page
void showInstructionPage()
{
	showDefaultPage();
	iShowImage(500, 600, 200, 80, instructionPage);

	
	if (nextCount == 1)
	{
		//if (nextPage[0] && !nextPage[1] && !nextPage[2]) {
			iShowImage(40, 20, 1200, 500, Intro[0]);
			//nextPage[1] = false;
			//nextPage[2] = false;
		//}
	}
	if (nextCount == 2)
	{
		//if (nextPage[1] && !nextPage[2] && !nextPage[0]) {
			iShowImage(40, 20, 1200, 500, Intro[1]);
			//nextPage[0] = false;
			//nextPage[2] = false;
		//}
	}
	if (nextCount == 3)
	{
		//if (nextPage[2] && !nextPage[1] && !nextPage[0]) {
			iShowImage(40, 20, 1200, 500, Intro[2]);
			//nextPage[0] = false;
			//nextPage[1] = false;
		//}
	}
	iShowImage(1020, 30, 70,40 ,introductionNextButton);
	



	//iText(400, 300, "Press Z", GLUT_BITMAP_TIMES_ROMAN_24);
}

//load game
void showLoadGamePage()
{
	showDefaultPage();
	iSetColor(255, 0, 0);
	iText(400, 450, "Game is under Construction", GLUT_BITMAP_TIMES_ROMAN_24);
}

//game over page
//game over page show when police will die
/*void showGameOverPage()
{
	if (PL1.pLife_index >= 19)
	{
		iClear();
		showDefaultPage();
		iShowImage(500, 400, 200, 80, gameOverPage);
		PL1.lifeShow = false;
		//initialValue();//initial value set
		iClear();
		showMenu();//home menu set
	}
}*/