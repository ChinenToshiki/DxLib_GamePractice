#include "DxLib.h"
#include "FreamControl.h"
#include "SceneManager.h"
#include "InputControl.h"

#define SCREEN_HEIGHT (720)
#define SCREEN_WIDTH (1280)
#define SCREEN_COLORBIT (32)
#define FONT_SIZE (20)

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrebInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetMainWindowText("ƒeƒgƒŠƒX");

	ChangeWindowMode(TRUE);

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLORBIT);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	FreamControl_Initialize();

	SceneManager_Initialize(E_TITLE);

	InputControl_Initialize();

	SetDrawScreen(DX_SCREEN_BACK);

	SetFontSize(FONT_SIZE);

	while (ProcessMessage() == 0 && GetExitButton() != TRUE && ErrorCheck() == D_NORMALITY)
	{
		FreamControl_Update();

		ClearDrawScreen();

		InputControl_Update();

		SceneManager_Update();

		SceneManager_Draw();

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}