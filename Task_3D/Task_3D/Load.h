#pragma once
#include <map>
#include <string>

class Load
{
public:
	// �f�X�g���N�^
	~Load();

	// �C���X�^���X�ϐ��̎擾
	static Load* Get(void) {
		return instance;
	}
	// �C���X�^���X��
	static void Create(void);
	// �j��
	static void Destroy(void);

	// �摜�̓ǂݍ���
	int LoadImg(std::string fileName);

	// ���f���̓ǂݍ���
	int LoadModel(std::string fileName);

private:
	// �R���X�g���N�^
	Load();
	Load(const Load&) {
	}
	void operator=(const Load&) {
	}

	// ���Z�b�g
	void Reset(void);


	// �C���X�^���X�ϐ�
	static Load* instance;

	// �摜�f�[�^
	std::map<std::string, int>image;

	// ���f���f�[�^
	std::map<std::string, int>model;
};
