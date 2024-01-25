#pragma once

#include <glm/glm.hpp>

#define v4 glm::vec4
#define v3 glm::vec3
#define v2 glm::vec2

class Stairs {
	public:
	v2 center, length;
	float yRotate;

	Stairs(v2 center, v2 length, float yRotate) {
		this->center = center;
		this->length = length;
		this->yRotate = yRotate;
	}
};