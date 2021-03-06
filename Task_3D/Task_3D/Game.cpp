#include "Game.h"
#include "Load.h"
#include "Input.h"
#include "Light\Light.h"
#include "Camera.h"
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

	//windowテキストの設定
	SetWindowText(_T("1601271_岡繁男"));

	//Dxlibの初期化
	if (DxLib_Init() == -1)
	{
		return;
	}

	// 非同期にセット
	SetUseASyncLoadFlag(true);

	//Zバッファの有効
	SetUseZBuffer3D(true);

	//Ｚバッファへの書き込みの有効
	SetWriteZBuffer3D(true);

	//ひとまずﾊﾞｯｸﾊﾞｯﾌｧに描画
	SetDrawScreen(DX_SCREEN_BACK);

	//ライティング計算の有効
	SetUseLighting(true);

	//標準ライトの有効
	SetLightEnable(true);

	SetTextureAddressModeUV(DX_TEXADDRESS_WRAP, DX_TEXADDRESS_WRAP);

	AddFontResourceEx("font/GN-Kin-iro_SansSerif.ttf", FR_PRIVATE, NULL);
	ChangeFont("GN-きんいろサンセリフ", DX_CHARSET_DEFAULT);
	SetFontSize(36);


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
	light = std::make_shared<Light>();
	cam = std::make_shared<Camera>();
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
	cam->UpData();
	scene->UpData();
}

// 実行
void Game::Accept(void)
{
	//ループ処理
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
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
