#include "Play.h"
#include "../Game.h"
#include "../CubeMane.h"
#include "../Input.h"
#include "../Camera.h"
#include "../Player/Player.h"
#include "../Loading/Loading.h"
#include "../Typedef.h"
#include "DxLib.h"

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
	CubeMane::Destroy();
}

// �N���X�̐���
void Play::Create(void)
{
	CubeMane::Create();
	Vec3f size(10.0f);
	CubeMane::Get()->CreateFoundation({ size.x * 4 / 2 - size.x * 2, -size.y * 5 / 2, size.z * 10 / 2 }, { size.x * 4, size.y * 5, size.z * 10 });
	
	for (int z = 9; z > 10 - 4; --z)
	{
		for (int i = 0; i < 4; ++i)
		{
			CubeMane::Get()->CreateForbidden({ -size.x / 2 + size.x * (i - 1), size.y / 2, size.z / 2 + size.z * z }, size);
		}
	}
	
	pl.reset(new Player(in));
	load.reset(new Loading(pl));
}

// �`��
void Play::Draw(void)
{
	if (load->GetFlag() == false)
	{
		load->Draw();

		DrawString(250, 250, "W�L�[�F�O��]", GetColor(255, 255, 255));
		DrawString(250, 300, "S�L�[�F���]", GetColor(255, 255, 255));
		DrawString(250, 350, "A�L�[�F����]", GetColor(255, 255, 255));
		DrawString(250, 400, "D�L�[�F�E��]", GetColor(255, 255, 255));
	}
	else
	{
		CubeMane::Get()->Draw();
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

	CubeMane::Get()->UpData();
	pl->UpData();
	Camera::UpData(pl);

	if (in.lock()->CheckTrigger(PAD_INPUT_8) == true)
	{
		CubeMane::Get()->SetMode("move", 1.0f, MGetRotX(RAD(1.0f)));
	}
	else if (in.lock()->CheckTrigger(PAD_INPUT_4) == true)
	{
		CubeMane::Get()->SetMode("move", 1.0f, MGetRotZ(RAD(1.0f)), {-1.0f, -1.0f, 0.0f});
	}
	else if (in.lock()->CheckTrigger(PAD_INPUT_6) == true)
	{
		CubeMane::Get()->SetMode("move", 1.0f, MGetRotZ(RAD(-1.0f)), {1.0f, -1.0f, 0.0f});
	}
	else if (in.lock()->CheckTrigger(PAD_INPUT_5) == true)
	{
		CubeMane::Get()->SetMode("move", 1.0f, MGetRotX(RAD(-1.0f)), {0.0f, -1.0f, -1.0f});
	}
}
