//
//  main.cpp
//  RBKeyPress
//
//  Created by yulin on 2017/8/24.
//  Copyright © 2017年 Copoch. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <LoadShaders.h>
#include <vapp.h>

using namespace std;

#define BUFFER_OFFSET(a) ((void*)(a))

enum VAO_IDs { Triangles, NumVAOs };
enum Buffer_IDs { ArrayBuffer, NumBuffers };
enum Attrib_IDs { vPosition = 0 };

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

const GLuint NumVertices = 6;

class KeyPress: public VermilionApplication {
public:
//    typedef class VermilionApplication base;
    virtual void initialize(const char* title);
//    virtual void Display(bool auto_redraw);
    virtual void finalize();
//    virtual void Resize(int width, int height);
//    void OnKey(int key, int scancode, int action, int mods);
    static VermilionApplication* Create(void)
    {                                                       
        return (s_app = new KeyPress);
    }
};

//BEGIN_APP_DECLARATION(KeyPress)
//    virtual void Initialize(const char* title);
//    virtual void Display(bool auto_redraw);
//    virtual void Finalize();
//    virtual void Resize(int width, int height);
//    void OnKey(int key, int scancode, int action, int mods);
//END_APP_DECLARATION()

MAIN_DECL {
    VermilionApplication* app = KeyPress::Create();
    
    return 0;
}

//DEFINE_APP(KeyPress, "KeyPress")

//
// init
//

void KeyPress::initialize(const char* title) {
    
}
//{
////    base::Initialize(title);
//    
//    
//    glGenVertexArrays( NumVAOs, VAOs );
//    glBindVertexArray( VAOs[Triangles] );
//    
//    GLfloat  vertices[NumVertices][2] = {
//        { -0.90f, -0.90f }, {  0.85f, -0.90f }, { -0.90f,  0.85f },  // Triangle 1
//        {  0.90f, -0.85f }, {  0.90f,  0.90f }, { -0.85f,  0.90f }   // Triangle 2
//    };
//    
//    glGenBuffers( NumBuffers, Buffers );
....................






























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































//    glBindBuffer( GL_ARRAY_BUFFER, Buffers[ArrayBuffer] );
//    glBufferData( GL_ARRAY_BUFFER, sizeof(vertices),
//                 vertices, GL_STATIC_DRAW );
//    
//    ShaderInfo  shaders[] = {
//        { GL_VERTEX_SHADER, "medias/shaders/keypress/keypress.vert" },
//        { GL_FRAGMENT_SHADER, "medias/shaders/keypress/keypress.frag" },
//        { GL_NONE, NULL }
//    };
//    
//    GLuint program = LoadShaders( shaders );
//    glUseProgram( program );
//    
//    glVertexAttribPointer( vPosition, 2, GL_FLOAT,
//                          GL_FALSE, 0, BUFFER_OFFSET(0) );
//    glEnableVertexAttribArray( vPosition );
//}
//
//void KeyPress::OnKey(int key, int scancode, int action, int mods)
//{
//    if (action == GLFW_PRESS)
//    {
//        switch (key)
//        {
//            case GLFW_KEY_M:
//            {
//                static GLenum  mode = GL_FILL;
//                
//                mode = ( mode == GL_FILL ? GL_LINE : GL_FILL );
//                glPolygonMode( GL_FRONT_AND_BACK, mode );
//            }
//                return;
//        }
//    }
//    
////    base::OnKey(key, scancode, action, mods);
//}
//
////
//// display
////
//
//void KeyPress::Display(bool auto_redraw)
//{
//    glClear( GL_COLOR_BUFFER_BIT );
//    
//    glBindVertexArray( VAOs[Triangles] );
//    glDrawArrays( GL_TRIANGLES, 0, NumVertices );
//    
////    base::Display(auto_redraw);
//}
//
//void KeyPress::Resize(int width, int height)
//{
//    glViewport(0, 0, width, height);
//}
//
//void KeyPress::Finalize(void)
//{
//    
//}