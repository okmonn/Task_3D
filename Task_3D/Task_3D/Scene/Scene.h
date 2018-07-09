#pragma once
#include "../Vector2.h"
#include "../Vector3.h"
#include <string>
#include <memory>

class Input;

class Scene
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
	Scene();
	// �f�X�g���N�^
	virtual ~Scene();

	// �`��
	virtual void Draw(void) = 0;

	// ����
	virtual void UpData(void) = 0;

protected:
	// �s��̃Z�b�g
	void SetMatrix(int model, const Vec3f& scal, float angle, const Vec3f& position);

	// �摜�̃Z�b�g
	void SetImage(std::string fileName, const Vec2& size, int x = 1, int y = 1, int large = 1);

	// �`��
	void DrawRectRotaGraph(const Image& image, bool reverse = false);

	// �{�b�N�X�̕`��
	void DrawBox(const Vec2 & pos, const Vec2 & size, unsigned int color, bool fill = true);


	// �C���v�b�g
	std::weak_ptr<Input>in;

	// �摜
	Image image;

	// �����x 
	int alpha;
};

