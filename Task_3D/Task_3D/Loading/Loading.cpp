#include "Loading.h"
#include "../Load.h"
#include "../Player/Player.h"
#include "../Typedef.h"
#include "DxLib.h"

// コンストラクタ
Loading::Loading(std::weak_ptr<Player>pl) : pl(pl)
{
	SetImage("img/nowloading.png", { 256, 256 }, { WINDOW_X / 2 - 256 / 2, WINDOW_Y / 2 - 256 / 2 });
	angle = 0.0f;
	flag = false;
}

// デストラクタ
Loading::~Loading()
{
}

// 描画
void Loading::Draw(void)
{
	if (CheckHandleASyncLoad(pl.lock()->GetModelHandle()) == TRUE)
	{
		DrawRectRotaGraph(image, RAD(angle));
		angle += 1.0f;
	}
	else
	{
		flag = true;
	}
}

// 画像のセット
void Loading::SetImage(std::string fileName, const Vec2 & size, const Vec2 & pos, int x, int y, int large)
{
	image.image = Load::Get()->LoadImg(fileName.c_str());
	image.pos = pos;
	image.size = size;
	image.x = x;
	image.y = y;
	image.max = image.x * image.y;
	image.index = 0;
	image.large = large;
}

// 描画
void Loading::DrawRectRotaGraph(const Image & image, const float & angle, bool reverse)
{
	DrawRectRotaGraph2(image.pos.x + (image.size.x * image.large) / 2, image.pos.y + (image.size.y * image.large) / 2,
		(image.index % image.x) * image.size.x, (image.index / image.x) * image.size.y,
		image.size.x, image.size.y,
		image.size.x / 2, image.size.y / 2,
		(double)image.large, (double)angle, image.image, true, reverse);
}
