#include "Scene.h"
#include "DxLib.h"

// コンストラクタ
Scene::Scene()
{
	alpha = 0;
}

// デストラクタ
Scene::~Scene()
{
}

// Zバッファのセット
void Scene::SetZBuffer(bool flag1, bool flag2)
{
	//Zバッファの有効
	SetUseZBuffer3D(flag1);
	//Ｚバッファへの書き込みを有効
	SetWriteZBuffer3D(flag2);
}
