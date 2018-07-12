#include "Light.h"
#include "DxLib.h"

// コンストラクタ
Light::Light()
{
	dir = 1.0f;
	diffuse = 0.8f;
	ambient = 0.3f;
	specular = 1.0f;

	SetLight();
}

// デストラクタ
Light::~Light()
{
}

// ライトのセット
void Light::SetLight(void)
{
	//ライトの向きのセット
	SetLightDirection(VGet(dir.x, dir.y, dir.z));
	//環境色
	SetGlobalAmbientLight(GetColorF(0.3f, 0.3f, 0.3f, 1.0f));
	//ディフューズ色のセット
	SetLightDifColor(GetColorF(diffuse.x, diffuse.y, diffuse.z, 1.0f));
	//アンビエント色のセット
	SetLightAmbColor(GetColorF(ambient.x, ambient.y, ambient.z, 1.0f));
	//スペキュラー色のセット
	SetLightSpcColor(GetColorF(specular.x, specular.y, specular.z, 1.0f));
}
