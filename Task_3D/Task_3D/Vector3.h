#pragma once

template<typename T>
class Vector3
{
public:
	// X要素
	T x;
	// Y要素
	T y;
	// Z要素
	T z;

	// コンストラクタ
	Vector3() {
	}
	Vector3(T x, T y, T z) : x(x), y(y), z(z) {
	}

	// デストラクタ
	Vector3() {
	}


};
