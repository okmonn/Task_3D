#include "Cube.h"
#include "../Load.h"
#include "../Typedef.h"

/* wait, move, moved, delete */

// �R���X�g���N�^
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

// �f�X�g���N�^
Cube::~Cube()
{
	Reset();
}

// ��Ԃ̃Z�b�g
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

// �`��
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

// �}�e���A���p�����[�^�̐ݒ�
void Cube::SetMaterialParam(const COLOR_F & ambient, const COLOR_F & diffuse, const COLOR_F & specular, const COLOR_F & emissive, float power)
{
	material.Ambient = ambient;
	material.Diffuse = diffuse;
	material.Specular = specular;
	material.Emissive = emissive;
	material.Power = power;
	DxLib::SetMaterialParam(material);
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
	//�����W
	float left = pos.x - size.x / 2.0f;
	//�E���W
	float right = pos.x + size.x / 2.0f;
	//����W
	float up = pos.y + size.y / 2.0f;
	//�����W
	float down = pos.y - size.y / 2.0f;
	//��O���W
	float front = pos.z - size.z / 2.0f;
	//�����W
	float back = pos.z + size.z / 2.0f;

	for (int i = 0; i < 4; ++i)
	{
		//����
		SetVertex({ left,  up,   front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 0.0f }, { 0.0f, 0.0f });
		//�E��
		SetVertex({ right, up,   front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 0.0f }, { 0.0f, 0.0f });
		//����
		SetVertex({ left,  down, front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 1.0f }, { 0.0f, 0.0f });
		//�E��
		SetVertex({ right, down, front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 1.0f }, { 0.0f, 0.0f });

		for (int m = 0; m < 4; ++m)
		{
			SetMatrix(i * 4 + m, MGetRotY(static_cast<float>(i) * DX_PI_F / 2.0f));
		}
	}

	//��
	//����
	SetVertex({ left, up, back   }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 0.0f }, { 0.0f, 0.0f });
	//�E��
	SetVertex({ right, up, back  }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 0.0f }, { 0.0f, 0.0f });
	//����
	SetVertex({ left, up, front  }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 1.0f }, { 0.0f, 0.0f });
	//�E��
	SetVertex({ right, up, front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 1.0f }, { 0.0f, 0.0f });

	//��
	//����
	SetVertex({ left, down, front  }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 0.0f }, { 0.0f, 0.0f });
	//�E��
	SetVertex({ right, down, front }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 0.0f }, { 0.0f, 0.0f });
	//����
	SetVertex({ left, down, back   }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 0.0f, 1.0f }, { 0.0f, 0.0f });
	//�E��
	SetVertex({ right, down, back  }, { 0.0f, 0.0f, -1.0f }, GetColorU8(255, 255, 255, 255), GetColorU8(255, 255, 255, 255), { 1.0f, 1.0f }, { 0.0f, 0.0f });
}

// �C���f�b�N�X�̃Z�b�g
void Cube::SetIndex(unsigned short i)
{
	index.push_back(i);
}

// �C���f�b�N�X�̃Z�b�g
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

// �ҋ@
void Cube::Wait(void)
{
	if (mode != "wait")
	{
		return;
	}

	//�x�_�������Ɏw��
	fulcrum.x = pos.x;
	fulcrum.y = pos.y - size.y / 2.0f;
	fulcrum.z = pos.z + size.z / 2.0f;

	//�x�_��O���Ɏw��
	/*fulcrum.x = pos.x;
	fulcrum.y = pos.y - size.y / 2.0f;
	fulcrum.z = pos.z - size.z / 2.0f;*/

	//�x�_�������Ɏw��
	/*fulcrum.x = pos.x - size.x / 2.0f;
	fulcrum.y = pos.y - size.y / 2.0f;
	fulcrum.z = pos.z;*/

	//�x�_���E���Ɏw��
	/*fulcrum.x = pos.x + size.x / 2.0f;
	fulcrum.y = pos.y - size.y / 2.0f;
	fulcrum.z = pos.z;*/
}

// �ړ�
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

// �ړ��I��
void Cube::Moved(void)
{
	if (mode != "moved")
	{
		return;
	}

	//���S�Z�b�g
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

// ����
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

// �[��
void Cube::Zero(void)
{
	SetAngle(0.0f);
}

// ����
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

// ���Z�b�g
void Cube::Reset(void)
{
	vertex.clear();
	index.clear();
}
