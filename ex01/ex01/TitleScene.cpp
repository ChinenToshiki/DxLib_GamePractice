#include"TitleScene.h"
#include"DxLib.h"
#include"InputControl.h"
#include"SceneManager.h"

int TitleImage;
int TitleBGM;
int TitleNumber[10];
int disp_num;
///////////
int TitleScene_Initialize(void) {
	int ret = 0;
	disp_num = 0;
	TitleImage = LoadGraph("images/title.png");
	TitleBGM = LoadSoundMem("sounds/title_bgm.mp3");
	TitleNumber[0] = LoadGraph("images/0.jpg");
	TitleNumber[1] = LoadGraph("images/1.jpg");
	TitleNumber[2] = LoadGraph("images/2.jpg");
	TitleNumber[3] = LoadGraph("images/3.jpg");
	TitleNumber[4] = LoadGraph("images/4.jpg");
	TitleNumber[5] = LoadGraph("images/5.jpg");
	TitleNumber[6] = LoadGraph("images/6.jpg");
	TitleNumber[7] = LoadGraph("images/7.jpg");
	TitleNumber[8] = LoadGraph("images/8.jpg");
	TitleNumber[9] = LoadGraph("images/9.jpg");
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
		if (GetMousePositionX() > 300 && GetMousePositionX() < 390 && GetMousePositionY() > 20 && GetMousePositionY() < 70)
		{
			if (disp_num < 9)
			{
				disp_num++;
			}
			else {
				disp_num = 0;
			}
		}
		else if (GetMousePositionX() > 300 && GetMousePositionX() < 390 && GetMousePositionY() > 200 && GetMousePositionY() < 250)
		{
			if (disp_num > 0);
			disp_num--;
		}
		if(disp_num < 0) {
			disp_num = 9;
		}
	}
}
void TitleScene_Draw(void) {
	DrawGraph(0, 0, TitleImage, FALSE);
	DrawGraph(300, 70, TitleNumber[disp_num], FALSE);
	//DrawBox(300, 70, 390, 200, GetColor(0, 0, 0), 0);
	DrawBox(300, 20, 390, 250, GetColor(0, 0, 0), 0);
	DrawBox(300, 200, 390, 250, GetColor(0, 0, 0), 1);
	

		//DrawBox(300, 85, 350,180, GetColor(0, 0, 0), 1);
	}