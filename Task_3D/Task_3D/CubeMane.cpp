#include "CubeMane.h"
#include "Cube\Cube.h"
#include "Cube\Forbidden.h"

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
	for (auto itr = cube.begin(); itr != cube.end();)
	{
		(*itr)->UpData();

		if ((*itr)->GetDie() == true)
		{
			itr = cube.erase(itr);
		}
		else
		{
			++itr;
		}
	}
}

// �L���[�u�̐���
void CubeMane::CreateForbidden(const Vec3f & pos, const Vec3f & size)
{
	cube.push_back(std::make_shared<Forbidden>(pos, size));
}

// �L���[�u�̏�Ԃ̃Z�b�g
void CubeMane::SetMode(std::string mode, float angle, const MATRIX& matrix, const Vec3f& dir)
{
	for (auto itr = cube.begin(); itr != cube.end(); ++itr)
	{
		if ((*itr)->GetMode() == "wait")
		{
			(*itr)->SetMode(mode, angle, matrix, dir);
		}
	}
}

// �L���[�u�T�C�Y�̎擾
Vec3f CubeMane::GetCubeSize(void) const
{
	if (cube.size() > 0)
	{
		return (*cube.begin())->GetSize();
	}

	return Vec3f(0.0f, 0.0f, 0.0f);
}

// ���Z�b�g
void CubeMane::Reset(void)
{
	cube.clear();
}
