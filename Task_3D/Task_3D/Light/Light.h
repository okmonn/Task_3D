#pragma once
#include "../Vector3.h"

class Light
{
public:
	// �R���X�g���N�^
	Light();
	// �f�X�g���N�^
	~Light();

	// �����̎擾
	Vec3f GetDir(void) const {
		return dir;
	}

	// �f�B�t���[�Y�F�̎擾
	Vec3f GetDiffuse(void) const {
		return diffuse;
	}

	// �A���r�G���g�F�̎擾
	Vec3f GetAmbient(void) const {
		return ambient;
	}

	// �X�y�L�����[�F�̎擾
	Vec3f GetSpecular(void) const {
		return specular;
	}

private:
	// ���C�g�̃Z�b�g
	void SetLight(void);


	// ����
	Vec3f dir;

	// �f�B�t���[�Y�F
	Vec3f diffuse;

	// �A���r�G���g�F
	Vec3f ambient;

	//�X�y�L�����[�F
	Vec3f specular;
};

