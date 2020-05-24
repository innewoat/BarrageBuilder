#pragma once
#ifndef TRACK_H
#define TRACK_H

#include "vec2.h"
#include <vector>
#include <cmath>
#include <iostream>

class Track {
public:
	virtual Vec2 get_pos(float t) = 0;
};

class FixedTrack :public Track {
public:
	FixedTrack(const Vec2& p) :pos(p) {}
	Vec2 get_pos(float t) {
		return pos;
	}
private:
	Vec2 pos;
};

class LineTrack :public Track {
public:
	LineTrack(const Vec2& s, const Vec2& e) :start(s), end(e) {}
	Vec2 get_pos(float t) {
		return (1.0 - t) * start + t * end;
	}
private:
	Vec2 start;
	Vec2 end;
};

class CycleLineTrack :public Track {
public:
	CycleLineTrack(const Vec2& s, const Vec2& e) :start(s), end(e) {}
	Vec2 get_pos(float t) {
		if (t < 0.5) {
			return (1.0f - 2 * t) * start + 2 * t * end;
		}
		else {
			return (2 * t - 1.0f) * start + (2.0f - 2 * t) * end;
		}
	}
private:
	Vec2 start;
	Vec2 end;
};

class BezierCurveTrack :public Track {
public:
	BezierCurveTrack() :points() {}

	Vec2 get_pos(float t) {
		int n = points.size();
		Vec2 res;

		for (int i = 0; i < n; i++) {
			float temp = powf((1 - t), n - i - 1) * powf(t, i) * c(i, n - 1);
			res = res + temp * points[i];
		}

		return res;
	}
	std::vector<Vec2> points;
private:
	long c(int i, int n) {
		long res = 1;
		if (i == 0 || i == n) {
			return res;
		}

		for (int m = 0; m < i; m++) {
			res *= (n - m);
		}

		for (int m = 0; m < i; m++) {
			res /= (i - m);
		}
		return res;
	}
};

#endif // !TRACK_H
