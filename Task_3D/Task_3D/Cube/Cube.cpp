#include "Cube.h"
#include "../Load.h"
#include "../Typedef.h"

float angle = 1.0f;

// �R���X�g���N�^
Cube::Cube()
{
	Reset();

	image = Load::Get()->LoadImg("img/cube_tex.png");

	VertexInit();
	IndexInit();
}

// �f�X�g���N�^
Cube::~Cube()
{
	Reset();
}

// �`��
void Cube::Draw(void)
{
	/*for (int z = 0; z < 9; ++z)
	{
		for (int x = -6; x < 6; ++x)
		{
			DrawCube3D(VGet(-5.0f + 2 * (5.0f + 0.1f) * x, 0.0f, -5.0f * z),
				VGet(5.0f + 2 * (5.0f + 0.1f) * x, -2.0f * 5.0f, 5.0f * z),
				GetColor(255, 255, 0), 0xffffff, true);
		}
	}*/

	int n = DrawPolygonIndexed3D(vertex.data(), (int)vertex.size(), index.data(), (int)vertex.size() / 2, image, true);
}

// ����
void Cube::UpData(void)
{
	for (UINT i = 0; i < vertex.size(); ++i)
	{
		SetMatrix(i, MMult(MGetRotY(RAD(angle)), MGetTranslate(VGet(0.1f, 0.0f, 0.0f))));
	}
}

// ���_�̃Z�b�g
void Cube::SetVertex(const Vec3f & pos, const Vec3f & normal, const COLOR_U8 & diffuse, const COLOR_U8 & specular, const Vec2f & uv, const Vec2f & subuv)
{
	VERTEX3D dummy = {};
	dummy.pos = VGet(pos.x, pos.y, pos.z);
	dummy.norm = VGet(normal.x, normal.y, normal.z);
	dummy.dif = diffuse;
	dummy.spc = specular;
	dummy.u = uv.x;
	dummy.v = uv.y;
	dummy.su = subuv.x;
	dummy.sv = subuv.y;

	vertex.push_back(dummy);
}

// ���_�̃Z�b�g
void Cube::VertexInit(void)
{
	//����
	SetVertex({ -5, 10, 0 }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 0.0f }, { 0.0f, 0.0f });
	//�E��
	SetVertex({  5, 10, 0 }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 0.0f }, { 0.0f, 0.0f });
	//����
	SetVertex({ -5,  5, 0 }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 1.0f }, { 0.0f, 0.0f });
	//�E��
	SetVertex({  5,  5, 0 }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 1.0f }, { 0.0f, 0.0f });
}

// �C���f�b�N�X�̃Z�b�g
void Cube::SetIndex(unsigned short i)
{
	index.push_back(i);
}

// �C���f�b�N�X�̃Z�b�g
void Cube::IndexInit(void)
{
	SetIndex(0);
	SetIndex(1);
	SetIndex(2);
	SetIndex(1);
	SetIndex(3);
	SetIndex(2);
}


// �s��̃Z�b�g
void Cube::SetMatrix(unsigned int index, const MATRIX & matrix)
{
	if (index >= vertex.size())
	{
		OutputDebugString("\n�z��𒴂����w��ł�\n");
		return;
	}

	auto pos = vertex[index].pos;
	auto norm = vertex[index].norm;
	vertex[index].pos = VTransform(pos, matrix);
	vertex[index].norm = VTransformSR(norm, matrix);
}

// ���Z�b�g
void Cube::Reset(void)
{
	vertex.clear();
	index.clear();
}
