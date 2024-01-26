#include<SkyBox.h>

float Vertices[] =
{
    -1.0f,-1.0f, 1.0f,//0
     1.0f,-1.0f, 1.0f,//1
     1.0f,-1.0f,-1.0f,//2
    -1.0f,-1.0f,-1.0f,//3
    -1.0f, 1.0f, 1.0f,//4
     1.0f, 1.0f, 1.0f,//5
     1.0f, 1.0f,-1.0f,//6
    -1.0f, 1.0f,-1.0f //7
};

unsigned int Indices[] =
{
    //right
    1 , 2 , 6 ,
    6 , 5 , 1 ,
    //left
    0 , 4 , 7 ,
    7 , 3 , 0 ,
    //top
    4 , 5 , 6 ,
    6 , 7 , 4 ,
    //bottom
    0 , 3 , 2 ,
    2 , 1 , 0 ,
    //back
    0 , 1 , 5 ,
    5 , 4 , 0 ,
    //front
    3 , 7 , 6 ,
    6 , 2 , 3 
};



SkyBox::SkyBox(Camera*& camera , Window*& window, std::string& templateName)
    :camera(camera) , window(window)
{
    skyShader = new Shader("res/shaders/Sky.shader");   

    skyShader->set1i("skybox", 0);

    std::string faces[6] =
    {
        ("res/textures/skybox/"+templateName+"/right.jpg").c_str(),
        ("res/textures/skybox/"+templateName+"/left.jpg").c_str(),
        ("res/textures/skybox/"+templateName+"/top.jpg").c_str(),
        ("res/textures/skybox/"+templateName+"/bottom.jpg").c_str(),
        ("res/textures/skybox/"+templateName+"/front.jpg").c_str(),
        ("res/textures/skybox/"+templateName+"/back.jpg").c_str()
    };

    GlCall(glGenVertexArrays(1 , &VAO));
    GlCall(glGenBuffers(1 , &VBO));
    GlCall(glGenBuffers(1 , &EBO));
    GlCall(glBindVertexArray(VAO));
    GlCall(glBindBuffer(GL_ARRAY_BUFFER , VBO));
    GlCall(glBufferData(GL_ARRAY_BUFFER , sizeof(Vertices) , &Vertices , GL_STATIC_DRAW));
    GlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , EBO));
    GlCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER , sizeof(Indices) , &Indices , GL_STATIC_DRAW));
    GlCall(glVertexAttribPointer(0,3,GL_FLOAT , GL_FALSE , 3 * sizeof(float) , (void*)0));
    GlCall(glEnableVertexAttribArray(0));
    GlCall(glBindBuffer(GL_ARRAY_BUFFER ,0 ));
    GlCall(glBindVertexArray(0));
    GlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , 0));

    GlCall(glGenTextures(1 , &cubemapTexture));
    GlCall(glBindTexture(GL_TEXTURE_CUBE_MAP , cubemapTexture));
    GlCall(glTexParameteri(GL_TEXTURE_CUBE_MAP , GL_TEXTURE_MAG_FILTER , GL_LINEAR));
    GlCall(glTexParameteri(GL_TEXTURE_CUBE_MAP , GL_TEXTURE_MIN_FILTER , GL_LINEAR));
    GlCall(glTexParameteri(GL_TEXTURE_CUBE_MAP , GL_TEXTURE_WRAP_S , GL_CLAMP_TO_EDGE));
    GlCall(glTexParameteri(GL_TEXTURE_CUBE_MAP , GL_TEXTURE_WRAP_T , GL_CLAMP_TO_EDGE));
    GlCall(glTexParameteri(GL_TEXTURE_CUBE_MAP , GL_TEXTURE_WRAP_R , GL_CLAMP_TO_EDGE));

    for (unsigned int i = 0; i < 6; i++) {
        int width, height, nrChannels;
        unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            stbi_set_flip_vertically_on_load(false);
            glTexImage2D
            (
                    GL_TEXTURE_CUBE_MAP_POSITIVE_X + i ,
                    0,
                    GL_RGB,
                    width,
                    height,
                    0,
                    GL_RGB,
                    GL_UNSIGNED_BYTE,
                    data
            );
        }
        else {
            std::cout << "failed to load skybox texture at path" << faces[i] << std::endl; 
        }
        stbi_image_free(data);
    }
};

void SkyBox::Draw()
{

    glDepthFunc(GL_LEQUAL);
    auto projection = glm::perspective(glm::radians(camera->Zoom), (float)window->WIDTH / (float)window->HEIGHT, 0.1f, 100.0f);
    skyShader->setProjection(projection);

    auto view = glm::mat4(1.0f);
    view = glm::mat4(glm::mat3(glm::lookAt(camera->Position, camera->Position + camera->Front, camera->Up)));
    skyShader->setView(view);

    GlCall(glBindVertexArray(VAO));
    GlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO));
    GlCall(glActiveTexture(GL_TEXTURE0));
    GlCall(glBindTexture(GL_TEXTURE_CUBE_MAP , cubemapTexture));
    GlCall(glDrawElements(GL_TRIANGLES , 36 , GL_UNSIGNED_INT , 0));
    GlCall(glBindVertexArray(0));

    glDepthFunc(GL_LESS);
};
