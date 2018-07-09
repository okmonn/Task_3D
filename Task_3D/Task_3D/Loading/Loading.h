#pragma once
#include "../Vector2.h"
#include <memory>

class Player;

class Loading
{
	// �摜�f�[�^
	struct Image {
		int image;
		Vec2 pos;
		Vec2 size;
		int x;
		int y;
		int max;
		int index;
		int large;
	};

public:
	// �R���X�g���N�^
	Loading(std::weak_ptr<Player>pl);
	// �f�X�g���N�^
	~Loading();

	// �`��
	void Draw(void);

	// �ǂݍ��݊����t���O�̎擾
	constexpr bool GetFlag(void) const {
		return flag;
	}

private:
	// �摜�̃Z�b�g
	void SetImage(std::string fileName, const Vec2& size, const Vec2& pos = { 0,0 }, int x = 1, int y = 1, int large = 1);

	// �`��
	void DrawRectRotaGraph(const Image& image, const float& angle = 0.0f, bool reverse = false);


	// �v���C���[
	std::weak_ptr<Player>pl;

	// �摜�f�[�^
	Image image;

	// �p�x
	float angle;

	// �ǂݍ��݊����t���O
	bool flag;

};

