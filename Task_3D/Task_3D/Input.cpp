#include "Input.h"
#include "DxLib.h"

// �R���X�g���N�^
Input::Input()
{
	state = 0;
	old_state = 0;
}

// �f�X�g���N�^
Input::~Input()
{
}

// ����
void Input::UpData(void)
{
	old_state = state;
	state = GetJoypadInputState(DX_INPUT_KEY_PAD1);
}
