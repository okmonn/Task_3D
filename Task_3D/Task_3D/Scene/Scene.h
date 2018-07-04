#pragma once
#include <memory>

class Input;

class Scene
{
public:
	// コンストラクタ
	Scene();
	// デストラクタ
	virtual ~Scene();

	// Zバッファのセット
	void SetZBuffer(bool flag1 = true, bool flag2 = true);

	// 描画
	virtual void Draw(void) = 0;

	// 処理
	virtual void UpData(void) = 0;

protected:
	// インプット
	std::weak_ptr<Input>in;

	// 透明度 
	int alpha;
};

