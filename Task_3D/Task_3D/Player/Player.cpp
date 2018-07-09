#include "Player.h"
#include "../Load.h"
#include "../Input.h"
#include "../Typedef.h"
#include "DxLib.h"

// コンストラクタ
Player::Player(std::weak_ptr<Input>in) : in(in)
{
	model = Load::Get()->LoadModel("model/PPK/ポプ子.pmx");
	pos = 0.0f;
	lpos = pos;
	scale = 1.0f;
	angle = 0.0f;
	speed = 0.5f;
	index = 0;
	animTime = 0.0f;
}

// デストラクタ
Player::~Player()
{
	MV1DeleteModel(model);
}

// 描画
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

// 処理
void Player::UpData(void)
{
	SetLocalPos();
	Animator();

	if (in.lock()->CheckPress(PAD_INPUT_RIGHT) == true)
	{
		angle = 270.0f;
		pos.x += speed;
		SetMode(1);
	}
	else if (in.lock()->CheckPress(PAD_INPUT_LEFT) == true)
	{
		angle = 90.0f;
		pos.x -= speed;
		SetMode(1);
	}
	else if (in.lock()->CheckPress(PAD_INPUT_UP) == true)
	{
		angle = 180.0f;
		pos.z += speed;
		SetMode(1);
	}
	else if (in.lock()->CheckPress(PAD_INPUT_DOWN) == true)
	{
		angle = 0.0f;
		pos.z -= speed;
		SetMode(1);
	}
	else if (in.lock()->CheckTrigger(PAD_INPUT_8) == true)
	{
		SetMode(1);
	}

	SetMatrix(model, scale, RAD(angle), pos);
}

// 状態のセット
void Player::SetMode(int i)
{
	if (index == 1)
	{
		return;
	}
	int n = 0;
	n = MV1DetachAnim(model, index);
	index = i;
	animTime = 0.0f;
	n = MV1AttachAnim(model, index, -1, 0);
}

// 画面内の確認
bool Player::CheckIn(void)
{
	if (lpos.x > 0 && lpos.x < WINDOW_X)
	{
		return true;
	}

	return false;
}

// ローカル座標のセット
void Player::SetLocalPos(void)
{
	lpos.x = ConvWorldPosToScreenPos(VGet(pos.x, pos.y, pos.z)).x;
	lpos.y = ConvWorldPosToScreenPos(VGet(pos.x, pos.y, pos.z)).y;
	lpos.z = ConvWorldPosToScreenPos(VGet(pos.x, pos.y, pos.z)).z;
}

// アニメーション管理
void Player::Animator(void)
{
	animTime += 0.5f;
	if (animTime > MV1GetAttachAnimTotalTime(model, index))
	{
		animTime = 0.0f;
	}
	MV1SetAttachAnimTime(model, index, animTime);
}

// 行列のセット
void Player::SetMatrix(int model, const Vec3f & scale, float angle, const Vec3f & position)
{
	// 拡大、回転、移動の順番
	MV1SetMatrix(model, MMult(MMult(
		MGetScale(VGet(scale.x, scale.y, scale.z)),
		MGetRotY((angle))),
		MGetTranslate(VGet(position.x, position.y, position.z))));
}
