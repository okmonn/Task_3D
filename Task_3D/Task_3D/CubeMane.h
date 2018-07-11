#pragma once
#include "Vector3.h"
#include <memory>
#include <list>
#include <string>

class Cube;

class CubeMane
{
public:
	// デストラクタ
	~CubeMane();

	// インスタンス
	static void Create(void);
	// 破棄
	static void Destroy(void);

	// インスタンス変数の取得
	static CubeMane* Get(void) {
		return instance;
	}

	// 描画
	void Draw(void);

	// 処理
	void UpData(void);

	// キューブの生成
	void CreateCube(const Vec3f& pos, const Vec3f& size);

	// キューブの状態のセット
	void SetMode(std::string mode);


private:
	// コンストラクタ
	CubeMane();
	CubeMane(const CubeMane&) {
	}
	void operator=(const CubeMane&) {
	}

	// リセット
	void Reset(void);


	// インスタンス変数
	static CubeMane* instance;

	// キューブリスト
	std::list<std::shared_ptr<Cube>>cube;
};

