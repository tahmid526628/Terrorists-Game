#pragma warning (disable : 4996)
#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
//#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_NO_DEPRECATE 

#include<stdlib.h>
#include<string.h>
#include "police.h"
//this header is for saving the game. here we use file
/*struct User
{
	char name[100];
	int score;
	int level;
	int life_index;

	User()
	{
		;
	}

	User(char *_name, int _score, int _level, int _life_index)
	{
		strcpy(name, _name);
		score = _score;
		level = _level;
		life_index = _life_index;
	}



}player;
*/

void scoreCalculation()
{
	newScore = score;

	FILE *fp = fopen("score.txt", "r");

	fscanf_s(fp, "%d", &highScore);


	if (newScore > highScore) {
		highScore = newScore;

		FILE *fp = fopen("score.txt", "w");

		fprintf_s(fp, "%d", highScore);
	}
	fclose(fp);

}


void scoreShow()
{
	FILE *fp = fopen("score.txt", "r");

	fscanf_s(fp, "%d", &highScore);

	iSetColor(200, 0, 0);
	itoa(highScore, highScoreStr, 10);
	iText(450, 300, "High Score: ", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(600, 300, highScoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
	fclose(fp);

}


#endif // FILE_H_INCLUDED
