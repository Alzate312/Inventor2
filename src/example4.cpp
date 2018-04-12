/*
    src/example3.cpp -- C++ version of an example application that shows
    how to use nanogui in an application with an already created and managed
    glfw context.

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

// GLFW
//#include <nanogui/nanogui.h>
#include <nanogui/nanogui.h>
#include <nanogui/opengl.h>
#include <nanogui/glutil.h>
#include <nanogui/screen.h>
#include <nanogui/window.h>
#include <nanogui/layout.h>
#include <nanogui/label.h>
#include <nanogui/checkbox.h>
#include <nanogui/button.h>
#include <nanogui/toolbutton.h>
#include <nanogui/popupbutton.h>
#include <nanogui/combobox.h>
#include <nanogui/progressbar.h>
#include <nanogui/entypo.h>
#include <nanogui/messagedialog.h>
#include <nanogui/textbox.h>
#include <nanogui/slider.h>
#include <nanogui/imagepanel.h>
#include <nanogui/imageview.h>
#include <nanogui/vscrollpanel.h>
#include <nanogui/colorwheel.h>
#include <nanogui/colorpicker.h>
#include <nanogui/graph.h>
#include <nanogui/tabwidget.h>
#include <iostream>
#include <vector>
#include "wall.h"
#include "columna.h"
#include "shaderClass.h"

using std::vector;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::to_string;

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


#include <iostream>

using namespace nanogui;



float vertices[] = {
    -1.0f, -1.0f, -1.0f,  0.5647058,0.7490196f,0.986666f, 0.5f,
    1.0f, -1.0f, -1.0f,  0.5647058,0.7490196f,0.986666f, 0.5f,
    1.0f,  1.0f, -1.0f,  0.5647058,0.7490196f,0.986666f, 0.5f,
    1.0f,  1.0f, -1.0f,  0.5647058,0.7490196f,0.986666f, 0.5f,
    -1.0f,  1.0f, -1.0f,  0.5647058,0.7490196f,0.986666f, 0.5f,
    -1.0f, -1.0f, -1.0f,  0.5647058,0.7490196f,0.986666f, 0.5f,

    -1.0f, -1.0f,  1.0f,  0.5647058,0.7490196f,0.986666f, 0.5f,
     1.0f, -1.0f,  1.0f,  0.5647058,0.7490196f,0.986666f, 0.5f,
     1.0f,  1.0f,  1.0f,  0.5647058,0.7490196f,0.986666f, 0.5f,
    1.0f,  1.0f,  1.0f,  0.5647058,0.7490196f,0.986666f, 0.5f,
    -1.0f,  1.0f,  1.0f,  0.5647058,0.7490196f,0.986666f, 0.5f,
    -1.0f, -1.0f,  1.0f,  0.5647058,0.7490196f,0.986666f, 0.5f,

    -1.0f,  1.0f,  1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    -1.0f,  1.0f, -1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    -1.0f, -1.0f, -1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    -1.0f, -1.0f, -1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    -1.0f, -1.0f,  1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    -1.0f,  1.0f,  1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,

    1.0f,  1.0f,  1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    1.0f,  1.0f, -1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    1.0f, -1.0f, -1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    1.0f, -1.0f, -1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    1.0f, -1.0f,  1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    1.0f,  1.0f,  1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,

    -1.0f, -1.0f, -1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    1.0f, -1.0f, -1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    1.0f, -1.0f,  1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    1.0f, -1.0f,  1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    -1.0f, -1.0f,  1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    -1.0f, -1.0f, -1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,

    -1.0f,  1.0f, -1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    1.0f,  1.0f, -1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    1.0f,  1.0f,  1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    1.0f,  1.0f,  1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    -1.0f,  1.0f,  1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f,
    -1.0f,  1.0f, -1.0f,  0.2509803f,0.52941176f,0.86666666f, 0.5f
};

float lines[] = {
    -1.0f, -1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f, -1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f, -1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f,  1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f,  1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f,  1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f,  1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f, -1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,

    -1.0f, -1.0f,  1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
     1.0f, -1.0f,  1.0f,     0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f, -1.0f,  1.0f,     0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f,  1.0f,  1.0f,     0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f,  1.0f,  1.0f,     0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f,  1.0f,  1.0f,    0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f,  1.0f, 1.0f,    0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f, -1.0f,  1.0f,    0.83529411f,0.22745098f,0.10196078, 1.0f,

    -1.0f,  1.0f,  1.0f,    0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f,  1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f,  1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f, -1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f, -1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f, -1.0f,  1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f, -1.0f,  1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f,  1.0f,  1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,

    1.0f,  1.0f,  1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f,  1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f,  1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f, -1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f, -1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f, -1.0f,  1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f, -1.0f,  1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f,  1.0f,  1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,

    -1.0f, -1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f, -1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f, -1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f, -1.0f,  1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f, -1.0f,  1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f, -1.0f,  1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f, -1.0f,  1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f, -1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,

    -1.0f,  1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f,  1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f,  1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f,  1.0f,  1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    1.0f,  1.0f,  1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f,  1.0f,  1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f,  1.0f,  1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f,
    -1.0f,  1.0f, -1.0f,   0.83529411f,0.22745098f,0.10196078, 1.0f


};
//screen dimension
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
//Cube variables
float cubeDimension = 0.0f;

//info needed in order to split the cube
float divisionSize = 0.0f;
float numberDivisions = 0;

//camera vectors
glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);

//variables used in the camera cotrol
bool firstMouse = true;
float yaw   = -90.0f;   // yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
float pitch =  0.0f;
float lastX =  800.0f / 2.0;
float lastY =  600.0 / 2.0;
float fov   =  45.0f;

//this guarantee that the camera speed is the same on every pc
float deltaTime = 0.0f;	// Time between current frame and last frame
bool movementActive = false;

vector<Columna> colVector;
Screen *screen = nullptr;
void mouse_callbackMovement(GLFWwindow* window, double xpos, double ypos){
    glfwSetCursorPosCallback(window,
                [](GLFWwindow *, double x, double y) {
                screen->cursorPosCallbackEvent(x, y);
            }
        );

        glfwSetMouseButtonCallback(window,
            [](GLFWwindow *, int button, int action, int modifiers) {
                screen->mouseButtonCallbackEvent(button, action, modifiers);
            }
        );

        glfwSetKeyCallback(window,
            [](GLFWwindow *, int key, int scancode, int action, int mods) {
                screen->keyCallbackEvent(key, scancode, action, mods);
            }
        );

        glfwSetCharCallback(window,
            [](GLFWwindow *, unsigned int codepoint) {
                screen->charCallbackEvent(codepoint);
            }
        );

        glfwSetDropCallback(window,
            [](GLFWwindow *, int count, const char **filenames) {
                screen->dropCallbackEvent(count, filenames);
            }
        );

        glfwSetScrollCallback(window,
            [](GLFWwindow *, double x, double y) {
                screen->scrollCallbackEvent(x, y);
        }
        );

        glfwSetFramebufferSizeCallback(window,
            [](GLFWwindow *, int width, int height) {
                screen->resizeCallbackEvent(width, height);
            }
        );
}

//every time the mouse moves we call this functions.
void mouse_callback(GLFWwindow* window, double xpos, double ypos){
    if (firstMouse){
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f; // change this value to your liking
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(front);
}

//if we want zoom 
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
    if (fov >= 1.0f && fov <= 45.0f)
        fov -= yoffset;
    if (fov <= 1.0f)
        fov = 1.0f;
    if (fov >= 45.0f)
        fov = 45.0f;
}

void processInput(GLFWwindow *window){//in order to close the window if it's pressed escape key
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    float cameraSpeed =  0.8f * deltaTime; // adjust accordingly
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS){
        if(movementActive == false){
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            glfwSetCursorPosCallback(window, mouse_callback);
            movementActive = true;
            
        }else{
            glfwSetInputMode(window, GLFW_CURSOR,GLFW_CURSOR_NORMAL);
            glfwSetCursorPosCallback(window, mouse_callbackMovement);
            movementActive = false;
        }
    }
}
//this method split the cube in x number of slices
void splitCube(float division[], float x, float y, float z,float colorR, float colorG, float colorB, float colorA){
    int temp= 0;
    float xpos = x;
    float ypos = y;
    float zpos = z;
    int globalCounter = 0;
    for(int i = 0; i <= numberDivisions; i++){
       temp = globalCounter * 14;
       division[temp] =  xpos;
       division[temp+1] = y;
       division[temp+2] = z;
       division[temp+3] = colorR;
       division[temp+4] = colorG;
       division[temp+5] = colorB;
       division[temp+6] = colorA;
       division[temp+7] = xpos;
       division[temp+8] = -y;
       division[temp+9] = z;
       division[temp+10] = colorR;
       division[temp+11] = colorG;
       division[temp+12] = colorB;
       division[temp+13] = colorA;
       xpos += divisionSize;
       globalCounter++;
    }
    xpos = x;
    for(int i = 0; i <= numberDivisions; i++){
        temp = globalCounter * 14;
        division[temp] =  x;
        division[temp+1] = ypos;
        division[temp+2] = z;
        division[temp+3] = colorR;
        division[temp+4] = colorG;
        division[temp+5] = colorB;
        division[temp+6] = colorA;
        division[temp+7] = -x;
        division[temp+8] = ypos;
        division[temp+9] = z;
        division[temp+10] = colorR;
        division[temp+11] = colorG;
        division[temp+12] = colorB;
        division[temp+13] = colorA;
        ypos += divisionSize;
        globalCounter++;
    }
    ypos = y;
    for(int i = 0; i <= numberDivisions; i++){
        temp = globalCounter * 14;
        division[temp] =  -x;
        division[temp+1] = y;
        division[temp+2] = zpos;
        division[temp+3] = colorR;
        division[temp+4] = colorG;
        division[temp+5] = colorB;
        division[temp+6] = colorA;
        division[temp+7] = -x;
        division[temp+8] = -y;
        division[temp+9] = zpos;
        division[temp+10] = colorR;
        division[temp+11] = colorG;
        division[temp+12] = colorB;
        division[temp+13] = colorA;
        zpos += divisionSize;
        globalCounter++;
    }
    zpos = z;
    for(int i = 0; i <= numberDivisions; i++){
        temp = globalCounter * 14;
        division[temp] =  -x;
        division[temp+1] = ypos;
        division[temp+2] = -z;
        division[temp+3] = colorR;
        division[temp+4] = colorG;
        division[temp+5] = colorB;
        division[temp+6] = colorA;
        division[temp+7] = -x;
        division[temp+8] = ypos;
        division[temp+9] = z;
        division[temp+10] = colorR;
        division[temp+11] = colorG;
        division[temp+12] = colorB;
        division[temp+13] = colorA;
        ypos += divisionSize;
        globalCounter++;
    }
    ypos = y;
    for(int i = 0; i <= numberDivisions; i++){
       temp = globalCounter * 14;
       division[temp] =  xpos;
       division[temp+1] = y;
       division[temp+2] = -z;
       division[temp+3] = colorR;
       division[temp+4] = colorG;
       division[temp+5] = colorB;
       division[temp+6] = colorA;
       division[temp+7] = xpos;
       division[temp+8] = -y;
       division[temp+9] = -z;
       division[temp+10] = colorR;
       division[temp+11] = colorG;
       division[temp+12] = colorB;
       division[temp+13] = colorA;
       xpos += divisionSize;
       globalCounter++;
    }
    xpos = x;
    for(int i = 0; i <= numberDivisions; i++){
        temp = globalCounter * 14;
        division[temp] =  x;
        division[temp+1] = ypos;
        division[temp+2] = -z;
        division[temp+3] = colorR;
        division[temp+4] = colorG;
        division[temp+5] = colorB;
        division[temp+6] = colorA;
        division[temp+7] = -x;
        division[temp+8] = ypos;
        division[temp+9] = -z;
        division[temp+10] = colorR;
        division[temp+11] = colorG;
        division[temp+12] = colorB;
        division[temp+13] = colorA;
        ypos += divisionSize;
        globalCounter++;
    }
    ypos = y;
    for(int i = 0; i <= numberDivisions; i++){
        temp = globalCounter * 14;
        division[temp] =  x;
        division[temp+1] = y;
        division[temp+2] = zpos;
        division[temp+3] = colorR;
        division[temp+4] = colorG;
        division[temp+5] = colorB;
        division[temp+6] = colorA;
        division[temp+7] = x;
        division[temp+8] = -y;
        division[temp+9] = zpos;
        division[temp+10] = colorR;
        division[temp+11] = colorG;
        division[temp+12] = colorB;
        division[temp+13] = colorA;
        zpos += divisionSize;
        globalCounter++;
    }
    zpos = z;
    for(int i = 0; i <= numberDivisions; i++){
        temp = globalCounter * 14;
        division[temp] =  x;
        division[temp+1] = ypos;
        division[temp+2] = z;
        division[temp+3] = colorR;
        division[temp+4] = colorG;
        division[temp+5] = colorB;
        division[temp+6] = colorA;
        division[temp+7] = x;
        division[temp+8] = ypos;
        division[temp+9] = -z;
        division[temp+10] = colorR;
        division[temp+11] = colorG;
        division[temp+12] = colorB;
        division[temp+13] = colorA;
        ypos += divisionSize;
        globalCounter++;
    }
    ypos = y;
    for(int i = 0; i <= numberDivisions; i++){
        temp = globalCounter * 14;
        division[temp] =  xpos;
        division[temp+1] = y;
        division[temp+2] = z;
        division[temp+3] = colorR;
        division[temp+4] = colorG;
        division[temp+5] = colorB;
        division[temp+6] = colorA;
        division[temp+7] = xpos;
        division[temp+8] = y;
        division[temp+9] = -z;
        division[temp+10] = colorR;
        division[temp+11] = colorG;
        division[temp+12] = colorB;
        division[temp+13] = colorA;
        xpos += divisionSize;
        globalCounter++;
    }
    xpos = x;
    for(int i = 0; i <= numberDivisions; i++){
        temp = globalCounter * 14;
        division[temp] =  x;
        division[temp+1] = y;
        division[temp+2] = zpos;
        division[temp+3] = colorR;
        division[temp+4] = colorG;
        division[temp+5] = colorB;
        division[temp+6] = colorA;
        division[temp+7] = -x;
        division[temp+8] = y;
        division[temp+9] = zpos;
        division[temp+10] = colorR;
        division[temp+11] = colorG;
        division[temp+12] = colorB;
        division[temp+13] = colorA;
        zpos += divisionSize;
        globalCounter++;
    }
    zpos = z;
    for(int i = 0; i <= numberDivisions; i++){
        temp = globalCounter * 14;
        division[temp] =  xpos;
        division[temp+1] = -y;
        division[temp+2] = z;
        division[temp+3] = colorR;
        division[temp+4] = colorG;
        division[temp+5] = colorB;
        division[temp+6] = colorA;
        division[temp+7] = xpos;
        division[temp+8] = -y;
        division[temp+9] = -z;
        division[temp+10] = colorR;
        division[temp+11] = colorG;
        division[temp+12] = colorB;
        division[temp+13] = colorA;
        xpos += divisionSize;
        globalCounter++;
    }
    xpos = x;
    for(int i = 0; i <= numberDivisions; i++){
        temp = globalCounter * 14;
        division[temp] =  -x;
        division[temp+1] = -y;
        division[temp+2] = zpos;
        division[temp+3] = colorR;
        division[temp+4] = colorG;
        division[temp+5] = colorB;
        division[temp+6] = colorA;
        division[temp+7] = x;
        division[temp+8] = -y;
        division[temp+9] = zpos;
        division[temp+10] = colorR;
        division[temp+11] = colorG;
        division[temp+12] = colorB;
        division[temp+13] = colorA;
        zpos += divisionSize;
        globalCounter++;
    }
    zpos = z;
    cout << globalCounter*14<<"\n";
}

float numRegla3(float x){
    if (x > cubeDimension){
            return (x-cubeDimension)/cubeDimension +1;
        }else{
            return x/cubeDimension;
        }
}

int main(int /* argc */, char ** /* argv */) {
    bool mal = false;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
    #endif

    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    // Create a GLFWwindow object
    GLFWwindow* window = glfwCreateWindow(800, 800, "Inventor", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);


    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

#if defined(NANOGUI_GLAD)
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        throw std::runtime_error("Could not initialize GLAD!");
    glGetError(); // pull and ignore unhandled errors like GL_INVALID_ENUM
#endif

    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_ALWAYS);
    //glEnable (GL_BLEND); 
    //glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //line properties
    //glEnable( GL_LINE_SMOOTH );
    Shader ourShader("vertexShader.vs","fragmentShader.fs");
    // Create a nanogui screen and pass the glfw pointer to initialize

    screen = new Screen();
    screen->initialize(window, true);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    //glfwSwapInterval(0);

    

    // Create nanogui gui
    //everything with the gui
    Window *win = new Window(screen,"Variables");
    win->setPosition(Vector2i(15, 15));
    win->setLayout(new GroupLayout());

    TextBox *longitudTb = new TextBox(win,"0");
    longitudTb->setDefaultValue("0");
    longitudTb->setEditable(true);
    longitudTb->setFixedSize(Vector2i(100, 20));
    longitudTb->setFormat("[-]?[0-9]*\\.?[0-9]+");
    TextBox *divisionTb = new TextBox(win,"Divisions");
    divisionTb->setEditable(true);
    divisionTb->setFixedSize(Vector2i(100, 20));
    divisionTb->setFormat("[-]?[0-9]*\\.?[0-9]+");
    Button *sendBtn = new Button(win, "Send");
    sendBtn->setCallback([divisionTb,longitudTb]() {
        numberDivisions = stoi(divisionTb->value());
        cubeDimension = stoi(longitudTb->value())/2;
        cout<<"size: " << numberDivisions<<"\n"<< cubeDimension<<"\n";        
     });

    Window *colWin= new Window(screen, "Columna");
    colWin->setPosition(Vector2i(15, 160));
    colWin->setLayout(new GroupLayout());
    Widget *widCol = new Widget(colWin);
    widCol->setLayout(new BoxLayout(Orientation::Horizontal,Alignment::Middle, 0, 6));
    TextBox *colX = new TextBox(widCol,"");
    colX->setPlaceholder("X1");
    colX->setEditable(true);
    colX->setFixedSize(Vector2i(30, 20));
    colX->setFormat("[-]?[0-9]*\\.?[0-9]+");
    TextBox *colX2 = new TextBox(widCol,"");
    colX2->setPlaceholder("X2");
    colX2->setEditable(true);
    colX2->setFixedSize(Vector2i(30, 20));
    colX2->setFormat("[-]?[0-9]*\\.?[0-9]+");
    widCol = new Widget(colWin);
    widCol->setLayout(new BoxLayout(Orientation::Horizontal,Alignment::Middle, 0, 6));
    TextBox *colY = new TextBox(widCol,"");
    colY->setPlaceholder("Y1");
    colY->setEditable(true);
    colY->setFixedSize(Vector2i(30, 20));
    colY->setFormat("[-]?[0-9]*\\.?[0-9]+");
    TextBox *colY2 = new TextBox(widCol,"");
    colY2->setPlaceholder("Y2");
    colY2->setEditable(true);
    colY2->setFixedSize(Vector2i(30, 20));
    colY2->setFormat("[-]?[0-9]*\\.?[0-9]+");
    widCol = new Widget(colWin);
    widCol->setLayout(new BoxLayout(Orientation::Horizontal,Alignment::Middle, 0, 6));
    TextBox *colZ = new TextBox(widCol,"");
    colZ->setPlaceholder("Z1");
    colZ->setEditable(true);
    colZ->setFixedSize(Vector2i(30, 20));
    colZ->setFormat("[-]?[0-9]*\\.?[0-9]+");
    TextBox *colZ2 = new TextBox(widCol,"");
    colZ2->setPlaceholder("Z1");
    colZ2->setEditable(true);
    colZ2->setFixedSize(Vector2i(30, 20));
    colZ2->setFormat("[-]?[0-9]*\\.?[0-9]+");
    TextBox *widthTbCol = new TextBox(colWin,"");
    widthTbCol->setPlaceholder("width");
    widthTbCol->setEditable(true);
    widthTbCol->setFixedSize(Vector2i(70, 20));
    widthTbCol->setFormat("[-]?[0-9]*\\.?[0-9]+");
    TextBox *heightTbCol = new TextBox(colWin,"");
    heightTbCol->setPlaceholder("Height");
    heightTbCol->setEditable(true);
    heightTbCol->setFixedSize(Vector2i(70, 20));
    heightTbCol->setFormat("[-]?[0-9]*\\.?[0-9]+");
    TextBox *deepTbCol = new TextBox(colWin,"");
    deepTbCol->setPlaceholder("deep");
    deepTbCol->setEditable(true);
    deepTbCol->setFixedSize(Vector2i(70, 20));
    deepTbCol->setFormat("[-]?[0-9]*\\.?[0-9]+");
    Button *sendColum = new Button(colWin, "Send");
    sendColum->setCallback([colX,colY,colZ,colX2,colY2,colZ2, widthTbCol, heightTbCol,deepTbCol]() {
        float x=0;float y=0; float z=0;float wi;float he; float de;
        float x2=0;float y2=0; float z2=0;

        if(colX2->value() == "" &&colY2->value() == ""  && colZ2->value() == "" ){
            x=numRegla3(stoi(colX->value()));
            y=numRegla3(stoi(colY->value()));
            z=numRegla3(stoi(colZ->value()));
            wi=numRegla3(stoi(widthTbCol->value()));
            he=numRegla3(stoi(heightTbCol->value()));
            de=numRegla3(stoi(deepTbCol->value()));
            Columna col(glm::vec3(x,y,z),wi,he,de);
            colVector.push_back(col);
        }else{
            x=numRegla3(stoi(colX->value()));
            y=numRegla3(stoi(colY->value()));
            z=numRegla3(stoi(colZ->value()));
            x2=numRegla3(stoi(colX2->value()));
            y2=numRegla3(stoi(colY2->value()));
            z2=numRegla3(stoi(colZ2->value()));
            wi=numRegla3(stoi(widthTbCol->value()));
            de=numRegla3(stoi(deepTbCol->value()));
            Columna col(glm::vec3(x,y,z),glm::vec3(x2,y2,z2),wi,de);
        }
     });
    
    Window *wallCol= new Window(screen, "Columna");
    wallCol->setPosition(Vector2i(155, 15));
    wallCol->setLayout(new GroupLayout());
    Widget *widWall = new Widget(wallCol);
    widWall->setLayout(new BoxLayout(Orientation::Horizontal,Alignment::Middle, 0, 6));
    TextBox *wallX = new TextBox(widWall,"");
    wallX->setPlaceholder("X1");
    wallX->setEditable(true);
    wallX->setFixedSize(Vector2i(30, 20));
    wallX->setFormat("[-]?[0-9]*\\.?[0-9]+");
    TextBox *wallX2 = new TextBox(widWall,"");
    wallX2->setPlaceholder("X2");
    wallX2->setEditable(true);
    wallX2->setFixedSize(Vector2i(30, 20));
    wallX2->setFormat("[-]?[0-9]*\\.?[0-9]+");
    widWall = new Widget(wallCol);
    widWall->setLayout(new BoxLayout(Orientation::Horizontal,Alignment::Middle, 0, 6));
    TextBox *wallY = new TextBox(widWall,"");
    wallY->setPlaceholder("Y1");
    wallY->setEditable(true);
    wallY->setFixedSize(Vector2i(30, 20));
    wallY->setFormat("[-]?[0-9]*\\.?[0-9]+");
    TextBox *wallY2 = new TextBox(widWall,"");
    wallY2->setPlaceholder("Y2");
    wallY2->setEditable(true);
    wallY2->setFixedSize(Vector2i(30, 20));
    wallY2->setFormat("[-]?[0-9]*\\.?[0-9]+");
    widWall = new Widget(wallCol);
    widWall->setLayout(new BoxLayout(Orientation::Horizontal,Alignment::Middle, 0, 6));
    TextBox *wallZ = new TextBox(widWall,"");
    wallZ->setPlaceholder("Z1");
    wallZ->setEditable(true);
    wallZ->setFixedSize(Vector2i(30, 20));
    wallZ->setFormat("[-]?[0-9]*\\.?[0-9]+");
    TextBox *wallZ2 = new TextBox(widWall,"");
    wallZ2->setPlaceholder("Z1");
    wallZ2->setEditable(true);
    wallZ2->setFixedSize(Vector2i(30, 20));
    wallZ2->setFormat("[-]?[0-9]*\\.?[0-9]+");
    TextBox *widthTbWall = new TextBox(wallCol,"");
    widthTbWall->setPlaceholder("width");
    widthTbWall->setEditable(true);
    widthTbWall->setFixedSize(Vector2i(70, 20));
    widthTbWall->setFormat("[-]?[0-9]*\\.?[0-9]+");
    TextBox *heightTbWall = new TextBox(wallCol,"");
    heightTbWall->setPlaceholder("Height");
    heightTbWall->setEditable(true);
    heightTbWall->setFixedSize(Vector2i(70, 20));
    heightTbWall->setFormat("[-]?[0-9]*\\.?[0-9]+");
    TextBox *deepTbWall = new TextBox(wallCol,"");
    deepTbWall->setPlaceholder("deep");
    deepTbWall->setEditable(true);
    deepTbWall->setFixedSize(Vector2i(70, 20));
    deepTbWall->setFormat("[-]?[0-9]*\\.?[0-9]+");
    Button *sendWall = new Button(wallCol, "Send");

    screen->setVisible(true);
    screen->performLayout();

    
    
    unsigned int VBO, VAO,VAOLINES,VBOLINES,VBOINTERNAL,VAOINTERNAL;;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAOLINES);
    glGenBuffers(1, &VBOLINES);
    glGenVertexArrays(1, &VAOINTERNAL);
    glGenBuffers(1, &VBOINTERNAL);

    //bind te internal lines of the each face

    //bind the lines array object for lines
    glBindVertexArray(VAOLINES);

    glBindBuffer(GL_ARRAY_BUFFER, VBOLINES);
    glBufferData(GL_ARRAY_BUFFER, sizeof(lines), lines, GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,7 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,7 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,7 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);

    //model matrix
    glm::mat4 model;
    model = glm::rotate(model, glm::radians(30.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    //view matrix
    glm::mat4 view;
    // note that we're translating the scene in the reverse direction of where we want to move
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

    //projection matrix
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);


    //projection matrix
    glm::mat4 projectionLines;
    projectionLines = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    
     //model matrix
    glm::mat4 modelLines;
    modelLines = glm::rotate(modelLines, glm::radians(30.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    //view matrix
    glm::mat4 viewLines;
    // note that we're translating the scene in the reverse direction of where we want to move
    viewLines = glm::translate(viewLines, glm::vec3(0.0f, 0.0f, -3.0f));
    
    int modelLocation,viewLocation, projLocation;
    modelLocation = glGetUniformLocation(ourShader.ID,"model");
    viewLocation = glGetUniformLocation(ourShader.ID,"view");
    projLocation = glGetUniformLocation(ourShader.ID,"projection");


    
	float lastFrame = 0.0f; // Time of last frame
	float currentFrame = 0.0f; // current frame
    //in oreder to have the same movementspeed in every computer
    
	glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
    };
    int temp = 0;
    
    Columna col(glm::vec3(0.2,0.8,0.2), 0.2f, 1.0f,0.4f);
    Columna col1(glm::vec3(1.8f,1.2f,1.8f),0.2f,1.0f,0.4f);
    Columna col2(glm::vec3(0.6f,0.6f,0.4f),glm::vec3(0.8f,0.8f,0.4f), 0.1f, 0.2f);
    // Game loop
    while (!glfwWindowShouldClose(window)) {
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

        processInput(window);

        ourShader.use();
        glLineWidth( 1.0f );

        glDepthFunc(GL_ALWAYS);
        glClearColor(0.35686274f, 0.3647059f, 0.3647059f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // Check if any events have been activated (key pressed, mouse moved etc.) and call corresponding response functions
        

        
        
        projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
 		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
 		model = glm::translate(model, cubePositions[0]);
    
        glUniformMatrix4fv(modelLocation,1,GL_FALSE,glm::value_ptr(model));
        glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLocation,1,GL_FALSE,glm::value_ptr(projection));
        
        glBindVertexArray(VAO); 
        // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES,0,36);
        glBindVertexArray(0);
        
        projectionLines = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
 		viewLines = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
 		modelLines = glm::translate(modelLines, cubePositions[0]);
        glUniformMatrix4fv(modelLocation,1,GL_FALSE,glm::value_ptr(modelLines));
        glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(viewLines));
        glUniformMatrix4fv(projLocation,1,GL_FALSE,glm::value_ptr(projectionLines));
        glBindVertexArray(VAOLINES);
        glDrawArrays(GL_LINES,0,48);
        glBindVertexArray(0);

        if(numberDivisions!=0 && mal == false){
            temp = (numberDivisions+1)*168;
            float internalLines[temp];
            splitCube(internalLines,-1.0f,-1.0f,-1.0f,0.83529411f,0.22745098f,0.10196078f,1.0f);
            cout << "temp:" <<temp << "\n";

            glBindVertexArray(VAOINTERNAL);

            glBindBuffer(GL_ARRAY_BUFFER, VBOINTERNAL);
            glBufferData(GL_ARRAY_BUFFER, sizeof(internalLines), internalLines, GL_STATIC_DRAW);

            glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,7 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);

            glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,7 * sizeof(float), (void*)(3* sizeof(float)));
            glEnableVertexAttribArray(1);
            mal =true;
            
        }else{
            glBindVertexArray(VAOINTERNAL);
            glDrawArrays(GL_LINES,0,temp);
            glBindVertexArray(0);
        }

        col.draw(view,projection,ourShader, viewLocation, projLocation, modelLocation);
        col1.draw(view,projection,ourShader, viewLocation, projLocation, modelLocation);
        col2.draw(view,projection,ourShader, viewLocation, projLocation, modelLocation);
        for (vector<Columna>::iterator it = colVector.begin(); it!=colVector.end(); ++it){
            (*it).draw(view,projection,ourShader, viewLocation, projLocation, modelLocation);
        }

        // Draw nanogui
        screen->drawContents();
        screen->drawWidgets();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
         
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAOLINES);
    glDeleteBuffers(1, &VBOLINES);
    glDeleteVertexArrays(1, &VAOINTERNAL);
    glDeleteBuffers(1, &VBOINTERNAL);
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();

    return 0;
}
