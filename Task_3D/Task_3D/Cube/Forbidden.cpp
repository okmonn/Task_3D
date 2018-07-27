#include "Forbidden.h"
#include "../Load.h"
#include "../Typedef.h"


// �R���X�g���N�^
Forbidden::Forbidden(const Vec3f& pos, const Vec3f& size)
{
	this->pos = pos;
	this->size = size;
	fulcrum = pos;

	image = Load::Get()->LoadImg("img/cube_tex.png");

	SetMaterialParam(GetColorF(0.2f, 0.2f, 0.2f, 1.0f), GetColorF(0.75f, 0.75f, 0.75f, 1.0f), GetColorF(1.0f, 1.0f, 1.0f, 1.0f), GetColorF(0.2f, 0.2f, 0.2f, 1.0f), 10.0f);
	VertexInit();
	IndexInit();

	func = &Forbidden::Wait;
}

// �f�X�g���N�^
Forbidden::~Forbidden()
{
	Reset();
}

// �`��
void Forbidden::Draw(void)
{
	int n = DrawPolygonIndexed3D(vertex.data(), (int)vertex.size(), index.data(), (int)vertex.size() / 2, image, true);
}

// �ҋ@
void Forbidden::Wait(void)
{
	if (mode != "wait")
	{
		return;
	}

	//SetMode("move");
	//func = &Forbidden::Move;

	//�x�_�������Ɏw��
	/*fulcrum.x = pos.x;
	fulcrum.y = pos.y - size.y / 2.0f;
	fulcrum.z = pos.z + size.z / 2.0f;*/

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

// �ړ���
void Forbidden::Move(void)
{
	if (mode != "move")
	{
		return;
	}

	if (rotTime >= 90.0f)
	{
		SetMode("moved");
		SetRotate(MGetRotX(RAD(0.0f)));
		func = &Forbidden::Moved;
		return;
	}

	//angle = 1.0f;
	//SetRotate(rot);
	rotTime += angle;

	for (UINT i = 0; i < vertex.size(); ++i)
	{
		SetMatrix(i, MMult(MMult(MGetTranslate(VGet(-fulcrum.x, -fulcrum.y, -fulcrum.z)), rotate), MGetTranslate(VGet(fulcrum.x, fulcrum.y, fulcrum.z))));
	}
}

// �ړ���
void Forbidden::Moved(void)
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
	func = &Forbidden::Wait;
}

// ����
void Forbidden::Delete(void)
{
	if (mode != "delete")
	{
		SetMode("wait");
		func = &Forbidden::Wait;
		return;
	}

	die = true;
}

// ����
void Forbidden::UpData(void)
{
	if (mode == "move")
	{
		func = &Forbidden::Move;
	}

	(this->*func)();

	//Zero();
}
