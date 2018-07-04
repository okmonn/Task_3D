#include "Title.h"
#include "Play.h"
#include "../Load.h"
#include "../Typedef.h"
#include "../Input.h"
#include "../Game.h"
#include "DxLib.h"

// �R���X�g���N�^
Title::Title(std::weak_ptr<Input>in)
{
	this->in = in;
	image = Load::Get()->LoadImg("img/iq.png");
}

// �f�X�g���N�^
Title::~Title()
{
}

// �`��
void Title::Draw(void)
{
	DrawGraph(0, 0, image, true);

	SetZBuffer();
	DrawSphere3D(VGet(WINDOW_X / 2, WINDOW_Y / 2, 0), 100.0f, 32, GetColor(255, 255, 128), GetColor(255, 255, 255), true);
}

// ����
void Title::UpData(void)
{
	if (in.lock()->CheckTrigger(PAD_INPUT_A) == true)
	{
		Game::Get().ChangeScene(new Play(in));
	}
}
