#include"DxLib.h"
#include"FreamControl.h"
#include"InputControl.h"
#include"SceneManager.h"

#define SCREEN_HIGHT (480)
#define SCREEN_WIDTH (640)
#define SCREEN_COLORBIT (32)
#define FONT_SIZE (20)

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrebInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//ウィンドウタイトル設定
	SetMainWindowText("Match 3 Puzzle");
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);
	//画面サイズの最大サイズ、カラービット数を設定
	SetGraphMode(SCREEN_WIDTH, SCREEN_HIGHT, SCREEN_COLORBIT);

	//Dxライブラリの初期化の処理
	if (DxLib_Init() == D_ERROR)
	{
		return D_ERROR;
	}
	//各機能の初期化処理
	FreamControl_Initialize();
	Input_Initialize();

	if (SceneManager_Initialize(E_TITLE) == D_ERROR)
	{
		return D_ERROR;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	SetFontSize(FONT_SIZE);

	while (ProcessMessage() != D_ERROR && Input_Escape() == FALSE)
	{
		Input_Update();

		SceneManager_Update();

		ClearDrawScreen();

		SceneManager_Draw();

		FreamControl_Update();

		ScreenFlip();
	}

	//Dxライフらりの使用の終了処理
	DxLib_End();

	return 0;
}