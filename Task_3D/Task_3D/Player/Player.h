#pragma once
#include "../Vector3.h"
#include <memory>

class Input;

class Player
{
public:
	// �R���X�g���N�^
	Player(std::weak_ptr<Input>in);
	// �f�X�g���N�^
	~Player();

	// �`��
	void Draw(void);

	// ����
	void UpData(void);

	// ���W�̎擾
	Vec3f GetPos(void) const {
		return pos;
	}
	// ���W�̃Z�b�g
	void SetPos(const Vec3f& pos) {
		this->pos = pos;
	}

	// �g�嗦�̎擾
	Vec3f GetScale(void) const {
		return scale;
	}
	// �g�嗦�̃Z�b�g
	void SetScale(const Vec3f& scale) {
		this->scale = scale;
	}

	// �p�x�̎擾
	constexpr float GetAngle(void) const {
		return angle;
	}
	// �p�x�̃Z�b�g
	void SetAngle(const float& i) {
		angle = i;
	}

private:
	// �s��̃Z�b�g
	void SetMatrix(int model, const Vec3f& scale, float angle, const Vec3f& position);


	// �C���v�b�g
	std::weak_ptr<Input>in;

	// ���f��
	int model;

	// ���W
	Vec3f pos;

	// �g�嗦
	Vec3f scale;

	// �p�x
	float angle;
};

