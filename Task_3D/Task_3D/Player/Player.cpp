#include "Player.h"
#include "../Load.h"
#include "../Input.h"
#include "../Typedef.h"
#include "DxLib.h"

// �A�j���[�V�������x
#define ANIM_SPEED 0.5f;

// �ړ����x
#define WALK_SPEED 0.5f;

// �R���X�g���N�^
Player::Player(std::weak_ptr<Input>in) : in(in)
{
	Reset();
	SetMode();

	model = Load::Get()->LoadModel("model/PPK/�|�v�q.pmx");
	pos = 0.0f;
	lpos = pos;
	scale = 1.0f;
	angle = 0.0f;
	speed = WALK_SPEED;
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
	Reset();
}

// �`��
void Player::Draw(void)
{
	if (CheckIn() == true)
	{
		MV1DrawModel(model);
	}

#ifdef _DEBUG
	DrawFormatString(10, GetFontSize(), GetColor(255, 0, 0), "%s", st.c_str());
#endif
}

// ����
void Player::UpData(void)
{
	(this->*func)();
}

// ��ԗv�f�̃Z�b�g
void Player::SetMode(void)
{
	stata["wait"] = 0;
	stata["walk"] = 1;
}

// ��Ԃ̃Z�b�g
void Player::SetMode(std::string stata)
{
	MV1DetachAnim(model, attach);
	flam = 0.0f;
	attach = MV1AttachAnim(model, this->stata[stata], -1, 0);
	animTime = MV1GetAttachAnimTotalTime(model, attach);
	st = stata;
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

// �A�j���[�V�����̏I���m�F
bool Player::CheckAnimEnd(void)
{
	if (flam >= animTime)
	{
		return true;
	}

	return false;
}

// �A�j���[�V�����Ǘ�
void Player::Animator(void)
{
	flam += ANIM_SPEED;
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
		SetMode("wait");
		mode = &Player::Wait;
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
		SetMode("walk");
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
		SetMode("wait");
		mode = &Player::Wait;
	}
}

// ���Z�b�g
void Player::Reset(void)
{
	stata.clear();
}
