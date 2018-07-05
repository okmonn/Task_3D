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

// �J�����̃Z�b�g
void Scene::SetCamera(const Vec3f & position, const Vec3f & target, float fov, float min, float max)
{
	//�J�����Z�b�g
	SetCameraPositionAndTarget_UpVecY(VGet(position.x, position.y, position.z), VGet(target.x, target.y, target.z));
	//���ߖ@�J�����̃Z�b�g
	SetupCamera_Perspective(RAD(fov));
	//�J�����̃j�A�t�@�[�̃Z�b�g
	SetCameraNearFar(min, max);
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
