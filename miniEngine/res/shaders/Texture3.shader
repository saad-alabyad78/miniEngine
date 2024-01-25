#shader vertex
#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTex;

out vec3 crntPos;
out vec3 Normal;
out vec2 texCoord;


uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;


void main()
{
	crntPos = vec3(model * vec4(aPos, 1.0f));
	Normal = mat3(transpose(inverse(model))) * aNormal;
	texCoord = aTex;
	gl_Position = projection * view * vec4(crntPos, 1.0);
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#shader fragment
#version 330 core

#define MAX_NOM_OF_LAMPS 13 + 13 + 9

out vec4 FragColor;

in vec3 crntPos;
in vec3 Normal;
in vec2 texCoord;

struct Son{
	//vec3 position;
	vec3 direction;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

struct Lamp {
	vec3 position;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float constant;
	float linear;//how far the light reaches
	float quadratic;//how fast the intensithy dies
};

struct Flash {
	vec3 position;
	vec3 direction;
	float cutOff;
	float outerCutOff;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float constant;
	float linear;
	float quadratic;
};

uniform sampler2D diffuse0;
//uniform sampler2D specular0;

uniform vec3 viewPos;
uniform float shininess;

uniform Son son;
uniform Lamp lamp[MAX_NOM_OF_LAMPS];
uniform Flash flash;

vec4 direcLight(Son son, vec3 norm, vec3 viewDir);
vec4 pointLight(Lamp lamp , vec3 norm , vec3 crntPos , vec3 viewDir);
vec4 spotLight(Flash flash , vec3 norm , vec3 crntPos ,vec3 viewDir);


void main()
{
	// properties
	vec3 norm = normalize(Normal);
	vec3 viewDir = normalize(viewPos - crntPos);

	vec4 texColor = texture(diffuse0 , texCoord);
	if(texColor.a < 0.1)
        discard;

	// phase 1: directional lighting
	vec4 result = direcLight(son, norm, viewDir);
	// phase 2: point lights
	for(int i=0 ; i < MAX_NOM_OF_LAMPS ; i++)
		 result += pointLight(lamp[i], norm, crntPos, viewDir);
	// phase 3: spot light
		 result += spotLight(flash, norm, crntPos, viewDir);

	FragColor = vec4(texColor.r * result.r, texColor.g * result.g, texColor.b * result.b, texColor.a) ;
}

vec4 pointLight(Lamp lamp, vec3 norm, vec3 crntPos, vec3 viewDir)
{
	// ambient
	vec3 ambient = lamp.ambient;

	// diffuse 
	vec3 lightDir = normalize(lamp.position - crntPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = lamp.diffuse * diff;

	// specular

	//vec3 reflectDir = reflect(-lightDir, norm);
	//float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);

	vec3 HalfWayDir = normalize(lightDir + viewDir);
	float spec = pow(max(dot(norm, HalfWayDir), 0.0), shininess);

	vec3 specular = lamp.specular * spec;

	// attenuation
	float distance = length(lamp.position - crntPos);
	float attenuation = 1.0 / (lamp.constant + lamp.linear * distance + lamp.quadratic * (distance * distance));

	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;

	return vec4(ambient + diffuse + specular, 1.0f);
}

vec4 direcLight(Son son, vec3 norm, vec3 viewDir)
{
	// ambient
	vec3 ambient = son.ambient;

	//diffuse
	vec3 lightDir = normalize(-son.direction);
	vec3 diffuse = max(dot(norm, lightDir), 0.0f) * son.diffuse;

	//specular
	//vec3 reflectionDir = reflect(-lightDir, norm);
	//float spec = pow(max(dot(viewDir, reflectionDir), 0.0f), shininess);

	vec3 HalfWayDir = normalize(lightDir + viewDir);
	float spec = pow(max(dot(norm, HalfWayDir), 0.0), shininess);

	vec3 specular = spec * son.specular;

	return vec4(ambient + diffuse + specular, 1.0f);
}

vec4 spotLight(Flash flash, vec3 norm, vec3 crntPos, vec3 viewDir)
{
	vec3 lightDir = normalize(flash.position - crntPos);

	// ambient
	vec3 ambient = flash.ambient;

	// diffuse 
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = flash.diffuse * diff;

	// specular
	//vec3 reflectDir = reflect(-lightDir, norm);
	//float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);

	vec3 HalfWayDir = normalize(lightDir + viewDir);
	float spec = pow(max(dot(norm, HalfWayDir), 0.0), shininess);

	vec3 specular = flash.specular * spec;

	// attenuation
	float distance = length(flash.position - crntPos);
	float attenuation = 1.0 / (flash.constant + flash.linear * distance + flash.quadratic * (distance * distance));

	// spotlight (soft edges)
	float theta = dot(lightDir, normalize(-flash.direction));
	float epsilon = (flash.cutOff - flash.outerCutOff);
	float intensity = clamp((theta - flash.outerCutOff) / epsilon, 0.0, 1.0);

	diffuse *= intensity;
	specular *= intensity;

	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;

	return vec4(ambient + diffuse + specular, 1.0f);
};