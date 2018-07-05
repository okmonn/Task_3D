#pragma once
#include <complex>

/* �R�����x�N�g�� */
template<typename T>
class Vector3
{
public:
	// X����
	T x;

	// Y����
	T y;

	// Z����
	T z;

	// �R���X�g���N�^
	Vector3() {
	};
	// �R���X�g���N�^
	constexpr Vector3(T x, T y, T z) : x(x), y(y), z(z) {
	};

	// �x�N�g���̒���
	T Length(void) const {
		return (T)std::sqrt(LengthSquare());
	}

	// �x�N�g���̒�����2��
	constexpr T LengthSquare(void) const {
		return (Dot(*this));
	}

	// �x�N�g���Ƃ̓���
	constexpr T Dot(const Vector3& vec) const {
		return (x * vec.x + y * vec.y + z * vec.z);
	}

	// �x�N�g���Ƃ̊O��
	constexpr Vector3 Cross(const Vector3& vec) const {
		return { (y * vec.z) - (z * vec.y), (z * vec.x - x * vec.z), (x * vec.y - y * vec.x) };
	}

	// �x�N�g���Ƃ̋���
	T Distance(const Vector3& vec) const {
		return (vec - *this).Length();
	}

	// �x�N�g���Ƃ̃��W�A���p�x
	T Radian(const Vector3& vec) const {
		return (T)std::acos(Dot(vec) / (Length() * vec.Length()));
	}

	// �x�N�g���Ƃ̌ʓx�@�p�x
	T Angle(const Vector3& vec) const {
		return (T)((float)Radian(vec) * 180.0f / 3.141592f);
	}

	// ���K��
	Vector3 Normalized(void) const {
		return (*this / Length());
	}

	// �[���m�F
	constexpr bool IsZero(void) const {
		return (x == (T)0 && y == (T)0 && z == (T)0);
	}

	// �f�X�g���N�^
	~Vector3() {
	};

	// �I�y���[�^�I�[�o�[���[�h
	constexpr Vector3 operator+(void) const {
		return *this;
	}
	constexpr Vector3 operator-(void) const {
		return { -x, -y, -z };
	}
	constexpr Vector3 operator+(const Vector3& vec) const {
		return { x + vec.x, y + vec.y, z + vec.z };
	}
	constexpr Vector3 operator+(const T i) const {
		return { x + i, y + i, z + i };
	}
	constexpr Vector3 operator-(const Vector3& vec) const {
		return { x - vec.x, y - vec.y, z - vec.z };
	}
	constexpr Vector3 operator-(const T i) const {
		return { x - i, y - i, z - i };
	}
	constexpr Vector3 operator*(const Vector3& vec) const {
		return { x * vec.x, y * vec.y, z * vec.z };
	}
	constexpr Vector3 operator*(const T i) const {
		return { x * i, y * i, z * i };
	}
	constexpr Vector3 operator/(const Vector3& vec) const {
		return { x / vec.x, y / vec.y, z / vec.z };
	}
	constexpr Vector3 operator/(const T i) const {
		return { x / i, y / i, z / i };
	}
	void operator=(const Vector3& vec) {
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}
	void operator=(const T i) {
		x = i;
		y = i;
		z = i;
	}
	void operator+=(const Vector3& vec) {
		x += vec.x;
		y += vec.y;
		z += vec.z;
	}
	void operator+=(const T i) {
		x += i;
		y += i;
		z += i;
	}
	void operator-=(const Vector3& vec) {
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
	}
	void operator-=(const T i) {
		x -= i;
		y -= i;
		z -= i;
	}
	void operator*=(const Vector3& vec) {
		x *= vec.x;
		y *= vec.y;
		z *= vec.z;
	}
	void operator*=(const T i) {
		x *= i;
		y *= i;
		z *= i;
	}
	void operator/=(const Vector3& vec) {
		x /= vec.x;
		y /= vec.y;
		z /= vec.z;
	}
	void operator/=(const T i) {
		x /= i;
		y /= i;
		z /= i;
	}
	constexpr bool operator==(const Vector3& vec) const {
		return (x == vec.x && y == vec.y && z == vec.z);
	}
	constexpr bool operator!=(const Vector3& vec) const {
		return !(x == vec.x && y == vec.y && z == vec.z);
	}
};

template<typename T>
inline constexpr Vector3<T> operator+(T i, Vector3<T>& vec) {
	return { vec.x + i, vec.y + i, vec.z + i };
}

template<typename T>
inline constexpr Vector3<T> operator-(T i, Vector3<T>& vec) {
	return { vec.x - i, vec.y - i, vec.z - i };
}

template<typename T>
inline constexpr Vector3<T> operator*(T i, Vector3<T>& vec) {
	return { vec.x * i, vec.y * i, vec.z * i };
}

template<typename T>
inline constexpr Vector3<T>operator/(T i, Vector3<T>& vec) {
	return { vec.x / i, vec.y / i, vec.z / i };
}

// Vector3<int>�̌^�ϊ�
typedef Vector3<int>Vec3;
// Vector3<float>�̌^�ϊ�
typedef Vector3<float>Vec3f;