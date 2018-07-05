#include "Scene.h"
#include "../Typedef.h"
#include "DxLib.h"

// コンストラクタ
Scene::Scene()
{
	alpha = 0;
}

// デストラクタ
Scene::~Scene()
{
}

// カメラのセット
void Scene::SetCamera(const Vec3f & position, const Vec3f & target, float fov, float min, float max)
{
	//カメラセット
	SetCameraPositionAndTarget_UpVecY(VGet(position.x, position.y, position.z), VGet(target.x, target.y, target.z));
	//遠近法カメラのセット
	SetupCamera_Perspective(RAD(fov));
	//カメラのニアファーのセット
	SetCameraNearFar(min, max);
}

// 行列のセット
void Scene::SetMatrix(int model, const Vec3f& scal, float angle, const Vec3f& position)
{
	// 拡大、回転、移動の順番
	MV1SetMatrix(model, MMult(MMult(
		MGetScale(VGet(scal.x, scal.y, scal.z)),
		MGetRotY(RAD(angle))),
		MGetTranslate(VGet(position.x, position.y, position.z))));
}
