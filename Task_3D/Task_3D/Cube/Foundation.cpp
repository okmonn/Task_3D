#include "Foundation.h"
#include "../Load.h"
#include "../Typedef.h"

// �R���X�g���N�^
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

// �f�X�g���N�^
Foundation::~Foundation()
{
	Reset();
}

// �`��
void Foundation::Draw(void)
{
	int n = DrawPolygonIndexed3D(vertex.data(), (int)vertex.size(), index.data(), (int)vertex.size() / 2, image, true);
}

// ����
void Foundation::UpData(void)
{
}
