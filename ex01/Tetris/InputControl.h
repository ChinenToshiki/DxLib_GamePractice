#pragma once

#include"InputControl.h"

void InputContorl_Initialize(void);
void InputContorl_Update(void);

int GetButton(int button);
int GetButtonDown(int button);
int GetButtonUp(int button);

int GetExitButton(void);