#include "Title.h"
#include "Play.h"
#include "../Load.h"
#include "../Typedef.h"
#include "../Input.h"
#include "../Game.h"
#include "DxLib.h"

// コンストラクタ
Title::Title(std::weak_ptr<Input>in)
{
	this->in = in;
	model = Load::Get()->LoadModel("model/Alicia/Alicia_solid.pmx");
}

// デストラクタ
Title::~Title()
{
}

// 描画
void Title::Draw(void)
{
	MV1DrawModel(model);
}

// 処理
void Title::UpData(void)
{
	if (in.lock()->CheckTrigger(PAD_INPUT_8) == true)
	{
		Game::Get().ChangeScene(new Play(in));
	}
}
