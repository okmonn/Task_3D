#pragma once
#include "../Vector2.h"
#include "../Vector3.h"
#include <vector>
#include "DxLib.h"

class Cube
{
public:
	// �R���X�g���N�^
	Cube();
	// �f�X�g���N�^
	~Cube();

	// �`��
	void Draw(void);

	// ����
	void UpData(void);

private:
	// ���_�̃Z�b�g
	void SetVertex(const Vec3f& pos, const Vec3f& normal, const COLOR_U8& diffuse, const COLOR_U8& specular, const Vec2f& uv, const Vec2f& subuv);
	void VertexInit(void);

	// �C���f�b�N�X�̃Z�b�g
	void SetIndex(unsigned short i);
	void IndexInit(void);

	// �s��̃Z�b�g
	void SetMatrix(unsigned int index, const MATRIX& matrix);

	// ���Z�b�g
	void Reset(void);


	// �摜�f�[�^
	int image;

	// ���_���
	std::vector<VERTEX3D>vertex;

	// �C���f�b�N�X
	std::vector<unsigned short>index;
};

