#include "Scene.h"
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

// Z�o�b�t�@�̃Z�b�g
void Scene::SetZBuffer(bool flag1, bool flag2)
{
	//Z�o�b�t�@�̗L��
	SetUseZBuffer3D(flag1);
	//�y�o�b�t�@�ւ̏������݂�L��
	SetWriteZBuffer3D(flag2);
}
