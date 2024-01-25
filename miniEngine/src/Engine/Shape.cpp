#include <Shape.h>

Shape::Shape() {};
Shape::~Shape() {};

inline int max(int a, int b) {
	return a > b ? a : b;
};

inline float max(float a, float b) {
	return a > b ? a : b;
};

inline int min(int a, int b) {
	return a < b ? a : b;
};

inline float min(float a, float b) {
	return a < b ? a : b;
};

// 0 1 
// 3 2
inline auto square(
	std::vector<Vertex>& vertices,

	float tlx, float tly, float tlz,
	float trx, float try_, float trz,
	float drx, float dry, float drz,
	float dlx, float dly, float dlz
)
{
	v3 normal = v3(tlx + trx + drx + dlx, tly + try_ + dry + dly, tlz + trz + drz + dlz);
	vertices.push_back(Vertex{ v3(tlx,tly,tlz),v3(normal),v2(0,1) });//0
	vertices.push_back(Vertex{ v3(trx,try_,trz),v3(normal),v2(1,1) });//1
	vertices.push_back(Vertex{ v3(drx,dry,drz),v3(normal),v2(1,0) });//2

	vertices.push_back(Vertex{ v3(tlx,tly,tlz),v3(normal),v2(0,1) });//0
	vertices.push_back(Vertex{ v3(dlx,dly,dlz),v3(normal),v2(0,0) });//3
	vertices.push_back(Vertex{ v3(drx,dry,drz),v3(normal),v2(1,0) });//2
};

// 0 1 
// 3 2 
inline auto square(
	std::vector<Vertex>& vertices,
	v3 normal,
	float tlx, float tly, float tlz,
	float trx, float try_, float trz,
	float drx, float dry, float drz,
	float dlx, float dly, float dlz
)
{
	vertices.push_back(Vertex{ v3(tlx,tly,tlz), normal,v2(0,1) });//0
	vertices.push_back(Vertex{ v3(trx,try_,trz),normal,v2(1,1) });//1
	vertices.push_back(Vertex{ v3(drx,dry,drz), normal,v2(1,0) });//2

	vertices.push_back(Vertex{ v3(tlx,tly,tlz), normal,v2(0,1) });//0
	vertices.push_back(Vertex{ v3(dlx,dly,dlz), normal,v2(0,0) });//3
	vertices.push_back(Vertex{ v3(drx,dry,drz), normal,v2(1,0) });//2
};

// 0 1 
// 3 2
inline auto square(
	std::vector<Vertex>& vertices,
	v3 normal,
	v3 V0,
	v3 V1,
	v3 V2,
	v3 V3
)
{
	vertices.push_back(Vertex{ V0, normal,v2(0,1) });//0
	vertices.push_back(Vertex{ V1,normal,v2(1,1) });//1
	vertices.push_back(Vertex{ V2, normal,v2(1,0) });//2

	vertices.push_back(Vertex{ V0, normal,v2(0,1) });//0
	vertices.push_back(Vertex{ V3, normal,v2(0,0) });//3
	vertices.push_back(Vertex{ V2, normal,v2(1,0) });//2
};

inline auto tringle(
	std::vector<Vertex>& vertices,
	v3 normal,
	v3 V0,
	v3 V1,
	v3 V2
)
{
	vertices.push_back(Vertex{ V0, normal,v2(0,0) });//0
	vertices.push_back(Vertex{ V1,normal,v2(0.5,1) });//1
	vertices.push_back(Vertex{ V2, normal,v2(1,0) });//2
};

Mesh* Shape::Sphere(float radius, int stacks, int slices, float stack_cut_ratio, float slice_cut_ratio) {

	std::vector<Vertex>vertices;

	stacks *= stack_cut_ratio;
	slices *= slice_cut_ratio;
	float stacks_angle = (PI * 2.0f) / (float)stacks;
	float slices_angle = (PI * 2.0f) / (float)slices;


	float tlx = 0, tly = 0, tlz = 0,
		trx = 0, try_ = 0, trz = 0,
		drx = 0, dry = 0, drz = 0,
		dlx = 0, dly = 0, dlz = 0;
	float xz_radius = 0, next_xz_radius = 0;

	for (int i = 0; i * max(stack_cut_ratio, 1.0f) < stacks; i++) {

		tly = try_ = static_cast<float>(cos(stacks_angle * i)) * radius;
		dly = dry = static_cast<float>(cos(stacks_angle * (i + 1))) * radius;

		xz_radius = static_cast<float>(sin(stacks_angle * i)) * radius;
		next_xz_radius = static_cast<float>(sin(stacks_angle * (i + 1))) * radius;

		for (int j = 0; j * max(slice_cut_ratio, 1.0f) < slices; j++) {

			tlx = static_cast<float>(sin(slices_angle * j)) * xz_radius;
			tlz = static_cast<float>(cos(slices_angle * j)) * xz_radius;

			trx = static_cast<float>(sin(slices_angle * (j + 1))) * xz_radius;
			trz = static_cast<float>(cos(slices_angle * (j + 1))) * xz_radius;

			dlx = static_cast<float>(sin(slices_angle * j)) * next_xz_radius;
			dlz = static_cast<float>(cos(slices_angle * j)) * next_xz_radius;

			drx = static_cast<float>(sin(slices_angle * (j + 1))) * next_xz_radius;
			drz = static_cast<float>(cos(slices_angle * (j + 1))) * next_xz_radius;

			square(
				vertices,
				tlx, tly, tlz,
				trx, try_, trz,
				drx, dry, drz,
				dlx, dly, dlz
			);
		}
	}
	std::vector<unsigned int> indices(vertices.size());
	for (int i = 0; i < vertices.size(); i++) {
		indices.push_back(i);
	};

	return new Mesh(vertices, indices, this->textures);
};

Mesh* Shape::FilledCircle(float height, float radius, int slices) {

	std::vector<Vertex>vertices;

	float angle = (PI * 2.0f) / slices;

	float  x = 0.0f, z = 0.0f;
	float lastX = 0, lastZ = 0;
	for (int i = 0; i <= slices; i++) {
		x = static_cast<float>(sin(angle * i)) * radius;
		z = static_cast<float>(cos(angle * i)) * radius;

		vertices.push_back(Vertex{ v3(0 , height , 0),v3(0,1,0),v2(0.5,1) });
		vertices.push_back(Vertex{ v3(x , height , z),v3(0,1,0),v2(1,0) });
		vertices.push_back(Vertex{ v3(lastX , height , lastZ),v3(0,1,0),v2(0,0) });

		vertices.push_back(Vertex{ v3(0 , -height , 0),v3(0,-1,0),v2(0.5,1) });
		vertices.push_back(Vertex{ v3(x , -height , z),v3(0,-1,0),v2(1,0) });
		vertices.push_back(Vertex{ v3(lastX , -height , lastZ),v3(0,-1,0),v2(0,0) });

		vertices.push_back(Vertex{ v3(lastX , height , lastZ),v3(x,0,z),v2(0,1) });
		vertices.push_back(Vertex{ v3(lastX , -height , lastZ),v3(x,0,z),v2(0,0) });
		vertices.push_back(Vertex{ v3(x , -height , z),v3(x,0,z),v2(1,0) });

		vertices.push_back(Vertex{ v3(lastX , height , lastZ),v3(x,0,z),v2(0,1) });
		vertices.push_back(Vertex{ v3(x , height , z),v3(x,0,z),v2(1,1) });
		vertices.push_back(Vertex{ v3(x , -height , z),v3(x,0,z),v2(1,0) });

		lastX = x;
		lastZ = z;
	}
	std::vector<unsigned int> indices(vertices.size());
	for (int i = 0; i < vertices.size(); i++) {
		indices.push_back(i);
	};

	return new Mesh(vertices, indices, this->textures);
}

Mesh* Shape::EmptyCircle(float height, float outer_radius, float inner_radius, float slices, float cut_ratio) {

	std::vector<Vertex>vertices;

	slices *= cut_ratio;
	float angle = (PI * 2.0f) / slices;

	float  outx = 0.0f, outz = 0.0f;
	float last_outX = 0.0f, last_outZ = 0.0f;

	float  inx = 0.0f, inz = 0.0f;
	float last_inX = 0.0f, last_inZ = 0.0f;

	for (int i = 0; i * max(cut_ratio, 1.0f) < slices; i++) {
		last_outX = static_cast<float>(sin(angle * i)) * outer_radius;
		last_outZ = static_cast<float>(cos(angle * i)) * outer_radius;

		last_inX = static_cast<float>(sin(angle * i)) * inner_radius;
		last_inZ = static_cast<float>(cos(angle * i)) * inner_radius;

		outx = static_cast<float>(sin(angle * (i + 1))) * outer_radius;
		outz = static_cast<float>(cos(angle * (i + 1))) * outer_radius;

		inx = static_cast<float>(sin(angle * (i + 1))) * inner_radius;
		inz = static_cast<float>(cos(angle * (i + 1))) * inner_radius;

		//left
		square(
			vertices,
			v3(last_outX + outx + outx + last_outX, 0, last_outZ + last_outZ + outz + outz),
			last_outX, height, last_outZ,
			outx, height, outz,
			outx, -height, outz,
			last_outX, -height, last_outZ
		);
		//right
		square(
			vertices,
			-v3(inx + inx + last_inX + last_inX, 0, inz + inz + last_inZ + last_inZ),
			inx, height, inz,
			last_inX, height, last_inZ,
			last_inX, -height, last_inZ,
			inx, -height, inz
		);
		if (cut_ratio > 1)
		{
			//front
			square(
				vertices,
				last_outX, height, last_outZ,
				last_inX, height, last_inZ,
				last_inX, -height, last_inZ,
				last_outX, -height, last_outZ
			);
			//back
			square(
				vertices,
				outx, height, outz,
				inx, height, inz,
				inx, -height, inz,
				outx, -height, outz
			);
		}
		//up
		square(
			vertices,
			v3(0, 1, 0),
			last_outX, height, last_outZ,
			last_inX, height, last_inZ,
			inx, height, inz,
			outx, height, outz
		);
		//down
		square(
			vertices,
			v3(0, -1, 0),
			last_outX, -height, last_outZ,
			last_inX, -height, last_inZ,
			inx, -height, inz,
			outx, -height, outz
		);
	}

	std::vector<unsigned int> indices(vertices.size());
	for (int i = 0; i < vertices.size(); i++) {
		indices.push_back(i);
	};

	return new Mesh(vertices, indices, this->textures);
};

Mesh* Shape::FilledCube(float x, float y, float z)
{
	std::vector<Vertex> vertices =
	{
		// COORDINATES        /         NORMALS         /       TEXTURE COORDINATES    //
		Vertex{v3(-x,-y,+z), v3(-1,0,0), v2(1,0)},//0
		Vertex{v3(-x,+y,+z), v3(-1,0,0), v2(1,1)},//1
		Vertex{v3(-x,+y,-z), v3(-1,0,0), v2(0,1)},//2
		Vertex{v3(-x,-y,+z), v3(-1,0,0), v2(1,0)},//0
		Vertex{v3(-x,-y,-z), v3(-1,0,0), v2(0,0)},//3
		Vertex{v3(-x,+y,-z), v3(-1,0,0), v2(0,1)},//2

		Vertex{v3(-x,-y,-z), v3(0,0,-1), v2(0,0)},//3
		Vertex{v3(-x,+y,-z), v3(0,0,-1), v2(0,1)},//2
		Vertex{v3(+x,+y,-z), v3(0,0,-1), v2(1,1)},//6
		Vertex{v3(-x,-y,-z), v3(0,0,-1), v2(0,0)},//3
		Vertex{v3(+x,-y,-z), v3(0,0,-1), v2(1,0)},//7
		Vertex{v3(+x,+y,-z), v3(0,0,-1), v2(1,1)},//6

		Vertex{v3(+x,-y,-z), v3(1,0,0), v2(0,0)},//7
		Vertex{v3(+x,+y,-z), v3(1,0,0), v2(0,1)},//6
		Vertex{v3(+x,+y,+z), v3(1,0,0), v2(1,1)},//5
		Vertex{v3(+x,-y,-z), v3(1,0,0), v2(0,0)},//7
		Vertex{v3(+x,-y,+z), v3(1,0,0), v2(1,0)},//4
		Vertex{v3(+x,+y,+z), v3(1,0,0), v2(1,1)},//5

		Vertex{v3(-x,-y,+z), v3(0,0,1), v2(0,0)},//0
		Vertex{v3(-x,+y,+z), v3(0,0,1), v2(0,1)},//1
		Vertex{v3(+x,+y,+z), v3(0,0,1), v2(1,1)},//5
		Vertex{v3(-x,-y,+z), v3(0,0,1), v2(0,0)},//0
		Vertex{v3(+x,-y,+z), v3(0,0,1), v2(1,0)},//4
		Vertex{v3(+x,+y,+z), v3(0,0,1), v2(1,1)},//5

		Vertex{v3(-x,+y,+z), v3(0,1,0), v2(0,0)},//1
		Vertex{v3(-x,+y,-z), v3(0,1,0), v2(0,1)},//2
		Vertex{v3(+x,+y,-z), v3(0,1,0), v2(1,1)},//6
		Vertex{v3(-x,+y,+z), v3(0,1,0), v2(0,0)},//1
		Vertex{v3(+x,+y,+z), v3(0,1,0), v2(1,0)},//5
		Vertex{v3(+x,+y,-z), v3(0,1,0), v2(1,1)},//6

		Vertex{v3(-x,-y,+z), v3(0,-1,0), v2(0,0)},//0
		Vertex{v3(-x,-y,-z), v3(0,-1,0), v2(0,1)},//3
		Vertex{v3(+x,-y,-z), v3(0,-1,0), v2(1,1)},//7
		Vertex{v3(-x,-y,+z), v3(0,-1,0), v2(0,0)},//0
		Vertex{v3(+x,-y,+z), v3(0,-1,0), v2(1,0)},//4
		Vertex{v3(+x,-y,-z), v3(0,-1,0), v2(1,1)},//7
	};

	std::vector<unsigned int> indices(vertices.size());
	for (int i = 0; i < vertices.size(); i++) {
		indices[i] = i;
	};

	return new Mesh(vertices, indices, this->textures);
}

Mesh* Shape::EmptyCube(float outx, float outy, float outz, float inx, float iny, float inz, float xOffset, float yOffset, float zOffset) {

	std::vector<Vertex>vertices;

	std::map<int, v3>V;
	std::map< std::string, v3>N;
	V[0] = v3(-outx, outy, outz);
	V[1] = v3(-outx, outy, -outz);
	V[2] = v3(-outx, -outy, -outz);
	V[3] = v3(-outx, -outy, outz);
	V[4] = v3(-inx + xOffset, iny + yOffset, inz + zOffset);
	V[5] = v3(-inx + xOffset, iny + yOffset, -inz + zOffset);
	V[6] = v3(-inx + xOffset, -iny + yOffset, -inz + zOffset);
	V[7] = v3(-inx + xOffset, -iny + yOffset, inz + zOffset);
	V[8] = v3(inx + xOffset, iny + yOffset, inz + zOffset);
	V[9] = v3(inx + xOffset, iny + yOffset, -inz + zOffset);
	V[10] = v3(inx + xOffset, -iny + yOffset, -inz + zOffset);
	V[11] = v3(inx + xOffset, -iny + yOffset, inz + zOffset);
	V[12] = v3(outx, outy, outz);
	V[13] = v3(outx, outy, -outz);
	V[14] = v3(outx, -outy, -outz);
	V[15] = v3(outx, -outy, outz);

	N["up"] = v3(0, 1, 0);
	N["down"] = v3(0, -1, 0);
	N["left"] = v3(-1, 0, 0);
	N["right"] = v3(1, 0, 0);
	N["front"] = v3(0, 0, -1);
	N["back"] = v3(0, 0, 1);

	square(vertices, N["left"], V[0], V[1], V[2], V[3]);
	square(vertices, N["right"], V[4], V[5], V[6], V[7]);
	square(vertices, N["left"], V[8], V[9], V[10], V[11]);
	square(vertices, N["right"], V[12], V[13], V[14], V[15]);
	square(vertices, N["back"], V[12], V[0], V[3], V[15]);
	square(vertices, N["front"], V[8], V[4], V[7], V[11]);
	square(vertices, N["back"], V[9], V[5], V[6], V[10]);
	square(vertices, N["front"], V[13], V[1], V[2], V[14]);
	square(vertices, N["up"], V[0], V[1], V[5], V[4]);
	square(vertices, N["up"], V[1], V[13], V[9], V[5]);
	square(vertices, N["up"], V[13], V[12], V[8], V[9]);
	square(vertices, N["up"], V[12], V[8], V[4], V[0]);
	square(vertices, N["down"], V[3], V[2], V[6], V[7]);
	square(vertices, N["down"], V[6], V[2], V[14], V[10]);
	square(vertices, N["down"], V[14], V[10], V[11], V[15]);
	square(vertices, N["down"], V[15], V[11], V[7], V[3]);

	std::vector<unsigned int> indices(vertices.size());
	for (int i = 0; i < vertices.size(); i++) {
		indices.push_back(i);
	};

	return new Mesh(vertices, indices, this->textures);
};

Mesh* Shape::Square(float x, float z)
{

	std::vector<Vertex> vertices =
	{
		// COORDINATES        /         NORMALS         /       TEXTURE COORDINATES    //
		Vertex{v3(-x, 0.0f,  z), v3(0.0f, 1.0f, 0.0f),  v2(0.0f, 0.0f)},
		Vertex{v3(-x, 0.0f, -z), v3(0.0f, 1.0f, 0.0f),  v2(0.0f, 1.0f)},
		Vertex{v3(x, 0.0f, -z),  v3(0.0f, 1.0f, 0.0f),  v2(1.0f, 1.0f)},
		Vertex{v3(x, 0.0f,  z),  v3(0.0f, 1.0f, 0.0f),  v2(1.0f, 0.0f)}
	};

	std::vector<unsigned int> indices =
	{
		0, 1, 2,
		0, 2, 3
	};

	return new Mesh(vertices, indices, this->textures);
};

Mesh* Shape::Square_Repet_Textures(float x, float z, float density, float pushright, float pushfront) {

	std::vector<Vertex> vertices =
	{
		// COORDINATES        /         NORMALS         /       TEXTURE COORDINATES    //
		Vertex{v3(-x, 0.0f,  z), v3(0.0f, 1.0f, 0.0f),  v2(-density * x + pushright, density * z + pushfront)},
		Vertex{v3(-x, 0.0f, -z), v3(0.0f, 1.0f, 0.0f),  v2(-density * x + pushright, -density * z + pushfront)},
		Vertex{v3(x, 0.0f, -z),  v3(0.0f, 1.0f, 0.0f),  v2(density * x + pushright, -density * z + pushfront)},
		Vertex{v3(x, 0.0f,  z),  v3(0.0f, 1.0f, 0.0f),  v2(density * x + pushright, density * z + pushfront)}
	};

	std::vector<unsigned int> indices =
	{
		0, 1, 2,
		0, 2, 3
	};

	return new Mesh(vertices, indices, this->textures);
}

Mesh* Shape::HalfGate(float Xradius, float Zradius, float height, int slices) {

	std::vector<Vertex>vertices;

	float angle = (PI) / slices; // didnt mult by 2 because it's half circle

	std::map<int, v3> V;

	V[0] = v3(-Xradius, height, -Zradius);
	V[1] = v3(Xradius, height, -Zradius);
	V[2] = v3(Xradius, -height, -Zradius);
	V[3] = v3(-Xradius, -height, -Zradius);
	square(vertices, v3(0, 0, -1), V[0], V[1], V[2], V[3]);

	float x, z;
	float nextX, nextZ;
	for (int i = 0; i < slices; i++) {
		x = -static_cast<float>(cos(angle * i)) * Xradius;
		z = -static_cast<float>(sin(angle * i)) * Zradius;

		nextX = -static_cast<float>(cos(angle * i + angle)) * Xradius;
		nextZ = -static_cast<float>(sin(angle * i + angle)) * Zradius;

		square(vertices,
			x, height, z,
			nextX, height, nextZ,
			nextX, -height, nextZ,
			x, -height, z
		);


		if (angle * i * 2.0f <= PI) {
			tringle(vertices,
				v3(0, 1, 0),
				v3(x, height, z),
				v3(nextX, height, nextZ),
				V[0]
			);
			tringle(vertices,
				v3(0, -1, 0),
				v3(x, -height, z),
				v3(nextX, -height, nextZ),
				V[3]
			);
		}

		if (angle * i * 2.0f >= PI) {
			tringle(vertices,
				v3(0, 1, 0),
				v3(x, height, z),
				v3(nextX, height, nextZ),
				V[1]
			);
			tringle(vertices,
				v3(0, -1, 0),
				v3(x, -height, z),
				v3(nextX, -height, nextZ),
				V[2]
			);
		}
	}



	std::vector<unsigned int> indices(vertices.size());
	for (int i = 0; i < vertices.size(); i++) {
		indices.push_back(i);
	};

	return new Mesh(vertices, indices, this->textures);
}

Mesh* Shape::Cone(float radius, float height, int slices, float cut_ratio) {

	std::vector<Vertex>vertices;

	float angle = (2.0f * PI) / slices;

	v3 upper_center = v3(0, height, 0);
	v3 lower_center = v3(0, 0, 0);

	float x, z, nextX, nextZ;
	for (int i = 0; i * max(cut_ratio, 1.0f) <= slices; i++) {
		x = static_cast<float>(sin(angle * i)) * radius;
		z = static_cast<float>(cos(angle * i)) * radius;

		nextX = static_cast<float>(sin(angle * i + angle)) * radius;
		nextZ = static_cast<float>(cos(angle * i + angle)) * radius;


		//float normal_lenght = (height * radius) / sqrt(height * height + radius * radius);
		float nx, nz, ny;
		nx = nz = 1.0f;//let us set it from our selfs

		ny = radius / height;

		v3 normal = v3(nx, ny, nz);

		tringle(
			vertices,
			normal, // bad normal  ... fix later 
			upper_center,
			v3(x, 0, z),
			v3(nextX, 0, nextZ)
		);

		tringle(
			vertices,
			v3(0, -1, 0),
			lower_center,
			v3(x, 0, z),
			v3(nextX, 0, nextZ)
		);

	}

	std::vector<unsigned int>indices(vertices.size());
	for (int i = 0; i < vertices.size(); i++) {
		indices[i] = i;
	}

	return new Mesh(vertices, indices, this->textures);
}

Mesh* Shape::EmptyCone(float out_radius, float in_radius, float height, int slices, float cut_ratio)
{
	std::vector<Vertex>vertices;

	float angle = (2.0f * PI) / slices;


	float xout, zout, nextXout, nextZout;
	float xin, zin, nextXin, nextZin;
	for (int i = 0; i * max(cut_ratio, 1.0f) <= slices; i++) {
		xout = static_cast<float>(sin(angle * i)) * out_radius;
		zout = static_cast<float>(cos(angle * i)) * out_radius;
		nextXout = static_cast<float>(sin(angle * i + angle)) * out_radius;
		nextZout = static_cast<float>(cos(angle * i + angle)) * out_radius;

		xin = static_cast<float>(sin(angle * i)) * in_radius;
		zin = static_cast<float>(cos(angle * i)) * in_radius;
		nextXin = static_cast<float>(sin(angle * i + angle)) * in_radius;
		nextZin = static_cast<float>(cos(angle * i + angle)) * in_radius;



		v3 tl, tr, dr, dl, normal;
		tl = v3(xin, height, zin);
		tr = v3(nextXin, height, nextZin);
		dr = v3(nextXout, 0, nextZout);
		dl = v3(xout, 0, zout);
		normal = v3(xin, height * height, zin);//bad normal
		square(
			vertices,
			normal,
			tl,
			tr,
			dr,
			dl
		);

	}

	std::vector<unsigned int>indices(vertices.size());
	for (int i = 0; i < vertices.size(); i++) {
		indices[i] = i;
	}

	return new Mesh(vertices, indices, this->textures);
}

Mesh* Shape::Parallelogram(float x, float y, float z, float angle) {

	std::vector<Vertex>vertices;

	float radius = x / static_cast<float>(cos(radians(angle)));
	float change = radius * static_cast<float>(sin(radians(angle)));

	std::map<int, v3> V;
	V[0] = v3(-x, y, -z + change);
	V[1] = v3(-x, -y, -z + change);
	V[2] = v3(-x, -y, z + change);
	V[3] = v3(-x, y, z + change);
	V[4] = v3(x, y, -z - change);
	V[5] = v3(x, -y, -z - change);
	V[6] = v3(x, -y, z - change);
	V[7] = v3(x, y, z - change);

	//very bad normal but i will caculate it later 
	v3 front_normal = v3(-x, 0, -z + change) + v3(x, 0, -z - change);
	v3 back_normal = v3(-x, 0, z + change) + v3(x, 0, z + change);

	square(vertices, v3(0, 1, 0), V[0], V[1], V[5], V[4]);//up
	square(vertices, v3(0, -1, 0), V[3], V[2], V[6], V[7]);//down
	square(vertices, v3(-1, 0, 0), V[0], V[1], V[2], V[3]);//left
	square(vertices, v3(1, 0, 0), V[4], V[5], V[6], V[7]);//right
	square(vertices, front_normal, V[1], V[5], V[6], V[2]);//front normal
	square(vertices, back_normal, V[0], V[4], V[7], V[3]);//back  normal

	std::vector<unsigned int>indices(vertices.size());
	for (int i = 0; i < vertices.size(); i++) {
		indices[i] = i;
	}

	return new Mesh(vertices, indices, this->textures);

}

Mesh* Shape::Stairs(float x, float y, float z, int steps) {

	std::vector<Vertex>vertices;

	float y_step = y / steps;
	float z_step = z / steps;

	float dy = y;
	float dz = -z;

	auto up_normal = v3(0, 1, 0);
	auto back_normal = v3(0, 0, 1);

	while (dy > -y and dz < z) {

		square(vertices, up_normal, v3(-x, dy, dz + z_step), v3(-x, dy, dz), v3(x, dy, dz), v3(x, dy, dz + z_step));//1 , 2 , 5 , 4
		square(vertices, back_normal, v3(-x, dy - y_step, dz + z_step), v3(-x, dy, dz + z_step), v3(x, dy, dz + z_step), v3(x, dy - y_step, dz + z_step));//0 , 1 , 4 , 3 

		dy -= y_step;
		dz += z_step;
	}

	std::vector<unsigned int>indices(vertices.size());
	for (int i = 0; i < vertices.size(); i++) {
		indices[i] = i;
	}

	return new Mesh(vertices, indices, this->textures);
}

Mesh* Shape::FilledStairs(float x, float y, float z, int steps)
{
	std::vector<Vertex>vertices;

	auto squareTex = [](
		std::vector<Vertex>& vertices,
		v3 normal,
		v3 tl,
		v3 tr,
		v3 dr,
		v3 dl,
		float y,
		float z
		) {
			vertices.push_back(Vertex{ tl,v3(normal),v2(tl.z / z,tl.y / y) });//0
			vertices.push_back(Vertex{ tr,v3(normal),v2(tr.z / z,tr.y / y) });//1
			vertices.push_back(Vertex{ dr,v3(normal),v2(dr.z / z,dr.y / y) });//2

			vertices.push_back(Vertex{ tl,v3(normal),v2(tl.z / z,tl.y / y) });//0
			vertices.push_back(Vertex{ dl,v3(normal),v2(dl.z / z,dl.y / y) });//3
			vertices.push_back(Vertex{ dr,v3(normal),v2(dr.z / z,dr.y / y) });//2
		};

	float y_step = y / steps;
	float z_step = z / steps;

	float dy = y;
	float dz = -z;

	auto up_normal = v3(0, 1, 0);
	auto back_normal = v3(0, 0, 1);
	auto front_normal = v3(0, 0, -1);
	auto left_normal = v3(-1, 0, 0);
	auto right_normal = v3(1, 0, 0);

	while (dy > -y and dz < z) {

		square(vertices, up_normal, v3(-x, dy, dz + z_step), v3(-x, dy, dz), v3(x, dy, dz), v3(x, dy, dz + z_step));//1 , 2 , 5 , 4
		square(vertices, back_normal, v3(-x, dy - y_step, dz + z_step), v3(-x, dy, dz + z_step), v3(x, dy, dz + z_step), v3(x, dy - y_step, dz + z_step));//0 , 1 , 4 , 3 

		//left
		squareTex(vertices, left_normal, v3(-x, dy, dz), v3(-x, dy, dz + z_step), v3(-x, -y, dz + z_step), v3(-x, -y, dz), y, z);
		//right
		squareTex(vertices, right_normal, v3(x, dy, dz), v3(x, dy, dz + z_step), v3(x, -y, dz + z_step), v3(x, -y, dz), y, z);

		dy -= y_step;
		dz += z_step;
	}

	square(vertices, front_normal, v3(-x, y, -z), v3(x, y, -z), v3(x, -y, -z), v3(-x, -y, -z));

	std::vector<unsigned int>indices(vertices.size());
	for (int i = 0; i < vertices.size(); i++) {
		indices[i] = i;
	}

	return new Mesh(vertices, indices, this->textures);
}

Mesh* Shape::Roof(float x, float outz, float inz, float angle, bool closer) {

	std::vector<Vertex>vertices;

	float radius = x / static_cast<float>(sin(radians(angle / 2.0f)));
	float y = static_cast<float>(cos(radians(angle / 2.0f))) * radius;

	std::map<int, v3> V;
	V[0] = v3(-x, 0, outz);
	V[1] = v3(0, y, inz);
	V[2] = v3(+x, 0, outz);
	V[3] = v3(-x, 0, -outz);
	V[4] = v3(0, y, -inz);
	V[5] = v3(+x, 0, -outz);

	auto left_normal = v3(-y, y, 0);
	auto right_normal = v3(y, y, 0);
	auto front_normal = v3(0, y, -(outz - inz) / 2);
	auto back_normal = v3(0, y, (outz - inz) / 2);

	if (closer)
	{
		tringle(vertices, back_normal, V[0], V[1], V[2]);
		tringle(vertices, front_normal, V[3], V[4], V[5]);
	}
	square(vertices, left_normal, V[0], V[1], V[4], V[3]);
	square(vertices, right_normal, V[2], V[1], V[4], V[5]);

	std::vector<unsigned int>indices(vertices.size());
	for (int i = 0; i < vertices.size(); i++) {
		indices[i] = i;
	}

	return new Mesh(vertices, indices, this->textures);
}

Mesh* Shape::FilledCubeTexture(float x, float y, float z, float textureScale)
{
	std::vector<Vertex> vertices =
	{
		// COORDINATES        /         NORMALS         /       TEXTURE COORDINATES    //
		Vertex{v3(-x,-y,+z), v3(-1,0,0), v2(textureScale * z * 1,  0)},//0
		Vertex{v3(-x,+y,+z), v3(-1,0,0), v2(textureScale * z * 1,  textureScale * y * 1)},//1
		Vertex{v3(-x,+y,-z), v3(-1,0,0), v2(0,            textureScale * y * 1)},//2
		Vertex{v3(-x,-y,+z), v3(-1,0,0), v2(textureScale * z * 1,  0)},//0
		Vertex{v3(-x,-y,-z), v3(-1,0,0), v2(0,            0)},//3
		Vertex{v3(-x,+y,-z), v3(-1,0,0), v2(0,            textureScale * y * 1)},//2

		Vertex{v3(-x,-y,-z), v3(0,0,-1), v2(0,            0)},//3
		Vertex{v3(-x,+y,-z), v3(0,0,-1), v2(0,            textureScale * y * 1)},//2
		Vertex{v3(+x,+y,-z), v3(0,0,-1), v2(textureScale * x * 1,  textureScale * y * 1)},//6
		Vertex{v3(-x,-y,-z), v3(0,0,-1), v2(0,            0)},//3
		Vertex{v3(+x,-y,-z), v3(0,0,-1), v2(textureScale * x * 1,  0)},//7
		Vertex{v3(+x,+y,-z), v3(0,0,-1), v2(textureScale * x * 1,  textureScale * y * 1)},//6

		Vertex{v3(+x,-y,-z), v3(1,0,0), v2(0,            0)},//7
		Vertex{v3(+x,+y,-z), v3(1,0,0), v2(0,            textureScale * y * 1)},//6
		Vertex{v3(+x,+y,+z), v3(1,0,0), v2(textureScale * z * 1,  textureScale * y * 1)},//5
		Vertex{v3(+x,-y,-z), v3(1,0,0), v2(0,            0)},//7
		Vertex{v3(+x,-y,+z), v3(1,0,0), v2(textureScale * z * 1,  0)},//4
		Vertex{v3(+x,+y,+z), v3(1,0,0), v2(textureScale * z * 1,  textureScale * y * 1)},//5

		Vertex{v3(-x,-y,+z), v3(0,0,1), v2(0,            0)},//0
		Vertex{v3(-x,+y,+z), v3(0,0,1), v2(0,            textureScale * y * 1)},//1
		Vertex{v3(+x,+y,+z), v3(0,0,1), v2(textureScale * x * 1,  textureScale * y * 1)},//5
		Vertex{v3(-x,-y,+z), v3(0,0,1), v2(0,            0)},//0
		Vertex{v3(+x,-y,+z), v3(0,0,1), v2(textureScale * x * 1,  0)},//4
		Vertex{v3(+x,+y,+z), v3(0,0,1), v2(textureScale * x * 1,  textureScale * y * 1)},//5

		Vertex{v3(-x,+y,+z), v3(0,1,0), v2(0,            0)},//1
		Vertex{v3(-x,+y,-z), v3(0,1,0), v2(0,            textureScale * z * 1)},//2
		Vertex{v3(+x,+y,-z), v3(0,1,0), v2(textureScale * x * 1,  textureScale * z * 1)},//6
		Vertex{v3(-x,+y,+z), v3(0,1,0), v2(0,            0)},//1
		Vertex{v3(+x,+y,+z), v3(0,1,0), v2(textureScale * x * 1,  0)},//5
		Vertex{v3(+x,+y,-z), v3(0,1,0), v2(textureScale * x * 1,  textureScale * z * 1)},//6

		Vertex{v3(-x,-y,+z), v3(0,-1,0), v2(0,            0)},//0
		Vertex{v3(-x,-y,-z), v3(0,-1,0), v2(0,            textureScale * z * 1)},//3
		Vertex{v3(+x,-y,-z), v3(0,-1,0), v2(textureScale * x * 1,  textureScale * z * 1)},//7
		Vertex{v3(-x,-y,+z), v3(0,-1,0), v2(0,            0)},//0
		Vertex{v3(+x,-y,+z), v3(0,-1,0), v2(textureScale * x * 1,  0)},//4
		Vertex{v3(+x,-y,-z), v3(0,-1,0), v2(textureScale * x * 1,  textureScale * z * 1)},//7
	};

	std::vector<unsigned int> indices(vertices.size());
	for (int i = 0; i < vertices.size(); i++) {
		indices[i] = i;
	};

	return new Mesh(vertices, indices, this->textures);
}

Mesh* Shape::threeCubes(float outx, float outy, float outz, float inx, float iny, float inz) {

	std::vector<Vertex>vertices;

	std::map<int, v3>V;
	std::map< std::string, v3>N;
	V[0] = v3(-outx, outy, outz);
	V[1] = v3(-outx, outy, -outz);
	V[2] = v3(-outx, -outy, -outz);
	V[3] = v3(-outx, -outy, outz);
	V[4] = v3(-inx, iny, inz);
	V[5] = v3(-inx, iny, -inz);
	V[6] = v3(-inx, -iny, -inz);
	V[7] = v3(-inx, -iny, inz);
	V[8] = v3(outx, iny, inz);
	V[9] = v3(outx, iny, -inz);
	V[10] = v3(outx, -iny, -inz);
	V[11] = v3(outx, -iny, inz);
	V[12] = v3(outx, outy, outz);
	V[13] = v3(outx, outy, -outz);
	V[14] = v3(outx, -outy, -outz);
	V[15] = v3(outx, -outy, outz);

	N["up"] = v3(0, 1, 0);
	N["down"] = v3(0, -1, 0);
	N["left"] = v3(-1, 0, 0);
	N["right"] = v3(1, 0, 0);
	N["front"] = v3(0, 0, -1);
	N["back"] = v3(0, 0, 1);

	square(vertices, N["left"], V[0], V[1], V[2], V[3]);
	square(vertices, N["right"], V[4], V[5], V[6], V[7]);
	square(vertices, N["back"], V[12], V[0], V[3], V[15]);
	square(vertices, N["front"], V[8], V[4], V[7], V[11]);
	square(vertices, N["back"], V[9], V[5], V[6], V[10]);
	square(vertices, N["front"], V[13], V[1], V[2], V[14]);
	square(vertices, N["up"], V[0], V[1], V[5], V[4]);
	square(vertices, N["up"], V[1], V[13], V[9], V[5]);
	square(vertices, N["up"], V[12], V[8], V[4], V[0]);
	square(vertices, N["down"], V[3], V[2], V[6], V[7]);
	square(vertices, N["down"], V[6], V[2], V[14], V[10]);
	square(vertices, N["down"], V[15], V[11], V[7], V[3]);

	square(vertices, N["right"], V[8], V[12], V[15], V[11]);
	square(vertices, N["right"], V[10], V[14], V[13], V[9]);

	std::vector<unsigned int> indices(vertices.size());
	for (int i = 0; i < vertices.size(); i++) {
		indices.push_back(i);
	};

	return new Mesh(vertices, indices, this->textures);
}

Mesh* Shape::FullGate(float x, float y, float z, float Xradius, float Zradius, int slices) {

	std::vector<Vertex>vertices;

	float angle = (PI) / slices; // didnt mult by 2 because it's half circle

	auto squareGate = [](
		std::vector<Vertex>& vertices,
		v3 normal,
		v3 tl,
		v3 tr,
		v3 dr,
		v3 dl,
		float x,
		float z
		) {
			vertices.push_back(Vertex{ tl,v3(normal),v2(tl.x / x,tl.z / z) });//0
			vertices.push_back(Vertex{ tr,v3(normal),v2(tr.x / x,tr.z / z) });//1
			vertices.push_back(Vertex{ dr,v3(normal),v2(dr.x / x,dr.z / z) });//2

			vertices.push_back(Vertex{ tl,v3(normal),v2(tl.x / x,tl.z / z) });//0
			vertices.push_back(Vertex{ dl,v3(normal),v2(dl.x / x,dl.z / z) });//3
			vertices.push_back(Vertex{ dr,v3(normal),v2(dr.x / x,dr.z / z) });//2
		};

	std::map<int, v3> V;
	V[0] = v3(-x, -y, 0);
	V[1] = v3(-x, y, 0);
	V[2] = v3(-x, y, -z);
	V[3] = v3(-x, -y, -z);
	V[4] = v3(x, -y, 0);
	V[5] = v3(x, y, 0);
	V[6] = v3(x, y, -z);
	V[7] = v3(x, -y, -z);

	square(vertices, v3(-1, 0, 0), V[0], V[1], V[2], V[3]);
	square(vertices, v3(0, 0, -1), V[3], V[2], V[6], V[7]);
	square(vertices, v3(1, 0, 0), V[4], V[5], V[6], V[7]);

	float X, Z;
	float nextX, nextZ;
	for (int i = 0; i < slices; i++) {
		X = -static_cast<float>(cos(angle * i)) * Xradius;
		Z = -static_cast<float>(sin(angle * i)) * Zradius;

		nextX = -static_cast<float>(cos(angle * i + angle)) * Xradius;
		nextZ = -static_cast<float>(sin(angle * i + angle)) * Zradius;

		v3
			tl = v3(X, +y, Z),
			tr = v3(nextX, +y, nextZ),
			dl = v3(X, -y, Z),
			dr = v3(nextX, -y, nextZ);

		v3 from_center = glm::normalize(v3(X, 0, Z) + v3(nextX, 0, nextZ));

		square(vertices, -from_center, tl, tr, dr, dl);

		v3 up_normal = v3(0, 1, 0);
		v3 down_normal = v3(0, -1, 0);

		//top
		squareGate
		(
			vertices,
			up_normal,
			tl,
			v3(tl.x, +y, -z),
			v3(tr.x, +y, -z),
			tr,
			x,
			z
		);
		//down
		squareGate
		(
			vertices,
			down_normal,
			dl,
			v3(dl.x, -y, -z),
			v3(dr.x, -y, -z),
			dr,
			x,
			z
		);

		//left
		if (angle * i * 2.0f <= PI) {
			//top
			squareGate
			(
				vertices,
				up_normal,
				tl,
				v3(-x, +y, tl.z),
				v3(-x, +y, tr.z),
				tr,
				x,
				z
			);
			//down
			squareGate
			(
				vertices,
				down_normal,
				dl,
				v3(-x, -y, dl.z),
				v3(-x, -y, dr.z),
				dr,
				x,
				z
			);
		}

		//right
		if (angle * i * 2.0f >= PI) {
			//top
			squareGate
			(
				vertices,
				up_normal,
				tl,
				v3(+x, +y, tl.z),
				v3(+x, +y, tr.z),
				tr,
				x,
				z
			);
			//down
			squareGate
			(
				vertices,
				down_normal,
				dl,
				v3(+x, -y, dl.z),
				v3(+x, -y, dr.z),
				dr,
				x,
				z
			);
		}
	}

	squareGate(vertices, v3(0, 1, 0), v3(-x, y, -Zradius), v3(-x, y, -z), v3(-Xradius, y, -z), v3(-Xradius, y, -Zradius), x, z);
	squareGate(vertices, v3(0, -1, 0), v3(-x, -y, -Zradius), v3(-x, -y, -z), v3(-Xradius, -y, -z), v3(-Xradius, -y, -Zradius), x, z);

	squareGate(vertices, v3(0, -1, 0), v3(+x, -y, -Zradius), v3(+x, -y, -z), v3(+Xradius, -y, -z), v3(+Xradius, -y, -Zradius), x, z);
	squareGate(vertices, v3(0, 1, 0), v3(+x, y, -Zradius), v3(+x, y, -z), v3(+Xradius, y, -z), v3(+Xradius, y, -Zradius), x, z);

	std::vector<unsigned int> indices(vertices.size());
	for (int i = 0; i < vertices.size(); i++) {
		indices.push_back(i);
	};

	return new Mesh(vertices, indices, this->textures);
}

Mesh* Shape::theDome_of_the_Rock_GROWND(float x, float y, float z, float texDensity)
{
	std::vector<Vertex>vertices;

	x /= 10.f;
	z /= 10.f;
	texDensity /= 10.f;

	auto UPsquareTexD = [&vertices, &texDensity]
	(
		v3 normal,
		v3 tl,
		v3 tr,
		v3 dr,
		v3 dl
		)
		{
			vertices.push_back({ tl ,normal , v2(tl.x,tl.z) * texDensity });
			vertices.push_back({ tr ,normal , v2(tr.x,tr.z) * texDensity });
			vertices.push_back({ dr ,normal , v2(dr.x,dr.z) * texDensity });
			vertices.push_back({ tl ,normal , v2(tl.x,tl.z) * texDensity });
			vertices.push_back({ dl ,normal , v2(dl.x,dl.z) * texDensity });
			vertices.push_back({ dr ,normal , v2(dr.x,dr.z) * texDensity });
		};

	auto XSIDEsquareTexD = [&vertices, &texDensity]
	(
		v3 normal,
		v3 tl,
		v3 tr,
		v3 dr,
		v3 dl
		)
		{
			vertices.push_back({ tl ,normal , v2(tl.x,tl.y) * texDensity });
			vertices.push_back({ tr ,normal , v2(tr.x,tr.y) * texDensity });
			vertices.push_back({ dr ,normal , v2(dr.x,dr.y) * texDensity });
			vertices.push_back({ tl ,normal , v2(tl.x,tl.y) * texDensity });
			vertices.push_back({ dl ,normal , v2(dl.x,dl.y) * texDensity });
			vertices.push_back({ dr ,normal , v2(dr.x,dr.y) * texDensity });
		};

	auto ZSIDEsquareTexD = [&vertices, &texDensity]
	(
		v3 normal,
		v3 tl,
		v3 tr,
		v3 dr,
		v3 dl
		)
		{
			vertices.push_back({ tl ,normal , v2(tl.z,tl.y) * texDensity });
			vertices.push_back({ tr ,normal , v2(tr.z,tr.y) * texDensity });
			vertices.push_back({ dr ,normal , v2(dr.z,dr.y) * texDensity });
			vertices.push_back({ tl ,normal , v2(tl.z,tl.y) * texDensity });
			vertices.push_back({ dl ,normal , v2(dl.z,dl.y) * texDensity });
			vertices.push_back({ dr ,normal , v2(dr.z,dr.y) * texDensity });
		};

	float xx = 443 / 2 + 444;
	float zz = 513 / 2 + 117;

	std::map<int, v3>dV, uV;
	dV[0] = v3((887 - xx) * x, -y, (572 - zz) * z);
	dV[1] = v3((533 - xx) * x, -y, (630 - zz) * z);
	dV[2] = v3((505 - xx) * x, -y, (489 - zz) * z);
	dV[3] = v3((551 - xx) * x, -y, (482 - zz) * z);
	dV[4] = v3((540 - xx) * x, -y, (434 - zz) * z);
	dV[5] = v3((493 - xx) * x, -y, (445 - zz) * z);
	dV[6] = v3((444 - xx) * x, -y, (214 - zz) * z);
	dV[7] = v3((488 - xx) * x, -y, (207 - zz) * z);
	dV[8] = v3((477 - xx) * x, -y, (154 - zz) * z);
	dV[9] = v3((881 - xx) * x, -y, (117 - zz) * z);

	uV[0] = v3((887 - xx) * x, +y, (572 - zz) * z);
	uV[1] = v3((533 - xx) * x, +y, (630 - zz) * z);
	uV[2] = v3((505 - xx) * x, +y, (489 - zz) * z);
	uV[3] = v3((551 - xx) * x, +y, (482 - zz) * z);
	uV[4] = v3((540 - xx) * x, +y, (434 - zz) * z);
	uV[5] = v3((493 - xx) * x, +y, (445 - zz) * z);
	uV[6] = v3((444 - xx) * x, +y, (214 - zz) * z);
	uV[7] = v3((488 - xx) * x, +y, (207 - zz) * z);
	uV[8] = v3((477 - xx) * x, +y, (154 - zz) * z);
	uV[9] = v3((881 - xx) * x, +y, (117 - zz) * z);

	std::map<std::string, v3>N;
	N["up"] = v3(0, 1, 0);
	N["down"] = v3(0, -1, 0);
	N["front"] = v3(0, 0, -1);
	N["back"] = v3(0, 0, 1);
	N["left"] = v3(-1, 0, 0);
	N["right"] = v3(1, 0, 0);


	//10 sides
	XSIDEsquareTexD(N["back"], uV[1], uV[0], dV[0], dV[1]);
	ZSIDEsquareTexD(N["left"], uV[2], uV[1], dV[1], dV[2]);
	XSIDEsquareTexD(N["front"], uV[2], uV[3], dV[3], dV[2]);
	ZSIDEsquareTexD(N["left"], uV[3], uV[4], dV[4], dV[3]);
	XSIDEsquareTexD(N["back"], uV[5], uV[4], dV[4], dV[5]);
	ZSIDEsquareTexD(N["left"], uV[5], uV[6], dV[6], dV[5]);
	XSIDEsquareTexD(N["front"], uV[6], uV[7], dV[7], dV[6]);
	ZSIDEsquareTexD(N["left"], uV[7], uV[8], dV[8], dV[7]);
	XSIDEsquareTexD(N["front"], uV[8], uV[9], dV[9], dV[8]);
	ZSIDEsquareTexD(N["right"], uV[9], uV[0], dV[0], dV[9]);
	//6 up
	UPsquareTexD(N["up"], uV[2], uV[3], uV[0], uV[1]);
	UPsquareTexD(N["up"], uV[0], uV[0], uV[3], uV[4]);
	UPsquareTexD(N["up"], uV[0], uV[0], uV[4], uV[7]);
	UPsquareTexD(N["up"], uV[0], uV[0], uV[7], uV[8]);
	UPsquareTexD(N["up"], uV[0], uV[0], uV[8], uV[9]);
	UPsquareTexD(N["up"], uV[4], uV[7], uV[6], uV[5]);




	std::vector<unsigned int> indices(vertices.size());
	for (int i = 0; i < vertices.size(); i++) {
		indices.push_back(i);
	};

	return new Mesh(vertices, indices, this->textures);
}

Mesh* Shape::Triangle(float x1, float z1, float x2, float z2)
{
	std::vector<Vertex>vertices;

	tringle(
		vertices,
		v3(0, 1, 0),
		v3(0, 0, 0),
		v3(x1, 0, z1),
		v3(x2, 0, z2)
	);

	std::vector<unsigned int>indices(vertices.size());
	for (int i = 0; i < vertices.size(); i++) {
		indices[i] = i;
	}

	return new Mesh(vertices, indices, this->textures);
}