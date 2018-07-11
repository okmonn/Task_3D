#pragma once
#include "Vector3.h"
#include <memory>
#include <list>

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
	void CreateCube(const Vec3f& pos, const Vec3f& size);


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
};

