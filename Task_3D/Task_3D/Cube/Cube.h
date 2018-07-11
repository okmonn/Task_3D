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
	void SetMode(std::string mode, const Vec3f& move = { 0.0f, 0.0f, 0.0f }, float angle = 0.0f);

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

	// �ړ��ʂ̎擾
	Vec3f GetMove(void) const {
		return move;
	}
	// �ړ��ʂ̃Z�b�g
	void SetMove(const Vec3f& move) {
		this->move = move;
	}

private:
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

	// �[��
	void Zero(void);

	// ���Z�b�g
	void Reset(void);


	// �摜�f�[�^
	int image;

	// ���S���W
	Vec3f pos;

	// �T�C�Y
	Vec3f size;

	// �p�x
	float angle;

	// �ړ���
	Vec3f move;

	// ���
	std::string mode;

	// ���_���
	std::vector<VERTEX3D>vertex;

	// �C���f�b�N�X
	std::vector<unsigned short>index;

	// �֐��|�C���^
	void (Cube::*func)(void);
};

