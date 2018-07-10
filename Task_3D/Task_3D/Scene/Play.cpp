#include "Play.h"
#include "../Game.h"
#include "../Input.h"
#include "../Cube/Cube.h"
#include "../Player/Player.h"
#include "../Loading/Loading.h"
#include "../Typedef.h"

#define ALPHA_MAX 255

// �R���X�g���N�^
Play::Play(std::weak_ptr<Input>in)
{
	this->in = in;
	alpha = ALPHA_MAX;
	func = &Play::FadeOut;


	Create();
}

// �f�X�g���N�^
Play::~Play()
{
}

// �N���X�̐���
void Play::Create(void)
{
	cube.reset(new Cube());
	pl.reset(new Player(in));
	load.reset(new Loading(pl));
}

// �`��
void Play::Draw(void)
{
	if (load->GetFlag() == false)
	{
		load->Draw();
	}
	else
	{
		cube->Draw();
		pl->Draw();
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawBox({ 0, 0 }, { WINDOW_X, WINDOW_Y }, GetColor(0, 0, 0));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// ����
void Play::UpData(void)
{
	(this->*func)();
}

// �t�F�[�h�C��
void Play::FadeIn(void)
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
void Play::FadeOut(void)
{
	if (alpha > 0)
	{
		alpha -= 5;
	}
	else
	{
		func = &Play::Run;
	}
}

// ����
void Play::Run(void)
{
	if (load->GetFlag() == false)
	{
		return;
	}

	cube->UpData();
	pl->UpData();
}
