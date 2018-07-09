#include "Player.h"
#include "../Load.h"
#include "../Input.h"
#include "../Typedef.h"
#include "DxLib.h"

// �R���X�g���N�^
Player::Player(std::weak_ptr<Input>in) : in(in)
{
	model = Load::Get()->LoadModel("model/PPK/�|�v�q.pmx");
	pos = 0.0f;
	lpos = pos;
	scale = 1.0f;
	angle = 0.0f;
	speed = 0.5f;
	attach = 0;
	flam = 0.0f;
	animTime = 0.0f;
	func = &Player::LoadUpData;
	mode = &Player::Wait;
}

// �f�X�g���N�^
Player::~Player()
{
	MV1DeleteModel(model);
}

// �`��
void Player::Draw(void)
{
	if (CheckIn() == true)
	{
		MV1DrawModel(model);
	}

#ifdef _DEBUG
	DrawFormatString(250, 250, GetColor(255, 0, 0), "%f", animTime);
#endif
}

// ����
void Player::UpData(void)
{
	(this->*func)();
}

// ��Ԃ̃Z�b�g
void Player::SetMode(int i)
{
	MV1DetachAnim(model, attach);
	flam = 0.0f;
	attach = MV1AttachAnim(model, i, -1, 0);
	animTime = MV1GetAttachAnimTotalTime(model, attach);
}

// ��ʓ��̊m�F
bool Player::CheckIn(void)
{
	if (lpos.x > 0 && lpos.x < WINDOW_X)
	{
		return true;
	}

	return false;
}

// ���[�J�����W�̃Z�b�g
void Player::SetLocalPos(void)
{
	lpos.x = ConvWorldPosToScreenPos(VGet(pos.x, pos.y, pos.z)).x;
	lpos.y = ConvWorldPosToScreenPos(VGet(pos.x, pos.y, pos.z)).y;
	lpos.z = ConvWorldPosToScreenPos(VGet(pos.x, pos.y, pos.z)).z;
}

// �A�j���[�V�����Ǘ�
void Player::Animator(void)
{
	flam += 0.5f;
	if (flam > animTime)
	{
		flam = 0.0f;
	}
	MV1SetAttachAnimTime(model, attach, flam);
}

// �s��̃Z�b�g
void Player::SetMatrix(int model, const Vec3f & scale, float angle, const Vec3f & position)
{
	// �g��A��]�A�ړ��̏���
	MV1SetMatrix(model, MMult(MMult(
		MGetScale(VGet(scale.x, scale.y, scale.z)),
		MGetRotY((angle))),
		MGetTranslate(VGet(position.x, position.y, position.z))));
}

// �ǂݍ��ݒ��̏���
void Player::LoadUpData(void)
{
	if (CheckHandleASyncLoad(model) == FALSE)
	{
		SetMode(0);
		func = &Player::NormalUpData;
	}
}

// �ǂݍ��ݏI���̏���
void Player::NormalUpData(void)
{
	SetLocalPos();
	Animator();

	(this->*mode)();

	SetMatrix(model, scale, RAD(angle), pos);
}

// �ҋ@
void Player::Wait(void)
{
	if (in.lock()->CheckPress(PAD_INPUT_RIGHT) == true || in.lock()->CheckPress(PAD_INPUT_LEFT) == true
		|| in.lock()->CheckPress(PAD_INPUT_UP) == true || in.lock()->CheckPress(PAD_INPUT_DOWN) == true)
	{
		SetMode(1);
		mode = &Player::Walk;
	}
}

// ����
void Player::Walk(void)
{
	if (in.lock()->CheckPress(PAD_INPUT_RIGHT) == true)
	{
		angle = 270.0f;
		pos.x += speed;
	}
	else if (in.lock()->CheckPress(PAD_INPUT_LEFT) == true)
	{
		angle = 90.0f;
		pos.x -= speed;
	}
	else if (in.lock()->CheckPress(PAD_INPUT_UP) == true)
	{
		angle = 180.0f;
		pos.z += speed;
	}
	else if (in.lock()->CheckPress(PAD_INPUT_DOWN) == true)
	{
		angle = 0.0f;
		pos.z -= speed;
	}
	else 
	{
		SetMode(0);
		mode = &Player::Wait;
	}
}
