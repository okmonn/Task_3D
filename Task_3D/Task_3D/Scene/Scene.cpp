#include "Scene.h"
#include "../Load.h"
#include "../Typedef.h"
#include "DxLib.h"

// �R���X�g���N�^
Scene::Scene()
{
	alpha = 0;
}

// �f�X�g���N�^
Scene::~Scene()
{
}

// �s��̃Z�b�g
void Scene::SetMatrix(int model, const Vec3f& scal, float angle, const Vec3f& position)
{
	// �g��A��]�A�ړ��̏���
	MV1SetMatrix(model, MMult(MMult(
		MGetScale(VGet(scal.x, scal.y, scal.z)),
		MGetRotY(RAD(angle))),
		MGetTranslate(VGet(position.x, position.y, position.z))));
}

// �摜�̃Z�b�g
void Scene::SetImage(std::string fileName, const Vec2 & size, int x, int y,  int large)
{
	image.image = Load::Get()->LoadImg(fileName.c_str());
	image.pos = 0;
	image.size = size;
	image.x = x;
	image.y = y;
	image.max = image.x * image.y;
	image.index = 0;
	image.large = large;
}

// �`��
void Scene::DrawRectRotaGraph(const Image & image, bool revrse)
{
	DrawRectRotaGraph2(image.pos.x + (image.size.x * image.large) / 2, image.pos.y + (image.size.y * image.large) / 2,
		(image.index % image.x) * image.size.x, (image.index / image.x) * image.size.y,
		image.size.x, image.size.y,
		image.size.x / 2, image.size.y / 2,
		(double)image.large, 0.0, image.image, true, revrse);
}

// �{�b�N�X�̕`��
void Scene::DrawBox(const Vec2 & pos, const Vec2 & size, unsigned int color, bool fill)
{
	DxLib::DrawBox(pos.x, pos.y, pos.x + size.x, pos.y + size.y, color, fill);
}
