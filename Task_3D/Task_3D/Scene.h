#pragma once
#include <memory>

class Input;

class Scene
{
public:
	// �R���X�g���N�^
	Scene();
	// �f�X�g���N�^
	virtual ~Scene();

	// �`��
	virtual void Draw(void) = 0;

	// ����
	virtual void UpData(void) = 0;

protected:
	// �C���v�b�g
	std::weak_ptr<Input>in;

	// �����x 
	int alpha;
};

