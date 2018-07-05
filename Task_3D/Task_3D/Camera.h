#pragma once
#include "Vector3.h"

class Camera
{
public:
	// コンストラクタ
	Camera();
	// デストラクタ
	~Camera();

	// カメラのセット
	void SetCamera(const Vec3f & pos, const Vec3f & target, const float fov, const float min, const float max);

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
	void SetPos(const float i) {
		pos = i;
	}

	// ターゲットの取得
	Vec3f GetTarget(void) const {
		return target;
	}
	// ターゲットのセット
	void SetTarget(const Vec3f& pos) {
		target = pos;
	}
	void SetTarget(const float i) {
		target = i;
	}

	// 遠近値の取得
	constexpr float GetAngle(void) const {
		return fov;
	}
	// 遠近値のセット
	void SetAngle(const float i) {
		fov = i;
	}

	//	ニア値の取得
	constexpr float GetNear(void) const {
		return min;
	}
	// ニア値のセット
	void SetNear(const float i) {
		min = i;
	}

	// ファー値の取得
	constexpr float GetFar(void) const {
		return max;
	}
	// ファー値のセット
	void SetFar(const float i) {
		max = i;
	}

private:
	// 座標
	Vec3f pos;

	// ターゲット
	Vec3f target;

	// 角度
	float fov;

	// ニア値
	float min;

	// ファー値
	float max;
};

