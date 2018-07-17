#include "Cube.h"
#include "../Load.h"
#include "../Typedef.h"

/* wait, move, moved, delete */

// コンストラクタ
Cube::Cube(const Vec3f& pos, const Vec3f& size) : pos(pos), size(size)
{
	Reset();

	image = Load::Get()->LoadImg("img/cube_tex.png");
	fulcrum = this->pos;
	angle = 0.0f;
	rotTime = 0.0f;
	mode = "wait";
	die = false;
	material = {};
	rotate = MGetRotY(angle);

	func = &Cube::Wait;

	SetMaterialParam(GetColorF(0.2f, 0.2f, 0.2f, 1.0f), GetColorF(0.75f, 0.75f, 0.75f, 1.0f), GetColorF(1.0f, 1.0f, 1.0f, 1.0f), GetColorF(0.2f, 0.2f, 0.2f, 1.0f), 10.0f);
	VertexInit();
	IndexInit();
}

// デストラクタ
Cube::~Cube()
{
	Reset();
}

// 状態のセット
void Cube::SetMode(std::string mode, const Vec3f & move, float angle, const MATRIX& rotate)
{
	if (this->mode != mode)
	{
		this->mode = mode;
	}

	rotTime = 0.0f;

	SetAngle(angle);
	SetRotate(rotate);
}

// 描画
void Cube::Draw(void)
{
	for (UINT z = 0; z < 10; ++z)
	{
		for (UINT x = 0; x < 10; ++x)
		{
			float y = (z % 2 == 0 && x % 2 == 0) ? -0.5f : 1.0f;
			DrawCube3D(VGet(x * 5.0f - 5.0f * 5, y, z * 5.0f - 5.0f * 2), VGet(x * 5.0f + 5.0f - 5.0f * 5, y -1.0f, z * 5.0f + 5.0f - 5.0f * 2), GetColor(255, 255, 0), 0xffffff, true);
		}
	}

	int n = DrawPolygonIndexed3D(vertex.data(), (int)vertex.size(), index.data(), (int)vertex.size() / 2, image, true);
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

	for (int i = 0; i < 4; ++i)
	{
		//左上
		SetVertex({ left,  up,   front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 0.0f }, { 0.0f, 0.0f });
		//右上
		SetVertex({ right, up,   front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 0.0f }, { 0.0f, 0.0f });
		//左下
		SetVertex({ left,  down, front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 1.0f }, { 0.0f, 0.0f });
		//右下
		SetVertex({ right, down, front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 1.0f }, { 0.0f, 0.0f });

		for (int m = 0; m < 4; ++m)
		{
			SetMatrix(i * 4 + m, MGetRotY(static_cast<float>(i) * DX_PI_F / 2.0f));
		}
	}

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

// 待機
void Cube::Wait(void)
{
	if (mode != "wait")
	{
		return;
	}

	//支点を奥下に指定
	fulcrum.x = pos.x;
	fulcrum.y = pos.y - size.y / 2.0f;
	fulcrum.z = pos.z + size.z / 2.0f;

	//支点を前下に指定
	/*fulcrum.x = pos.x;
	fulcrum.y = pos.y - size.y / 2.0f;
	fulcrum.z = pos.z - size.z / 2.0f;*/

	//支点を左下に指定
	/*fulcrum.x = pos.x - size.x / 2.0f;
	fulcrum.y = pos.y - size.y / 2.0f;
	fulcrum.z = pos.z;*/

	//支点を右下に指定
	/*fulcrum.x = pos.x + size.x / 2.0f;
	fulcrum.y = pos.y - size.y / 2.0f;
	fulcrum.z = pos.z;*/
}

// 移動
void Cube::Move(void)
{
	if (mode != "move")
	{
		return;
	}

	if (rotTime >= 90.0f)
	{
		SetMode("moved");
		func = &Cube::Moved;
		return;
	}

	angle = 1.0f;
	SetRotate(MGetRotX(RAD(angle)));
	rotTime+= angle;
}

// 移動終了
void Cube::Moved(void)
{
	if (mode != "moved")
	{
		return;
	}

	//中心セット
	pos = 0.0f;
	for (unsigned int i = 0; i < vertex.size(); ++i)
	{
		pos.x += vertex[i].pos.x;
		pos.y += vertex[i].pos.y;
		pos.z += vertex[i].pos.z;
	}
	pos /= static_cast<float>(vertex.size());

	SetMode("wait");
	func = &Cube::Wait;
}

// 消去
void Cube::Delete(void)
{
	if (mode != "delete")
	{
		SetMode("wait");
		func = &Cube::Wait;
		return;
	}

	die = true;
}

// ゼロ
void Cube::Zero(void)
{
	SetAngle(0.0f);
}

// 処理
void Cube::UpData(void)
{
	if (mode == "move")
	{
		func = &Cube::Move;
	}

	(this->*func)();

	for (UINT i = 0; i < vertex.size(); ++i)
	{
		SetMatrix(i, MMult(MMult(MGetTranslate(VGet(-fulcrum.x, -fulcrum.y, -fulcrum.z)), rotate), MGetTranslate(VGet(fulcrum.x, fulcrum.y, fulcrum.z))));
	}

	Zero();
}

// リセット
void Cube::Reset(void)
{
	vertex.clear();
	index.clear();
}
