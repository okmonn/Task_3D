#pragma once

template<typename T>
class Vector3
{
public:
	// X�v�f
	T x;
	// Y�v�f
	T y;
	// Z�v�f
	T z;

	// �R���X�g���N�^
	Vector3() {
	}
	Vector3(T x, T y, T z) : x(x), y(y), z(z) {
	}

	// �f�X�g���N�^
	Vector3() {
	}


};
