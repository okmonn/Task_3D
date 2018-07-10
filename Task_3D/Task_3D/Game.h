#pragma once
#include <memory>

class Input;
class Light;
class Camera;
class Scene;

class Game
{
public:
	// デストラクタ
	~Game();

	// インスタンス変数の取得
	static Game& Get(void) {
		static Game instance;
		return instance;
	}

	// シーン切り替え
	void ChangeScene(Scene* scene);

	// 初期化
	void Init(void);

	// 実行
	void Accept(void);

	// 終了
	void End(void);

private:
	// コンストラクタ
	Game();
	Game(const Game&) {
	}

	// オペレータのオーバーロード
	void operator=(const Game&) {
	}

	// クラスの生成
	void Create(void);

	// 描画
	void Draw(void);

	// 処理
	void UpData(void);


	// インプット
	std::shared_ptr<Input>in;

	// ライト
	std::shared_ptr<Light>light;

	// カメラ
	std::shared_ptr<Camera>cam;

	// シーン
	std::shared_ptr<Scene>scene;
};

