#pragma once
#include "../Vector3.h"
#include <memory>

class Input;

class Player
{
public:
	// コンストラクタ
	Player(std::weak_ptr<Input>in);
	// デストラクタ
	~Player();

	// 描画
	void Draw(void);

	// 処理
	void UpData(void);

	// 座標の取得
	Vec3f GetPos(void) const {
		return pos;
	}
	// 座標のセット
	void SetPos(const Vec3f& pos) {
		this->pos = pos;
	}

	// 拡大率の取得
	Vec3f GetScale(void) const {
		return scale;
	}
	// 拡大率のセット
	void SetScale(const Vec3f& scale) {
		this->scale = scale;
	}

	// 角度の取得
	constexpr float GetAngle(void) const {
		return angle;
	}
	// 角度のセット
	void SetAngle(const float& i) {
		angle = i;
	}

private:
	// 行列のセット
	void SetMatrix(int model, const Vec3f& scale, float angle, const Vec3f& position);


	// インプット
	std::weak_ptr<Input>in;

	// モデル
	int model;

	// 座標
	Vec3f pos;

	// 拡大率
	Vec3f scale;

	// 角度
	float angle;
};

