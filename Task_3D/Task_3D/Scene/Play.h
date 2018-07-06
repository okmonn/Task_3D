#pragma once
#include "Scene.h"

class Player;

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


	// プレイヤー
	std::shared_ptr<Player>pl;
};

