#include "Play.h"
#include "../Player/Player.h"
#include "DxLib.h"

// �R���X�g���N�^
Play::Play(std::weak_ptr<Input>in)
{
	this->in = in;


	Create();
}

// �f�X�g���N�^
Play::~Play()
{
}

// �N���X�̐���
void Play::Create(void)
{
	pl = std::make_shared<Player>(in);
}

// �`��
void Play::Draw(void)
{
	pl->Draw();
}

// ����
void Play::UpData(void)
{
	pl->UpData();
}
