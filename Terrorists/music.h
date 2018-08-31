void Bomb(bool n) {

	if (n)
		PlaySound("music\\Bomb\\bomb.wav", NULL, SND_ASYNC);
	else
		PlaySound(0,0,0);
}

void BossInitial(bool n) {

	if (n)
		PlaySound("music\\boss\\iWillKillYou.wav", NULL, SND_ASYNC);
	else
		PlaySound(0, 0, 0);
}

void InitialSiren(bool n) {

	if (n)
		PlaySound("music\\initial\\Siren.wav", NULL, SND_ASYNC);
	else
		PlaySound(0, 0, 0);
}

void LevelChange(bool n) {

	if (n)
		PlaySound("music\\levelChange\\levelChange.wav", NULL, SND_ASYNC);
	else
		PlaySound(0, 0, 0);
}

void Level01Music(bool n) {

	if (n)
		PlaySound("music\\LevelMusic\\01.wav", NULL, SND_LOOP | SND_ASYNC);
	else
		PlaySound(0, 0, 0);
}

void Level02Music(bool n) {

	if (n)
		PlaySound("music\\LevelMusic\\02.wav", NULL, SND_LOOP | SND_ASYNC);
	else
		PlaySound(0, 0, 0);
}

void Level03Music(bool n) {

	if (n)
		PlaySound("music\\LevelMusic\\03.wav", NULL, SND_LOOP | SND_ASYNC);
	else
		PlaySound(0, 0, 0);
}

void Level03BossStrike(bool n) {

	if (n)
		PlaySound("music\\LevelMusic\\03boss.wav", NULL, SND_ASYNC);
	else
		PlaySound(0, 0, 0);
}

void GunReload(bool n) {

	if (n)
		PlaySound("music\\Reload\\reload.wav", NULL, SND_ASYNC);
	else
		PlaySound(0, 0, 0);
}

void GunSingleShoot(bool n) {

	if (n)
		PlaySound("music\\singleShot\\gunShot.wav", NULL, SND_ASYNC);
	else
		PlaySound(0, 0, 0);
}

void WarShootingMusic(bool n) {

	if (n)
		PlaySound("music\\warShooting\\warShoot.wav", NULL, SND_ASYNC);
	else
		PlaySound(0, 0, 0);
}

