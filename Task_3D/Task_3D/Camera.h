#pragma once
#include "Vector3.h"
#include <memory>

class Input;
class Player;

class Camera
{
public:
	// �R���X�g���N�^
	Camera();
	Camera(std::weak_ptr<Input>in);
	// �f�X�g���N�^
	~Camera();

	// �J�����̃Z�b�g
	void SetCamera(const Vec3f & pos, const Vec3f & target, const float fov, const float min, const float max);

	// ����
	void UpData(void);
	static void UpData(std::shared_ptr<Player>pl);

	// �v���C���[�̃Z�b�g
	static void SetPlayer(std::shared_ptr<Player>player) {
		pl = player;
	}

	// ���W�̎擾
	Vec3f GetPos(void) const {
		return pos;
	}
	// ���W�̃Z�b�g
	void SetPos(const Vec3f& pos) {
		this->pos = pos;
	}
	void SetPos(const float i) {
		pos = i;
	}

	// �^�[�Q�b�g�̎擾
	Vec3f GetTarget(void) const {
		return target;
	}
	// �^�[�Q�b�g�̃Z�b�g
	void SetTarget(const Vec3f& pos) {
		target = pos;
	}
	void SetTarget(const float i) {
		target = i;
	}

	// ���ߒl�̎擾
	constexpr float GetAngle(void) const {
		return fov;
	}
	// ���ߒl�̃Z�b�g
	void SetAngle(const float i) {
		fov = i;
	}

	//	�j�A�l�̎擾
	constexpr float GetNear(void) const {
		return min;
	}
	// �j�A�l�̃Z�b�g
	void SetNear(const float i) {
		min = i;
	}

	// �t�@�[�l�̎擾
	constexpr float GetFar(void) const {
		return max;
	}
	// �t�@�[�l�̃Z�b�g
	void SetFar(const float i) {
		max = i;
	}

private:
	// �C���v�b�g
	std::weak_ptr<Input>in;

	// �v���C���[
	static std::weak_ptr<Player>pl;

	// ���W
	static Vec3f pos;

	// �^�[�Q�b�g
	static Vec3f target;

	// �p�x
	float fov;

	// �j�A�l
	float min;

	// �t�@�[�l
	float max;
};

