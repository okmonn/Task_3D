#include "Game.h"
#include "Load.h"
#include "Input.h"
#include "Scene\Scene.h"
#include "Scene\Title.h"
#include "Icon\Icon.h"
#include "Typedef.h"
#include "DxLib.h"

// �R���X�g���N�^
Game::Game()
{
}

// �f�X�g���N�^
Game::~Game()
{
}

// ������
void Game::Init(void)
{
	//�O���t�B�b�N���[�h�̐ݒ�
	SetGraphMode(WINDOW_X, WINDOW_Y, 32);

	//true:window�@false:�ٽ�ذ�
	ChangeWindowMode(true);

	// �A�C�R���Z�b�g
	SetWindowIconID(ICON_ID);

	//window�e�L�X�g�̐ݒ�
	SetWindowText(_T("1601271_���ɒj"));

	//Dxlib�̏�����
	if (DxLib_Init() == -1)
	{
		return;
	}

	// �񓯊��ɃZ�b�g
	SetUseASyncLoadFlag(true);

	//Z�o�b�t�@�̗L��
	SetUseZBuffer3D(true);

	//�y�o�b�t�@�ւ̏������݂̗L��
	SetWriteZBuffer3D(true);

	//�ЂƂ܂��ޯ��ޯ̧�ɕ`��
	SetDrawScreen(DX_SCREEN_BACK);

	Create();
}

// �V�[���؂�ւ�
void Game::ChangeScene(Scene * scene)
{
	this->scene.reset(scene);
}


// �N���X�̐���
void Game::Create(void)
{
	Load::Create();
	in = std::make_shared<Input>();
	ChangeScene(new Title(in));
}

// �`��
void Game::Draw(void)
{
	//��ʏ���
	ClsDrawScreen();
	
	scene->Draw();

	//����ʂ�\��ʂɏu�ԃR�s�[
	ScreenFlip();
}

// ����
void Game::UpData(void)
{
	Draw();

	in->UpData();
	scene->UpData();
}

// ���s
void Game::Accept(void)
{
	//���[�v����
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		UpData();
	}
}

// �I��
void Game::End(void)
{
	Load::Destroy();
	DxLib_End();
}
