#pragma once
#include "../Vector2.h"
#include "../Vector3.h"
#include <string>
#include <vector>
#include "DxLib.h"

class Cube
{
public:
	// コンストラクタ
	Cube(const Vec3f& pos, const Vec3f& size);
	// デストラクタ
	~Cube();

	// 状態のセット
	void SetMode(std::string mode, const Vec3f& move = { 0.0f, 0.0f, 0.0f }, float angle = 0.0f, const MATRIX& rotate = MGetRotY(0.0f));

	// 描画
	void Draw(void);

	// 処理
	void UpData(void);

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

	// 角度の取得
	float GetAngle(void) const {
		return angle;
	}
	// 角度のセット
	void SetAngle(float angle) {
		this->angle = angle;
	}

	// 移動量の取得
	Vec3f GetMove(void) const {
		return move;
	}
	// 移動量のセット
	void SetMove(const Vec3f& move) {
		this->move = move;
	}

	// 回転行列の取得
	MATRIX GetRotate(void) const {
		return rotate;
	}
	// 回転行列のセット
	void SetRotate(const MATRIX& matrix) {
		rotate = matrix;
	}

private:
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

	// 待機
	void Wait(void);

	// 移動
	void Move(void);

	// 移動終了
	void Moved(void);

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

	// 角度
	float angle;

	// 移動量
	Vec3f move;

	// 状態
	std::string mode;

	// 回転行列
	MATRIX rotate;

	// 頂点情報
	std::vector<VERTEX3D>vertex;

	// インデックス
	std::vector<unsigned short>index;

	// マテリアルアンビエント
	MATERIALPARAM material;

	// 関数ポインタ
	void (Cube::*func)(void);
};

