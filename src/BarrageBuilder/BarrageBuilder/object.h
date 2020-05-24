#pragma once
#ifndef OBJECT_H
#define OBJECT_H

#include "vec2.h"
#include "track.h"
#include "color.h"
#include "primitive.h"
#include "font.h"
#include <string>

class Object {
public:
	Object(Vec2 p) :pos(p), track_p(nullptr), track_t(0) {}

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
	TestObject1(Vec2 pos, int w, int h) :Object(pos) {
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
					res.set_pixel(i, j, 0x0000000);
				}
			}
		}
	}
protected:
	int w;
	int h;
};

class TestObject3 :public Object {
public:
	TestObject3(Vec2 pos, std::string s) :Object(pos), content(s) {}

	void build_primitive(Primitive& res) {
		res.resize(FONT_SIZE * content.length(), FONT_SIZE);
		res.w = FONT_SIZE * content.length();
		res.h = FONT_SIZE;
		res.x = this->pos.x - res.w / 2;
		res.y = this->pos.y - res.h / 2;

		const char* str = content.c_str();
		for (int i = 0; i < content.length(); i++) {
			Font& f = Fonts::get_instance().get_font(str[i]);
			draw_char(res, f, i);
		}
	}
private:
	std::string content;

	void draw_char(Primitive& res, Font& f, int index) {
		int offset_x = index * FONT_SIZE;
		for (int j = 0; j < FONT_SIZE; j++) {
			for (int i = 0; i < FONT_SIZE; i++) {
				if (need_draw(f, i, j)) {
					res.set_pixel(i + offset_x, j, Color(0x000000ff));
				}
				else {
					res.set_pixel(i + offset_x, j, Color(0x00000000));
				}
			}
		}
	}
};
#endif // !OBJECT_H
