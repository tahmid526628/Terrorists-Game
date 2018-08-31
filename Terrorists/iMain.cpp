#include "iGraphics.h"
#include "menu.h"
#include "life.h"
#include "police.h"
#include "background.h"
#include "enemy.h"
#include "menupage.h"
#include "bullet.h"
#include "vehicle.h"
#include "file.h"
#include "music.h"

#define SCREENWIDTH 1280
#define SCREENHEIGHT 720

int mposx,  mposy;
int enemy;

int loadCount = 0;
bool musicOn = true;
int snd ;
int soundCount = 1;
int textCount = 0; //for message

//All police related variables decleration and functions in police.h header file
//All background related variables decleration and functions in background.h header file
//All life related variables decleration and functions in life.h header file


//all initial value for starting new game
void initialValueNewGame()
{
	//enemy
	for (int i = 0; i < FIRSTSTAGEENEMY; i++)
	{
		e1[i].enemy_x = 1280 + rand() % 900;
		e1[i].enemy_y = 130;
	}
	//life
	PL1.lifeShow = true;
	PL1.pLife_index = 0;
	//Bullet
}

//loading page essentials
int loadingPageBg;
int loadingBox[5];
int loading;
int gameName;
int loadingCount = 0;
int loadingIndex = 0;
char loadingBoxAr[5][100] = { "image\\loadingPage\\Asset1.png","image\\loadingPage\\Asset2.png" ,"image\\loadingPage\\Asset3.png" ,"image\\loadingPage\\Asset4.png" ,"image\\loadingPage\\Asset5.png" };
//loading page function
void loadingPageShow()
{
	iShowImage(0, 0, SCREENWIDTH, SCREENHEIGHT, loadingPageBg);
	iShowImage(350, 400, 600, 200, gameName);
	iShowImage(500, 200, 300, 80, loadingBox[loadingIndex]);
	iShowImage(600, 150, 100, 50, loading);
	loadingCount++;
	if (loadingCount >= 100)
	{
		loadingIndex++;
		loadingCount = 0;
		if (loadingIndex > 4)
		{
			loadingCount = 0;
			//loadingIndex = 0;
		}
	}

}

void iDraw()
{
	//place your drawing codes here
	iClear();

	//loading page
	loadingPageShow();

	if (loadingIndex > 4)
	{
		iClear();
		showMenu();//showing the Menu background and the buttons
	}
	

	if (startButtonState)
	{
		iClear();
		//comeFromMainMenu = true;
		showNewGamePage();
		//comeFromNewGamePage = false;
		showBackButton();

	}
	if (newGameButtonState)
	{
		iClear();
		
		showCharacterSelectPage();
		snd = 1;
		if (firstCharacter)
		{
			if (level == 0)
			{
				iClear();
				//level = 1;
				backgroundRoadShow();
				snd = 2;

				if (stateRight)
				{
					police1RightShow();//when stateRight is true then policeRightShow() function is called
				}
				if (stateLeft)
				{
					police1LeftShow();//when stateLeft is true then policeLeftShow() function is called
				}

				/*********************************************life related code**************************************/
				if(PL1.lifeShow)
					iShowImage(PL1.pLife_x, PL1.pLife_y, PL1.pLife_width, PL1.pLife_height, policeLife1[PL1.pLife_index]);
				//life regain
				showLifeGain();
				collisionBetweenPolice1AndLifeGain();

				/*if (bulletState)
				{
					showPolice1Bullet();
				}*/

				/************************************enemy showing codes*********************************/
				//enemy showing
				enemyShow();

				/*************************************the following codes for bullets showing***********************************/
				//bullet showing
				setPolice1BulletValue();
				showAndMovePoliceBullet();

				//enemies bullet
				enemyBulletShow();


				//score related code
				sprintf_s(scoreStr, "%d", score);
				iText(100, 590, scoreStr, GLUT_BITMAP_HELVETICA_18);

				//game over page show
				showGameOverPage();
				
			}
		}
		if(secondCharacter)
		{
			if (level == 0)
			{
				iClear();
				backgroundRoadShow();
				/*following code for showing police 2 character*/
				if (stateRight1)
				{
					police2RightShow();//when stateRight1 is true then police2RightShow() function is called
				}
				if (stateLeft1)
				{
					police2LeftShow();//when stateLeft1 is true then police2LeftShow() function is called
				}


				//police life showing
				if (PL1.lifeShow)
					iShowImage(PL1.pLife_x, PL1.pLife_y, PL1.pLife_width, PL1.pLife_height, policeLife1[PL1.pLife_index]);
				//life regain
				showLifeGain();
				collisionBetweenPolice2AndLifeGain();

				/************************************enemy showing codes*********************************/
				//enemy showing
				enemyShow();


				/*************************************the following codes for bullets showing***********************************/
				//bullet showing
				setPolice2BulletValue();
				showAndMovePoliceBullet();
				//collisionBetweenPoliceBulletAndEnemy();

				//enemies bullet
				enemyBulletShow();
				//printf("%d\n", score);
				

				//score related code
				sprintf_s(scoreStr, "%d", score);
				iText(100, 590, scoreStr, GLUT_BITMAP_HELVETICA_18);

				//game over page show
				showGameOverPage();
			}
		}

		if (level == 2)
		{
			
			if(firstCharacter)
			{
				iClear();
				stage2BackgroundShow();//second stage background show
									   /*following code for showing police 1 character*/
				if (stateRight)
				{
					police1RightShow();//when stateRight is true then police1RightShow() function is called
				}
				if (stateLeft)
				{
					police1LeftShow();//when stateLeft is true then police1LeftShow() function is called
				}
				//life show
				if (PL1.lifeShow)
					iShowImage(PL1.pLife_x, PL1.pLife_y, PL1.pLife_width, PL1.pLife_height, policeLife1[PL1.pLife_index]);
				//life regain
				showLifeGain();
				collisionBetweenPolice1AndLifeGain();

				/************************************enemy showing codes*********************************/
				//enemy 1 show
				enemyShow();
				//enemy 2 show
				enemy2Show();
				
				/*************************************the following codes for bullets showing***********************************/
				//bullet showing
				setPolice1BulletValue();
				showAndMovePoliceBullet();

				//enemies bullet
				enemyBulletShow();

				//plane show and it's rocket bomb
				showPlane();
				collisionGroundAndRocketBomb();//this function is for showing blast image
				planeBlastDiePolice1();//collision between police and rocket

				//train show
				trainShow();

			

				//score related code
				sprintf_s(scoreStr, "%d", score);
				iText(100, 590, scoreStr, GLUT_BITMAP_HELVETICA_18);

				//game over page show
				showGameOverPage();

			}
			if (secondCharacter)
			{
				iClear();
				stage2BackgroundShow();//second stage background show

									   /*following code for showing police 2 character*/
				if (stateRight1)
				{
					police2RightShow();//when stateRight1 is true then police2RightShow() function is called
				}
				if (stateLeft1)
				{
					police2LeftShow();//when stateLeft1 is true then police2LeftShow() function is called
				}

				//police life showing
				if (PL1.lifeShow)
					iShowImage(PL1.pLife_x, PL1.pLife_y, PL1.pLife_width, PL1.pLife_height, policeLife1[PL1.pLife_index]);
				//life regain
				showLifeGain();
				collisionBetweenPolice2AndLifeGain();


				/************************************enemy showing codes*********************************/
				//enemy showing
				enemyShow();
				//enemy 2 show
				enemy2Show();


				/*************************************the following codes for bullets showing***********************************/
				//bullet showing
				setPolice2BulletValue();
				showAndMovePoliceBullet();
				//collisionBetweenPoliceBulletAndEnemy();

				//enemies bullet
				enemyBulletShow();

				//plane show and it's rocket bomb
				showPlane();
				collisionGroundAndRocketBomb();//this function is for showing blast image
				planeBlastDiePolice2();//collision between police and rocket

				//train show
				trainShow();

				

				//score related code
				sprintf_s(scoreStr, "%d", score);
				iText(100, 590, scoreStr, GLUT_BITMAP_HELVETICA_18);

				//game over page show
				showGameOverPage();


			}
		}

		/***************************** following lines are for stage three.*************************/
		if (level == 3)
		{
			if (firstCharacter)
			{
				iClear();
				stage3BackgroundShow();//second stage background show
									   /*following code for showing police 1 character*/
				if (stateRight)
				{
					police1RightShow();//when stateRight is true then police1RightShow() function is called
				}
				if (stateLeft)
				{
					police1LeftShow();//when stateLeft is true then police1LeftShow() function is called
				}
				//life show
				if (PL1.lifeShow)
					iShowImage(PL1.pLife_x, PL1.pLife_y, PL1.pLife_width, PL1.pLife_height, policeLife1[PL1.pLife_index]);
				//life regain
				showLifeGain();
				collisionBetweenPolice1AndLifeGain();


				/************************************enemy showing codes*********************************/
				//enemy show
				enemyShow();
				//enemy 2 show
				enemy2Show();


				/*************************************the following codes for bullets showing***********************************/
				//bullet showing
				setPolice1BulletValue();
				showAndMovePoliceBullet();

				//enemies bullet
				enemyBulletShow();

				//plane show and it's rocket bomb
				showPlane();
				collisionGroundAndRocketBomb();//this function is for showing blast image
				planeBlastDiePolice1();//collision between police and rocket

				

				//score related code
				sprintf_s(scoreStr, "%d", score);
				iText(100, 590, scoreStr, GLUT_BITMAP_HELVETICA_18);

				//tank showing lines
				showTank();
				tankBulletCollisionPolice1();

				//some message
				iSetColor(255, 0, 0);
				if (textCount >= 0 && textCount <= 150)
				{
					iText(200, 600, "Remember for destroying Tank you have \nto use rocket launcher and when \nyou move you can't use rocket laucher.\n Press c and then press left mouse button\nto use rocket launcher.", GLUT_BITMAP_HELVETICA_18);
					textCount++;
				}

				//game over page show
				showGameOverPage();

				//game win page show
				winGame();


			}
			if (secondCharacter)
			{
				iClear();
				stage3BackgroundShow();//second stage background show

									   /*following code for showing police 2 character*/
				if (stateRight1)
				{
					police2RightShow();//when stateRight1 is true then police2RightShow() function is called
				}
				if (stateLeft1)
				{
					police2LeftShow();//when stateLeft1 is true then police2LeftShow() function is called
				}

				//police life showing
				if (PL1.lifeShow)
					iShowImage(PL1.pLife_x, PL1.pLife_y, PL1.pLife_width, PL1.pLife_height, policeLife1[PL1.pLife_index]);
				showLifeGain();
				collisionBetweenPolice2AndLifeGain();


				/************************************enemy showing codes*********************************/
				//enemy showing
				enemyShow();
				//enemy 2 show
				enemy2Show();


				/*************************************the following codes for bullets showing***********************************/
				//bullet showing
				setPolice2BulletValue();
				showAndMovePoliceBullet();

				//enemies bullet
				enemyBulletShow();

				//plane show and it's rocket bomb
				showPlane();
				collisionGroundAndRocketBomb();//this function is for showing blast image
				planeBlastDiePolice2();//collision between police and rocket

				
				//score related code
				sprintf_s(scoreStr, "%d", score);
				iText(100, 590, scoreStr, GLUT_BITMAP_HELVETICA_18);

				//tank showing lines
				showTank();
				tankBulletCollisionPolice2();

				//some message
				iSetColor(255, 0, 0);
				if (textCount >= 0 && textCount <= 150)
				{
					iText(200, 600, "Remember for destroying Tank you have \nto use rocket launcher and when \nyou move you can't use rocket laucher.\n Press c and then press left mouse button\nto use rocket launcher.", GLUT_BITMAP_HELVETICA_18);
					textCount++;
				}

				//game over page show
				showGameOverPage();

				//game win page show
				winGame();

			}
		}
	}
	if (loadGameButtonState)
	{
		//load game page
		iClear();
		showLoadGamePage();
		showBackButton();
	}
	if (exitButtonState)//exit
		exit(0);
	if (scoreButtonState)
	{
		//high score page showing block
		iClear();
		showHighScorePage();
		showBackButton();
	}
	if (optionsButtonState)
	{
		//option page showing block
		iClear();
		showOptionPage();
		showBackButton();
	}
	if (creditButtonState)
	{
		//credit page showing block
		iClear();
		showCreditPage();
		showBackButton();
	}
	if (instructionButtonState)
	{
		//instruction page showing
		iClear();
		showInstructionPage();
		showBackButton();
	}
	//back logic
	if (backButtonState && comeFromNewGamePage)
	{
		iClear();
		showNewGamePage();
		showBackButton();		
	}
	if (backButtonState && comeFromMainMenu)
	{
		//this block is for back button
		iClear();
		showMenu();
	}
	if (pause)
	{
		//this is for pause the game
		pausePage();
	}
	/*if (quitToMainMenuState)
	{
		//this block is for showing the menu after pressing Quit To Main Menu button 
		iClear();
		showMenu();
	}*/
	
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (mx >= 100 && mx <= 100 + BUTTONWIDTH && my >= 300 && my <= 300 + BUTTONHEIGHT && !optionsButtonState && !scoreButtonState && !instructionButtonState && !creditButtonState && !exitButtonState && !newGameButtonState && !loadGameButtonState)
		{
			startButtonState = true;
			optionsButtonState = false;
			scoreButtonState = false;
			instructionButtonState = false;
			creditButtonState = false;
			exitButtonState = false;
			newGameButtonState = false;
			loadGameButtonState = false;
			backButtonState = false;
			quitToMainMenuState = false;
			InitialSiren(true);

			comeFromMainMenu = true;
			comeFromNewGamePage = false;
		}
		if (mx >= 100 && mx <= 100 + BUTTONWIDTH && my >= 200 && my <= 200 + BUTTONHEIGHT && !scoreButtonState && !instructionButtonState && !creditButtonState && !exitButtonState && !newGameButtonState && !loadGameButtonState && !startButtonState)
		{
			optionsButtonState = true;
			scoreButtonState = false;
			instructionButtonState = false;
			creditButtonState = false;
			exitButtonState = false;
			newGameButtonState = false;
			loadGameButtonState = false;
			backButtonState = false;
			startButtonState = false;
			quitToMainMenuState = false;
			LevelChange(true);

			comeFromMainMenu = true;
			comeFromNewGamePage = false;
		}
		if (mx >= 100 && mx <= 100 + BUTTONWIDTH && my >= 100 && my <= 100 + BUTTONHEIGHT && !instructionButtonState && !creditButtonState && !exitButtonState && !newGameButtonState && !loadGameButtonState && !startButtonState && !optionsButtonState)
		{
			scoreButtonState = true;
			instructionButtonState = false;
			creditButtonState = false;
			exitButtonState = false;
			newGameButtonState = false;
			loadGameButtonState = false;
			backButtonState = false;
			startButtonState = false;
			optionsButtonState = false;
			quitToMainMenuState = false;
			WarShootingMusic(true);

			comeFromMainMenu = true;
			comeFromNewGamePage = false;
		}
		if (mx >= 400 && mx <= 400 + BUTTONWIDTH && my >= 300 && my <= 300 + BUTTONHEIGHT && !creditButtonState && !exitButtonState && !newGameButtonState && !loadGameButtonState && !startButtonState && !optionsButtonState && !scoreButtonState)
		{
			instructionButtonState = true;
			creditButtonState = false;
			exitButtonState = false;
			newGameButtonState = false;
			loadGameButtonState = false;
			backButtonState = false;
			startButtonState = false;
			optionsButtonState = false;
			scoreButtonState = false;
			quitToMainMenuState = false;
			LevelChange(true);

			comeFromMainMenu = true;
			comeFromNewGamePage = false;
		}
		if (mx >= 400 && mx <= 400 + BUTTONWIDTH && my >= 200 && my <= 200 + BUTTONHEIGHT && !exitButtonState && !newGameButtonState && !loadGameButtonState && !startButtonState && !optionsButtonState && !scoreButtonState && !instructionButtonState)
		{
			creditButtonState = true;
			exitButtonState = false;
			newGameButtonState = false;
			loadGameButtonState = false;
			backButtonState = false;
			startButtonState = false;
			optionsButtonState = false;
			scoreButtonState = false;
			instructionButtonState = false;
			quitToMainMenuState = false;
			GunSingleShoot(true);

			comeFromMainMenu = true;
			comeFromNewGamePage = false;
		}
		if (mx >= 400 && mx <= 400 + BUTTONWIDTH && my >= 100 && my <= 100 + BUTTONHEIGHT && !newGameButtonState && !loadGameButtonState && !startButtonState && !optionsButtonState && !scoreButtonState && !instructionButtonState && !creditButtonState)
		{
			exitButtonState = true;
			newGameButtonState = false;
			loadGameButtonState = false;
			backButtonState = false;
			startButtonState = false;
			optionsButtonState = false;
			scoreButtonState = false;
			instructionButtonState = false;
			creditButtonState = false;
			quitToMainMenuState = false;
		}
		if (mx >= 500 && mx <= 500 + BUTTONWIDTH && my >= 450 && my <= 450 + BUTTONHEIGHT && !loadGameButtonState && !optionsButtonState && !scoreButtonState && !instructionButtonState && !creditButtonState && !exitButtonState && startButtonState)
		{
			newGameButtonState = true;
			loadGameButtonState = false;
			backButtonState = false;
			startButtonState = false;
			optionsButtonState = false;
			scoreButtonState = false;
			instructionButtonState = false;
			creditButtonState = false;
			exitButtonState = false;
			quitToMainMenuState = false;
		}
		if (mx >= 500 && mx <= 500 + BUTTONWIDTH && my >= 350 && my <= 350 + BUTTONHEIGHT && !optionsButtonState && !scoreButtonState && !instructionButtonState && !creditButtonState && !exitButtonState && !newGameButtonState && startButtonState)
		{
			loadGameButtonState = true;
			backButtonState = false;
			startButtonState = false;
			optionsButtonState = false;
			scoreButtonState = false;
			instructionButtonState = false;
			creditButtonState = false;
			exitButtonState = false;
			newGameButtonState = false;
			quitToMainMenuState = false;

			comeFromMainMenu = true;
			comeFromNewGamePage = false;
		}
		if (mx >= 50 && mx <= 50 + 100 && my >= 40 && my <= 40 + 50 && !newGameButtonState)
		{
			backButtonState = true;
			startButtonState = false;
			optionsButtonState = false;
			scoreButtonState = false;
			instructionButtonState = false;
			creditButtonState = false;
			exitButtonState = false;
			newGameButtonState = false;
			loadGameButtonState = false;
			quitToMainMenuState = false;
		}
		if (mx >= 500 && mx <= 500 + BUTTONWIDTH && my >= 500 && my <= 500 + BUTTONHEIGHT)//&& !optionsButtonState && !scoreButtonState && !instructionButtonState && !creditButtonState && !loadGameButtonState && !quitToMainMenuState)
		{
			iResumeTimer(0);
			iResumeTimer(1);
			iResumeTimer(2);
			iResumeTimer(3);
			iResumeTimer(4);
			iResumeTimer(5);
			iResumeTimer(6);
			iResumeTimer(7);
			iResumeTimer(8);
			iResumeTimer(9);
			pause = false;
		}
		/*if (mx >= 500 && mx <= 500 + BUTTONWIDTH && my >= 350 && my <= 350 + 100 && !optionsButtonState && !scoreButtonState && !instructionButtonState && !creditButtonState && !exitButtonState && !loadGameButtonState)
		{
			quitToMainMenuState = true;
			backButtonState = false;
			startButtonState = false;
			optionsButtonState = false;
			scoreButtonState = false;
			instructionButtonState = false;
			creditButtonState = false;
			exitButtonState = false;
			newGameButtonState = false;
			loadGameButtonState = false;
			//pause = true;
		}*/

		//next button logic in instruction page
		if (mx >= 1020 && mx <= 1020 + 70 && my >= 30 && my <= 30 + 40)
		{
			nextCount += 1;
			if (nextCount > 3)
			{
				nextCount = 1;
			}
		}

		if (firstCharacter || secondCharacter)
		{
			bullets[k].show = true;
			k++;

			if (k >= 12)
				k = 0;
		}
		
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouse(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == 'd')
	{
		/*when pressing 'd' the stateLeft becomes false and stateRight becomes true that's why the reverse image not showing.
		Then when x-coordinate of police 1 is greater than 1200 then the road background moves and when less than 1200 then
		policeMoveRight() funtion is called.
		*/
		stateLeft = false;
		stateRight = true;
		if (p1.police_x <= 600)
		{
			policeMoveRight();
		}
		
		if (p1.police_x >= 600)
		{
			roadBackgroundChange();
			//p1.police1_x += 5;
			p1.policeWalk_index++;
			if (p1.policeWalk_index >= 8)
			{
				p1.policeWalk_index = 0;
			}
			p1.policeIdleShow = false;
		}
	}
	if (key == 'a')
	{
		/*when pressing 'a' the stateLeft becomes true and stateRight becomes false that's why the reverse image showing.
		Then policeMoveLeft() function is called.
		*/
		stateRight = false;
		stateLeft = true;
		if (p1.police_x >= 55)
		{
			policeMoveLeft();
		}
	}
	if (key == 'n')
	{
		level = 2;
		Level02Music(true);
	}
	if (key == 'm')
	{
		level = 3;
	}
	if (key == 'p')
	{
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
		iPauseTimer(3);
		iPauseTimer(4);
		iPauseTimer(5);
		iPauseTimer(6);
		iPauseTimer(7);
		iPauseTimer(8);
		iPauseTimer(9);

		pause = true;
	}
	if (key == '1')
	{
		firstCharacter = true;
		Level01Music(true);
		soundCount = 2;
		initialValueNewGame();
	}
	if (key == '2')
	{
		secondCharacter = true;
		soundCount = 2;
		initialValueNewGame();
		//PlaySound("music\\menu.wav", NULL, SND_LOOP);
	}

	if (key == 'j')//police 1 jump key
	{
		if (!jump1)
		{
			jump1 = true;
			jump1Up = true;
		}
	}

	if (key == ' ')//police 2 jump key
	{
		if (!jump2)
		{
			jump2 = true;
			jump2Up = true;
		}
	}
	if (key == 'c')
	{
		if (level == 3)
		{
			police1_rocket = true;
			police2_rokcet = true;
		}
	}
		
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_RIGHT)
	{
		/*when pressing 'right key' the stateLeft1 becomes false and stateRight1 becomes true that's why the reverse image not showing.
		Then when x-coordinate of police 2 is greater than 1200 then the road background moves and when less than 1200 then
		policeMoveRight() funtion is called.
		*/
		stateLeft1 = false;
		stateRight1 = true;
		if (p2.police_x <= 600)
		{
			police2MoveRight();
		}

		if (p2.police_x >= 600)
		{
			roadBackgroundChange();
			//p2.police1_x += 5;
			p2.policeWalk_index++;
			if (p2.policeWalk_index >= 8)
			{
				p2.policeWalk_index = 0;
			}
			p2.policeIdleShow = false;
		}
	}
	if (key == GLUT_KEY_LEFT) 
	{
		stateRight1 = false;
		stateLeft1 = true;
		if (p2.police_x >= 55)
		{
			police2MoveLeft();
		}
	}

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}





int main()
{
	
	//place your own initialization codes here.
	iInitialize(SCREENWIDTH, SCREENHEIGHT, "Terrorists");


	setButtonValue();//setting value of coordinates of buttons
	loadMenu();//image loading for buttons and menu background
	//InitialSiren(true);
	backgroundSet();
	backgroundSetValue();
	iSetTimer(50, backgroundChange);
	//third stage tree render
	//iSetTimer(20, changeTree);

	

	/*****************************************************life related code******************************************************/
	policeLifeSet();
	policeLifeSetValue();
	lifeGainSetValue();
	iSetTimer(40, changeLifeGain);
	
	policeMoveSet();
	police1SetValue();
	//iSetTimer(40, police1Change);

	police2SetValue();//police 2 set value function call 


	/***********************************************The following codes are for enemies********************************************/
	//enemy move
	enemyMoveSet();
	enemy1SetValue();
	iSetTimer(20, enemyMoveLeft);
	//enemy 2 value set and move
	enemy2SetValue();
	iSetTimer(25, enemy2MoveLeft);
	//iSetTimer(20, changeIndex);


	//default page set
	setDefaultPageValue();
	loadDefaultPage();
	loadHighScorePage();
	loadOptionPage();
	loadCreditPage();
	loadInstructionPage();
	loadPausedImage();

	//initialValue();

	//load bullet image
	loadBullet();

	//bullet of enemies related things
	setEnemyBulletValue();
	iSetTimer(10, enemyBulletChangeForPolice1);//this function renders enemies bullet and decrease the life of police when collision occure
	iSetTimer(10, enemyBulletChangeForPolice2);//this function for collision of police 2


	//bullet related police
	//iSetTimer(5, collisionBetweenPoliceBulletAndEnemy);


	//load image for vehicle
	loadVehicleImage();
	//move function for plane it's rocket bomb
	iSetTimer(100, planeChange);

	//game over page load
	loadGameOverPage();

	//for police jumping
	iSetTimer(15, police2JumpChange);//police 2 jump
	iSetTimer(15, police1JumpChange);//police 1 jump
	
	
	//loading page eesentials load
	for (int i = 0; i < 5; i++)
	{
		loadingBox[i] = iLoadImage(loadingBoxAr[i]);
	}
	loading = iLoadImage("image\\loadingPage\\loading.png");
	gameName = iLoadImage("image\\name.png");
	loadingPageBg = iLoadImage("image\\loadingPage\\loadingBG.png");

	
	//level change
	iSetTimer(20, levelchange);

	//tank
	setValueOfTank();
	//iSetTimer(20, moveEnemyTank);
	//iSetTimer(20, rocket);
	//iSetTimer(15, tankBulletCollisionPolice2);


	iStart();
	//return 0;
}
