#pragma once
#include <Mesh.h>
#include <map>
#define v4 glm::vec4
#define v3 glm::vec3
#define v2 glm::vec2
#define mat4 glm::mat4
#define translate glm::translate
#define rotate glm::rotate
#define radians glm::radians
const float PI = 3.141592653589793238463;

class Shape {
public:
	Shape();
	~Shape();

	void setTextures(std::vector<Texture>& textures) {
		this->textures = textures;
	}

	Mesh* Sphere(float radius, int stacks, int slices, float stack_cut_ratio = 1, float slice_cut_ratio = 1);
	Mesh* Square(float x, float z);
	Mesh* FilledCube(float x, float y, float z);
	Mesh* EmptyCube(float outx, float outy, float outz, float inx, float iny, float inz,
		float xOffset = 0, float yOfest = 0, float zOffset = 0);
	Mesh* FilledCircle(float height, float radius, int slices);
	Mesh* EmptyCircle(float height, float outer_radius, float inner_radius, float slices, float cut_ratio = 1);
	Mesh* HalfGate(float Xradius, float Zradius, float height, int slices);
	Mesh* FullGate(float x, float y, float z, float Xradius, float Zradius, int slices);
	Mesh* Cone(float radius, float height, int slices, float cut_ratio = 1);
	Mesh* EmptyCone(float out_radius, float in_radius, float height, int slices, float cut_ratio = 1);
	Mesh* Square_Repet_Textures(float x, float z, float density = 1, float pushright = 0, float pushfront = 0);
	Mesh* Square_Repet_Textures2(float density, float pushright, float pushfront, float x, float z) {
		return Square_Repet_Textures(x, z, density, pushright, pushfront);
	}
	Mesh* Parallelogram(float x, float y, float z, float angle);
	Mesh* Stairs(float x, float y, float z, int steps);
	Mesh* FilledStairs(float x, float y, float z, int steps);
	Mesh* Roof(float x, float outz, float inz, float angle, bool closer = true);
	Mesh* FilledCubeTexture(float x, float y, float z, float textureScale);
	Mesh* threeCubes(float outx, float outy, float outz, float inx, float iny, float inz);
	Mesh* Triangle(float x1, float z1, float x2, float z2);
	Mesh* theDome_of_the_Rock_GROWND(float x, float y, float z, float texDensity);
private:
	std::vector<Texture>textures;
};