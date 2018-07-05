#pragma once
#include "../Vector3.h"
#include <memory>

class Input;

class Scene
{
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
	// カメラのセット
	void SetCamera(const Vec3f& position, const Vec3f& target, float fov, float min, float max);

	// 行列のセット
	void SetMatrix(int model, const Vec3f& scal, float angle, const Vec3f& position);


	// インプット
	std::weak_ptr<Input>in;

	// 透明度 
	int alpha;
};

