#include "Title.h"
#include "Play.h"
#include "../Load.h"
#include "../Input.h"
#include "../Game.h"
#include "../Typedef.h"
#include "DxLib.h"

// 透明度最大値
#define ALPHA_MAX 255

// コンストラクタ
Title::Title(std::weak_ptr<Input>in)
{
	this->in = in;
	alpha = ALPHA_MAX;
	SetImage("img/title.png", { 242, 87 });
	image.pos = { WINDOW_X / 2 - image.size.x / 2, WINDOW_Y / 2 - image.size.y / 2 };
	func = &Title::FadeOut;
}

// デストラクタ
Title::~Title()
{
}

// 描画
void Title::Draw(void)
{
	DrawRectRotaGraph(image);
	DrawString(WINDOW_X / 2 - 64, 450, "Wキー：スタート", GetColor(255, 255, 255));

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawBox({ 0, 0 }, { WINDOW_X, WINDOW_Y }, GetColor(0, 0, 0));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// 処理
void Title::UpData(void)
{
	(this->*func)();
}

// フェードイン
void Title::FadeIn(void)
{
	if (alpha < ALPHA_MAX)
	{
		alpha += 5;
	}
	else
	{
		Game::Get().ChangeScene(new Play(in));
	}
}

// フェードアウト
void Title::FadeOut(void)
{
	if (alpha > 0)
	{
		alpha -= 5;
	}
	else
	{
		if (in.lock()->CheckTrigger(PAD_INPUT_8) == true)
		{
			func = &Title::FadeIn;
		}
	}
}
