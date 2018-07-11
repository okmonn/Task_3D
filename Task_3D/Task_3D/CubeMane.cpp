#include "CubeMane.h"
#include "Cube\Cube.h"
#include "DxLib.h"

CubeMane* CubeMane::instance = nullptr;

// �R���X�g���N�^
CubeMane::CubeMane()
{
	Reset();
}

// �f�X�g���N�^
CubeMane::~CubeMane()
{
	Reset();
}

// �C���X�^���X
void CubeMane::Create(void)
{
	if (instance == nullptr)
	{
		instance = new CubeMane();
	}
}

// �j��
void CubeMane::Destroy(void)
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

// �`��
void CubeMane::Draw(void)
{
	for (auto itr = cube.begin(); itr != cube.end(); ++itr)
	{
		(*itr)->Draw();
	}
}

// ����
void CubeMane::UpData(void)
{
	for (auto itr = cube.begin(); itr != cube.end(); ++itr)
	{
		(*itr)->UpData();
	}
}

// �L���[�u�̐���
void CubeMane::CreateCube(const Vec3f & pos, const Vec3f & size)
{
	cube.push_back(std::make_shared<Cube>(pos, size));
}

// ���Z�b�g
void CubeMane::Reset(void)
{
	cube.clear();
}
