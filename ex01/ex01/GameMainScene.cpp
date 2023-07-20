#include"GameMainScene.h"
#include"DxLib.h"
#include"Stage.h"
#include"SceneManager.h"

#define TIMELIMIT (3600*3)
#define NUMBER_IMAGE_MAX (10)

int GameScore;
int GameLevel;
int GameMission;
int GameTime;
int GameCount;
int ReStartFlag;

int NumberImage[NUMBER_IMAGE_MAX];

int GameMainScene_Initialize(void)
{
	int ret = 0;
	int i;
	LoadDivGraph("images/number.png", NUMBER_IMAGE_MAX, NUMBER_IMAGE_MAX, 1, 60, 120, NumberImage);

	ret = StageInitialize();

	for (i = 0; i < NUMBER_IMAGE_MAX; i++)
	{
		if (NumberImage[i] == D_ERROR)
		{
			ret = D_ERROR;
			break;
		}
	}
	if (GameCount == 0)
	{
		GameScore = 0;
		GameLevel = 1;
		Set_StageMission(3);
		GameCount++;
	}
	else
	{
		GameLevel++;
		Set_StageMission(3);
	}
	GameTime = TIMELIMIT;

	return ret;
}

void GameMainScene_Update(void)
{
	switch (Get_StageState())
	{
	case 0:
		SelectBlock();
		break;
	case 2:
		MoveBlock();
		break;
	case 3:
		CheckBlock();
		break;
	case 4:
		CheckClear();
		break;
	default:
		break;
	}
	GameTime--;

	if (GameTime < 0)
	{
		Change_Scene(E_GAME_OVER);
	}
	if (Get_StageClearFlag())
	{
		Change_Scene(E_GAME_CLEAR);
	}
}

void GameMainScene_Draw(void)
{
	int PosX = 600;
	int tmp_level = GameLevel;
	int tmp_score = Get_StageScore();

	StageDraw();
	if (Get_StageState() == -1)
	{
		FadeOutBlock();
	}
	do {
		DrawRotaGraph(PosX, 80, 0.5f, 0, NumberImage[tmp_level % 10], TRUE);
		tmp_level /= 10;
		PosX -= 30;

	} while (tmp_level > 0);
	PosX = 620;
	do {
		DrawRotaGraph(PosX, 160, 0.3f, 0, NumberImage[tmp_score % 10], TRUE);
		tmp_score /= 10;
		PosX -= 20;
	} while (tmp_score > 0);
	DrawBox(491, 469, 509, 469 - GameTime / 60 * 2, 0x0033ff, TRUE);

}