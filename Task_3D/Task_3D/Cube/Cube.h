#pragma once
#include "../Vector2.h"
#include "../Vector3.h"
#include <vector>
#include "DxLib.h"

class Cube
{
public:
	// コンストラクタ
	Cube();
	// デストラクタ
	~Cube();

	// 描画
	void Draw(void);

	// 処理
	void UpData(void);

private:
	// 頂点のセット
	void SetVertex(const Vec3f& pos, const Vec3f& normal, const COLOR_U8& diffuse, const COLOR_U8& specular, const Vec2f& uv, const Vec2f& subuv);
	void VertexInit(void);

	// インデックスのセット
	void SetIndex(unsigned short i);
	void IndexInit(void);

	// 行列のセット
	void SetMatrix(unsigned int index, const MATRIX& matrix);

	// リセット
	void Reset(void);


	// 画像データ
	int image;

	// 頂点情報
	std::vector<VERTEX3D>vertex;

	// インデックス
	std::vector<unsigned short>index;
};

