#pragma once
#ifndef VEC2_H
#define VEC2_H

struct Vec2 {
	float x;
	float y;
	Vec2():x(0),y(0){}
	Vec2(int px, int py) :x(px), y(py) {}
	Vec2(float px, float py) :x(px), y(py) {}
	Vec2(double px, double py): x(px),y(py) {}
	Vec2(const Vec2& p):x(p.x),y(p.y){}

	inline Vec2 operator+(const Vec2& p) {
		return Vec2(this->x + p.x, this->y + p.y);;
	}

	inline Vec2 operator-(const Vec2& p) {
		return Vec2(this->x - p.x, this->y - p.y);
	}

	friend std::ostream& operator<<(std::ostream& output,
		const Vec2& v)
	{
		output << v.x << " " << v.y;
		return output;
	}
};

inline Vec2 operator*(float f, const Vec2& p) {
	return Vec2(p.x * f, p.y * f);
}

inline Vec2 operator*(const Vec2& p, float f) {
	return Vec2(p.x * f, p.y * f);
}

inline Vec2 operator*(double d, const Vec2& p) {
	return Vec2(p.x * d, p.y * d);
}

inline Vec2 operator*(const Vec2& p, double d) {
	return Vec2(p.x * d, p.y * d);
}

inline Vec2 operator/(const Vec2& p, float f) {
	return Vec2((float)p.x / f, (float)p.y / f);
}

#endif // !POINT_H
