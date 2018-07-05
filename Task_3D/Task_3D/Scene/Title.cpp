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
	model = Load::Get()->LoadModel("model/Alicia/Alicia_solid.pmx");
}

// �f�X�g���N�^
Title::~Title()
{
}

// �`��
void Title::Draw(void)
{
	SetCamera({ 0.0f, 15.0f, -25.0f }, { 0.0f, 10.0f, 0.0f }, 60.0f, 0.5f, 300.0f);

	MV1DrawModel(model);
}

// ����
void Title::UpData(void)
{
	if (in.lock()->CheckTrigger(PAD_INPUT_8) == true)
	{
		Game::Get().ChangeScene(new Play(in));
	}
}
