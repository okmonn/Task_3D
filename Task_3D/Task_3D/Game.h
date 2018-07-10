#pragma once
#include <memory>

class Input;
class Light;
class Camera;
class Scene;

class Game
{
public:
	// �f�X�g���N�^
	~Game();

	// �C���X�^���X�ϐ��̎擾
	static Game& Get(void) {
		static Game instance;
		return instance;
	}

	// �V�[���؂�ւ�
	void ChangeScene(Scene* scene);

	// ������
	void Init(void);

	// ���s
	void Accept(void);

	// �I��
	void End(void);

private:
	// �R���X�g���N�^
	Game();
	Game(const Game&) {
	}

	// �I�y���[�^�̃I�[�o�[���[�h
	void operator=(const Game&) {
	}

	// �N���X�̐���
	void Create(void);

	// �`��
	void Draw(void);

	// ����
	void UpData(void);


	// �C���v�b�g
	std::shared_ptr<Input>in;

	// ���C�g
	std::shared_ptr<Light>light;

	// �J����
	std::shared_ptr<Camera>cam;

	// �V�[��
	std::shared_ptr<Scene>scene;
};

