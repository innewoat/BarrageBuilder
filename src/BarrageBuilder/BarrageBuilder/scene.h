#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "primitive.h"

class Scene {
public:
	Scene() :pixels(height, std::vector<Color>(width)) {		
		clean();
	}

	~Scene() {
	}


	void clean() {
		for (int j = 0; j < height; j++) {
			for (int i = 0; i < width; i++) {
				pixels[j][i] = 0x7f7f7fff;
			}
		}
	}

	void draw(std::vector<Primitive*> primitives) {
		for (Primitive* primitive : primitives) {
			int base_x = primitive->x;
			int base_y = primitive->y;

			for (int j = 0; j < primitive->h; j++) {
				for (int i = 0; i < primitive->w; i++) {
					int target_x = base_x + i;
					int target_y = base_y + j;
					if (target_x >= 0 && target_x < width && target_y >= 0 && target_y < height) {
						if (primitive->get_pixel(i, j).a != 0) {
							pixels[target_y][target_x] = primitive->get_pixel(i, j);
						}
					}
				}
			}
		}
	}

	void save_to_file(std::string file_name) {
		//clean();

		std::ofstream file;
		file_name = "./output/" + file_name;
		file.open(file_name, std::fstream::out | std::fstream::trunc);

		file << "P3" << std::endl;
		file << width << " " << height << std::endl;
		file << "255" << std::endl;

		for (int j = 0; j < height; j++) {
			std::stringbuf res;
			std::ostream os(&res);

			for (int i = 0; i < width; i++) {
				Color c = pixels[j][i];
				file << c << "\n";
			}
		}

		file.close();
	}

private:
	const int width = 240;
	const int height = 400;

	std::vector<std::vector<Color>> pixels;
};

#endif // !SCENE_H
