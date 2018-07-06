#pragma once
#include <complex>

/* �Q�����x�N�g�� */
template<typename T>
class Vector2
{
public:
	// X����
	T x;

	// Y����
	T y;

	// �R���X�g���N�^
	Vector2() {
	}
	// �R���X�g���N�^
	constexpr Vector2(T x, T y) : x(x), y(y) {
	}

	// �x�N�g���̒���
	T Length(void) const {
		return (T)std::sqrt(LengthSquare());
	}

	// �x�N�g���̒�����2��
	constexpr T LengthSquare(void) const {
		return (Dot(*this));
	}

	// �x�N�g���Ƃ̓���
	constexpr T Dot(const Vector2& vec) const {
		return (x * vec.x + y * vec.y);
	}

	// �x�N�g���Ƃ̋���
	T Distance(const Vector2& vec) const {
		return (vec - *this).Length();
	}

	// �x�N�g���Ƃ̃��W�A���p�x
	T Radian(const Vector2& vec) const {
		return (T)std::acos(Dot(vec) / (Length() * vec.Length()));
	}

	// �x�N�g���Ƃ̌ʓx�@�p�x
	T Angle(const Vector2& vec) const {
		return (T)((float)Radian(vec) * 180.0f / 3.141592f);
	}

	// ���K��
	Vector2 Normalized(void) const {
		return (*this / Length());
	}

	// �[���m�F
	constexpr bool IsZero(void) const {
		return (x == (T)0 && y == (T)0);
	}

	// �f�X�g���N�^
	~Vector2() {
	}

	// �I�y���[�^�I�[�o�[���[�h
	constexpr Vector2 operator+(void) const {
		return *this;
	}
	constexpr Vector2 operator-(void) const {
		return { -x, -y };
	}
	constexpr Vector2 operator+(const Vector2& vec) const {
		return { x + vec.x, y + vec.y };
	}
	constexpr Vector2 operator+(const T i) const {
		return { x + i, y + i };
	}
	constexpr Vector2 operator-(const Vector2& vec) const {
		return { x - vec.x, y - vec.y };
	}
	constexpr Vector2 operator-(const T i) const {
		return { x - i, y - i };
	}
	constexpr Vector2 operator*(const Vector2& vec) const {
		return { x * vec.x, y * vec.y };
	}
	constexpr Vector2 operator*(const T i) const {
		return { x * i, y * i };
	}
	constexpr Vector2 operator/(const Vector2& vec) const {
		return { x / vec.x, y / vec.y };
	}
	constexpr Vector2 operator/(const T i) const {
		return { x / i, y / i };
	}
	void operator=(const Vector2& vec) {
		x = vec.x;
		y = vec.y;
	}
	void operator=(const T i) {
		x = i;
		y = i;
	}
	void operator+=(const Vector2& vec) {
		x += vec.x;
		y += vec.y;
	}
	void operator+=(const T i) {
		x += i;
		y += i;
	}
	void operator-=(const Vector2& vec) {
		x -= vec.x;
		y -= vec.y;
	}
	void operator-=(const T i) {
		x -= i;
		y -= i;
	}
	void operator*=(const Vector2& vec) {
		x *= vec.x;
		y *= vec.y;
	}
	void operator*=(const T i) {
		x *= i;
		y *= i;
	}
	void operator/=(const Vector2& vec) {
		x /= vec.x;
		y /= vec.y;
	}
	void operator/=(const T i) {
		x /= i;
		y /= i;
	}
	constexpr bool operator==(const Vector2& vec) const {
		return (x == vec.x && y == vec.y);
	}
	constexpr bool operator!=(const Vector2& vec) const {
		return !(x == vec.x && y == vec.y);
	}
};

template<typename T>
inline constexpr Vector2<T> operator+(T i, Vector2<T>& vec) {
	return { vec.x + i, vec.y + i };
}

template<typename T>
inline constexpr Vector2<T> operator-(T i, Vector2<T>& vec) {
	return { vec.x - i, vec.y - i };
}

template<typename T>
inline constexpr Vector2<T> operator*(T i, Vector2<T>& vec) {
	return { vec.x * i, vec.y * i };
}

template<typename T>
inline constexpr Vector2<T>operator/(T i, Vector2<T>& vec) {
	return { vec.x / i, vec.y / i };
}

// Vector2<int>�̌^�ϊ�
typedef Vector2<int>Vec2;
// Vector2<float>�̌^�ϊ�
typedef Vector2<float>Vec2f;