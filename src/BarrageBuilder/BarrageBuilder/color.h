#pragma once
#ifndef COLOR_H
#define COLOR_H

#include <ostream>

struct Color {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;

	Color():r(0),g(0),b(0),a(0){}
	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
	Color(unsigned int c) {
		this->r = (c >> 24) & 0xff;
		this->g = (c >> 16) & 0xff;
		this->b = (c >> 8) & 0xff;
		this->a = c & 0xff;
	}

	Color& operator=(const Color& c) {
		this->r = c.r;
		this->g = c.g;
		this->b = c.b;
		this->a = c.a;
		return *this;
	}

	Color& operator=(int c) {
		this->r = (c >> 24) & 0xff;
		this->g = (c >> 16) & 0xff;
		this->b = (c >> 8) & 0xff;
		this->a = c & 0xff;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& output,
		const Color& c)
	{
		output << (int)c.r << " " << (int)c.g << " " << (int)c.b;
		return output;
	}

};

#endif // !COLOR_H
