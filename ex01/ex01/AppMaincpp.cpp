#include"DxLib.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrebInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//�ϐ���`
	//int num = 0;

	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//Dx���C�u�����̏������̏���
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//���͑ҋ@
	WaitKey();

	//Dx���C�t���̎g�p�̏I������
	DxLib_End();

	return 0;
}