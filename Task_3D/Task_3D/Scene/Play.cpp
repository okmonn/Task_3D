#include "Play.h"
#include "../Player/Player.h"
#include "DxLib.h"

// コンストラクタ
Play::Play(std::weak_ptr<Input>in)
{
	this->in = in;


	Create();
}

// デストラクタ
Play::~Play()
{
}

// クラスの生成
void Play::Create(void)
{
	pl = std::make_shared<Player>(in);
}

// 描画
void Play::Draw(void)
{
	pl->Draw();
}

// 処理
void Play::UpData(void)
{
	pl->UpData();
}
