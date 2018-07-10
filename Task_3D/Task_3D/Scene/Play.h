#pragma once
#include "Scene.h"

class Cube;
class Player;
class Loading;

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

	// �t�F�[�h�C��
	void FadeIn(void);

	// �t�F�[�h�A�E�g
	void FadeOut(void);

	// ����
	void Run(void);


	// �L���[�u
	std::shared_ptr<Cube>cube;

	// �v���C���[
	std::shared_ptr<Player>pl;

	// ���[�f�B���O
	std::shared_ptr<Loading>load;

	// �֐��|�C���^
	void (Play::*func)(void);
};

