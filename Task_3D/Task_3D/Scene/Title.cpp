#include "Title.h"
#include "Play.h"
#include "../Load.h"
#include "../Input.h"
#include "../Game.h"
#include "../Typedef.h"
#include "DxLib.h"

// コンストラクタ
Title::Title(std::weak_ptr<Input>in)
{
	this->in = in;
	SetImage("img/title.png", { 242, 87 });
	image.pos = { WINDOW_X / 2 - image.size.x / 2, WINDOW_Y / 2 - image.size.y / 2 };
}

// デストラクタ
Title::~Title()
{
}

// 描画
void Title::Draw(void)
{
	DrawRectRotaGraph(image);
}

// 処理
void Title::UpData(void)
{
	if (in.lock()->CheckTrigger(PAD_INPUT_8) == true)
	{
		Game::Get().ChangeScene(new Play(in));
	}
}
