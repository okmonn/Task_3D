#pragma once
#include "Cube.h"

class Foundation :
	public Cube
{
public:
	// コンストラクタ
	Foundation(const Vec3f& pos, const Vec3f& size, int x, int y, int z);
	// デストラクタ
	~Foundation();

	// 描画
	void Draw(void);

	// 処理
	void UpData(void);

private:

};

