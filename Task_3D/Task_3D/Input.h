#pragma once
class Input
{
public:
	// �R���X�g���N�^
	Input();
	// �f�X�g���N�^
	~Input();

	// ���݂̃L�[��Ԃ̃`�F�b�N
	constexpr bool CheckTrigger(int key)const {
		return (state & key) && !(old_state & key);
	}
	// ���݂̃L�[������Ԃ̃`�F�b�N
	constexpr bool CheckPress(int key)const {
		return (state & key);
	}

	// ����
	void UpData(void);

private:
	// ���݂̃L�[���
	int state;

	// �O�̃L�[���
	int old_state;
};

