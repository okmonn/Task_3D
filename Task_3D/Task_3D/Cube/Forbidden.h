#pragma once
#include "Cube.h"
class Forbidden :
	public Cube
{
public:
	// �R���X�g���N�^
	Forbidden(const Vec3f& pos, const Vec3f& size);
	// �f�X�g���N�^
	~Forbidden();

	// �`��
	void Draw(void);

	// ����
	void UpData(void);

private:
	// �ҋ@
	void Wait(void);
	// �ړ���
	void Move(void);
	// �ړ���
	void Moved(void);
	// ����
	void Delete(void);


	// �֐��|�C���^
	void(Forbidden::*func)(void);
};

