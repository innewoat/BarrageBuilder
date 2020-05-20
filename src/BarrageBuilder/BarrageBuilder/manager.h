#pragma once
#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <vector>
#include "scene.h"
#include "track.h"
#include "primitive.h"
#include "object.h"


class Manager {
public:
	Scene scene;
	std::vector<Object*> objects;
	std::vector<Track*> tracks;
	
	Manager() {
		init();
	}

	~Manager() {
		for (Object* object : objects) {
			delete object;
		}

		for (Track* track : tracks) {
			delete track;
		}
	}

	void init() {
		scene.clean();
		objects.clear();
		tracks.clear();

		Object* testObject = new TestObject2(Vec2(120, 300), 40, 40);
		Track* testTrack1 = new LineTrack(Vec2(120, 300), Vec2(120, 100));
		BezierCurveTrack* testTrack2 = new BezierCurveTrack();
		testTrack2->points.push_back(Vec2(40, 300));
		testTrack2->points.push_back(Vec2(40, 100));
		testTrack2->points.push_back(Vec2(200, 100));

		testObject->setTrack(*testTrack2);
		
		objects.push_back(testObject);
		tracks.push_back(testTrack1);
		tracks.push_back(testTrack2);
	}

	void move() {
		for (Object* object : objects) {
			object->moveOnTrack();
		}
	}

	void draw(std::string filename) {
		scene.clean();

		std::vector<Primitive*> primitives;
		for (Object* object : objects) {
			Primitive* p = new Primitive();
			object->build_primitive(*p);
			primitives.push_back(p);
		}

		scene.draw(primitives);
		scene.save_to_file(filename);

		for (Primitive* primitive : primitives) {
			delete primitive;
		}
	}

	void loop() {
		for (int i = 0; i < 100; i++) {
			std::string file_name = "pic_" + std::to_string(i) + ".ppm";
			draw(file_name);
			move();
			std::cout << i << std::endl;
		}
	}

};

#endif // !MANAGER_H
