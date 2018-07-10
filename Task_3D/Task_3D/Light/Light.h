#pragma once
#include "../Vector3.h"

class Light
{
public:
	// コンストラクタ
	Light();
	// デストラクタ
	~Light();

	// 向きの取得
	Vec3f GetDir(void) const {
		return dir;
	}

	// ディフューズ色の取得
	Vec3f GetDiffuse(void) const {
		return diffuse;
	}

	// アンビエント色の取得
	Vec3f GetAmbient(void) const {
		return ambient;
	}

	// スペキュラー色の取得
	Vec3f GetSpecular(void) const {
		return specular;
	}

private:
	// ライトのセット
	void SetLight(void);


	// 向き
	Vec3f dir;

	// ディフューズ色
	Vec3f diffuse;

	// アンビエント色
	Vec3f ambient;

	//スペキュラー色
	Vec3f specular;
};

