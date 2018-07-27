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
	void CreateForbidden(const Vec3f& pos, const Vec3f& size);
	void CreateFoundation(const Vec3f& pos, const Vec3f& size, int x = 4, int y = 5, int z = 10);

	// キューブの状態のセット
	void SetMode(std::string mode, float angle = 1.0f, const MATRIX& matrix = MGetRotY(1.0f), const Vec3f& dir = {0.0f, -1.0f, 1.0f});

	// キューブサイズの取得
	Vec3f GetCubeSize(void) const;
	Vec3f GetFoundationSize(void) const;


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

	std::shared_ptr<Cube>foundation;
};

