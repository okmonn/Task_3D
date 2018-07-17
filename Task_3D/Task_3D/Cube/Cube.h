#pragma once
#include "../Vector2.h"
#include "../Vector3.h"
#include <string>
#include <vector>
#include "DxLib.h"

class Cube
{
public:
	// �R���X�g���N�^
	Cube(const Vec3f& pos, const Vec3f& size);
	// �f�X�g���N�^
	~Cube();

	// ��Ԃ̃Z�b�g
	void SetMode(std::string mode, const Vec3f& move = { 0.0f, 0.0f, 0.0f }, float angle = 0.0f, const MATRIX& rotate = MGetRotY(0.0f));

	// �`��
	void Draw(void);

	// ����
	void UpData(void);

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

private:
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

	// �ҋ@
	void Wait(void);

	// �ړ�
	void Move(void);

	// �ړ��I��
	void Moved(void);

	// ����
	void Delete(void);

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

	// ���_���
	std::vector<VERTEX3D>vertex;

	// �C���f�b�N�X
	std::vector<unsigned short>index;

	// �}�e���A���A���r�G���g
	MATERIALPARAM material;

	// �֐��|�C���^
	void (Cube::*func)(void);
};

