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
	scale = 1.0f;
	angle = 0.0f;
}

// �f�X�g���N�^
Player::~Player()
{
	MV1DeleteModel(model);
}

// �`��
void Player::Draw(void)
{
	MV1DrawModel(model);
	DrawFormatString(250, 250, GetColor(255, 0, 0), "%f", angle);
}

// ����
void Player::UpData(void)
{
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

// �s��̃Z�b�g
void Player::SetMatrix(int model, const Vec3f & scale, float angle, const Vec3f & position)
{
	// �g��A��]�A�ړ��̏���
	MV1SetMatrix(model, MMult(MMult(
		MGetScale(VGet(scale.x, scale.y, scale.z)),
		MGetRotY((angle))),
		MGetTranslate(VGet(position.x, position.y, position.z))));
}
