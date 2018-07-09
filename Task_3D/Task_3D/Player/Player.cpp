#include "Player.h"
#include "../Load.h"
#include "../Input.h"
#include "../Typedef.h"
#include "DxLib.h"

// �R���X�g���N�^
Player::Player(std::weak_ptr<Input>in) : in(in)
{
	model = Load::Get()->LoadModel("model/Alicia/Alicia_solid.pmx");
	pos = 0.0f;
	lpos = pos;
	scale = 1.0f;
	angle = 0.0f;
	index = 0;
	animTime = 0.0f;
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
#endif
}

// ����
void Player::UpData(void)
{
	SetLocalPos();
	Animator();

	if (in.lock()->CheckPress(PAD_INPUT_RIGHT) == true)
	{
		angle = 270.0f;
		pos.x += 0.5f;
		
	}
	else if (in.lock()->CheckPress(PAD_INPUT_LEFT) == true)
	{
		angle = 90.0f;
		pos.x -= 0.5f;
	}
	else if (in.lock()->CheckPress(PAD_INPUT_UP) == true)
	{
		angle = 180.0f;
		pos.z += 0.5f;
	}
	else if (in.lock()->CheckPress(PAD_INPUT_DOWN) == true)
	{
		angle = 0.0f;
		pos.z -= 0.5f;
	}

	SetMatrix(model, scale, RAD(angle), pos);
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
	++animTime;
	if (animTime > MV1GetAttachAnimTotalTime(model, index))
	{
		animTime = 0.0f;
	}
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
