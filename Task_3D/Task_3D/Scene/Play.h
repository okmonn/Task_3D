#pragma once
#include "Scene.h"

class Player;

class Play :
	public Scene
{
public:
	// �R���X�g���N�^
	Play(std::weak_ptr<Input>in);
	// �f�X�g���N�^
	~Play();

	// �`��
	void Draw(void);

	// ����
	void UpData(void);

private:
	// �N���X�̐���
	void Create(void);


	// �v���C���[
	std::shared_ptr<Player>pl;
};

