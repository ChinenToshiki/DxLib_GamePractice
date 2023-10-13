#include"InputControl.h"
#include"DxLib.h"

#define XINPUT_BUTTON_MAX (16)

enum KEY_STATE
{
	E_NONE,
	E_CLICK,
	E_PRESS,
	E_RELEASED,
	E_KEY_STATE_MAX
};

KEY_STATE button_state[XINPUT_BUTTON_MAX];

void InputControl_Initialize(void)
{
	int i;

	for (i = 0; i < XINPUT_BUTTON_MAX; i++)
	{
		button_state[i] = E_NONE;
	}
}

void InputControl_Update(void)
{
	int i;
	XINPUT_STATE input_controller;

	GetJoypadXInputState(DX_INPUT_PAD1, &input_controller);

	for (i = 0; i < XINPUT_BUTTON_MAX; i++)
	{
		if (input_controller.Buttons[i] == TRUE)
		{
			switch (button_state[i])
			{
			case E_NONE:
			case E_RELEASED:
				button_state[i] = E_CLICK;
				break;
			case E_CLICK:
			case E_PRESS:
				button_state[i] = E_PRESS;
				break;
			default:
				button_state[i] = E_NONE;
				break;
			}
		}
	}
}

