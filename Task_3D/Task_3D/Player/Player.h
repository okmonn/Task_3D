#pragma once
#include "../Vector2.h"
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

	// ���[�J�����W�̎擾
	Vec3f GetLocalPos(void) const {
		return lpos;
	}
	// ���[�J�����W�̃Z�b�g
	void SetLocalPos(const Vec3f& pos) {
		lpos = pos;
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

	// ���f���n���h���̎擾
	constexpr int GetModelHandle(void) const {
		return model;
	}

private:
	// ��Ԃ̃Z�b�g
	void SetMode(int i);

	// ��ʓ��̊m�F
	bool CheckIn(void);

	// ���[�J�����W�̃Z�b�g
	void SetLocalPos(void);

	// �A�j���[�V�����Ǘ�
	void Animator(void);

	// �s��̃Z�b�g
	void SetMatrix(int model, const Vec3f& scale, float angle, const Vec3f& position);

	// �ǂݍ��ݒ��̏���
	void LoadUpData(void);

	// �ǂݍ��ݏI���̏���
	void NormalUpData(void);

	// �ҋ@
	void Wait(void);

	// ����
	void Walk(void);


	// �C���v�b�g
	std::weak_ptr<Input>in;

	// ���f��
	int model;

	// ���W
	Vec3f pos;

	// ���[�J�����W
	Vec3f lpos;

	// �g�嗦
	Vec3f scale;

	// �p�x
	float angle;

	// �ړ����x
	float speed;

	// �A�^�b�`�ԍ�
	int attach;

	// �t���[��
	float flam;

	// �A�j���[�V�����t���[��
	float animTime;

	// �֐��|�C���^
	void (Player::*func)(void);
	void (Player::*mode)(void);
};

