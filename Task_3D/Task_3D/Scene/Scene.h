#pragma once
#include "../Vector2.h"
#include "../Vector3.h"
#include <string>
#include <memory>

class Input;

class Scene
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
	Scene();
	// デストラクタ
	virtual ~Scene();

	// 描画
	virtual void Draw(void) = 0;

	// 処理
	virtual void UpData(void) = 0;

protected:
	// 行列のセット
	void SetMatrix(int model, const Vec3f& scal, float angle, const Vec3f& position);

	// 画像のセット
	void SetImage(std::string fileName, const Vec2& size, int x = 1, int y = 1, int large = 1);

	// 描画
	void DrawRectRotaGraph(const Image& image, bool reverse = false);

	// ボックスの描画
	void DrawBox(const Vec2 & pos, const Vec2 & size, unsigned int color, bool fill = true);


	// インプット
	std::weak_ptr<Input>in;

	// 画像
	Image image;

	// 透明度 
	int alpha;
};

