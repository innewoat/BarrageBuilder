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

		//Object* testObject = new TestObject2(Vec2(120, 300), 40, 40);
		//LineTrack* testTrack1 = new LineTrack(Vec2(120, 300), Vec2(120, 100));
		//BezierCurveTrack* testTrack2 = new BezierCurveTrack();
		//testTrack2->points.push_back(Vec2(40, 300));
		//testTrack2->points.push_back(Vec2(40, 100));
		//testTrack2->points.push_back(Vec2(200, 100));

		//testObject->setTrack(*testTrack1);
		//testObject->setTrack(*testTrack2);
		//objects.push_back(testObject);
		//tracks.push_back(testTrack1);
		//tracks.push_back(testTrack2);

		Object* why = new TestObject3(Vec2(120, 200), "why");
		Object* so = new TestObject3(Vec2(120, 200), "so");
		Object* serious = new TestObject3(Vec2(120, 200), "serious");

		Track* why_track = new CycleLineTrack(Vec2(120, 200), Vec2(120, 0));
		Track* so_track = new CycleLineTrack(Vec2(120, 200), Vec2(0, 400));
		Track* serious_track = new CycleLineTrack(Vec2(120, 200), Vec2(240, 400));

		why->setTrack(*why_track);
		so->setTrack(*so_track);
		serious->setTrack(*serious_track);

		objects.push_back(why);
		objects.push_back(so);
		objects.push_back(serious);

		tracks.push_back(why_track);
		tracks.push_back(so_track);
		tracks.push_back(serious_track);
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
