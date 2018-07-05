#pragma once
#include <map>
#include <string>

class Load
{
public:
	// デストラクタ
	~Load();

	// インスタンス変数の取得
	static Load* Get(void) {
		return instance;
	}
	// インスタンス化
	static void Create(void);
	// 破棄
	static void Destroy(void);

	// 画像の読み込み
	int LoadImg(std::string fileName);

	// モデルの読み込み
	int LoadModel(std::string fileName);

private:
	// コンストラクタ
	Load();
	Load(const Load&) {
	}
	void operator=(const Load&) {
	}

	// リセット
	void Reset(void);


	// インスタンス変数
	static Load* instance;

	// 画像データ
	std::map<std::string, int>image;

	// モデルデータ
	std::map<std::string, int>model;
};
