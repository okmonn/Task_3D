#include "Play.h"
#include "../Game.h"
#include "../CubeMane.h"
#include "../Input.h"
#include "../Player/Player.h"
#include "../Loading/Loading.h"
#include "../Typedef.h"
#include "DxLib.h"

#define ALPHA_MAX 255

// コンストラクタ
Play::Play(std::weak_ptr<Input>in)
{
	this->in = in;
	alpha = ALPHA_MAX;
	func = &Play::FadeOut;


	Create();
}

// デストラクタ
Play::~Play()
{
	CubeMane::Destroy();
}

// クラスの生成
void Play::Create(void)
{
	CubeMane::Create();
	CubeMane::Get()->CreateCube({ 0.0f, 10.0f, 0.0f }, { 5.0f, 5.0f, 5.0f });
	pl.reset(new Player(in));
	load.reset(new Loading(pl));
}

// 描画
void Play::Draw(void)
{
	if (load->GetFlag() == false)
	{
		load->Draw();
	}
	else
	{
		CubeMane::Get()->Draw();
		pl->Draw();
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawBox({ 0, 0 }, { WINDOW_X, WINDOW_Y }, GetColor(0, 0, 0));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// 処理
void Play::UpData(void)
{
	(this->*func)();
}

// フェードイン
void Play::FadeIn(void)
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
void Play::FadeOut(void)
{
	if (alpha > 0)
	{
		alpha -= 5;
	}
	else
	{
		func = &Play::Run;
	}
}

// 処理
void Play::Run(void)
{
	if (load->GetFlag() == false)
	{
		return;
	}

	CubeMane::Get()->UpData();
	pl->UpData();
}
