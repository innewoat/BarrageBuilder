#pragma once
#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "color.h"
#include <vector>

class Primitive {
public:
	int x;
	int y;
	int w;
	int h;
	std::vector<Color> pixels;

	Primitive():x(0),y(0),w(0),h(0),pixels()
	{}
	void resize(int w, int h) {
		pixels.resize(w * h);
	}

	void set_pixel(int x, int y, Color c) {
		pixels[x + y * w] = c;
	}

	Color get_pixel(int x, int y) {
		return pixels[x + y * w];
	}
};

#endif // !PRIMITIVE_H
