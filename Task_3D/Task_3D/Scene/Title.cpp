#include "Title.h"
#include "Play.h"
#include "../Load.h"
#include "../Input.h"
#include "../Game.h"
#include "../Typedef.h"
#include "DxLib.h"

// �R���X�g���N�^
Title::Title(std::weak_ptr<Input>in)
{
	this->in = in;
	SetImage("img/title.png", { 242, 87 });
	image.pos = { WINDOW_X / 2 - image.size.x / 2, WINDOW_Y / 2 - image.size.y / 2 };
}

// �f�X�g���N�^
Title::~Title()
{
}

// �`��
void Title::Draw(void)
{
	DrawRectRotaGraph(image);
}

// ����
void Title::UpData(void)
{
	if (in.lock()->CheckTrigger(PAD_INPUT_8) == true)
	{
		Game::Get().ChangeScene(new Play(in));
	}
}
