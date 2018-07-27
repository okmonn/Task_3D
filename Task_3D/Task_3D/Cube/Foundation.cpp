#include "Foundation.h"
#include "../Load.h"
#include "../Typedef.h"

// コンストラクタ
Foundation::Foundation(const Vec3f& pos, const Vec3f& size, int x, int y, int z)
{
	this->pos = pos;
	this->size = size;
	this->x = x;
	this->y = y;
	this->z = z;

	image = Load::Get()->LoadImg("img/cube_tex.png");

	VertexInit();
	IndexInit();
}

// デストラクタ
Foundation::~Foundation()
{
	Reset();
}

// 描画
void Foundation::Draw(void)
{
	int n = DrawPolygonIndexed3D(vertex.data(), (int)vertex.size(), index.data(), (int)vertex.size() / 2, image, true);
}

// 処理
void Foundation::UpData(void)
{
}
