#pragma once
#include "Cube.h"

class Foundation :
	public Cube
{
public:
	// �R���X�g���N�^
	Foundation(const Vec3f& pos, const Vec3f& size, int x, int y, int z);
	// �f�X�g���N�^
	~Foundation();

	// �`��
	void Draw(void);

	// ����
	void UpData(void);

private:

};

