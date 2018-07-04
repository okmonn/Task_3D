#pragma once
class Input
{
public:
	// コンストラクタ
	Input();
	// デストラクタ
	~Input();

	// 現在のキー状態のチェック
	constexpr bool CheckTrigger(int key)const {
		return (state & key) && !(old_state & key);
	}
	// 現在のキー押下状態のチェック
	constexpr bool CheckPress(int key)const {
		return (state & key);
	}

	// 処理
	void UpData(void);

private:
	// 現在のキー状態
	int state;

	// 前のキー状態
	int old_state;
};

