#pragma once
#include "Scene.h"

class Title :
	public Scene
{
public:
	// �R���X�g���N�^
	Title(std::weak_ptr<Input>in);
	// �f�X�g���N�^
	~Title();

	// �`��
	void Draw(void);

	// ����
	void UpData(void);

private:
	// �t�F�[�h�C��
	void FadeIn(void);

	// �t�F�[�h�A�E�g
	void FadeOut(void);


	// �֐��|�C���^
	void (Title::*func)(void);
};

