#pragma once
#include <Mesh.h>
#include <Shape.h>

#define defaultParameters std::vector<Mesh*>& meshes,float scale, float Yrotate , v3 positionVec3 ,std::vector<std::vector<Texture> >& textures

#define NoTextureDefaultParameters std::vector<Mesh*>& meshes,float scale, float Yrotate , v3 positionVec3 

class ShapeDesigner {
private:
	Shape* shape;
public:
	ShapeDesigner() { this->shape = new Shape(); };
	
	mat4 fastModel(float scale , v3 allPosition, float allRotation, v3 justThisPostion, v3 justThisRotation)
	{
		//first assign the model to mat4 1 so you dont copy the previous changes from the previous mesh
		mat4 model = mat4(1.0f);
		//1)translate to positionVec3 this is for all the meshes of this function
		model = translate(model, allPosition);
		//2)rotate Yrotate degrees arround the Y (v3(0,1,0)) this is for all the meshes of this function
		model = rotate(model, radians(allRotation), v3(0, 1, 0));
		//3)translate to this mesh postion (what do you want) this is for all the meshes of this function
		//
		// 	   note here you want to mult the vector by scale
		//
		model = translate(model, scale * justThisPostion);
		//4)rotate any degree you want degrees arround the Y (v3(0,1,0)) this is for this mesh only

		model = rotate(model, radians((float)justThisRotation.x), v3(1, 0, 0));
		model = rotate(model, radians((float)justThisRotation.y), v3(0, 1, 0));
		model = rotate(model, radians((float)justThisRotation.z), v3(0, 0, 1));

		return model;
	}
	mat4 fastModel2(float scale , v3 allPosition, float allRotation, v3 justThisPostion, v3 justThisRotation, mat4 model0)
	{
		//first assign the model to mat4 1 so you dont copy the previous changes from the previous mesh
		mat4 model = model0;
		//1)translate to positionVec3 this is for all the meshes of this function
		model = translate(model, allPosition);
		//2)rotate Yrotate degrees arround the Y (v3(0,1,0)) this is for all the meshes of this function
		model = rotate(model, radians(allRotation), v3(0, 1, 0));
		//3)translate to this mesh postion (what do you want) this is for all the meshes of this function
		//
		// 	   note here you want to mult the vector by scale
		//
		model = translate(model, scale * justThisPostion);
		//4)rotate any degree you want degrees arround the Y (v3(0,1,0)) this is for this mesh only

		model = rotate(model, radians((float)justThisRotation.x), v3(1, 0, 0));
		model = rotate(model, radians((float)justThisRotation.y), v3(0, 1, 0));
		model = rotate(model, radians((float)justThisRotation.z), v3(0, 0, 1));

		return model;
	}
	mat4 fastModel2Copy(mat4 model0, float scale , v3 allPosition, float allRotation, v3 justThisPostion, v3 justThisRotation)
	{
		//first assign the model to mat4 1 so you dont copy the previous changes from the previous mesh
		mat4 model = model0;
		//1)translate to positionVec3 this is for all the meshes of this function
		model = translate(model, allPosition);
		//2)rotate Yrotate degrees arround the Y (v3(0,1,0)) this is for all the meshes of this function
		model = rotate(model, radians(allRotation), v3(0, 1, 0));
		//3)translate to this mesh postion (what do you want) this is for all the meshes of this function
		//
		// 	   note here you want to mult the vector by scale
		//
		model = translate(model, scale * justThisPostion);
		//4)rotate any degree you want degrees arround the Y (v3(0,1,0)) this is for this mesh only

		model = rotate(model, radians((float)justThisRotation.x), v3(1, 0, 0));
		model = rotate(model, radians((float)justThisRotation.y), v3(0, 1, 0));
		model = rotate(model, radians((float)justThisRotation.z), v3(0, 0, 1));

		return model;
	}

	void RamadanLamp(NoTextureDefaultParameters);

	void BigGate(NoTextureDefaultParameters);
	void BigGate2(NoTextureDefaultParameters, mat4 model0);

	void column(NoTextureDefaultParameters);

	void Minaret1(NoTextureDefaultParameters);
	void Minaret1(NoTextureDefaultParameters, mat4 model);
	void Minaret2(NoTextureDefaultParameters);
	void Minaret3(NoTextureDefaultParameters);


	void Dome_of_the_Rock(NoTextureDefaultParameters);
	void Dome_of_the_Chain(NoTextureDefaultParameters);

	void Dome_of_the_Rock_DOOR1(NoTextureDefaultParameters);
	void Dome_of_the_Rock_DOOR2(NoTextureDefaultParameters);

	void Dome_of_the_Rock_GATE2(NoTextureDefaultParameters);
	void Dome_of_the_Rock_GATE3(NoTextureDefaultParameters);
	void Dome_of_the_Rock_GATE4(NoTextureDefaultParameters);

	void Dome_of_the_Rock_GROUND(NoTextureDefaultParameters);
	void Dome_of_the_Rock_Stairs(NoTextureDefaultParameters);

	void idk1(NoTextureDefaultParameters);
	void idk2(NoTextureDefaultParameters);
	void idk3(NoTextureDefaultParameters);
	void idk3(NoTextureDefaultParameters, mat4 model0);
	void idk4(NoTextureDefaultParameters);

	void Qibali_Dome_for_abd(NoTextureDefaultParameters);
	void Qibali_Dome_for_abd(NoTextureDefaultParameters, mat4 model0);
};

