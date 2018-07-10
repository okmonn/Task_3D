#pragma once
#include "Scene.h"

class Cube;
class Player;
class Loading;

class Play :
	public Scene
{
public:
	// コンストラクタ
	Play(std::weak_ptr<Input>in);
	// デストラクタ
	~Play();

	// 描画
	void Draw(void);

	// 処理
	void UpData(void);

private:
	// クラスの生成
	void Create(void);

	// フェードイン
	void FadeIn(void);

	// フェードアウト
	void FadeOut(void);

	// 処理
	void Run(void);


	// キューブ
	std::shared_ptr<Cube>cube;

	// プレイヤー
	std::shared_ptr<Player>pl;

	// ローディング
	std::shared_ptr<Loading>load;

	// 関数ポインタ
	void (Play::*func)(void);
};

