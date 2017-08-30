#ifndef __VAPP_H__
#define __VAPP_H__

#include <glad/glad.h>

class VermilionApplication {
protected:
    inline VermilionApplication() {}
    virtual ~VermilionApplication() {}
    static VermilionApplication* s_app;
    GLFWwindow* m_pWindow;
    
#ifdef _WIN32
    ULONGLONG       m_appStartTime;
#else
    struct timeval  m_appStartTime;
#endif

    static void window_size_callback(GLFWwindow* window, int width, int height);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void char_callback(GLFWwindow* window, unsigned int codepoint);
    unsigned int app_time();
    
#ifdef _DEBUG
    static void APIENTRY DebugOutputCallback(GLenum source,
                                             GLenum type,
                                             GLuint id,
                                             GLenum severity,
                                             GLsizei length,
                                             const GLchar* message,
                                             GLvoid* userParam);
#endif

public:
    void loop();
    virtual void initialize(const char* title = 0);
    virtual void display(bool auto_redraw = true)
    {
        glfwSwapBuffers(m_pWindow);
    }
    virtual void finalize() {}
    virtual void resize(int width, int height)
    {
        glViewport(0, 0, width, height);
    }
    virtual void onKey(int key, int scancode, int action, int mods) {}
    virtual void onChar(unsigned int codepoint) {}
};

// #define BEGIN_APP_DECLARATION(appclass)                     \
// class appclass : public VermilionApplication                \
// {                                                           \
// public:                                                     \
//     typedef class VermilionApplication base;                \
//     static VermilionApplication* Create(void)              \
//     {                                                       \
//         return (s_app = new appclass);                      \
//     }

// #define END_APP_DECLARATION()                               \
// };

// #ifdef _DEBUG

// #ifdef _WIN32
// #define DEBUG_OUTPUT_CALLBACK                                                  \
// void APIENTRY VermilionApplication::DebugOutputCallback(GLenum source,         \
//                                                         GLenum type,           \
//                                                         GLuint id,             \
//                                                         GLenum severity,       \
//                                                         GLsizei length,        \
//                                                         const GLchar* message, \
//                                                         GLvoid* userParam)     \
// {                                                                              \
//     OutputDebugStringA(message);                                               \
//     OutputDebugStringA("\n");                                                  \
// }

// #else
// #define DEBUG_OUTPUT_CALLBACK                                                  \
// void APIENTRY VermilionApplication::DebugOutputCallback(GLenum source,         \
//                                                         GLenum type,           \
//                                                         GLuint id,             \
//                                                         GLenum severity,       \
//                                                         GLsizei length,        \
//                                                         const GLchar* message, \
//                                                         GLvoid* userParam)     \
// {                                                                              \
//     printf("Debug Message: SOURCE(0x%04X), "\
//         "TYPE(0x%04X), "\
//         "ID(0x%08X), "\
//         "SEVERITY(0x%04X), \"%s\"\n",\
//         source, type, id, severity, message);\
// }
// #endif

// #else
// #define DEBUG_OUTPUT_CALLBACK
// #endif

#ifdef _WIN32
#define MAIN_DECL int CALLBACK WinMain(_In_ HINSTANCE hInstance,         \
                                        _In_ HINSTANCE hPrevInstance,    \
                                        _In_ LPSTR lpCmdLine,            \
                                        _In_ int nCmdShow)
#else
#define MAIN_DECL int main(int argc, char ** argv)
#endif

#define DEFINE_APP(appclass, title)                         \
    VermilionApplication* VermilionApplication::s_app;      \
                                                            \
    void VermilionApplication::loop()                       \
    {                                                       \
        do                                                  \
        {                                                   \
            display();                                      \
            glfwPollEvents();                               \
        } while (!glfwWindowShouldClose(m_pWindow));        \
    }                                                       \
                                                            \
    MAIN_DECL                                               \
    {                                                       \
        VermilionApplication* app = appclass::Create();     \
        app->Ionitialize(title);                            \
        app->loop();                                        \
        app->finalize();                                    \
                                                            \
        return 0;                                           \
    }                                                       \
                                                            \
    // DEBUG_OUTPUT_CALLBACK

#endif   // __VAPP_H__
