#pragma once
#include "Vector3.h"
#include <memory>
#include <list>
#include <string>
#include "DxLib.h"

class Cube;

class CubeMane
{
public:
	// �f�X�g���N�^
	~CubeMane();

	// �C���X�^���X
	static void Create(void);
	// �j��
	static void Destroy(void);

	// �C���X�^���X�ϐ��̎擾
	static CubeMane* Get(void) {
		return instance;
	}

	// �`��
	void Draw(void);

	// ����
	void UpData(void);

	// �L���[�u�̐���
	void CreateForbidden(const Vec3f& pos, const Vec3f& size);
	void CreateFoundation(const Vec3f& pos, const Vec3f& size, int x = 4, int y = 5, int z = 10);

	// �L���[�u�̏�Ԃ̃Z�b�g
	void SetMode(std::string mode, float angle = 1.0f, const MATRIX& matrix = MGetRotY(1.0f), const Vec3f& dir = {0.0f, -1.0f, 1.0f});

	// �L���[�u�T�C�Y�̎擾
	Vec3f GetCubeSize(void) const;
	Vec3f GetFoundationSize(void) const;


private:
	// �R���X�g���N�^
	CubeMane();
	CubeMane(const CubeMane&) {
	}
	void operator=(const CubeMane&) {
	}

	// ���Z�b�g
	void Reset(void);


	// �C���X�^���X�ϐ�
	static CubeMane* instance;

	// �L���[�u���X�g
	std::list<std::shared_ptr<Cube>>cube;

	std::shared_ptr<Cube>foundation;
};

