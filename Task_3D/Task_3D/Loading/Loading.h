#pragma once
#include "../Vector2.h"
#include <memory>

class Player;

class Loading
{
	// 画像データ
	struct Image {
		int image;
		Vec2 pos;
		Vec2 size;
		int x;
		int y;
		int max;
		int index;
		int large;
	};

public:
	// コンストラクタ
	Loading(std::weak_ptr<Player>pl);
	// デストラクタ
	~Loading();

	// 描画
	void Draw(void);

	// 読み込み完了フラグの取得
	constexpr bool GetFlag(void) const {
		return flag;
	}

private:
	// 画像のセット
	void SetImage(std::string fileName, const Vec2& size, const Vec2& pos = { 0,0 }, int x = 1, int y = 1, int large = 1);

	// 描画
	void DrawRectRotaGraph(const Image& image, const float& angle = 0.0f, bool reverse = false);


	// プレイヤー
	std::weak_ptr<Player>pl;

	// 画像データ
	Image image;

	// 角度
	float angle;

	// 読み込み完了フラグ
	bool flag;

};

