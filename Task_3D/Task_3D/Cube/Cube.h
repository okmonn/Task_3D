#pragma once
#include "../Vector2.h"
#include "../Vector3.h"
#include <string>
#include <vector>
#include "../Typedef.h"
#include "DxLib.h"

class Cube
{
public:
	// コンストラクタ
	Cube();
	// デストラクタ
	virtual ~Cube();

	// 状態のセット
	void SetMode(std::string mode, float angle = 1.0f, const MATRIX& rotate = MGetRotX(RAD(1.0f)), const Vec3f& dir = {0.0f, -1.0f, 1.0f});

	// 描画
	virtual void Draw(void) = 0;

	// 処理
	virtual void UpData(void) = 0;

	// 中心座標の取得
	Vec3f GetCenter(void) const
	{
		return pos;
	}
	// 中心座標のセット
	void SetCenter(const Vec3f& vec) {
		pos = vec;
	}

	// 支点座標の取得
	Vec3f GetFulcrum(void) const {
		return fulcrum;
	}
	// 支点座標のセット
	void SetFulcrum(const Vec3f& fulcrum) {
		this->fulcrum = fulcrum;
	}

	// サイズの取得
	Vec3f GetSize(void) const {
		return size;
	}
	// サイズのセット
	void SetSize(const Vec3f& vec) {
		size = vec;
	}

	// 移動方向の取得
	Vec3f GetDir(void) const {
		return dir;
	}
	// 移動方向のセット
	void SetDir(const Vec3f& dir) {
		this->dir = dir;
	}

	// 角度の取得
	float GetAngle(void) const {
		return angle;
	}
	// 角度のセット
	void SetAngle(float angle) {
		this->angle = angle;
	}

	// 回転行列の取得
	MATRIX GetRotate(void) const {
		return rotate;
	}
	// 回転行列のセット
	void SetRotate(const MATRIX& matrix) {
		rotate = matrix;
	}

	// 状態の取得
	std::string GetMode(void) const {
		return mode;
	}

	// 消去フラグの取得
	bool GetDie(void) const {
		return die;
	}
	// 消去フラグのセット
	void SetDie(const bool& flag) {
		die = flag;
	}

protected:
	// マテリアルパラメータの設定
	void SetMaterialParam(const COLOR_F& ambient, const COLOR_F& diffuse, const COLOR_F& specular, const COLOR_F& emissive, float power);

	// 頂点のセット
	void SetVertex(const Vec3f& pos, const Vec3f& normal, const COLOR_U8& diffuse, const COLOR_U8& specular, const Vec2f& uv, const Vec2f& subuv);
	void VertexInit(void);

	// インデックスのセット
	void SetIndex(unsigned short i);
	void IndexInit(void);

	// 行列のセット
	void SetMatrix(unsigned int index, const MATRIX& matrix);

	// ゼロ
	void Zero(void);

	// リセット
	void Reset(void);


	// 画像データ
	int image;

	// 中心座標
	Vec3f pos;

	// 支点座標
	Vec3f fulcrum;

	// サイズ
	Vec3f size;

	// 移動方向
	Vec3f dir;

	// 角度
	float angle;

	// 回転時間
	float rotTime;

	// 状態
	std::string mode;

	// 消去フラグ
	bool die;

	// 回転行列
	MATRIX rotate;

	MATRIX rot;

	// 頂点情報
	std::vector<VERTEX3D>vertex;

	// インデックス
	std::vector<unsigned short>index;

	// マテリアルアンビエント
	MATERIALPARAM material;

	int x;
	int y;
	int z;
};

