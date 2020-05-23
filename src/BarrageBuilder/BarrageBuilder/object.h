#pragma once
#ifndef OBJECT_H
#define OBJECT_H

#include "vec2.h"
#include "track.h"
#include "color.h"
#include "primitive.h"
#include "font.h"

class Object {
public:
	Object(Vec2 p):pos(p),track_p(nullptr),track_t(0) {}

	virtual void build_primitive(Primitive&) = 0;

	void setTrack(Track& track) {
		track_p = &track;
	}

	void moveOnTrack() {
		if (track_p == nullptr)
			return;

		this->pos = track_p->get_pos(track_t);
		track_t += 0.01;
		if (track_t > 1)
			track_t -= 1;
	}

protected:
	Vec2 pos;
	Track* track_p;
	float track_t;
};

class TestObject1 :public Object {
public:
	TestObject1(Vec2 pos, int w, int h):Object(pos) {
		this->w = w;
		this->h = h;
	}

	void build_primitive(Primitive& res) {
		res.resize(w, h);
		res.x = this->pos.x;
		res.y = this->pos.y;
		res.w = w;
		res.h = h;
		Color c(255, 0, 0, 255);
		for (int j = 0; j < res.h; j++) {
			for (int i = 0; i < res.w; i++) {
				res.set_pixel(i, j, c);
			}
		}
	}
protected:
	int w, h;
};

class TestObject2 : public Object {
public:
	TestObject2(Vec2 pos, int w, int h) :Object(pos) {
		this->w = w;
		this->h = h;
	}
	void build_primitive(Primitive& res) {
		res.resize(w, h);
		res.x = this->pos.x;
		res.y = this->pos.y;
		res.w = w;
		res.h = h;

		Color c(0xff0000ff);
		
		int temp = w * h - w * w - h * h;

		for (int j = 0; j < res.h; j++) {
			for (int i = 0; i < res.w; i++) {
				if (4 * (i * i - i * w + j * j - j * h) < temp - 16) {
					res.set_pixel(i, j, c);
				}
				else {
					res.set_pixel(i, j, 0x7f7f7fff);
				}
			}
		}
	}
protected:
	int w;
	int h;
};

//class Object {
//public:
//	int x, y;
//	int width, height;
//
//	Object(int w, int h) {
//		width = w;
//		height = h;
//		x = 0;
//		y = 0;
//	}
//
//	void setXY(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
//
//	virtual int getColor(int pos_x, int pox_y) {
//		return 0x00000000;
//	}
//
//	virtual void move() {};
//};
//
//class TestObject :public Object {
//private:
//	float speed;
//	int color;
//
//public:
//	TestObject(int w, int h, float f, int c) :Object(w, h) {
//		speed = -f;
//		color = c;
//	}
//
//	int getColor(int pos_x, int pos_y) {
//		return color;
//	}
//
//	void move() {
//		y += speed;
//	}
//};
//
//class TestObject2 :public Object {
//private:
//	float p;
//	int color;
//	int x0, y0;
//	int x1, y1;
//	int x2, y2;
//
//public:
//	TestObject2(int w, int h, int x, int y, float radio, int c) :Object(w, h) {
//		p = 0;
//		color = c;
//		x0 = x;
//		y0 = y;
//		x2 = x;
//		y2 = 0;
//		x1 = x + radio * y;
//		y1 = y / 2;
//	}
//
//	int getColor(int pos_x, int pos_y) {
//		return color;
//	}
//
//	void move() {
//		this->x = (1.0f - p) * (1.0f - p) * x0 + 2 * (1.0f - p) * p * x1 + p * p * x2;
//		this->y = (1.0f - p) * (1.0f - p) * y0 + 2 * (1.0f - p) * p * y1 + p * p * y2;
//
//		p += 0.01f;
//	}
//};
//
//class TestObject3 :public Object {
//private:
//	float p;
//	Vec2 start;
//	Vec2 end;
//	int color;
//	BezierCurve move_curve;
//
//public:
//	TestObject3(int w, int h, Vec2 s, Vec2 e, int c) :Object(w, h), start(s), end(e), color(c) {
//		p = 0;
//
//		move_curve.addP(s);
//
//		Vec2 p = e - s;
//		int px = p.x;
//		int py = p.y;
//
//		move_curve.addP(s + Vec2((float)px * 3.5f, (float)py * 0.3f));
//		move_curve.addP(s + Vec2(-(float)px * 3.5f, (float)py * 0.8f));
//		move_curve.addP(e);
//	}
//
//	int getColor(int pos_x, int pos_y) {
//		return color;
//	}
//
//	void move() {
//		Vec2 now = move_curve.getP(p);
//		this->x = now.x;
//		this->y = now.y;
//		p += 0.01f;
//	}
//};

#endif // !OBJECT_H
