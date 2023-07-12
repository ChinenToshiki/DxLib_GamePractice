#include"TitleScene.h"
#include"DxLib.h"
#include"InputControl.h"
#include"SceneManager.h"

int TitleImage;
int TitleBGM;

///////////
int TitleScene_Initialize(void) {
	int ret = 0;
	TitleImage = LoadGraph("images/title.png");
	TitleBGM = LoadSoundMem("sounds/title_bgm.mp3");
	if (TitleImage == D_ERROR)
	{
		ret = D_ERROR;
	}
	if(TitleBGM == D_ERROR) 
	{
	ret = D_ERROR;
	}
return ret;
}
void TitleScene_Update(void) {
	if (CheckSoundMem(TitleBGM) == 0) {
		PlaySoundMem(TitleBGM, DX_PLAYTYPE_BACK);
	}
	if (GetKeyFlg(MOUSE_INPUT_LEFT) == TRUE) {
		if (GetMousePositionX() > 120 && GetMousePositionX() < 290 && GetMousePositionY() > 260 && GetMousePositionY() < 315)
		{
			Change_Scene(E_GAMEMAIN);

			StopSoundMem(TitleBGM);
		}
		if (GetMousePositionX() > 120 && GetMousePositionX() < 220 && GetMousePositionY() > 345 && GetMousePositionY() < 400)
		{
			Change_Scene(E_END);
			StopSoundMem(TitleBGM);
		}
	}
}
void TitleScene_Draw(void) {
	DrawGraph(0, 0, TitleImage, FALSE);
}