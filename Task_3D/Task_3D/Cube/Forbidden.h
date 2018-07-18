#pragma once
#include "Cube.h"
class Forbidden :
	public Cube
{
public:
	// コンストラクタ
	Forbidden(const Vec3f& pos, const Vec3f& size);
	// デストラクタ
	~Forbidden();

	// 描画
	void Draw(void);

	// 処理
	void UpData(void);

private:
	// 待機
	void Wait(void);
	// 移動中
	void Move(void);
	// 移動後
	void Moved(void);
	// 消去
	void Delete(void);


	// 関数ポインタ
	void(Forbidden::*func)(void);
};

