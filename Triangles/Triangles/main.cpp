//
//  main.cpp
//  Triangles
//
//  Created by yulin on 2017/8/22.
//  Copyright © 2017年 Copoch. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <LoadShaders.h>

using namespace std;

#define BUFFER_OFFSET(a) ((void*)(a))

static const GLfloat g_vertex_buffer_data[] = {
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    0.0f,  1.0f, 0.0f,
};

static void error_callback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

int main(int argc, const char* argv[]) {
    GLFWwindow* window;
    
    glfwSetErrorCallback(error_callback);
    
    /* Initialize the library */
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    
    // 使用最新的OpenGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello Triangles", NULL, NULL);
    
    if (!window) {
        glfwTerminate();
        return -1;
    }
    
    glfwSetKeyCallback(window, key_callback);
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    
    
    GLuint vertexbuffer;
    
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    
//    cout << "OpenGL Vendor:" << glGetString(GL_VENDOR) << endl;
//    cout << "OpenGL Renderer: " << glGetString(GL_RENDERER) << endl;
//    cout << "OpenGL Version: " << glGetString(GL_VERSION) << endl;
//    cout << "GLSL Version:" << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
    
    ShaderInfo  shaders[] =
    {
        { GL_VERTEX_SHADER, "medias/shaders/triangles/triangles.vert" },
        { GL_FRAGMENT_SHADER, "medias/shaders/triangles/triangles.frag" },
        { GL_NONE, NULL }
    };

    GLuint program = LoadShaders( shaders );
    glUseProgram( program );

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glEnableVertexAttribArray(0);
//        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
                              0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                              3,                  // size
                              GL_FLOAT,           // type
                              GL_FALSE,           // normalized?
                              0,                  // stride
                              BUFFER_OFFSET(0)    // array buffer offset
                              );
        // Draw the triangle
        glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
        glDisableVertexAttribArray(0);
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        
        /* Poll for and process events */
        glfwPollEvents();
    }
    
    glfwTerminate();
    
    exit(EXIT_SUCCESS);
}
