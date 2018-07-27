#pragma once
#include "../Vector2.h"
#include "../Vector3.h"
#include <string>
#include <vector>
#include "../Typedef.h"
#include "DxLib.h"

class Cube
{
public:
	// �R���X�g���N�^
	Cube();
	// �f�X�g���N�^
	virtual ~Cube();

	// ��Ԃ̃Z�b�g
	void SetMode(std::string mode, float angle = 1.0f, const MATRIX& rotate = MGetRotX(RAD(1.0f)), const Vec3f& dir = {0.0f, -1.0f, 1.0f});

	// �`��
	virtual void Draw(void) = 0;

	// ����
	virtual void UpData(void) = 0;

	// ���S���W�̎擾
	Vec3f GetCenter(void) const
	{
		return pos;
	}
	// ���S���W�̃Z�b�g
	void SetCenter(const Vec3f& vec) {
		pos = vec;
	}

	// �x�_���W�̎擾
	Vec3f GetFulcrum(void) const {
		return fulcrum;
	}
	// �x�_���W�̃Z�b�g
	void SetFulcrum(const Vec3f& fulcrum) {
		this->fulcrum = fulcrum;
	}

	// �T�C�Y�̎擾
	Vec3f GetSize(void) const {
		return size;
	}
	// �T�C�Y�̃Z�b�g
	void SetSize(const Vec3f& vec) {
		size = vec;
	}

	// �ړ������̎擾
	Vec3f GetDir(void) const {
		return dir;
	}
	// �ړ������̃Z�b�g
	void SetDir(const Vec3f& dir) {
		this->dir = dir;
	}

	// �p�x�̎擾
	float GetAngle(void) const {
		return angle;
	}
	// �p�x�̃Z�b�g
	void SetAngle(float angle) {
		this->angle = angle;
	}

	// ��]�s��̎擾
	MATRIX GetRotate(void) const {
		return rotate;
	}
	// ��]�s��̃Z�b�g
	void SetRotate(const MATRIX& matrix) {
		rotate = matrix;
	}

	// ��Ԃ̎擾
	std::string GetMode(void) const {
		return mode;
	}

	// �����t���O�̎擾
	bool GetDie(void) const {
		return die;
	}
	// �����t���O�̃Z�b�g
	void SetDie(const bool& flag) {
		die = flag;
	}

protected:
	// �}�e���A���p�����[�^�̐ݒ�
	void SetMaterialParam(const COLOR_F& ambient, const COLOR_F& diffuse, const COLOR_F& specular, const COLOR_F& emissive, float power);

	// ���_�̃Z�b�g
	void SetVertex(const Vec3f& pos, const Vec3f& normal, const COLOR_U8& diffuse, const COLOR_U8& specular, const Vec2f& uv, const Vec2f& subuv);
	void VertexInit(void);

	// �C���f�b�N�X�̃Z�b�g
	void SetIndex(unsigned short i);
	void IndexInit(void);

	// �s��̃Z�b�g
	void SetMatrix(unsigned int index, const MATRIX& matrix);

	// �[��
	void Zero(void);

	// ���Z�b�g
	void Reset(void);


	// �摜�f�[�^
	int image;

	// ���S���W
	Vec3f pos;

	// �x�_���W
	Vec3f fulcrum;

	// �T�C�Y
	Vec3f size;

	// �ړ�����
	Vec3f dir;

	// �p�x
	float angle;

	// ��]����
	float rotTime;

	// ���
	std::string mode;

	// �����t���O
	bool die;

	// ��]�s��
	MATRIX rotate;

	MATRIX rot;

	// ���_���
	std::vector<VERTEX3D>vertex;

	// �C���f�b�N�X
	std::vector<unsigned short>index;

	// �}�e���A���A���r�G���g
	MATERIALPARAM material;

	int x;
	int y;
	int z;
};

