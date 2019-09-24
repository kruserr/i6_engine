//#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string project_name = "i6_engine";
    int screen_width = 1280;
    int screen_height = 720;
    int opengl_version_major = 3; // 4
    int opengl_version_minor = 0; // 1

    //Init GLFW
    if(!glfwInit())
    {
        std::cout << "ERROR"  << std::endl; 
        return(-1);
    }

    // GLFW Hints
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_VISIBLE, GL_TRUE);
    glfwWindowHint(GLFW_DECORATED, GL_TRUE);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, opengl_version_major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, opengl_version_minor);

    // Old GLFW Hints
    //glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    // Set Screen width and height
    GLFWmonitor* primary = glfwGetPrimaryMonitor();
    glfwGetMonitorWorkarea(primary, nullptr, nullptr, &screen_width, &screen_height);
    std::cout << screen_height << '\n' << screen_width << '\n';

    GLFWwindow* window = glfwCreateWindow(screen_width, screen_height, project_name.c_str(), nullptr, nullptr); // windowed
    //GLFWwindow* window = glfwCreateWindow(screen_width, screen_height, project_name.c_str(), primary, nullptr); // fullscreen
    if(window == nullptr)
    {
        std::cout << "ERROR"  << std::endl;
        glfwTerminate();
        return(-1);
    }

    uint32_t extensionCount = 0;
    //vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported" << std::endl;

    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;

    glfwMakeContextCurrent(window);

    // Game Loop
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glfwGetKey(window, GLFW_KEY_W);
        glfwGetKey(window, GLFW_KEY_A);
        glfwGetKey(window, GLFW_KEY_S);
        glfwGetKey(window, GLFW_KEY_D);

        //glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }


    glfwDestroyWindow(window);

    glfwTerminate();

    return 0;
}