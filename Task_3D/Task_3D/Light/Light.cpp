#include "Light.h"
#include "DxLib.h"

// �R���X�g���N�^
Light::Light()
{
	dir = 1.0f;
	diffuse = 0.8f;
	ambient = 0.3f;
	specular = 1.0f;

	SetLight();
}

// �f�X�g���N�^
Light::~Light()
{
}

// ���C�g�̃Z�b�g
void Light::SetLight(void)
{
	//���C�g�̌����̃Z�b�g
	SetLightDirection(VGet(dir.x, dir.y, dir.z));
	//���F
	SetGlobalAmbientLight(GetColorF(0.3f, 0.3f, 0.3f, 1.0f));
	//�f�B�t���[�Y�F�̃Z�b�g
	SetLightDifColor(GetColorF(diffuse.x, diffuse.y, diffuse.z, 1.0f));
	//�A���r�G���g�F�̃Z�b�g
	SetLightAmbColor(GetColorF(ambient.x, ambient.y, ambient.z, 1.0f));
	//�X�y�L�����[�F�̃Z�b�g
	SetLightSpcColor(GetColorF(specular.x, specular.y, specular.z, 1.0f));
}
