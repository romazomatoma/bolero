#define USE_GLFW
#ifdef USE_GLFW
#include <GLFW/glfw3.h>
#endif
#include <iostream>

int TryMain(){
#ifdef USE_GLFW
    if (!glfwInit()){
        return 1;
    }
    const char *glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow *window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL);
    if (window == NULL){
        return 1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        {
            glBegin(GL_LINES);
            static float x = 0;
            glVertex3f(0,0.25f,0);
            glVertex3f(x+=0.01f,0,0);
            glEnd();
        }

        glfwSwapBuffers(window);
    }
    glfwDestroyWindow(window);
    glfwTerminate();
#endif
    return 0;
}

int main(){
    std::cout << "hello try" << std::endl;
    return TryMain();
}
