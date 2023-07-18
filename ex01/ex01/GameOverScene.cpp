#include "GameOverScene.h"
#include "DxLib.h"
#include "SceneManager.h"

int GameOverImage;
int GameOverSE;
int GameOverFlag;

int GameOverScene_Initialize(void)
{
	int ret = 0;
	GameOverImage = LoadGraph("images/gameover.png");
	GameOverSE = LoadSoundMem("sounds/gameover_se.mp3");
	GameOverFlag = FALSE;

	if (GameOverImage == -1)
	{
		ret = -1;
	}
	if (GameOverSE == -1)
	{
		ret = -1;
	}
	return ret;
}

void GameOverScene_Update(void)
{
	if (CheckSoundMem(GameOverSE) == 0)
	{
		if (GameOverFlag == TRUE)
		{
			Change_Scene(E_GAME_OVER);
		}
		else
		{
			PlaySoundMem(GameOverSE, DX_PLAYTYPE_BACK);
			GameOverFlag = TRUE;
		}
	}
}

void GameOverScene_Draw(void)
{
	DrawGraph(0, 0, GameOverImage, FALSE);
}