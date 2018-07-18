#include "Cube.h"
#include "../Load.h"
#include "../Typedef.h"

/* wait, move, moved, delete */

// コンストラクタ
Cube::Cube()
{
	Reset();

	dir = { 0.0f, -1.0f, 1.0f };
	angle = 0.0f;
	rotTime = 0.0f;
	mode = "wait";
	die = false;
	material = {};
	rotate = MGetRotY(angle);
}

// デストラクタ
Cube::~Cube()
{
}

// 状態のセット
void Cube::SetMode(std::string mode, float angle, const MATRIX& rotate, const Vec3f& dir)
{
	if (this->mode != mode)
	{
		this->mode = mode;
	}
	else
	{
		return;
	}

	rotTime = 0.0f;
	rot = rotate;
	SetAngle(angle);
	SetRotate(rotate);
	SetDir(dir);

	fulcrum.x = pos.x + (size.x / 2.0f * dir.x);
	fulcrum.y = pos.y + (size.y / 2.0f * dir.y);
	fulcrum.z = pos.z + (size.z / 2.0f * dir.z);
}

// マテリアルパラメータの設定
void Cube::SetMaterialParam(const COLOR_F & ambient, const COLOR_F & diffuse, const COLOR_F & specular, const COLOR_F & emissive, float power)
{
	material.Ambient = ambient;
	material.Diffuse = diffuse;
	material.Specular = specular;
	material.Emissive = emissive;
	material.Power = power;
	DxLib::SetMaterialParam(material);
}

// 頂点のセット
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

// 頂点のセット
void Cube::VertexInit(void)
{
	//左座標
	float left = pos.x - size.x / 2.0f;
	//右座標
	float right = pos.x + size.x / 2.0f;
	//上座標
	float up = pos.y + size.y / 2.0f;
	//下座標
	float down = pos.y - size.y / 2.0f;
	//手前座標
	float front = pos.z - size.z / 2.0f;
	//奥座標
	float back = pos.z + size.z / 2.0f;

	//前
	//左上
	SetVertex({ left,  up,   front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 0.0f }, { 0.0f, 0.0f });
	//右上
	SetVertex({ right, up,   front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 0.0f }, { 0.0f, 0.0f });
	//左下
	SetVertex({ left,  down, front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 1.0f }, { 0.0f, 0.0f });
	//右下
	SetVertex({ right, down, front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 1.0f }, { 0.0f, 0.0f });

	//左
	//左上
	SetVertex({ left,  up,   back }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 0.0f }, { 0.0f, 0.0f });
	//右上
	SetVertex({ left, up,   front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 0.0f }, { 0.0f, 0.0f });
	//左下
	SetVertex({ left,  down, back }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 1.0f }, { 0.0f, 0.0f });
	//右下
	SetVertex({ left, down, front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 1.0f }, { 0.0f, 0.0f });

	//奥
	//左上
	SetVertex({ right,  up,   back }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 0.0f }, { 0.0f, 0.0f });
	//右上
	SetVertex({ left, up,   back }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 0.0f }, { 0.0f, 0.0f });
	//左下
	SetVertex({ right,  down, back }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 1.0f }, { 0.0f, 0.0f });
	//右下
	SetVertex({ left, down, back }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 1.0f }, { 0.0f, 0.0f });

	//右
	//左上
	SetVertex({ right,  up,   front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 0.0f }, { 0.0f, 0.0f });
	//右上
	SetVertex({ right, up,   back }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 0.0f }, { 0.0f, 0.0f });
	//左下
	SetVertex({ right,  down, front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 1.0f }, { 0.0f, 0.0f });
	//右下
	SetVertex({ right, down, back }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 1.0f }, { 0.0f, 0.0f });

	//上
	//左上
	SetVertex({ left, up, back   }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 0.0f }, { 0.0f, 0.0f });
	//右上
	SetVertex({ right, up, back  }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 0.0f }, { 0.0f, 0.0f });
	//左下
	SetVertex({ left, up, front  }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 1.0f }, { 0.0f, 0.0f });
	//右下
	SetVertex({ right, up, front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 1.0f }, { 0.0f, 0.0f });

	//下
	//左上
	SetVertex({ left, down, front  }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 0.0f }, { 0.0f, 0.0f });
	//右上
	SetVertex({ right, down, front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 0.0f }, { 0.0f, 0.0f });
	//左下
	SetVertex({ left, down, back   }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 1.0f }, { 0.0f, 0.0f });
	//右下
	SetVertex({ right, down, back  }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 1.0f }, { 0.0f, 0.0f });
}

// インデックスのセット
void Cube::SetIndex(unsigned short i)
{
	index.push_back(i);
}

// インデックスのセット
void Cube::IndexInit(void)
{
	USHORT index = 0;
	for (UINT i = 0; i < vertex.size() / 4; ++i)
	{
		SetIndex(index++);
		SetIndex(index++);
		SetIndex(index--);
		SetIndex(index);
		index += 2;
		SetIndex(index--);
		SetIndex(index);
		index += 2;
	}
}


// 行列のセット
void Cube::SetMatrix(unsigned int index, const MATRIX & matrix)
{
	if (index >= vertex.size())
	{
		OutputDebugString("\n配列を超えた指定です\n");
		return;
	}

	auto pos = vertex[index].pos;
	auto norm = vertex[index].norm;
	vertex[index].pos = VTransform(pos, matrix);
	vertex[index].norm = VTransformSR(norm, matrix);
}

// ゼロ
void Cube::Zero(void)
{
	SetAngle(0.0f);
	SetRotate(MGetRotY(0.0f));
}

// リセット
void Cube::Reset(void)
{
	vertex.clear();
	index.clear();
}
