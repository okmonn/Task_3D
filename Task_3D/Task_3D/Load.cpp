#include "Load.h"
#include "DxLib.h"

Load* Load::instance = nullptr;

// コンストラクタ
Load::Load()
{
	Reset();
}

// デストラクタ
Load::~Load()
{
	Reset();
}

// インスタンス化
void Load::Create(void)
{
	if (instance == nullptr)
	{
		instance = new Load();
	}
}

// 破棄
void Load::Destroy(void)
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

// 画像の読み込み
int Load::LoadImg(std::string fileName)
{
	if (image.find(fileName) != image.end())
	{
		return image[fileName];
	}
	else
	{
		image[fileName] = LoadGraph(fileName.c_str());
		return image[fileName];
	}

	return 0;
}

// モデルの読み込み
int Load::LoadModel(std::string fileName)
{
	if (model.find(fileName) != model.end())
	{
		return MV1DuplicateModel(model[fileName]);
	}
	else
	{
		return model[fileName] = MV1LoadModel(fileName.c_str());
		if (model[fileName] != -1)
		{
			return MV1DuplicateModel(model[fileName]);
		}
	}

	return 0;
}

// リセット
void Load::Reset(void)
{
	for (auto itr = image.begin(); itr != image.end(); ++itr)
	{
		DeleteGraph(itr->second);
	}
	image.clear();
	for (auto itr = model.begin(); itr != model.end(); ++itr)
	{
		MV1DeleteModel(itr->second);
	}
	model.clear();
}

