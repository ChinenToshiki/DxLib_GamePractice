#include "TitleScene.h"
#include "InputControl.h"
#include "SceneManager.h"
#include "DxLib.h"

enum
{
	E_TITLE_BGM,
	E_TITLE_SE_CURSOR,
	E_TITLE_SE_SELECT,
	E_SOUND_MAX
};

int cursor_number;
int sounds[E_SOUND_MAX];

