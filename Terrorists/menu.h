#include "menupage.h"
//#include "allvalue.h"
//#include "bullet.h"
#include "enemy.h"
#include "police.h"
#include"file.h"
#include "vehicle.h"



#define BUTTONWIDTH 200
#define BUTTONHEIGHT 50

//following variable are related to menu buttons
bool startButtonState = false;
bool optionsButtonState = false;
bool scoreButtonState = false;
bool instructionButtonState = false;
bool creditButtonState = false;
bool exitButtonState = false;
bool newGameButtonState = false;
bool loadGameButtonState = false;
bool backButtonState = false;
bool resumeButtonState = false;
bool quitToMainMenuState = false;
bool pause = false;
int level = 0;

//back logic
bool comeFromMainMenu = false;
bool comeFromNewGamePage = false;

int menu_bg, startButton, optionsButton, scoreButton, instructionButton, creditButton, exitButton;
int newGameButton;
int loadGameButton;
int backButton;
int resumeButton;
int quitToMainMenuButton;

//character selection
int firstCharacterImg;
int secondCharacterImg;
bool firstCharacter;
bool secondCharacter;

//after game over page show
int gameOverCount = 1;
bool gameOver = false;

//game win page
int winBg;
int win;
int winCount = 0;

struct Button
{
	int start_x;
	int start_y;
	int option_x;
	int option_y;
	int score_x;
	int score_y;
	int instruct_x;
	int instruct_y;
	int credit_x;
	int credit_y;
	int exit_x;
	int exit_y;
	int newGame_x;
	int newGame_y;
	int loadGame_x;
	int loadGame_y;
	int back_x;
	int back_y;
	int resume_x;
	int resume_y;
	int quitToMenu_x;
	int quitToMenu_y;
	int firstChar_x;
	int firstChar_y;
	int secondChar_x;
	int secondChar_y;
}button;

void setButtonValue()
{
	button.start_x = 100;
	button.start_y = 300;
	button.option_x = 100;
	button.option_y = 200;
	button.score_x = 100;
	button.score_y = 100;
	button.instruct_x = 400;
	button.instruct_y = 300;
	button.credit_x = 400;
	button.credit_y = 200;
	button.exit_x = 400;
	button.exit_y = 100;
	button.newGame_x = 500;
	button.newGame_y = 450;
	button.loadGame_x = 500;
	button.loadGame_y = 350;
	button.back_x = 50;
	button.back_y = 40;
	button.resume_x = 500;
	button.resume_y = 500;
	button.quitToMenu_x = 500;
	button.quitToMenu_y = 350;
	button.firstChar_x = 300;
	button.firstChar_y = 350;
	button.secondChar_x = 700;
	button.secondChar_y = 350;

}

void loadMenu()
{
	menu_bg = iLoadImage("image\\menu background.png");
	startButton = iLoadImage("image\\Start.png");
	optionsButton = iLoadImage("image\\Options.png");
	scoreButton = iLoadImage("image\\HighScore.png");
	instructionButton = iLoadImage("image\\Instruction.png");
	creditButton = iLoadImage("image\\Credit.png");
	exitButton = iLoadImage("image\\Exit.png");
	newGameButton = iLoadImage("image\\NewGame.png");
	loadGameButton = iLoadImage("image\\Load.png");
	backButton = iLoadImage("image\\Back.png");
	quitToMainMenuButton = iLoadImage("image\\QuitMainMenu.png");
	resumeButton = iLoadImage("image\\Resume.png");
	firstCharacterImg = iLoadImage("image\\1st.png");
	secondCharacterImg = iLoadImage("image\\2nd.png");
	winBg = iLoadImage("image\\winBG.jgp");
	win = iLoadImage("image\\win.png");
}

void showMenu()
{
	iShowImage(0, 0, 1280, 720, menu_bg);
	iShowImage(button.start_x, button.start_y, BUTTONWIDTH, BUTTONHEIGHT, startButton);
	iShowImage(button.option_x, button.option_y, BUTTONWIDTH, BUTTONHEIGHT, optionsButton);
	iShowImage(button.score_x, button.score_y, BUTTONWIDTH, BUTTONHEIGHT, scoreButton);
	iShowImage(button.instruct_x, button.instruct_y, BUTTONWIDTH, BUTTONHEIGHT, instructionButton);
	iShowImage(button.credit_x, button.credit_y, BUTTONWIDTH, BUTTONHEIGHT, creditButton);
	iShowImage(button.exit_x, button.exit_y, BUTTONWIDTH, BUTTONHEIGHT, exitButton);
}

//new game and load game page
void showNewGamePage()
{
	showDefaultPage();
	iShowImage(button.newGame_x, button.newGame_y, BUTTONWIDTH, BUTTONHEIGHT, newGameButton);
	iShowImage(button.loadGame_x, button.loadGame_y, BUTTONWIDTH, BUTTONHEIGHT, loadGameButton);
}

//back button
void showBackButton()
{
	iShowImage(button.back_x, button.back_y, 100, 50, backButton);
}

//resume button
void showResumeButton()
{
	iShowImage(button.resume_x, button.resume_y, BUTTONWIDTH, BUTTONHEIGHT, resumeButton);
}

//quit to main menu button
void showQuitToMainMenuButton()
{
	iShowImage(button.quitToMenu_x, button.quitToMenu_y, BUTTONWIDTH, 100, quitToMainMenuButton);
}

//pause page
void pausePage()
{
	//iPauseTimer(0);
	showDefaultPage();
	showResumeButton();
	showQuitToMainMenuButton();
	iShowImage(500, 600, 200, 80, pausedImage);
	//iText(400, 450, "The game is Paused", GLUT_BITMAP_TIMES_ROMAN_24);
}

//character choosing page
void showCharacterSelectPage()
{
	iShowImage(button.firstChar_x, button.firstChar_y, 200, 200, firstCharacterImg);
	iShowImage(button.secondChar_x, button.secondChar_y, 200, 200, secondCharacterImg);
	iText(500, 200, "Press 1 to select Character 1 and press 2 to select Character 2", GLUT_BITMAP_TIMES_ROMAN_24);
}



//all initial value for starting new game
void initialValue()
{
	//enemy
	/*for (int i = 0; i < FIRSTSTAGEENEMY; i++)
	{
		e1[i].enemy_x = 1280 + rand() % 900;
		e1[i].enemy_y = 130;
		//eB1[i].x = 950;
	}*/

	//life
	PL1.lifeShow = true;
	PL1.pLife_index = 0;
	//Bullet
	//cnt = 0;
	//initialBulletValue();
	//menu
	startButtonState = false;
	optionsButtonState = false;
	scoreButtonState = false;
	instructionButtonState = false;
	creditButtonState = false;
	exitButtonState = false;
	newGameButtonState = false;
	loadGameButtonState = false;
	backButtonState = false;
	resumeButtonState = false;
	//quitToMainMenuState = false;
	pause = false;

	comeFromMainMenu = false;
	comeFromNewGamePage = false;

	//k = 0;//bullet global variable
	level = 0;
	score = 0;
	police1SetValue();
	police2SetValue();
	enemy1SetValue();
	enemy2SetValue();
	enemy2ComingCountDown = 0;
	enemy2KillCountDown = 0;
	//setEnemyBulletValue();

	firstCharacter = false;
	secondCharacter = false;

	//tank
	eTank.x = 2000;
	eTank.y = 130;
	tankBullet_x = 750;
	tankBullet_show = false;

	//police rocket launcher
	police1_rocket = false;
	police2_rokcet = false;

}


//game over page
void showGameOverPage()
{
	if (PL1.pLife_index >= 19)
	{
		iClear();
		//User player();
		showDefaultPage();
		iShowImage(500, 400, 200, 80, gameOverPage);

		//score related code
		sprintf_s(scoreStr, "%d", score);
		iText(500, 300, "Your Score: ", GLUT_BITMAP_HELVETICA_18);
		iText(650, 300, scoreStr, GLUT_BITMAP_HELVETICA_18);

		//highscore calculation
		scoreCalculation();
		//scoreShow();

		PL1.lifeShow = false;
		gameOverCount++;
		if (gameOverCount >= 150)
		{
			initialValue();//initial value set
			iClear();
		    showMenu();//home menu set
		}
		//initialValue();//initial value set
		//iClear();
		//showMenu();//home menu set
	}
}

//game win page
void winGame()
{
	if (tankDestroy)
	{
		iClear();
		initialValue();
		iShowImage(0, 0, 1280, 720, winBg);
		iShowImage(600, 300, 200, 120, win);
		winCount++;
		if (winCount >= 150)
		{
			iClear();
			showMenu();
		}
	}
}