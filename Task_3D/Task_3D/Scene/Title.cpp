#include "Title.h"
#include "Play.h"
#include "../Load.h"
#include "../Input.h"
#include "../Game.h"
#include "../Typedef.h"
#include "DxLib.h"

// �����x�ő�l
#define ALPHA_MAX 255

// �R���X�g���N�^
Title::Title(std::weak_ptr<Input>in)
{
	this->in = in;
	alpha = ALPHA_MAX;
	SetImage("img/title.png", { 242, 87 });
	image.pos = { WINDOW_X / 2 - image.size.x / 2, WINDOW_Y / 2 - image.size.y / 2 };
	func = &Title::FadeOut;
}

// �f�X�g���N�^
Title::~Title()
{
}

// �`��
void Title::Draw(void)
{
	DrawRectRotaGraph(image);
	DrawString(WINDOW_X / 2 - 64, 450, "W�L�[�F�X�^�[�g", GetColor(255, 255, 255));

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawBox({ 0, 0 }, { WINDOW_X, WINDOW_Y }, GetColor(0, 0, 0));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// ����
void Title::UpData(void)
{
	(this->*func)();
}

// �t�F�[�h�C��
void Title::FadeIn(void)
{
	if (alpha < ALPHA_MAX)
	{
		alpha += 5;
	}
	else
	{
		Game::Get().ChangeScene(new Play(in));
	}
}

// �t�F�[�h�A�E�g
void Title::FadeOut(void)
{
	if (alpha > 0)
	{
		alpha -= 5;
	}
	else
	{
		if (in.lock()->CheckTrigger(PAD_INPUT_8) == true)
		{
			func = &Title::FadeIn;
		}
	}
}
