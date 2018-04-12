//opengl libraries

#if defined(NANOGUI_GLAD)
    #if defined(NANOGUI_SHARED) && !defined(GLAD_GLAPI_EXPORT)
        #define GLAD_GLAPI_EXPORT
    #endif

    #include <glad/glad.h>
#else
    #if defined(__APPLE__)
        #define GLFW_INCLUDE_GLCOREARB
    #else
        #define GL_GLEXT_PROTOTYPES
    #endif
#endif

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//c++ libraries and the shadder class for opengl
#include <cstdio>
#include <iostream>
#include <cmath>
#include "shaderClass.h"

using namespace std;
class Columna{
    private:
        float width;
        float height;
        float deep;
        glm::vec3 initialPosition;
        float points[252];
        //opengl elements
        unsigned int VBOCOLUMN,VAOCOLUMN;
        glm::mat4 model;
    public:
    void fillpoints(){
        float xpos = this->width/2;
        float ypos = this->height/2;
        float zpos = this->deep/2;
        float tempPoints[] = {
            -xpos ,-ypos, -zpos,  0.664f, 0.0313725490f, 0.0313725490f, 1.0f,
            xpos ,-ypos, -zpos,   0.664f, 0.0313725490f, 0.0313725490f, 1.0f,
            xpos ,ypos, -zpos,    0.664f, 0.0313725490f, 0.0313725490f, 1.0f,
            xpos ,ypos, -zpos,    0.664f, 0.0313725490f, 0.0313725490f, 1.0f,
            -xpos ,ypos, -zpos,   0.664f, 0.0313725490f, 0.0313725490f, 1.0f,
            -xpos ,-ypos, -zpos,  0.664f, 0.0313725490f, 0.0313725490f, 1.0f,

            -xpos ,-ypos, zpos,   0.664f, 0.0313725490f, 0.0313725490f, 1.0f,
            xpos ,-ypos, zpos,    0.664f, 0.0313725490f, 0.0313725490f, 1.0f,
            xpos ,ypos, zpos,     0.664f, 0.0313725490f, 0.0313725490f, 1.0f,
            xpos ,ypos, zpos,     0.664f, 0.0313725490f, 0.0313725490f, 1.0f,
            -xpos ,ypos, zpos,    0.664f, 0.0313725490f, 0.0313725490f, 1.0f,
            -xpos ,-ypos, zpos,   0.664f, 0.0313725490f, 0.0313725490f, 1.0f,

            -xpos ,ypos, zpos,    0.82f, 0.04f, 0.04f, 1.0f,
            -xpos ,ypos, -zpos,   0.82f, 0.04f, 0.04f, 1.0f,
            -xpos ,-ypos, -zpos,  0.82f, 0.04f, 0.04f, 1.0f,
            -xpos ,-ypos, -zpos,  0.82f, 0.04f, 0.04f, 1.0f,
            -xpos ,-ypos, zpos,   0.82f, 0.04f, 0.04f, 1.0f,
            -xpos ,ypos, zpos,    0.82f, 0.04f, 0.04f, 1.0f,

            xpos ,ypos, zpos,     0.82f, 0.04f, 0.04f, 1.0f,
            xpos ,ypos, -zpos,    0.82f, 0.04f, 0.04f, 1.0f,
            xpos ,-ypos, -zpos,   0.82f, 0.04f, 0.04f, 1.0f,
            xpos ,-ypos, -zpos,   0.82f, 0.04f, 0.04f, 1.0f,
            xpos ,-ypos, zpos,    0.82f, 0.04f, 0.04f, 1.0f,
            xpos ,ypos, zpos,     0.82f, 0.04f, 0.04f, 1.0f,

            -xpos ,-ypos, -zpos,  0.988f, 0.3f, 0.3f, 1.0f,
            xpos ,-ypos, -zpos,   0.988f, 0.3f, 0.3f, 1.0f,
            xpos ,-ypos, zpos,    0.988f, 0.3f, 0.3f, 1.0f,
            xpos ,-ypos, zpos,    0.988f, 0.3f, 0.3f, 1.0f,
            -xpos ,-ypos, zpos,   0.988f, 0.3f, 0.3f, 1.0f,
            -xpos ,-ypos, -zpos,  0.988f, 0.3f, 0.3f, 1.0f,

            -xpos ,ypos, -zpos,   0.988f, 0.3f, 0.3f, 1.0f,
            xpos ,ypos, -zpos,    0.988f, 0.3f, 0.3f, 1.0f,
            xpos ,ypos, zpos,     0.988f, 0.3f, 0.3f, 1.0f,
            xpos ,ypos, zpos,     0.988f, 0.3f, 0.3f, 1.0f,
            -xpos ,ypos, zpos,    0.988f, 0.3f, 0.3f, 1.0f,
            -xpos ,ypos, -zpos,   0.988f, 0.3f, 0.3f, 1.0f
        };
        for(int i = 0; i < 252; i++){
            this->points[i]=tempPoints[i];
        }
    }
    Columna (){};
    Columna (glm::vec3 origin,float width, float height, float deep){
        this->width = width;
        this->height = height;
        this->deep = deep;
        this -> initialPosition = glm::vec3(origin.x-1.0f,origin.y-1.0f,origin.z-1.0f);
        this->fillpoints();
        this->model = glm::rotate(model, glm::radians(30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        this->model = glm::translate(this->model, this->initialPosition);
        glGenVertexArrays(1, &this->VAOCOLUMN);
        glGenBuffers(1, &this->VBOCOLUMN);
        glBindVertexArray(VAOCOLUMN);

        glBindBuffer(GL_ARRAY_BUFFER, VBOCOLUMN);
        glBufferData(GL_ARRAY_BUFFER, sizeof(this->points), this->points, GL_STATIC_DRAW);

        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,7 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,7 * sizeof(float), (void*)(3* sizeof(float)));
        glEnableVertexAttribArray(1);
        state = true;
    }
    Columna (glm::vec3 pos1, glm::vec3 pos2, float width, float deep){
        this->width = width;
        this->deep = deep;
        this->height = sqrt(pow(pos2.x-pos1.x,2)+pow(pos2.y-pos1.y,2)+pow(pos2.z-pos1.z,2));
        this->initialPosition = glm::vec3(pos1.x-1, pos1.y-1, pos1.z-1);
        this->fillpoints();
        this->model = glm::rotate(model, glm::radians(30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        float angleY = (180/M_PI) * asin((pos2.y-pos1.y)/sqrt(pow(pos2.x-pos1.x,2)+pow(pos2.y-pos1.y,2)));
        float angleZ = (180/M_PI) * asin((pos2.x-pos1.x)/sqrt(pow(pos2.x-pos1.x,2)+pow(pos2.z-pos1.z,2)));
        this->model = glm::rotate(model, glm::radians(-(90.0f-angleY)), glm::vec3(1.0f,0.0f,0.0f));
        this->model = glm::rotate(model, glm::radians(-(90.0f-angleZ)), glm::vec3(0.0f,0.0f,1.0f));
        this->model = glm::translate(this->model, this->initialPosition);
        glGenVertexArrays(1, &this->VAOCOLUMN);
        glGenBuffers(1, &this->VBOCOLUMN);
        glBindVertexArray(VAOCOLUMN);

        glBindBuffer(GL_ARRAY_BUFFER, VBOCOLUMN);
        glBufferData(GL_ARRAY_BUFFER, sizeof(this->points), this->points, GL_STATIC_DRAW);

        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,7 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,7 * sizeof(float), (void*)(3* sizeof(float)));
        glEnableVertexAttribArray(1);
    }
    void draw(glm::mat4 view, glm::mat4 projection, Shader ourShader,int viewLocation, int projLocation,int modelLocation){
        ourShader.use();

        glUniformMatrix4fv(modelLocation,1,GL_FALSE,glm::value_ptr(this->model));
        glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLocation,1,GL_FALSE,glm::value_ptr(projection));
        
        glBindVertexArray(this->VAOCOLUMN); 
            // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES,0,36);
        glBindVertexArray(0);
    }
    bool state;
    void verPuntos(){
        for(int i = 0; i<216; i++){
            cout << this->points[i] << " ";
        }
}
        
};