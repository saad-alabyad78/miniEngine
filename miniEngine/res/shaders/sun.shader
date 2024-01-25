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
	Normal = aNormal;
	texCoord = aTex;
	gl_Position = projection * view * vec4(crntPos, 1.0);
}








/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#shader fragment
#version 330 core

out vec4 FragColor;

in vec3 crntPos;
in vec3 Normal;
in vec2 texCoord;

uniform sampler2D diffuse0;

void main()
{
	FragColor = texture(diffuse0, texCoord);
}