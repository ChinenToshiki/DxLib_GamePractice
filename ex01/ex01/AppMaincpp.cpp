#include"DxLib.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrebInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//変数定義
	//int num = 0;

	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//Dxライブラリの初期化の処理
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//入力待機
	WaitKey();

	//Dxライフらりの使用の終了処理
	DxLib_End();

	return 0;
}