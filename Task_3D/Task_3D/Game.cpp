#include "Game.h"
#include "Load.h"
#include "Input.h"
#include "Scene\Scene.h"
#include "Scene\Title.h"
#include "Icon\Icon.h"
#include "Typedef.h"
#include "DxLib.h"

// コンストラクタ
Game::Game()
{
}

// デストラクタ
Game::~Game()
{
}

// 初期化
void Game::Init(void)
{
	//グラフィックモードの設定
	SetGraphMode(WINDOW_X, WINDOW_Y, 32);

	//true:window　false:ﾌﾙｽｸﾘｰﾝ
	ChangeWindowMode(true);

	// アイコンセット
	SetWindowIconID(ICON_ID);

	// 非同期にセット
	SetUseASyncLoadFlag(TRUE);

	//windowテキストの設定
	SetWindowText(_T("1601271_岡繁男"));

	//SetWindowIconID(100);

	//Dxlibの初期化
	if (DxLib_Init() == -1)
	{
		return;
	}

	//ひとまずﾊﾞｯｸﾊﾞｯﾌｧに描画
	SetDrawScreen(DX_SCREEN_BACK);

	Create();
}

// シーン切り替え
void Game::ChangeScene(Scene * scene)
{
	this->scene.reset(scene);
}


// クラスの生成
void Game::Create(void)
{
	Load::Create();
	in = std::make_shared<Input>();
	ChangeScene(new Title(in));
}

// 描画
void Game::Draw(void)
{
	//画面消去
	ClsDrawScreen();
	
	scene->Draw();

	//裏画面を表画面に瞬間コピー
	ScreenFlip();
}

// 処理
void Game::UpData(void)
{
	Draw();

	in->UpData();
	scene->UpData();
}

// 実行
void Game::Accept(void)
{
	//ループ処理
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		UpData();
	}
}

// 終了
void Game::End(void)
{
	Load::Destroy();
	DxLib_End();
}
