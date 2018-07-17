#include "CubeMane.h"
#include "Cube\Cube.h"
#include "DxLib.h"

CubeMane* CubeMane::instance = nullptr;

// コンストラクタ
CubeMane::CubeMane()
{
	Reset();
}

// デストラクタ
CubeMane::~CubeMane()
{
	Reset();
}

// インスタンス
void CubeMane::Create(void)
{
	if (instance == nullptr)
	{
		instance = new CubeMane();
	}
}

// 破棄
void CubeMane::Destroy(void)
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

// 描画
void CubeMane::Draw(void)
{
	for (auto itr = cube.begin(); itr != cube.end(); ++itr)
	{
		(*itr)->Draw();
	}
}

// 処理
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

// キューブの生成
void CubeMane::CreateCube(const Vec3f & pos, const Vec3f & size)
{
	cube.push_back(std::make_shared<Cube>(pos, size));
}

// キューブの状態のセット
void CubeMane::SetMode(std::string mode)
{
	for (auto itr = cube.begin(); itr != cube.end(); ++itr)
	{
		if ((*itr)->GetMode() == "wait")
		{
			(*itr)->SetMode(mode);
		}
	}
}

// リセット
void CubeMane::Reset(void)
{
	cube.clear();
}
