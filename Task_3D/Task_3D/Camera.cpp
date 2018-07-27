#include "Camera.h"
#include "Input.h"
#include "Player\Player.h"
#include "Typedef.h"
#include "DxLib.h"

Vec3f Camera::pos = 0.0f;
Vec3f Camera::target = 0.0f;

// コンストラクタ
Camera::Camera()
{
	pos = 0.0f;
	target = 0.0f;
	min = 0.0f;
	max = 0.0f;

	SetCamera({ -10.0f, 25.0f, -50.0f }, { 0.0f, 10.0f, 0.0f }, 60.0f, 0.5f, 300.0f);
}

// コンストラクタ
Camera::Camera(std::weak_ptr<Input> in) : in(in)
{
	pos = 0.0f;
	target = 0.0f;
	min = 0.0f;
	max = 0.0f;

	SetCamera({ 0.0f, 15.0f, -25.0f }, { 0.0f, 10.0f, 0.0f }, 60.0f, 0.5f, 300.0f);
}

// デストラクタ
Camera::~Camera()
{
}

// カメラのセット
void Camera::SetCamera(const Vec3f & pos, const Vec3f & target, const float fov, const float min, const float max)
{
	this->pos = pos;
	this->target = target;
	this->fov = fov;
	this->min = min;
	this->max = max;
}

// 処理
void Camera::UpData(void)
{
	//カメラセット
	SetCameraPositionAndTarget_UpVecY(VGet(pos.x, pos.y, pos.z), VGet(target.x, target.y, target.z));
	//遠近法カメラのセット
	SetupCamera_Perspective(RAD(fov));
	//カメラのニアファーのセット
	SetCameraNearFar(min, max);
}

// 処理
void Camera::UpData(std::shared_ptr<Player> pl)
{
	target = pl->GetPos();
	static Vec3f tmp = target - pos;
	pos = target - tmp;
}
