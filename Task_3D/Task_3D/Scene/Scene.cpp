#include "Scene.h"
#include "../Typedef.h"
#include "DxLib.h"

// �R���X�g���N�^
Scene::Scene()
{
	alpha = 0;
}

// �f�X�g���N�^
Scene::~Scene()
{
}

// �s��̃Z�b�g
void Scene::SetMatrix(int model, const Vec3f& scal, float angle, const Vec3f& position)
{
	// �g��A��]�A�ړ��̏���
	MV1SetMatrix(model, MMult(MMult(
		MGetScale(VGet(scal.x, scal.y, scal.z)),
		MGetRotY(RAD(angle))),
		MGetTranslate(VGet(position.x, position.y, position.z))));
}
