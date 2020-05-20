#pragma once
#ifndef OBJECT_FACTORY_H
#define OBJECT_FACTORY_H

#include <iostream>
#include "object.h"
#include <random>

class ObjectFactory
{
public:
	~ObjectFactory() {
		std::cout << "destructor called!" << std::endl;
	}
	ObjectFactory(const ObjectFactory&) = delete;
	ObjectFactory& operator=(const ObjectFactory&) = delete;
	static ObjectFactory& get_instance() {
		static ObjectFactory instance;
		return instance;
	}

	Object* get_object(int x, int y) {
		/*float speed = distribution(generator) % 10 + 5.0f;
		int color = distribution(generator) << 24 | distribution(generator) << 16 | distribution(generator) << 8 | 0xff;
		Object* r;*/
		/*r = new TestObject(10, 10, speed, color);
		r->setXY(x, y);*/
		/*r = new TestObject2(10, 10, x, y, 0.3, color);
		r->setXY(x, y);*/

		/*int end_x = x + (distribution(generator) % 100 - 100);
		r = new TestObject3(5, 5, Vec2(x, y), Vec2(end_x, 0), color);*/

		return nullptr;
	}
private:
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution;

	ObjectFactory() :distribution(0, 255) {
	}
};


#endif // !OBJECT_FACTORY_H
